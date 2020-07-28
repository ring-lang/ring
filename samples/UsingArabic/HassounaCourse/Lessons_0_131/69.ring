
myfile = "
<html>
	<head><title>My Page</title></head>
	<body>
		<h1 id=h></h1>
		<input id=txt />
		<button onclick=window.h.innerHTML='Hello'+window.txt.value>
			Click Here!
		</button>
	</body>
</html>
"

write("file.html" , myfile)

system("file.html")
