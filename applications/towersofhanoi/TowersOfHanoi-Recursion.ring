// The Towers of Hanoi, a game solved through Recursion 
// Bert Mariani 2020-07-24

count =   0
Tower = [[],[],[]]

See "How many Disks (5) : "  give aDisks    // Ask User
      Disks    = number(aDisks)
      Tower[1] = 1:Disks

See ".....START Disk from Pillar x to y | "  
      for i = 1 to Disks   See " "+ i   next   See " | "+ nl

Move (1, 2, 3, Disks)      //===>>> CALL

? "Finished"

//-----------------------------------------
// Recursive Logic - This is the Algorithm

Func Move(Src, Dest, Spare, numDisks)

   if numDisks > 1    
      Move (Src, Spare, Dest, numDisks-1)   //===>>> Recursion
   ok

   
   Display(Src, Dest)
   

   if numDisks > 1
      Move (Spare, Dest, Src, numDisks-1)   //===>>> Recursion  
   ok
   
return

//--------------------------------------
// Format output for Moves and Pillars

Func Display(Src, Dest)

   count++
   if  count < 10     See "   "   
   but count < 100    See "  "   
   but count < 1000   See " "     
   ok
   
   See " "+ count +" Move disk from Pillar "+ Src +" to "+ Dest +" | "
   
   Insert( Tower[Dest], 0, Tower[Src][1] )
      Del( Tower[Src],  1)
   

      for i = 1 to len(Tower[1])  See " "+ Tower[1][i]  next
         nCount = Disks - len(Tower[1])
         See copy("  ", nCount)   See " | "
 
 

      for i = 1 to len(Tower[2])  See " "+ Tower[2][i]  next
         nCount = Disks - len(Tower[2])
         See copy("  ", nCount)   See " | "

   

      for i = 1 to len(Tower[3])  See " "+ Tower[3][i]  next
         nCount = Disks - len(Tower[3])
         See copy("  ", nCount)   See " | "     
   
      See nl
   
return

//--------------------------------
