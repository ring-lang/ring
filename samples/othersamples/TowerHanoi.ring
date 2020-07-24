#=================#
# Tower of hanoi 
#=================#

n_discs = 5

Alist = [1,2,3,4,5]    // Rod List with Disk 1-5
Blist = []
Clist = []

//------------------------------
// Main Prog

See "Start: ...................... A: "  Display(Alist)

hanoi( n_discs, 'A', 'B', 'C' )


//==============================

Func hanoi( n, src, dst, aux )

  if n >= 1
  
    hanoi( n - 1, src, aux, dst )       # recurs
    See nl+ "Move disk: "+n +"  from "+ src + "  to " + dst +"   "

    VisualRods(n, src, dst)    

    hanoi( n - 1, aux, dst, src )       # recurs
    
  ok

//------------------------------------
// Moved Disk 1-5 on Rod-List A B C

Func VisualRods(n, src, dst)

          if src = 'A'  Del( AList, 1) ok
          if src = 'B'  Del( BList, 1) ok
          if src = 'C'  Del( CList, 1) ok
          
          if dst = 'A'  Insert( AList, 0, n) ok
          if dst = 'B'  Insert( BList, 0, n) ok
          if dst = 'C'  Insert( CList, 0, n) ok
          
           See " A: " Display(Alist)
           See " B: " Display(Blist)
           See " C: " Display(Clist)
           
return

//----------------------------------------    
// Display Tower with Disk numbers

Func Display(Tower)

   if len(Tower) > 0
         for i = 1 to len(Tower)
            See  ""+ Tower[i] +" "
         next
   else
       See "..."
   ok
   
   See tab 
return

//-----------------------------------
