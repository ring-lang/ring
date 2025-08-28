# -*- coding: utf-8 -*-
"""
	pygments.lexers.ring
	~~~~~~~~~~~~~~~~~~~~

	Lexer for the Ring programming language.

	:copyright: Copyright 2025 by the Ring team.
"""

import re

from pygments.lexer import RegexLexer, include, words, bygroups
from pygments.token import Text, Comment, Operator, Keyword, Name, String, \
	Number, Punctuation

__all__ = ['RingLexer']


class RingLexer(RegexLexer):
	"""
	Lexer for the Ring programming language (https://ring-lang.net/).
	"""
	name = 'Ring'
	aliases = ['ring']
	filenames = ['*.ring', '*.rh', '*.rform']
	mimetypes = ['text/x-ring']

	# Ring is case-insensitive.
	flags = re.IGNORECASE | re.MULTILINE | re.UNICODE

	identifier = r'[a-zA-Z_@$][\w@$]*'

	keywords_control = (
		'if', 'but', 'elseif', 'else', 'other', 'ok', 'endif', 'end',
		'switch', 'on', 'case', 'off', 'endswitch',
		'for', 'in', 'to', 'step', 'next', 'endfor', 'foreach',
		'while', 'endwhile',
		'do', 'again',
		'return', 'bye',
		'exit', 'break', 'loop', 'continue',
		'call',
	)

	keywords_exception = (
		'try', 'catch', 'done', 'endtry',
	)

	keywords_declaration = (
		'class', 'endclass', 'from',
		'func', 'def', 'function', 'endfunc', 'endfunction',
		'package', 'endpackage', 'private',
	)

	keywords_module = (
		'load', 'import',
	)

	keywords_oop = (
		'new', 'self', 'this', 'super',
	)

	keywords_io = (
		'see', 'put', 'give', 'get',
	)

	variables_builtin = (
		'true', 'false', 'nl', 'null', 'tab', 'cr', 'sysargv', 'ccatcherror',
		'ringoptionalfunctions'
	)

	scanner_commands = (
		'changeringkeyword', 'changeringoperator', 'disablehashcomments',
		'enablehashcomments', 'loadsyntax',
	)

	functions_builtin = (
		'acos', 'add', 'addattribute', 'adddays', 'addmethod', 'ascii', 'asin',
		'assert', 'atan', 'atan2', 'attributes', 'binarysearch', 'bytes2double',
		'bytes2float', 'bytes2int', 'callgarbagecollector', 'callgc', 'ceil',
		'cfunctions', 'char', 'chdir', 'checkoverflow', 'classes', 'classname',
		'clearerr', 'clock', 'clockspersecond', 'closelib', 'copy', 'cos',
		'cosh', 'currentdir', 'date', 'dec', 'decimals', 'del', 'diffdays',
		'dir', 'direxists', 'double2bytes', 'eval', 'exefilename', 'exefolder',
		'exp', 'fabs', 'fclose', 'feof', 'ferror', 'fexists', 'fflush',
		'fgetc', 'fgetpos', 'fgets', 'filename', 'find', 'float2bytes',
		'floor', 'fopen', 'fputc', 'fputs', 'fread', 'freopen', 'fseek',
		'fsetpos', 'ftell', 'functions', 'fwrite', 'getarch', 'getattribute',
		'getchar', 'getfilesize', 'getnumber', 'getpathtype', 'getpointer',
		'getptr', 'getstring', 'globals', 'hex', 'hex2str', 'importpackage',
		'input', 'insert', 'int2bytes', 'intvalue', 'isalnum', 'isalpha',
		'isandroid', 'isattribute', 'iscfunction', 'isclass', 'iscntrl',
		'isdigit', 'isfreebsd', 'isfunction', 'isglobal', 'isgraph',
		'islinux', 'islist', 'islocal', 'islower', 'ismacosx', 'ismethod',
		'ismsdos', 'isnull', 'isnumber', 'isobject', 'ispackage',
		'ispackageclass', 'ispointer', 'isprint', 'isprivateattribute',
		'isprivatemethod', 'ispunct', 'isspace', 'isstring', 'isunix',
		'isupper', 'iswindows', 'iswindows64', 'isxdigit', 'left', 'len',
		'lines', 'list', 'list2str', 'loadlib', 'locals', 'log', 'log10',
		'lower', 'max', 'memcpy', 'memorycopy', 'mergemethods', 'methods',
		'min', 'murmur3hash', 'newlist', 'nofprocessors', 'nothing',
		'nullpointer', 'nullptr', 'number', 'obj2ptr', 'object2pointer',
		'objectid', 'optionalfunc', 'packageclasses', 'packagename',
		'packages', 'parentclassname', 'perror', 'pointer2object',
		'pointer2string', 'pointercompare', 'pow', 'prevfilename', 'print',
		'print2str', 'ptr2obj', 'ptr2str', 'ptrcmp', 'puts', 'raise',
		'random', 'randomize', 'read', 'ref', 'reference', 'refcount',
		'remove', 'rename', 'reverse', 'rewind', 'right', 'ring_give',
		'ring_see', 'ring_state_delete', 'ring_state_filetokens',
		'ring_state_findvar', 'ring_state_init', 'ring_state_main',
		'ring_state_mainfile', 'ring_state_new', 'ring_state_newvar',
		'ring_state_resume', 'ring_state_runcode', 'ring_state_runcodeatins',
		'ring_state_runfile', 'ring_state_runobjectfile',
		'ring_state_scannererror', 'ring_state_setvar',
		'ring_state_stringtokens', 'ringvm_callfunc', 'ringvm_calllist',
		'ringvm_cfunctionslist', 'ringvm_classeslist', 'ringvm_codelist',
		'ringvm_evalinscope', 'ringvm_fileslist', 'ringvm_functionslist',
		'ringvm_genarray', 'ringvm_give', 'ringvm_hideerrormsg', 'ringvm_info',
		'ringvm_ismempool', 'ringvm_memorylist', 'ringvm_packageslist',
		'ringvm_passerror', 'ringvm_runcode', 'ringvm_scopescount',
		'ringvm_see', 'ringvm_settrace', 'ringvm_tracedata',
		'ringvm_traceevent', 'ringvm_tracefunc', 'setattribute', 'setpointer',
		'setptr', 'shutdown', 'sin', 'sinh', 'sort', 'space', 'sqrt',
		'srandom', 'str2hex', 'str2hexcstyle', 'str2list', 'strcmp', 'string',
		'substr', 'swap', 'sysget', 'sysset', 'syssleep', 'system', 'sysunset',
		'tan', 'tanh', 'tempfile', 'tempname', 'time', 'timelist', 'trim',
		'type', 'ungetc', 'unsigned', 'upper', 'uptime', 'variablepointer',
		'varptr', 'version', 'windowsnl', 'write'
	)

	tokens = {
		'root': [
			# Whitespace and Comments
			(r'\s+', Text),
			(r'//.*?\n', Comment.Single),
			(r'#.*?\n', Comment.Single),
			(r'/\*', Comment.Multiline, 'comment'),

			# Scanner Commands
			(r'^\s*(%s)\b' % '|'.join(scanner_commands), Comment.Preproc),

			# String Literals
			(r':' + identifier, String.Symbol),
			(r'"', String.Double, 'string-double'),
			(r"'", String.Single, 'string-single'),
			(r'`', String.Backtick, 'string-backtick'),

			# Highlight Declarations
			(r'(\bclass)(\s+)(\w+)', bygroups(Keyword.Declaration, Text, Name.Class)),
			(r'(\bfrom)(\s+)(\w+)', bygroups(Keyword.Declaration, Text, Name.Class)),
			(r'(\bfunc|def|function)(\s+)(\w+)', bygroups(Keyword.Declaration, Text, Name.Function)),
			(r'(\bpackage|import)(\s+)([a-zA-Z_@$][\w@$.]*)', bygroups(Keyword.Namespace, Text, Name.Namespace)),
			(r'(\bnew)(\s+)(\w+)', bygroups(Keyword.Pseudo, Text, Name.Class)),


			# Keywords
			(words(keywords_control, prefix=r'\b', suffix=r'\b'), Keyword),
			(words(keywords_exception, prefix=r'\b', suffix=r'\b'), Keyword),
			(words(keywords_declaration, prefix=r'\b', suffix=r'\b'), Keyword.Declaration),
			(words(keywords_module, prefix=r'\b', suffix=r'\b'), Keyword.Namespace),
			(words(keywords_oop, prefix=r'\b', suffix=r'\b'), Keyword.Pseudo),
			(words(keywords_io, prefix=r'\b', suffix=r'\b'), Keyword),
			(words(variables_builtin, prefix=r'\b', suffix=r'\b'), Name.Builtin.Pseudo),
			(words(('and', 'or', 'not'), prefix=r'\b', suffix=r'\b'), Operator.Word),

			# Built-in Functions
			(words(functions_builtin, prefix=r'\b', suffix=r'\b(?=\s*\()'),
			 Name.Builtin),

			# Function calls
			(r'\b(%s)(?=\s*\()' % identifier, Name.Function),

			# Numbers
			(r'0x[a-f0-9_]+', Number.Hex),
			(r'0b[01_]+', Number.Bin),
			(r'0o[0-7_]+', Number.Oct),
			(r'[0-9]+(?:_[0-9]+)*\.[0-9]*(?:_[0-9]+)*([eE][-+]?[0-9]+)?', Number.Float),
			(r'[0-9]+(?:_[0-9]+)*', Number.Integer),

			# Operators
			(r'(\+\+|\-\-|\*\*|\^\^|!=|<=|>=|<<|>>|&&|\|\|)', Operator),
			(r'(\+=|-=|\*=|/=|%=|<<=|>>=|&=|\|=|\^=)', Operator),
			(r'[-+/*%=<>&|!~.:^?]', Operator),

			# Punctuation
			(r'[\[\](){},;]', Punctuation),

			# Identifiers
			(identifier, Name),
		],
		'comment': [
			(r'[^*/]+', Comment.Multiline),
			(r'/\*', Comment.Multiline, '#push'),
			(r'\*/', Comment.Multiline, '#pop'),
			(r'[*/]', Comment.Multiline),
		],
		'string-double': [
			(r'[^"#]+', String.Double),
			(r'#\{', String.Interpol, 'interpolation'),
			(r'"', String.Double, '#pop'),
		],
		'string-single': [
			(r"[^'#]+", String.Single),
			(r'#\{', String.Interpol, 'interpolation'),
			(r"'", String.Single, '#pop'),
		],
		'string-backtick': [
			(r"[^`#]+", String.Backtick),
			(r'#\{', String.Interpol, 'interpolation'),
			(r'`', String.Backtick, '#pop'),
		],
		'interpolation': [
			(r'\}', String.Interpol, '#pop'),
			include('root'),
		],
	}