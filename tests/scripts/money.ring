see "Enter money : " give nMoney
see "Enter years : " give nYears

nMoney = number(nMoney)
nYears = number(nYears)

nTotal = nMoney
for x = 1 to nYears
	nTotal = nTotal + (nTotal*0.06)
next

See "total : " + nTotal + nl

see string(nTotal) + 5 + nl