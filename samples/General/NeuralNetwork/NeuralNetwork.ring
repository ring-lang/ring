#-------------------------------------
# Author : Azzeddine Remmal
# 20-09-2022
#-------------------------------------

load "stdlibcore.ring"
load "CalcMatrix.ring"


NN = new DeepNeuralNetwork()
MC = new MatrixCalc

aFontColor = [CC_FG_RED,CC_FG_GREEN,CC_FG_YELLOW,CC_FG_BLUE,CC_FG_MAGENTA,CC_FG_CYAN]

Descreption = "
 X = [hours studying, hours sleeping]
 y = score on test, 
 xPredicted = 4 hours studying & 8 hours sleeping (input data for prediction)
"

X = [[2,9],[4,5],[3,6]]
y = [[92],[89],[86]]

# Scale units
# Maximum of X array
X = MC.DivByNum(X,MC.Maximum(X,false))

# Max test score is 100
y = MC.DivByNum(y,100)

StartTime = clock()
nIndex = 0

# Trains the NN 100 Epocks
Epocks = 100
for i = 1 to Epocks step 1 { 
	system("cls")
	percent = i*100/Epocks
	ProgBar = "|"+Copy("-",percent)
	negProgBar = Copy("-",100-percent)+"|"
	? cc_print(13|2,"#Epocks : ")+i
	? cc_print(CC_FG_MAGENTA|CC_BG_BLACK,"Predicted Output: ")+cc_print(CC_FG_CYAN|CC_BG_BLACK,ToCode(NN.forward(X)))
	decimals(2)
	if percent = 100 { 
		see cc_print(CC_FG_BLUE|CC_BG_GREEN,ProgBar)+percent+"%"+nl
		else
			see cc_print(CC_FG_BLUE|CC_BG_BLUE,ProgBar)+cc_print(CC_FG_WHITE|CC_BG_BLACK,negProgBar)+percent+"%"+nl
	} 
	Seconds = (clock()-StartTime)/clockspersecond()
	if Seconds <= 60 { 
		? cc_print(CC_FG_YELLOW|CC_BG_BLACK,"Get Train Time ")+Seconds+" Seconds"
		elseif Seconds > 60
			Minits = Seconds/60
			? cc_print(CC_FG_GREEN|CC_BG_BLACK,"Get Train Time ")+Minits+" Minits"
		elseif Minits > 60
			Hour = Seconds/60
			? cc_print(CC_FG_MAGENTA|CC_BG_BLACK,"Get Train Time ")+Hour+" Hour"
	} 
	decimals(32)
	# Mean sum squared loss	
	Loss = MC.Mean(MC.Square(MC.Subtract(y,NN.forward(X))))
	? cc_print(CC_FG_RED|CC_BG_BLACK,"Loss: ")+Loss
	NN.train(X,y)
} 

? cc_print(11|2,"Predicted Output: ")+cc_print(CC_FG_YELLOW|CC_BG_BLACK,ToCode(NN.forward(X)))
NN.saveWeights()
xPredicted = [[5,6]]

# Maximum of xPredicted (our input data for the prediction)

xPredicted = MC.DivByNum(xPredicted,MC.Maximum(xPredicted,false))
ReadData("NetworkWeight.txt")
NN.predict()

func ReadData(FileName) { 
	aReadData = read(FileName)
	Eval(aReadData)
} 

class DeepNeuralNetwork

	inputSize
	outputSize
	hiddenSize
	W1
	W2
	W3
	z2
	z4

	func Init() { 
		# Parameters
		MC = new MatrixCalc
		inputSize = 2
		outputSize = 1
		hiddenSize = 8
		# Weights
		# (inputSize x hiddenSize) weight matrix from input to hidden layer
		W1 = MC.MRand(inputSize,hiddenSize)
		# (hiddenSize x hiddenSize) weight matrix from hidden to output layer
		W2 = MC.MRand(hiddenSize,hiddenSize)
		# (hiddenSize x outputSize) weight matrix from hidden to output layer
		W3 = MC.MRand(hiddenSize,outputSize)
	} 

	func Forward(X) { 
		# Forward propagation through our network
		# Dot product of X (input) and first set of 8x2 weights
		z = MC.Multdot(X,W1)
		# Activation function
		z2 = MC.MTanh(z)
		# Dot product of hidden layer (z2) and second set of 8x8 weights
		z3 = MC.Multdot(z2,W2)
		# Activation function
		z4 = MC.MTanh(z3)
		# Dot product of hidden layer (z4) and third set of 8x1 weights
		z5 = MC.Multdot(z4,W3)
		# Final activation function
		o = MC.Sigmoid(z5)
		return o
	} 

	func Backward(X,y,o) { 
		# Backward propagate through the network
		# Error in output
		o_error = MC.Subtract(y,o)
		# Applying derivative of sigmoid to error
		o_delta = MC.Multiply(o_error,MC.SigmoidPrime(o))
		# z2 error: how much our hidden layer weights contributed to output error
		z4_error = MC.Multdot(o_delta,MC.Transpose(W3))
		# applying derivative of sigmoid to z3 error
		z4_delta = MC.Multiply(z4_error,MC.MTanhPrime(z4))
		# z2 error: how much our hidden layer weights contributed to output error
		z2_error = MC.Multdot(z4_delta,MC.Transpose(W2))
		# applying derivative of sigmoid to z2 error
		z2_delta = MC.Multiply(z2_error,MC.MTanhPrime(z2))
		# adjusting first set (input --> hidden) weights
		W1 = MC.Add(W1,MC.Multdot(MC.Transpose(X),z4_delta))
		# adjusting second set (hidden --> output) weights
		W2 = MC.Add(W2,MC.Multdot(MC.Transpose(z2),z2_delta))
		# adjusting therd set (hidden --> output) weights
		W3 = MC.Add(W3,MC.Multdot(MC.Transpose(z4),o_delta))
	} 

	func Train(X,y) { 
		o = forward(X)
		backward(X,y,o)
	} 

	func SaveWeights() { 
		cCode = ""
		cCode += "w1 = "+ToCode(W1)+windowsnl()+windowsnl()
		cCode += "w2 = "+ToCode(W2)+windowsnl()+windowsnl()
		cCode += "w3 = "+ToCode(W3)
		write("NetworkWeight.txt",cCode)
	} 

	func Predict() { 
		? "Predicted data based on trained weights: "+windowsnl()
		? cc_print(11|2,"Input (scaled) = ")+cc_print(CC_FG_YELLOW|CC_BG_BLACK,ToCode(xPredicted)+windowsnl())
		? cc_print(11|2,"Y = ")+cc_print(CC_FG_YELLOW|CC_BG_BLACK,ToCode(y))
		? cc_print(11|2,"Output = ")+cc_print(CC_FG_YELLOW|CC_BG_BLACK,ToCode(forward(xPredicted)))
		? cc_print(11|2,"Weight1 = ")+cc_print(CC_FG_DARK_YELLOW|CC_BG_BLACK,ToCode(w1))
		? cc_print(11|2,"Weight2 = ")+cc_print(CC_FG_DARK_YELLOW|CC_BG_BLACK,ToCode(w2))
		? cc_print(11|2,"Weight3 = ")+cc_print(CC_FG_DARK_YELLOW|CC_BG_BLACK,ToCode(w3))
	} 
