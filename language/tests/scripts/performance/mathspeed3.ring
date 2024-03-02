load "stdlibcore.ring"

func main
aList = newlist(800,800)

width = 800
height = 800
iteration = 500
minI = -2.28000000
MAXi = -2.52500000
MINR = 0.38000000
MaxR = 1.18000000

 startCalcClock = clock()	
	
    stepR = (maxR - minR) / width               ### step-Real-horizontal
    stepI = (maxI - minI) / height              ### step-Virtual-vertical

    for y = 1 to height                         ### Each vertical point Ring at 1
         pointI = minI + stepI * y              ### Imaginary + Step

        for x = 1 to width                      ### Each horizontal point Ring at 1
              pointR = minR + stepR * x         ### Real horizontal + Step

               zR = pointR                      ### Depth - horizontal-real
               zI = pointI                      ### Depth - vertical-imaginary

            for n = 0 to iteration              ### Does it leave Orbit ?
                a = zR * zR                  ###  zR^2  - horizontal-real
                b = zI * zI                   ###  zI^2  - vertical-imaginary

                if a + b > 4 exit ok            ### Beyond boundary limits +-2 

                zI = 2 * zR * zI + pointI       ### Vertical-imaginary + Step
                zR = a - b + pointR             ### Horizontal-real

            next

	    aList[x][y] = N
			
        next

    next
	
? "Time = " + ((clock()-startCalcClock)/clockspersecond()) + " seconds"
	
