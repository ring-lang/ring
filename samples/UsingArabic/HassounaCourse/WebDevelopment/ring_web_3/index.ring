#!ring -cgi
load "weblib.ring"
import system.web

new page{

html('<h1>Hi, we will learn web design</h1>')
html('<h2>1- HTML </h2>')
html('<h3> •Basic Page</h3>')
html( text(' <html>') + "<br>" )
html( text('  <head>') + "<br>" )
html( text('   <title>My Page Title</title>') + "<br>" )
html( text('  </head>') + "<br>" )
html( text('  <body>') + "<br>" )
html( text('    <h1>Hello Web</h1>') + "<br>" )
html( text('  </body>') + "<br>" )
html( text(' </html>') + "<br>" )
}
