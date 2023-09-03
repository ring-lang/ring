Ring programming language - Documents folder
============================================

In this folder we have the Ring programming language documentation 

The documentation is created using Sphinx (A popular tool written in Python)

(1) Install Python (Tested using Python 3.11.5)

(2) Install Sphinx (Tested using v6.2.1) 

	pip install -U sphinx==6.2.1

(3) To use the pygments lexer, copy ring.py to Python\Lib\site-packages\pygments\lexers

(4) Add the next line to _mapping.py

	'RingLexer': ('pygments.lexers.ring', 'Ring', ('ring',), ('*.ring',), ('text/ring',)),

(5) Then run _mapping.py
	
	python _mapping.py

(6) Install rtd_theme (Tested using v1.3.0)

	pip install sphinx_rtd_theme

(7) To generate CHM file, Use Microsoft Help Workshop. 

	Tested using HTML Help Workshop 4.74.8702

(8) To generate PDF file, Install MiKTeX (https://miktex.org/download) then LyX (https://www.lyx.org/Download)

	Tested using MiKTeX 23.4
	Tested using LyX 2.3.7
