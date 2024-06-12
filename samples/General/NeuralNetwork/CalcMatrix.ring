#-------------------------------------
# Author : Azzeddine Remmal
# 20-09-2022
#-------------------------------------

load "stdlibcore.ring"
load "consolecolors.ring"

Decimals(16)
Seed = random(9)

func ToCode (aInput) { 
	cCode = "["
	lStart = True
	for item in aInput { 
		if !lStart { 
			cCode += ","+Char(32)
			else
				lStart = False
		} 
		if isString(item) { 
			item2 = item
			item2 = substr(item2,'"','"+char(34)+"')
			cCode += Char(32)+'"'+item2+'"'
			elseif isnumber(item)
				cCode += Char(32)+""+item
			elseif islist(item)
				cCode += Windowsnl()
				cCode += ToCode(item)
			elseif isobject(item)
				aAttribut = attributes(item)
				cCode += "["
				lStart = True
				for attribut in aAttribut { 
					if !lStart { 
						cCode += ","
						else
							lStart = False
					} 
					value = getattribute(item,attribut)
					cCode += ":"+attribut+"="
					if isString(value) { 
						cCode += '"'+value+'"'
						elseif isNumber(value)
							cCode += value
						elseif isList(value)
							cCode += ToCode(value)
						elseif isobject(value)
							cCode += ToCode(value)
					} 
				} 
				cCode += " ]"+Windowsnl()
		} 
	} 
	cCode += Char(32)+"]"
	return cCode
} 

