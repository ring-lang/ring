//---------------------------------------------------------------------------
// Borland C++ Builder 6.0
//#include <vcl.h>
//#pragma hdrstop
//#pragma argsused

#include "ring.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//===========================================================================

clock_t start, end;
double  timeused;

int  Able[9][9], Baker[9][9], Rufus[60][2], Charlie[9][9];
int  row, col, icount, mode;

//==========================================================
// FUNCTION TO DISPLAY SUDOKU  "able" Array

void display()
{

   int  row, column ;
   char alpha ;

   printf("\n|-----------------------|\n");

   for (row = 0; row < 9; row++ )
   {
      printf("|");
      for (column = 0; column < 9; column++ )
      {
         printf(" %d", Able[row][column]) ;

         if ((column +1) % 3 == 0 )
         {   printf(" |");
         }
      }
      printf("\n");

      if ((row+1) % 3 == 0 )
      {   printf("|-----------------------|\n");
      }
   }

 return;
}


//=========================================================================
// m ROW , n COL

isFixed(int count, int m, int n)
{
   int i;

   for(i = 0; i < count; i++)
   {  if( m == Rufus[i][0] && n == Rufus[i][1])
      {  return(1);
      }
   }

 return(0);
}


//==========================================================
// BOX
// m ROW , n COL

int checkBox(int m, int n)
{
    int x,y;

    for(x = (m/3)*3; x < ((m/3)*3+3); x++)
    {   for(y = (n/3)*3; y < ((n/3)*3+3); y++)
        {
            if(m != x && n != y)
            {   if( Able[m][n] == Able[x][y])
            {
               return(0);
            }
         }
        }
   }

 return(1);
}

//==========================================================
// ROW
// m ROW , n COL

int checkRow(int m, int n)
{
   int x;

    for(x = 0; x < 9;x++)
    {
        if(x != n)
        {   if( Able[m][n] == Able[m][x])
            {   return(0);
         }
      }
    }

 return(1);
}

//==========================================================
// COLUMN
// m ROW , n COL

int checkCol(int m, int n)
{
    int x;

    for(x = 0; x < 9; x++)
    {
        if(x != m)
        {   if( Able[m][n] == Able[x][n])
            {   return(0);
         }
      }
    }

 return(1);
}

//==========================================================
// FUNCTION TO CHECK CONSISTENCY OF AN ELEMENT
// m ROW , n COL

int check(int m,int n)
{
    int c;
    c = checkBox(m,n);         // BOX
    
    if(c == 1)
        c = c * checkRow(m,n);  // ROW
    else
        return(c);

    if(c == 1)
        c = c * checkCol(m,n);  // COL
    else
        return(c);

  return(c);
}


//==========================================================
/*FUNCTION TO SOLVE SUDOKU*/

