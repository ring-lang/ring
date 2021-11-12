# This is the SquaresPuzzle game, a simple RingAllegro application
# Author : Majdi Sobain <majdisobain@gmail.com>

Load "gamelib.ring"

BoardDim = 398
SquarePositions = [[0,0],2,3,4,5,6,7,8,9]
SquareDim = 0
Moves = 0
Squares = ["square",1]

# Initialization ===========
al_init()
al_init_image_addon()
al_init_font_addon()
al_init_ttf_addon()
font = al_load_ttf_font("pirulen.ttf",14,0 )
display = al_create_display(406,500)
al_set_window_title(display,"Squares Puzzle Game")
al_set_display_icon(display,al_load_bitmap("sp-palace.jpg"))
al_clear_to_color(al_map_rgb(255,255,255))
Board = al_create_bitmap(boarddim,boarddim)
al_set_target_bitmap(board)
al_clear_to_color(al_map_rgb(220,220,220))
al_set_target_bitmap(al_get_backbuffer(display))
al_draw_bitmap(board,al_get_display_width(display) / 2 - boarddim /2,al_get_display_height(display) / 2 - boarddim / 2,0)
Image = al_create_sub_bitmap(al_load_bitmap("sp-palace.jpg"),0,0,boarddim - 8 ,boarddim - 8)
MoveLabel = al_create_bitmap(al_get_display_width(display),30)
al_set_target_bitmap(movelabel)
al_clear_to_color(al_map_rgb(220,220,220))
al_set_target_bitmap(al_get_backbuffer(display))
al_draw_text(font, al_map_rgb(0,0,0), 150, 20,ALLEGRO_ALIGN_LEFT, "Squares :)")
al_flip_display()

# Events Initialization ===============================
event_queue = al_create_event_queue()
ev = al_new_allegro_event()
al_register_event_source(event_queue, al_get_display_event_source(display))
al_install_mouse()
al_register_event_source(event_queue, al_get_mouse_event_source())
al_install_keyboard()
al_register_event_source(event_queue, al_get_keyboard_event_source())

# SetSquaresPositionsAndDimensions =======================
squaredim = (boarddim - 8) / 3
boardx = al_get_display_width(display) /2 - boarddim /2
boardy = al_get_display_height(display) /2 - boarddim /2
SquarePositions[1] = [boardx +2 , boardy +2]
SquarePositions[2] = [boardx + squaredim + 4, boardy +2]
SquarePositions[3] = [boardx + squaredim * 2 + 6, boardy +2]
SquarePositions[4] = [boardx +2 , boardy + squaredim + 4]
SquarePositions[5] = [boardx + squaredim + 4, boardy + squaredim + 4]
SquarePositions[6] = [boardx + squaredim * 2 + 6, boardy + squaredim + 4]
SquarePositions[7] = [boardx +2 , boardy + squaredim * 2 + 6]
SquarePositions[8] = [boardx + squaredim + 4, boardy + squaredim * 2 + 6]
SquarePositions[9] = [boardx + squaredim * 2 + 6, boardy + squaredim * 2 + 6]

# CreateSquares ==========================
squares = list(9)
ind = 1
for j = 0 to 2
	for i = 0 to 2
		squares[ind] = [al_create_sub_bitmap(image,i * squaredim, j * squaredim,squaredim,squaredim),-1]
		ind += 1
	next
next
squares[9] = [al_create_sub_bitmap(board,1,1,squaredim,squaredim),-1]

# Draw full Pic with timer ===========
al_draw_bitmap(image,al_get_display_width(display) /2 - boarddim /2 + 4,al_get_display_height(display) /2 - boarddim /2 + 4,0)
al_flip_display()


timer = al_create_timer(1)
al_register_event_source(event_queue, al_get_timer_event_source(timer))
al_start_timer(timer)