class MatrixCalc

	func CreateMatrix (DMatrix) { 
		SizeMatrix = len(DMatrix)
		NewParms = []
		for i = 2 to SizeMatrix { 
			NewParms+DMatrix[i]
		} 
		aOutput = list(DMatrix[1])
		if SizeMatrix = 1 { 
			for item in aOutput { 
				item = 0
			} 
			return aOutput
		} 
		for t in aOutput { 
			t = CreateMatrix(NewParms)
		} 
		return aOutput
	} 

	func ZeroPad (Matrix,topPadding,leftPadding) { 
		nOfRows = len(Matrix)+(topPadding*2)
		nOfCols = len(Matrix[1])+(leftPadding*2)
		aPad = MC.zeros(nOfRows,nOfCols)
		for i = topPadding+1 to nOfRows-topPadding { 
			for j = leftPadding+1 to nOfCols-leftPadding { 
				aPad[i][j] = Matrix[i-topPadding][j-leftPadding]
			} 
		} 
		return aPad
	} 

	func DivByNum (Matrix,num) { 
		aDivMatrix = Matrix
		if len(Matrix[1]) = 1 { 
			for v = 1 to len(Matrix) { 
				aDivMatrix[v][1] = Matrix[v][1]/num
			} 
			elseif len(Matrix) = 1
				for h = 1 to len(Matrix[1]) { 
					aDivMatrix[1][h] = Matrix[1][h]/num
				} 
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[v]) { 
						aDivMatrix[v][h] = Matrix[v][h]/num
					} 
				} 
		} 
		return aDivMatrix
	} 

	func MultDot (MatrixA,MatrixB) { 
		vertA = len(MatrixA)
		horzA = len(MatrixA[1])
		vertB = len(MatrixB)
		horzB = len(MatrixB[1])
		vertC = len(MatrixA)
		horzC = len(MatrixB)
		MulMatrix = list(vertA,horzB)
		#Make array bigV and bigH
		if horzA! = vertB { 
			? "Error: Cant Multiply the Matrix dimension: Horz-A:"+horzA+" MUST EQUAL vert-B:"+vertB
			? "dimension-A:"+vertA+"X"+horzA+"-----"+"dimension-B:"+vertB+"X"+horzB
			return 
		} 
		for v = 1 to vertA { 
			for h = 1 to horzB { 
				Sum = 0
				for k = 1 to horzA { 
					Sum += MatrixA[v][k]*MatrixB[k][h]
				} 
				MulMatrix[v][h] = Sum
			} 
		} 
		return MulMatrix
	} 

	func Multiply (MatrixA,MatrixB) { 
		vertA = len(MatrixA)
		horzA = len(MatrixA[1])
		vertB = len(MatrixB)
		horzB = len(MatrixB[1])
		aMultiply = list(vertA,horzA)
		if vertA! = vertB OR horzA! = horzB { 
			see "Error: Cant Multiply the Matrix dimension: Horz-A:"+horzA+" MUST EQUAL Horz-B:"+horzB+nl
			"vert-A:"+vertA+" MUST EQUAL vert-B:"+vertB
			return 1 
		} 
		for v = 1 to vertA { 
			for h = 1 to horzA { 
				aMultiply[v][h] = MatrixA[v][h]*MatrixB[v][h]
			} 
		} 
		return aMultiply
	} 

	func Add (MatrixA,MatrixB) { 
		vertA = len(MatrixA)
		horzA = len(MatrixA[1])
		vertB = len(MatrixB)
		horzB = len(MatrixB[1])
		aSum = list(vertA,horzA)
		if vertA! = vertB OR horzA! = horzB { 
			see "Error: Cant Add the Matrix dimension: Horz-A:"+horzA+" MUST EQUAL Horz-B:"+horzB+nl
			"vert-A:"+vertA+" MUST EQUAL vert-B:"+vertB
			return 1 
		} 
		for v = 1 to vertA { 
			for h = 1 to horzA { 
				aSum[v][h] = MatrixA[v][h]+MatrixB[v][h]
			} 
		} 
		return aSum
	} 

	func Subtract (MatrixA,MatrixB) { 
		vertA = len(MatrixA)
		horzA = len(MatrixA[1])
		vertB = len(MatrixB)
		horzB = len(MatrixB[1])
		aSubtract = list(vertA,horzA)
		if vertA! = vertB OR horzA! = horzB { 
			see "Error: Cant Subtract the Matrix dimension: Horz-A:"+horzA+" MUST EQUAL Horz-B:"+horzB+nl
			"vert-A:"+vertA+" MUST EQUAL vert-B:"+vertB
			return 1 
		} 
		for v = 1 to vertA { 
			for h = 1 to horzA { 
				aSubtract[v][h] = MatrixA[v][h]-MatrixB[v][h]
			} 
		} 
		return aSubtract
	} 

	func Transpose (Matrix) { 
		if len(Matrix) = 1 { 
			aTranspose = list(len(Matrix[1]),1)
			for v = 1 to len(aTranspose[1]) { 
				aTranspose[v][1] = Matrix[1][v]
			} 
			return aTranspose
			elseif len(Matrix[1]) = 1
				aTranspose = list(1,len(Matrix))
				for v = 1 to len(aTranspose) { 
					aTranspose[1][v] = Matrix[v][1]
				} 
				return aTranspose
			else
				aTranspose = list(len(Matrix[1]),len(Matrix))
				for v = 1 to len(aTranspose) { 
					for h = 1 to len(aTranspose[1]) { 
						aTranspose[v][h] = Matrix[h][v]
					} 
				} 
				return aTranspose
		} 
	} 

	func Maximum (Matrix,Axis) { 
		aMaximum = Matrix
		aAxis = []
		if !isList(Matrix[1]) { 
			return Max( Matrix ) 
		} 
		if Axis = 1 { 
			for v = 1 to len(Matrix) { 
				for h = 1 to len(Matrix) { 
					aAxis+aMaximum[v][Axis]
				} 
				Axis++
			} 
			aMaximum = Max(aAxis)
			return aMaximum
			elseif Axis = 0
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aAxis+aMaximum[v][h]
					} 
				} 
				aMaximum = Max(aAxis)
				return aMaximum
		} 
	} 

	func Zeros (vNum,hNum) { 
		aZeros = list(vNum,hNum)
		for v = 1 to vNum { 
			for h = 1 to hNum { 
				aZeros[v][h] = 0
			} 
		} 
		return aZeros
	} 

	func Identity (Num) { 
		aIdentity = Zeros(Num,Num)
		for v = 1 to Num { 
			aIdentity[v][v] = 1
		} 
		return aIdentity
	} 

	func Diag (alist) { 
		Num = len(alist)
		aDaig = Zeros(Num,Num)
		for v = 1 to Num { 
			aDaig[v][v] = alist[v]
		} 
		return aDaig
	} 

	func RandSeed (nSeed) { 
		Seed = nSeed
	} 

	func rand () { 
		x = sin(seed++)*10000
		return x- floor( x ) 
	} 

	func MRandInt (vNum,hNum,nMax) { 
		aMRandInt = list(vNum,hNum)
		for v = 1 to vNum { 
			for h = 1 to hNum { 
				aMRandInt[v][h] = Random(nMax)
			} 
		} 
		return aMRandInt
	} 

	func MRand (vNum,hNum) { 
		aRand = list(vNum,hNum)
		for v = 1 to vNum { 
			for h = 1 to hNum { 
				aRand[v][h] = Rand()
			} 
		} 
		return aRand
		#--------------------------------------------------------------
		#Arithmetic mean is the sum of elements along an axis divided by the number of elements.
		#The numpy.mean() function returns the arithmetic mean of elements in the array.
		#If the axis is mentioned, it is calculated along it.
		#--------------------------------------------------------------
	} 

	func Mean (Matrix) { 
		aArithmeticMean = Matrix
		aSum = []
		for v = 1 to len(aArithmeticMean) { 
			for h = 1 to len(aArithmeticMean[1]) { 
				aSum+aArithmeticMean[v][h]
			} 
		} 
		Sum = 0
		#? ToCode(aSum)
		for x = 1 to len(aSum) { 
			Sum += aSum[x]
		} 
		return Sum/ len( aSum ) 
	} 

	func Msqrt (Matrix) { 
		aSquare = Matrix
		for v = 1 to len(aSquare) { 
			for h = 1 to len(aSquare[1]) { 
				aSquare[v][h] = sqrt(Matrix[v][h])
			} 
		} 
		return aSquare
	} 


	func Square (Matrix) { 
		aSquare = Matrix
		for v = 1 to len(aSquare) { 
			for h = 1 to len(aSquare[1]) { 
				aSquare[v][h] = pow(Matrix[v][h],2)
			} 
		} 
		return aSquare
	} 

	func Sigmoid (Matrix) { 

		#--------------------------------------------------------------
		#The MatrixSigmoid() is a mathematical function used to find
		#the exponential values of all the elements present in the input Matrix.
		#--------------------------------------------------------------

		aSigmoid = Matrix
		for v = 1 to len(aSigmoid) { 
			for h = 1 to len(aSigmoid[1]) { 
				aSigmoid[v][h] = 1/(1+exp(-Matrix[v][h]))
			} 
		} 
		return aSigmoid
	} 

	func SigmoidPrime (Matrix) { 

		#--------------------------------------------------------------
		#The MatrixSigmoidPrime() is a mathematical function used to find
		#the derivative exponential values of all the elements present in the input Matrix.
		#--------------------------------------------------------------

		aSigmoidPrimeMatrix = Matrix
		if len(Matrix) = 1 { 
			aSigmoidPrimeMatrix = list(1,len(Matrix[1]))
			for v = 1 to len(Matrix[1]) { 
				aSigmoidPrimeMatrix[1][v] = Matrix[1][v]*(1-Matrix[1][v])
			} 
			return aSigmoidPrimeMatrix
			elseif len(Matrix[1]) = 1
				aSigmoidPrimeMatrix = list(len(Matrix),1)
				for v = 1 to len(Matrix) { 
					aSigmoidPrimeMatrix[v][1] = Matrix[v][1]*(1-Matrix[v][1])
				} 
				return aSigmoidPrimeMatrix
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aSigmoidPrimeMatrix[v][h] = Matrix[v][h]*(1-Matrix[v][h])
					} 
				} 
				return aSigmoidPrimeMatrix
		} 
	} 

	func MTanh (Matrix) { 

		#--------------------------------------------------------------
		#The hyperbolic tangent of an angle x is the ratio of the hyperbolic sine and hyperbolic cosine.
		#tanh ( x ) = sinh ( x ) cosh ( x ) = e 2 x − 1 e 2 x + 1 .
		#In terms of the traditional tangent function with a complex argument,
		#the identity is. tanh ( x ) = − i tan ( i x )
		#--------------------------------------------------------------


		aTanh = Matrix
		for v = 1 to len(aTanh) { 
			for h = 1 to len(aTanh[1]) { 
				aTanh[v][h] = tanh(Matrix[v][h])
			} 
		} 
		return aTanh
	} 

	func MTanhPrime (Matrix) { 
		aTanhPrime = Matrix
		if len(Matrix) = 1 { 
			aTanhPrime = list(1,len(Matrix[1]))
			for v = 1 to len(Matrix[1]) { 
				aTanhPrime[1][v] = 1-pow(tanh(Matrix[1][v]),2)
			} 
			return aTanhPrime
			elseif len(Matrix[1]) = 1
				aTanhPrime = list(len(Matrix),1)
				for v = 1 to len(Matrix) { 
					aTanhPrime[v][1] = 1-pow(tanh(Matrix[v][1]),2)
				} 
				return aTanhPrime
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aTanhPrime[v][h] = 1-pow(tanh(Matrix[v][h]),2)
					} 
				} 
				return aTanhPrime
		} 
	} 

	func LeakyReLU (Matrix) { 

		#--------------------------------------------------------------
		#/*What is LeakyReLU?
		#		Image result for LeakyReLU derivative
		#		Leaky Rectified Linear Unit, or Leaky ReLU,
		#		is a type of activation function based on a ReLU,
		#		 but it has a small slope for negative values instead of a flat slope.
		#		 The slope coefficient is determined before training,
		#		 i.e. it is not learnt during training*/
		#--------------------------------------------------------------

		aTanh = Matrix
		for v = 1 to len(aTanh) { 
			for h = 1 to len(aTanh[1]) { 
				aTanh[v][h] = MLeakyReLU(Matrix[v][h])
			} 
		} 
		return aTanh
	} 

	func LeakyReLUPrime (Matrix) { 
		aTanhPrime = Matrix
		if len(Matrix) = 1 { 
			aTanhPrime = list(1,len(Matrix[1]))
			for v = 1 to len(Matrix[1]) { 
				aTanhPrime[1][v] = MLeakyReLUPrime(Matrix[1][v])
			} 
			return aTanhPrime
			elseif len(Matrix[1]) = 1
				aTanhPrime = list(len(Matrix),1)
				for v = 1 to len(Matrix) { 
					aTanhPrime[v][1] = MLeakyReLUPrime(Matrix[v][1])
				} 
				return aTanhPrime
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aTanhPrime[v][h] = MLeakyReLUPrime(Matrix[v][h])
					} 
				} 
				return aTanhPrime
		} 
	} 

	func ReLu (Matrix) { 
		aTanh = Matrix
		for v = 1 to len(aTanh) { 
			for h = 1 to len(aTanh[1]) { 
				aTanh[v][h] = MReLu(Matrix[v][h])
			} 
		} 
		return aTanh
	} 

	func ReLuPrime (Matrix) { 
		aReLuPrime = Matrix
		if len(Matrix) = 1 { 
			aReLuPrime = list(1,len(Matrix[1]))
			for v = 1 to len(Matrix[1]) { 
				aReLuPrime[1][v] = MReLuPrime(Matrix[1][v])
			} 
			return aReLuPrime
			elseif len(Matrix[1]) = 1
				aReLuPrime = list(len(Matrix),1)
				for v = 1 to len(Matrix) { 
					aReLuPrime[v][1] = MReLuPrime(Matrix[v][1])
				} 
				return aReLuPrime
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aReLuPrime[v][h] = MReLuPrime(Matrix[v][h])
					} 
				} 
				return aReLuPrime
		} 
	} 

	func MLeakyReLU (input) { 
		if input < 0 { 
			Output = input*0.01
			return Output
			else
				Output = input
				return Output
		} 
	} 

	func MLeakyReLUPrime (input) { 
		if input < 0 { 
			Output = 0.01
			return Output
			else
				Output = 1
				return Output
		} 
	} 

	func MReLu (input) { 
		if input < 0 { 
			Output = 0
			return Output
			else
				Output = input
				return Output
		} 
	} 

	func MReLuPrime (input) { 
		if input < 0 { 
			Output = 0
			return Output
			else
				Output = 1
				return Output
		} 
	} 

	func MExp (Matrix) { 
		aExp = Matrix
		for v = 1 to len(aExp) { 
			for h = 1 to len(aExp[1]) { 
				aExp[v][h] = exp(Matrix[v][h])
			} 
		} 
		return aExp
	} 

	func MSum (Matrix,Axis) { 
		if Axis { 
			aSum = list(len(Matrix),1)
			for v = 1 to len(Matrix) { 
				for h = 1 to len(Matrix[1]) { 
					nSum = 0
					for k = 1 to len(Matrix[1]) { 
						nSum += Matrix[v][k]
					} 
					aSum[v][1] = nSum
				} 
			} 
			return aSum
			else
				aSum = list(1,len(Matrix[1]))
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						nSum = 0
						for k = 1 to len(Matrix) { 
							nSum += Matrix[k][h]
							#?"sum:" +   nSum
						} 
						aSum[1][h] = nSum
					} 
				} 
				return aSum
		} 
	} 

	func Softmax (Matrix) { 
		MatrixExp = MExp(Matrix)
		MatrixSum = MSum(MatrixExp,0)
		MtxSoftmax = DivByNum(MatrixExp,MatrixSum[1][1])
		return MtxSoftmax
	} 

	func HorStack (MatrixA,MatrixB) { 
		aHorStack = MatrixA
		for i = 1 to len(MatrixB) { 
			for j = 1 to len(MatrixB[1]) { 
				aHorStack[i]+MatrixB[i][j]
			} 
		} 
		return aHorStack
	} 

	func VerStack (MatrixA,MatrixB) { 
		aVerStack = MatrixA
		for i = 1 to len(MatrixB) { 
			aVerStack+MatrixB[i]
		} 
		return aVerStack
	} 

	func Ravel (Matrix) { 
		aRavel = []
		for i = 1 to len(Matrix) { 
			for j = 1 to len(Matrix[1]) { 
				aRavel+Matrix[i][j]
			} 
		} 
		return aRavel
	} 

	func ZeroLike (Matrix) { 
		aZeroLike = Matrix
		for i = 1 to len(Matrix) { 
			for j = 1 to len(Matrix[1]) { 
				aZeroLike[i][j] = 0
			} 
		} 
		return aZeroLike
	} 

	func Atleast2d (aInput) { 
		aAtleast2d = []
		for i = 1 to len(aInput) { 
			aAtleast2d+[aInput[i]]
		} 
		return aAtleast2d
	} 

	func argmax (aList) { 
		Max = Max(aList)
		index = find(aList,Max)
		return index
	} 

	func DeRepeat (aInput) { 
		aDeRepeat = []
		for i = 1 to len(aInput) { 
			if find(aDeRepeat,aInput[i]) = 0 { 
				aDeRepeat+aInput[i]
			} 
		} 
		return aDeRepeat
	} 

	func Append (MatrixA,MatrixB,Axis) { 
		aAppend = MatrixA
		if Axis = 1 { 
			for v = 1 to len(MatrixB) { 
				for h = 1 to len(MatrixB[1]) { 
					aAppend[v]+MatrixB[v][h]
				} 
			} 
			return aAppend
			elseif Axis = 0
				alist = []
				for v = 1 to len(MatrixB) { 
					for h = 1 to len(MatrixB[1]) { 
						alist+MatrixB[v][h]
					} 
				} 
				aAppend+alist
				return aAppend
		} 
	} 

	func AllSum (Matrix) { 
		aArithmeticMean = Matrix
		aSum = []
		for v = 1 to len(aArithmeticMean) { 
			for h = 1 to len(aArithmeticMean[1]) { 
				aSum+aArithmeticMean[v][h]
			} 
		} 
		Sum = 0
		for x = 1 to len(aSum) { 
			Sum += aSum[x]
		} 
		return Sum
	} 
