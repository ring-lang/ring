aVPLs = [
	:scratch = true ,
	:alice = true ,
	:prograph = true ,
	:labview = true ,
	:forms3 = true ,
	:vipr = true,
	:limnor = true,
	:tersus = true,
	:envision = true,
	:lava = true
]

See "
Why you need the VPL?
(1) Education
(2) Research
(3) Development
" give purpose

switch purpose
on "1"
	# For education we accept scratch and alice only
	# So we execlude tools used for research/development
	aVPLs[:prograph] 	= false
	aVPLs[:labview] 	= false
	aVPLs[:forms3] 		= false
	aVPLs[:vipr] 		= false
	aVPLs[:limnor] 		= false
	aVPLs[:tersus] 		= false
	aVPLs[:envision] 	= false
	aVPLs[:lava] 		= false
on "2"
	# The researcher need to know all of the tools
on "3"
	# for development we execlude education/research tools
	aVPLs[:scratch] 	= false
	aVPLs[:alice] 		= false
	aVPLs[:forms3] 		= false
	aVPLs[:vipr] 		= false
	aVPLs[:lava] 		= false
off

Output()

See "
Age/Job ?
(1) Less than 14 - children
(2) Student (i.e. > 14)
(3) Researcher/Employee
" Give AgeJob
Switch AgeJob
on "1"
	# here we accept scratch only
	aVPLs[:alice] 		= false
	aVPLs[:prograph] 	= false
	aVPLs[:labview] 	= false
	aVPLs[:forms3] 		= false
	aVPLs[:vipr] 		= false
	aVPLs[:limnor] 		= false
	aVPLs[:tersus] 		= false
	aVPLs[:envision] 	= false
	aVPLs[:lava] 		= false
on "2"
	# here we accept alice only
	aVPLs[:scratch]		= false
	aVPLs[:prograph] 	= false
	aVPLs[:labview] 	= false
	aVPLs[:forms3] 		= false
	aVPLs[:vipr] 		= false
	aVPLs[:limnor] 		= false
	aVPLs[:tersus] 		= false
	aVPLs[:envision] 	= false
	aVPLs[:lava] 		= false

on "3"
	# here we exclude scratch and alice
	aVPLs[:scratch] 	= false
	aVPLs[:alice] 		= false
off

Output()

See "
Visual Representation ?
Here you can select more than one option
(1) Block
(2) Spread Sheet
(3) Circles
(4) TreeView
(5) Diagramatic 
(6) Iconic
" Give VR
# the substr function can search for sub string in string
if not substr(VR,"1") 
	# here we exclude scratch and alice
	aVPLs[:scratch]		= false
	aVPLs[:alice]		= false
ok
if not substr(VR,"2") 
	# here we exclude forms/3
	aVPLs[:forms3]		= false
ok
if not substr(VR,"3") 
	# here we exclude VIPR
	aVPLs[:vipr]		= false
ok
if not substr(VR,"4") 
	# here we exclude LAVA
	aVPLs[:lava]		= false
ok
if not substr(VR,"5") 
	# here we exclude Limnor, Tersus, Prograph, Envision and LabView
	aVPLs[:limnor]		= false
	aVPLs[:tersus]		= false
	aVPLs[:prograph]	= false
	aVPLs[:envision]	= false
	aVPLs[:labview]		= false
ok
if not substr(VR,"6") 
	# here we exclude Limnor, Tersus, Prograph and LabView
	aVPLs[:limnor]		= false
	aVPLs[:tersus]		= false
	aVPLs[:prograph]	= false
	aVPLs[:labview]		= false
ok

Output()

See "
Types of applications ?
Here you can select more than one option
(1) Desktop
(2) Web
(3) Mobile
" Give AppType
if not substr(AppType,"1") 
	aVPLs[:alice]		= false
	aVPLs[:prograph]	= false
	aVPLs[:labview]		= false
	aVPLs[:prograph]	= false
	aVPLs[:forms3]		= false
	aVPLs[:labview]		= false
	aVPLs[:vipr]		= false
	aVPLs[:lava]		= false
ok
if not (substr(AppType,"2")  or substr(AppType,"3")  )
	aVPLs[:tersus]		= false
ok

Output()

See "
Development Stage ?
Here you can select more than one option
(1) Production Ready
(2) Under Development
(3) No more development 
" Give DevStage
if not substr(DevStage,"1") 
	aVPLs[:prograph] 	= false
	aVPLs[:labview] 	= false
	aVPLs[:limnor] 		= false
	aVPLs[:tersus] 		= false
ok
if not substr(DevStage,"2") 
	aVPLs[:envision] 	= false
ok
if not substr(DevStage,"3") 
	aVPLs[:forms3] 		= false
	aVPLs[:vipr] 		= false
	aVPLs[:lava] 		= false
ok

Output()

See "
License ?
Here you can select more than one option
(1) Commercial
(2) Freeware
(3) Open Source
" Give License
if not substr(License,"1") 
	# here we avoid LabView and Prograph
	aVPLs[:prograph]	= false
	aVPLs[:labview]		= false
ok
if not substr(License,"2") 
	# here we avoid free tools (not commercial/open source)
	aVPLs[:scratch]	 = false
	aVPLs[:alice] = false
	aVPLs[:forms3] = false
ok
if not ( substr(License,"1")  or substr(License,"2") )
	aVPLs[:limnor]	 = false	
ok
if not substr(License,"3") 
	# here we avoid open source tools
	aVPLs[:tersus]	 = false
 	aVPLs[:envision] = false
	aVPLs[:lava]	 = false
ok

Output()

Func Output

See "
============
Output 
============
" 
for x in aVPLs
	see size(x[1],10) + "   "
	if x[2] = true
		see "True" + nl
	else
		see "False" + nl
	ok
next


func size x,y
	return x + copy(" ",y-len(x))