moves = 3
while true
	al_wait_for_event(event_queue, ev)
	al_draw_bitmap(movelabel,0,al_get_display_height(display) - 30,0)
	al_draw_text(font, al_map_rgb(0,0,0), 200, al_get_display_height(display) - 20,ALLEGRO_ALIGN_LEFT, string(moves))
	moves -= 1
	al_flip_display()
	if moves = -1 moves = 0 exit ok
end
al_destroy_timer(timer)
al_rest(1)
al_draw_bitmap(movelabel,0,al_get_display_height(display) - 30,0)
al_draw_text(font, al_map_rgb(0,0,0), 150, al_get_display_height(display) - 20,ALLEGRO_ALIGN_LEFT, "Moves : " + moves)
al_flip_display()

# RandomizePositions ================================
for i = 1 to 9
	while true
		Ind = LimitRandom(1,9)
		found = false
		for s in squares
			if ind = s[2] found = true ok
		next
		if found = false squares[i][2] = ind exit ok
	end
next

# DrawRandomizedSquares ===============
al_set_target_bitmap(al_get_backbuffer(display))
al_draw_bitmap(board,al_get_display_width(display) / 2 - boarddim /2,al_get_display_height(display) / 2 - boarddim / 2,0)
for s in squares
	al_draw_bitmap(s[1],SquarePositions[s[2]][1],SquarePositions[s[2]][2],0)
next
al_flip_display()

while true
	al_wait_for_event(event_queue, ev)
	switch al_get_allegro_event_type(ev)
	on ALLEGRO_EVENT_DISPLAY_CLOSE
		exit
	on ALLEGRO_EVENT_MOUSE_BUTTON_UP
		mouse_x = al_get_allegro_event_mouse_x(ev)
		mouse_y = al_get_allegro_event_mouse_y(ev)
		for cursqr = 1 to 9
			dx = mouse_x - SquarePositions[cursqr][1]
			dy = mouse_y - SquarePositions[cursqr][2]
			if dx < squaredim and dx > 0 
				if dy < squaredim and dy > 0
					ns = CheckNearSpace(cursqr)
					if ns != 0 exsquareposition(cursqr,ns)
					ok
				ok
			ok
		next
	on ALLEGRO_EVENT_KEY_UP
		switch al_get_allegro_event_keyboard_keycode(ev)
		on ALLEGRO_KEY_UP
			ps = GiveSelectedSqrInd(1)
			if ps != 0 exsquareposition(ps,squares[9][2]) ok
		on ALLEGRO_KEY_DOWN
			ps = GiveSelectedSqrInd(3)
		             if ps != 0 exsquareposition(ps,squares[9][2]) ok
	            	on ALLEGRO_KEY_LEFT
			ps = GiveSelectedSqrInd(4)
		             if ps != 0 exsquareposition(ps,squares[9][2]) ok
            		on ALLEGRO_KEY_RIGHT
			ps = GiveSelectedSqrInd(2)
		             if ps != 0 exsquareposition(ps,squares[9][2]) ok
		off
	off
	if Solved() = true
		ft = al_load_ttf_font("pirulen.ttf",20,0 )
		lastpanel = al_create_bitmap(350,70)
		al_set_target_bitmap(lastpanel)
		al_clear_to_color(al_map_rgb(255,255,255))
		al_set_target_bitmap(al_get_backbuffer(display))
		al_draw_bitmap(lastpanel,al_get_display_width(display) /2 - boarddim /2 + 24,al_get_display_height(display) /2 -30,0)
if moves < 50
		al_draw_text(ft, al_map_rgb(0,0,0), 40, al_get_display_height(display) /2 - 20,ALLEGRO_ALIGN_LEFT, "Congratulations ^_^")
		al_draw_text(font, al_map_rgb(0,0,0), 80, al_get_display_height(display) /2,ALLEGRO_ALIGN_LEFT, "You Are Really Genius")
