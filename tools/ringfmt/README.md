RingFmt Tool
============

RingFmt is a source code formatter and beautifier

Usage
=====

	Usage: ringfmt filename.ring [Options]

Options
=======

	-keywords:lower   : Convert all keywords to lowercase (default setting)
	-keywords:upper   : Convert all keywords to UPPERCASE
	-keywords:name    : Convert keywords to NameCase (e.g., Class, From)
	-indentation:tabs : Use tab characters for indentation (default setting)
	-indentation:2    : Use 2 spaces per indentation level
	-indentation:4    : Use 4 spaces per indentation level
	-indentation:8    : Use 8 spaces per indentation level
	-output:print     : Print formatted output (default setting)
	-output:write     : Overwrite the source file with formatted output
	-output:none      : No output