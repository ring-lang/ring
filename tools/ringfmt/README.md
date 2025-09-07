RingFmt Tool
============

RingFmt is a source code formatter and beautifier

Usage
=====

	Usage: ringfmt filename.ring [Options]

Options
=======

	-keywords:lower   (k:l): Convert all keywords to lowercase (default setting)
	-keywords:upper   (k:u): Convert all keywords to UPPERCASE
	-keywords:name    (k:n): Convert keywords to NameCase (e.g., Class, From)
	-indentation:tabs (i:t): Use tab characters for indentation (default setting)
	-indentation:2    (i:2): Use 2 spaces per indentation level
	-indentation:4    (i:4): Use 4 spaces per indentation level
	-indentation:8    (i:8): Use 8 spaces per indentation level
	-output:print     (o:p): Print formatted output (default setting)
	-output:write     (o:w): Overwrite the source file with formatted output
	-output:none      (o:n): No output