solve()
{
   int i, m = 0, n = 0, number, c,fixed;

   //-----------
    MAINALLOT:                 

        for( m = row; m < 9; m++)        // m ROW
        {
            n = col;
            while(n < 9)                  // n COL
            {
                number = 1;
                fixed  = isFixed( icount, m, n);
                
                if(fixed == 0)
                {
               //-----------
                    ALLOT:

                    Able[m][n] = number;
                    c = check(m,n);         // Check ROW-COL

                    if(c == 0)
                    {
                        number++;
                        if(number > 9)
                        {
                            Able[m][n] = 0;

                            if(n == 0)
                            {
                                row = m-1; col = 8;
                                if(row < 0)
                                    return(0);
                                
                                goto BACKADJUST;        //===>>>
                            }
                            else
                            {
                                row = m; col = n -1;
                                if(row < 0 || col < 0)
                                    return(0);

                                goto BACKADJUST;        //===>>>
                            }
                        }
                        
                        goto ALLOT;
                    }
                }
                
                n++;
                if(n > 8)
                    col = 0;
            }
        }
    return(1);

   //-----------
    BACKADJUST:

        fixed = isFixed(icount,row,col);

        if(fixed == 0)
        {
            number = Able[row][col];
            
            ALLOT1:
            
                number++;
                Able[row][col] = number;

                if(number > 9)
                {
                    Able[row][col] = 0;
                    if(col == 0)
                    {
                        row--; col = 8;
                        if(row < 0)
                            return(0);
                        
                        goto BACKADJUST;        //===>>>
                    }
                    else
                    {
                        col--;
                        if(col < 0)
                            return(0);
                        
                        goto BACKADJUST;         //===>>>
                    }
            }

            c = check(row,col);

            if(c == 0)
                goto ALLOT1;
            
            else
            {
                if(col == 8)
                {
                    row++;
                    if(row > 8)
                        return(0);
                    col = 0;
                    
                    goto MAINALLOT;         //===>>>
                }
                else
                {
                    col++;
                    if(col > 8)
                        return(0);
                    
                    goto MAINALLOT;         //===>>>
                }
            }
        }
        else
        {
            if(col == 0)
            {
                row--; col = 8;
                if(row < 0)
                    return(0);
                
                goto BACKADJUST;         //===>>>
            }
            else
            {
                col--;
                if(col < 0)
                    return(0);
                
                goto BACKADJUST;         //===>>>
            }
        }
        
}


//==========================================================
/*FUNCTION TO GENERATE SODOKU*/

