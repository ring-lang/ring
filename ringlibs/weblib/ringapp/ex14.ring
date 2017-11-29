#!ring -cgi

Load "weblib.ring"
Import System.Web

New Page
{
	boxstart()
		text("HTML Special Characters")
		newline()
	boxend()
	text('
		<html>
			<body>
				<p> "hello world" </p>
			</body>
		</html>
	')
}


