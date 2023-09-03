Ring programming language - Documents folder
============================================

In this folder we have the Ring programming language documentation 

The documentation is created using Sphinx (A popular tool written in Python)

(1) Install Python (Tested using Python 3.11.5)

(2) Install Sphinx (Tested using v6.2.1) 

	pip install -U sphinx

(3) To use the pygments lexer, copy ring.py to Python\Lib\site-packages\pygments\lexers

(4) Add the next line to _mapping.py

	'RingLexer': ('pygments.lexers.ring', 'Ring', ('ring',), ('*.ring',), ('text/ring',)),

(5) Then run _mapping.py
	
	python _mapping.py

(6) Install rtd_theme

	pip install sphinx_rtd_theme

(7) To generate CHM file, Use Microsoft Help Workshop (from WayBack Machine): https://web.archive.org/web/20200918004813/http://download.microsoft.com/download/0/A/9/0A939EF6-E31C-430F-A3DF-DFAE7960D564/htmlhelp.exe

(8) To generate PDF file, Use Lyx (https://www.lyx.org/Download) and MiKTEX (https://miktex.org/download)

(9) To generate ePub file (optional), running make.bat epub
