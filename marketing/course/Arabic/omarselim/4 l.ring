? date()
x=date()
?time()
y= adddays(x,5)
?y
? diffdays(x,y)
? timelist()

?timelist()[1]

/* 
number*/
? 100/4
?101%4

alist=[
	:name="omar selim",
	:job="bim editor",
	:country="egypt"


]
? alist

? alist [:name]
if alist [:city]=null  alist[:city]="cairo" ok
? alist[:city]

? "size:" +len(alist)
for aitem in alist 
  ? 	aitem [2]
next



slist=["one","two","three","four"]
?slist
?len(slist)
sstring =list2str(slist)
? sstring



xx="welcome"
?  upper(xx)
? left(xx,2)
word="hi man in ring langage "
? substr(word,11,4)
?substr(word,"ring")

?substr(word,"ring","***ring****")


nlist=1:10
? nlist
del(nlist,3)
? nlist
nlist +"egypt"
list2 =sort(slist)
?list2
