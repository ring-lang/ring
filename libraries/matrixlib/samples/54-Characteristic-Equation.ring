// Func CharEquation(N) & EigenValue4(N)
// Characteristic Polynomial of a 4x4 Matrix [A - λI]
// EigneValue for the 4x4 matrix
// Bert MAriani 2023/06/23

Load "stdlibcore.ring"
Load "matrixlib.ring"

Func Main()

// Solution => λ4  -4λ3  -8λ2  -3λ
              
N  = [[1,2,1,2],     
      [1,1,1,4],    
      [1,1,1,4],    
      [1,1,1,1]]    
     
S1 = CharEquation(N)
See "Matrix " MatrixPrint(N)			   
See "Characteristic Equation: x4 -4x3 -8x2 -3x  0 "  MatrixFlatPrint(S1)

E1 = EigenValue4(N)
See "EigenValue 0, -1, 5.54, -0.54"  MatrixPrint(E1)

See nl+"==========================="+nl

A  = [[1,0,1,0], 
      [1,1,1,0],                 
      [1,1,1,0],                   
      [1,1,1,1]]                  

Solution = CharEquation(A)
See "Matrix " MatrixPrint(A)			   
See "Characteristic Equation: x4 -4x3 +4x2 -x  0 "  MatrixFlatPrint(Solution)

E1 = EigenValue4(A)
See "EigenValue 0, 1, 2.62, -.38"  MatrixPrint(E1)

See nl+"==========================="+nl