void generate(int select)
{
    int c,i,m,n,count = 1,fixed,error;
    int choice ;
    time_t t;

    choice = select ;       // Level or Difficulty

    srand((unsigned) time(&t));     // Seed Random number  //randomize();

   //-----------
    GENERATE:
    
    for(m = 0; m <9 ; m++)        // m ROW
    {   for(n = 0; n < 9; n++)     // n COL
        {   Able[m][n] = 0;
       }
    }   
        
    for(i = 0; i < 60; i++)
    {
        Rufus[i][0] = 20; Rufus[i][1] = 20;    // Rufus 1..60 = [20][20]
    }
    
    //clrscr();
    //printf("\n Enter your choice of difficulty");
    //printf("\n 1.VERY EASY \n 2.EASY\n 3.MEDIUM \n 4.HARD \n ENTER: ");
    //scanf("%c",&choice);
    
    // Difficulty levels would vary from number of filled in squares
    //  - 17 Extreme
    //  - 26 Hard
    //  - 33 Newspaper level
    //  - 40 Easy
    //  - 50 Beginner
    
    switch(choice)
    {
        case 1: mode = 50 + rand() % 4;
              break;
        case 2: mode = 42 + rand() % 8;
              break;
        case 3: mode = 35 + rand() % 6;
              break;
        case 4: mode = 28 + rand() % 4;
              break;
        case 5: mode = 22 + rand() % 4;
              break;
              
        default : mode = 34 + rand() % 4;

        //default : getchar();
        //goto GENERATE;            //===>>>  Not 1 to 4
    }
	
	printf("Choice: %d Mode: %d \n", choice, mode);


    start = clock();

    Able[0][0]  = 1 + rand() % 8;
    Rufus[0][0] = 0;
    Rufus[0][1] = 0;
    
    for(count = 1; count < 10; count++)
    {
      //-----------
        CHOOSE:

        m = rand() % 9;
      n = rand() % 9;
        fixed = isFixed(icount, m, n);
        
        if(fixed == 1)
            goto CHOOSE;            //===>>>

        Rufus[count][0] = m;       // m Row
        Rufus[count][1] = n;       // n COL

      //-----------
        ALLOT:

            Able[m][n] = 1 + rand() % 9;

            if( Able[m][n] == 0)
                goto ALLOT;          //===>>>

            c = check(m,n);
            
            if(c==0)
                goto ALLOT;          //===>>>
            
    }

    icount = count;
    error  = solve();
    
    for(m = 0; m < 9; m++)
    {   for(n = 0;n<9;n++)
        {   Baker[m][n] = Able[m][n];
            row = 0; col = 0;
      }
   }
            
    for(i = 0; i < 60; i++)
    {
        Rufus[i][0] = 20; Rufus[i][1] = 20;
    }
    
    if(error==0)
        goto GENERATE;            //===>>>
    
    
    for(count = 0; count < mode / 2; count++)
    {
      //-----------
        CHOOSE2:

            m = rand() % 9;
         n = rand() % 5;
            fixed = isFixed(count,m,n);

            if(fixed==1)
                goto CHOOSE2;          //===>>>

            Rufus[count][0] = m;
         Rufus[count][1] = n;
            Rufus[count + mode / 2][0] = 8 -m;
            Rufus[count + mode / 2][1] = 8 -n;
    }

    for(m = 0; m <9 ; m++)
        for(n = 0; n < 9; n++)
        {
            fixed = isFixed(mode, m, n);
            if(fixed != 1 )
            {   Able[m][n] = 0;
         }
        }

    icount = mode;



    end = clock();
    timeused = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("Time taken: %f seconds \n", timeused ) ;

    //printf("Generate display to Solve \n");
    //display();

    //getchar();

 return;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////

//=================================================================
//=================================================================
// MAIN EQUIVALENT
// Must be LOWER-CASE names --- ring_functionname
// Request to GENERATE a puzzle of LEVEL 1..4

//=========================================================
//=========================================================
// CALLed BY -- aList = CreateTable(9,9,2)

RING_FUNC(ring_createtable)
{
    List *pList, *pRow;
    int   x, y, nRows, nCols;
    int   level, nbr, i, j;
    
    void  generate(int);
    int   solve(), checkBox(), checkRow(), checkCol(), check(), isFixed();
    void  display();
    
    // Create the List
        pList = RING_API_NEWLIST;
    
    // Create the table items
        nRows = (int) RING_API_GETNUMBER(1);
        nCols = (int) RING_API_GETNUMBER(2);
        level = (int) RING_API_GETNUMBER(3);
        
		//printf("Called with LEVEL: %d \n", level);

        generate(level);                            // ===>>> GENERATE PUZZLE
        
		
        // GENERATED Puzzle To RETURN
        for(x = 1 ; x <= nRows ; x++) 
        {
            pRow = ring_list_newlist(pList);
            for(y = 1 ; y <= nCols ; y++) 
            {
                nbr = Able[x-1][y-1];                   // C-Code-0, Ring-1 based
                ring_list_adddouble(pRow, nbr);     // <<<=== RETURN GENERATED PUZZLE
            }
        }
        
        
        // Show SOLUTION
        for(i = 0; i < 9; i++)
        {  for(j = 0; j < 9; j++)
            {   Able[i][j] = Baker[i][j];
            }
        }

   // printf("After Main display Solved Puzzle \n");
   // display();
        
    // Return Output
        RING_API_RETLIST(pList);
}

//=========================================================
//=========================================================
// Must be LOWER-CASE names 

RING_API void ringlib_init(RingState *pRingState)
{
    ring_vm_funcregister("createtable",  ring_createtable);
}


////////////////////////////////////////////////////////////////////



//===========================================================================
// MAIN PRORAM
//
/*
int main(int argc, char* argv[])
{
   void  generate(int);
    int   solve(), checkBox(), checkRow(), checkCol(), check(), isFixed();
   void  display();

   int  i,j;
   int  select = 9 ;
   
   //-----------------

   if ( argc >= 2 )
   {   select = atoi(argv[1]) ;
       printf("Select: %d ..\n", select);
   }

   printf("ARGS: %d, %s, %s ...\n",argc, argv[0], argv[1] );

    //clrscr();
   generate(select);                // ===>>> Generate Puzzle

   for(i = 0; i < 9; i++)
   {  for(j = 0; j < 9; j++)
      { Able[i][j] = Baker[i][j];
      }
   }

   printf("After Main display Solved Puzzle \n");
   display();
   getchar();


 return 0 ;


}
*/
