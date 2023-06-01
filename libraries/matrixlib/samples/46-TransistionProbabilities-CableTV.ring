// Matrix of Transition Probabililies
Load "stdlibcore.ring"
Load "matrixlib.ring"

// Two competing companies offer cable television service to a city of 100,000 households
// Change in subscription each yeay
// Company A now has 15,000 subscribers
// Company B has 20,000 subscribers
// No cable in 65,000 housholds
// How many subscribers will each company have a year from now 
//
// CableA Retains  70% Losses 20% to CableB  Gains 15% from CableB  Gains 15% from NoCable Losses 10% to NoCable
// CableB Retains  80% Losses 15% to CableA  Gains 20% from CableA  Gains 15% from NoCable Losses  5% to NoCable
// NoCable Retains 70% Losses 15% to CableA  Gains 10% from CableA  Gains  5% from CableB  Losses 15% to CableB
//
// Matrix of Transistion Probabilities
// From A     B     None    To A B None
PS = [[0.70, 0.15, 0.15],
      [0.20, 0.80, 0.15],
      [0.10, 0.05, 0.70]] 
	 
// State Matrix representing the current population in each of 3 states
// A B None
XS = [[15000],
      [20000],
      [65000]]
	 
// To find State Matrix representing the population in each of 3 states after 1 year
// Multiply P by X


See "PS start" MatrixPrint(PS)
See "XS start" MatrixPrint(XS)

for i = 1 to 20
   PXA = MatrixMulti(PS,XS)
   See "PX after year: "+i  MatrixPrint(PXA)
   XS = PXA
next