but moves >= 50 and moves < 100
		al_draw_text(ft, al_map_rgb(0,0,0), 40, al_get_display_height(display) /2 - 20,ALLEGRO_ALIGN_LEFT, "Congratulations ^_^")
		al_draw_text(font, al_map_rgb(0,0,0), 100, al_get_display_height(display) /2,ALLEGRO_ALIGN_LEFT, "You Are Really Smart")
but moves >= 100 and moves < 200
		al_draw_text(ft, al_map_rgb(0,0,0), 40, al_get_display_height(display) /2 - 20,ALLEGRO_ALIGN_LEFT, "Congratulations ^_^")
		al_draw_text(font, al_map_rgb(0,0,0), 100, al_get_display_height(display) /2,ALLEGRO_ALIGN_LEFT, "You Are Smart")
but moves >= 200	
		al_draw_text(ft, al_map_rgb(0,0,0), 40, al_get_display_height(display) /2 - 20,ALLEGRO_ALIGN_LEFT, "Congratulations ^_^")
		al_draw_text(font, al_map_rgb(0,0,0), 90, al_get_display_height(display) /2,ALLEGRO_ALIGN_LEFT, "But Slowly Solved")
ok
		al_flip_display()
		al_rest(15)
		exit
	ok
end


# Finalization =================
al_destroy_event_queue(event_queue)
al_destroy_allegro_event(ev)
for s in squares
	al_destroy_bitmap(s[1])
next
al_destroy_bitmap(image)
al_destroy_bitmap(board)
al_destroy_display(display)	

al_exit()

# =======END=of=Execution======

func LimitRandom S,E
while true
r = random(e)
if r >= s return r ok
end

func ExSquarePosition filled,spaced
	al_set_target_bitmap(al_get_backbuffer(display))
	al_draw_bitmap(squares[find(squares,filled,2)][1],SquarePositions[squares[9][2]][1],SquarePositions[squares[9][2]][2],0)
	al_draw_bitmap(squares[9][1],SquarePositions[filled][1],SquarePositions[filled][2],0)
	squares[9][2] = filled
	squares[find(squares,filled,2)][2] = spaced
	moves += 1
	al_draw_bitmap(movelabel,0,al_get_display_height(display) - 30,0)
	al_draw_text(font, al_map_rgb(0,0,0), 150, al_get_display_height(display) - 20,ALLEGRO_ALIGN_LEFT, "Moves : " + moves)
	al_flip_display()

func CheckNearSpace i
	S = squares[9][2]
	switch i
	on 1
		switch s on 2 return s on 4 return s off
	on 2
		switch s on 1 return s on 3 return s on 5 return s off
	on 3
		switch s on 2 return s on 6 return s off
	on 4
		switch s on 1 return s on 5 return s on 7 return s off
	on 5
		switch s on 2 return s on 4 return s on 6 return s on 8 return s off
	on 6
		switch s on 3 return s on 5 return s on 9 return s off
	on 7
		switch s on 4 return s on 8 return s off
	on 8
		switch s on 5 return s on 7 return s on 9 return s off
	on 9
		switch s on 6 return s on 8 return s off
	off
return 0

func GiveSelectedSqrInd Dir # Up 1, Right 2, Down 3, Left 4
	S = squares[9][2]
	switch s
	on 1
		switch dir on 1 return 4 on 4 return 2 off
	on 2
		switch dir on 1 return 5 on 2 return 1 on 4 return 3 off
	on 3
		switch dir on 1 return 6 on 2 return 2 off
	on 4
		switch dir on 1 return 7 on 4 return 5 on 3 return 1 off
	on 5
		switch dir on 1 return 8 on 2 return 4 on 3 return 2 on 4  return 6 off
	on 6
		switch dir on 1 return 9 on 2 return 5 on 3 return 3 off
	on 7
		switch dir on 3 return 4 on 4 return 8 off 
	on 8
		switch dir on 2 return 7 on 3 return 5 on 4 return 9 off
	on 9
		switch dir on 2 return 8 on 3 return 6 off
	off
return 0

func Solved
	for i = 1 to 9
	if squares[i][2] != i return false ok
	next
return true
