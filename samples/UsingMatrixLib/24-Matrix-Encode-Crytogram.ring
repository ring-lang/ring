// Bert Mariani  2023-02-24
// Encrytion-Decrption of a Message, Using Matrix and Inverse-Matrix (Linear Algebra)
Load "stdlibcore.ring"

 
//==============================
// Encrypt Matrix                    
MA = [[  1, -2,  2 ],
      [ -1,  1,  3 ],
      [  1, -1, -4 ]]

// Decrypt Matrix is Inverse Matrix of MA (Linear Algebra)
MC = [[ -1, -10, -8 ],
      [ -1, -6,  -5 ],
      [  0, -1,  -1 ]]


aCodeTable = "A":"Z"             // A B C ... X Y Z _
insert(aCodeTable,0,"_")         // 0=_ 1 =A 2=B  ..25=Y 26=Z

Message = "PLEASE_SEND_MONEY_"

//===============================


aCodeNumbers    = CodeMessage(Message)            // 16 12 5   1  19 5 

aEncryptNumbers = Encrypt(aCodeNumbers)           // 9 -25 48 -13 12 39

aDecryptNumbers = Decrypt(aEncryptNumbers)        // 16 12 5   1  19 5

aDecodeMessage  = DecodeMessage(aDecryptNumbers)  // PLE ASE


//=============================================
//=============================================
// FUNCTIONS

//===================================
// Message:      "P  L  E   A S  E   _ S  E   N  D _   M  O  N    E  Y  _ " 
// aCodeNumbers: "16 12 5   1 19 5   0 19 5   14 4 0   13 15 14   5  25 0 "

Func CodeMessage(Message)

  sizeMsg      = len(Message)         // Input Letters
  aCodeNumbers = list(sizeMsg)        // Code Numbers A=1 Z=27
  sizeCodeLet  = len(aCodeTable)      // GlobalTable "_A:Z"

 
 for i = 1 to sizeMsg
   
    Letter = Message[i]                        // find P in string
    
    for j = 1 to sizeCodeLet
        if Letter = aCodeTable[j]
           aCodeNumbers[i] = j -1              // Ring Index 1
        ok
    next

  next

  See "Code Numders: "
  DisplayFlat(aCodeNumbers)

return aCodeNumbers


//=============================================
// aCodeNumbers: "16 12 5    1   19 5    0  19 5   14  4  0   13  15 14   5  25 0 "
// ENCRYPT       "9 -25 48, -13 -12 39, -14 14 37, 10 -24 40, 12 -25 15, -20 15 85 " 

Func Encrypt(aCodeNbrs)

 MD =  [ 16, 12,  5 ]       // Horz Row: Code Nbrs :  1*16 + -1*12 + 1*5 => 16 -12  5 = 9

 MA = [[  1, -2,  2 ],      // Vert Col: Encrypt MAtrix
       [ -1,  1,  3 ],
       [  1, -1, -4 ]]

 //--------------------------------
 
 sizeEncryptNbrs  = len(aCodeNbrs)
 aEncryptNbrs     = list(sizeEncryptNbrs)   // Output array 
 cycleCount       = sizeEncryptNbrs / 3     // Match MA MD width

 for limit = 1 to cycleCount
  
    for p = 1 to 3                          // Fetch 3 aCodeNbrs at a time
       pos   = ((limit -1) * 3) +p
       MD[p] =   aCodeNbrs[pos]
    next


    for v = 1 to 3                          // MA Each Vert Col
       Nbr = 0

       for h = 1 to 3                       // MD Each Horz Row
          Nbr += MD[h] * MA[h][v]           // HorzRow * VertCol  
       next

       posin  = ((limit -1) * 3) +v         // position input to 
       aEncryptNbrs[posin] = Nbr
     next
  
 next

 See "Encrypt Numbers: "
 DisplayFlat(aEncryptNbrs)

return aEncryptNbrs

//====================================
// Encrypt Numbers  "9 -25 48, -13 -12 39, -14 14 37, 10 -24 40, 12 -25 15, -20 15 85 " 
// Decrypt Numbers  "16 12 5    1   19 5    0  19 5   14  4  0   13  15 14   5  25 0 "

Func Decrypt(aEncryptNumbers)
 
 MD =  [ 16, 12,  5 ]          // Nbrs to Decrypy

 MC = [[ -1, -10, -8 ],        // InverseMatrix for Decrypt
       [ -1, -6,  -5 ],
       [  0, -1,  -1 ]]

 sizeDecryptNbrs  = len(aEncryptNumbers)      // 18
 aDecryptNbrs     = list(sizeDecryptNbrs)     // Output array
 cycleCount       = sizeDecryptNbrs / 3       // Match MA MD width

 for limit = 1 to cycleCount
  
    for p = 1 to 3                            // Fetch 3 aCodeNbrs at a time
       pos   = ((limit -1) * 3) +p
       MD[p] =  aEncryptNumbers[pos]
    next


    for v = 1 to 3                          // MA Each Vert Col
       Nbr = 0

       for h = 1 to 3                       // MD Each Horz Row
          Nbr += MD[h] * MC[h][v]           // MC HorzRow * VertCol  
       next

       posin  = ((limit -1) * 3) +v         // position input to 
       aDecryptNbrs[posin] = Nbr
     next
  
 next

 See "DecryptNumbers: "
 DisplayFlat(aDecryptNbrs)
  
return aDecryptNbrs

//=============================================
// DecryptNumbers: "16 12 5    1   19 5    0  19 5   14  4  0   13  15 14   5  25 0 "
// DecodeLetters   "P  L  E    A   S  E    _  S  E   N   D  _   M   O  N    E  Y  _ "

Func DecodeMessage(aDecryptNbrs)

//   sizeMsg      = len(Message)         // Input Letters
//   aCodeNumbers = list(sizeMsg)        // Code Numbers A=1 Z=27
//   sizeCodeLet  = len(aCodeTable)      // GlobalTable "_A:Z"
// ---------------------------
  sizeNbrs     = len(aDecryptNbrs)       // Input Numbers
  aCodeLetters = list(sizeNbrs)          // To Letters A=1 Z=27
  sizeCodeLet  = len(aCodeTable)         // GlobalTable "_A:Z"
 
 
  for i = 1 to sizeNbrs
    Number = aDecryptNbrs[i]             // Get Number to Decode 
    Letter = aCodeTable[Number +1]       // Ring +1
    aCodeLetters[i] = Letter 
  next

  See "Code Letters: "
  DisplayFlat(aCodeLetters)

return aCodeLetters

//=============================================
// Display a Matrix Array by Row and Col size

Func DisplayArray(A)

x = len(A)       // Rows horz
y = len(A[1])    // Cols vert

 for h = 1 to x
   for v = 1 to y
     See " "+ A[h][v]
   next
   See nl
 next
   See nl

return

//================================================
// Display a Flat Array

Func DisplayFlat(A)

 x = len(A)           // Rows horz

 for h = 1 to x
     See " "+ A[h]
 next
     See nl

return

//================================================
