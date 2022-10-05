/*
 * Application       : Object
 * Author            : Hany Ibrahim Ahmed
 * Date              : 22/12/2017
 */
# variables types (string,number,list,object,c object) 
# Project---->files(*.ring)
# control structures----->while ,for ,if ver 2
 
#=============================================

alist=[:one,:two,:three]
for item in alist
?item
	switch item
	case :one item=1
	case :two item=2
	case:three item=3
	else item=0
	end
next
?alist
#========
alist=[:one,:two,:three]
for item in alist{
?item
	switch item{
	case :one item=1
	case :two item=2
	case :three item=3
	else item=0
	}
}
?alist
