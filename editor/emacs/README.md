Emacs support for Ring programming language
===========================================

This is Ring highlight syntax support for Emacs editor

Please follow these steps

1 - Copy ring-mode.el to emacs folder\lisp

	Example : C:\emacs-24.3\lisp

2 - Run Emacs

3 - open the file for settings in emacs
	C-x C-f ~/.emacs

4 - Add the next two lines

	(add-to-list 'load-path "~/.emacs.d/lisp/")
	(load "ring-mode") 
