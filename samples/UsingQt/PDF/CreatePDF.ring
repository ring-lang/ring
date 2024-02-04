load "guilib.ring"

new QApp 

? "Generate test.pdf"

html = "<div align=right>
   Ring Language
</div>
<div align=left>
   Generate PDF File<br>
   Using RingQt<br>
</div>
<h1 align=center>I Love Programming</h1>
<p align=justify>
   Each problem is a new journey 
</p>
<div align=right>Thanks!</div>"

document = new QTextDocument()
document.setHtml(html)

printer = new QPrinter(0);
printer.setOutputFormat(1);
printer.setOutputFileName("test.pdf");

document.print(printer);

System("test.pdf")
