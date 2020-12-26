#====================================================#
# Erlang B Formula
# 2020, Mahmoud Fayed <msfclipper@yahoo.com 
#====================================================#

func Table_ABJKQ N,nAMin,nAMax,nStep
	aTable = []
	for A = nAMin to nAMax step nStep
		B = erlang(N,A) 
		J = calcJ_usingAB(22,b)
		K = calcK_usingAJ(A,J)
		Q = calcQ_usingKN(K,N)
		aTable + [A,B,J,K,Q]
	next
	return aTable	

func fact i
	if i=0 return 1 ok
	return i * fact(i-1)

func erLang N,A
	first = pow(A,N)/Fact(n)	
	nSum = 0
	for i=0 to N
		nSum += pow(A,i)/Fact(i)	
	next
	return first/nSum

# J = A*B
func calcJ_usingAB A,B
	return A*B

# K = A-J
func calcK_usingAJ A,J
	return A-J

# Q = K/N
func calcQ_usingKN K,N
	return K/N
