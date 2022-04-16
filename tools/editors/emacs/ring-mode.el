;; ring-mode.el - very basic ring mode

(require 'cl)
(require 'rx)
(require 'js)

(defconst ring-mode-syntax-table
  (let ((table (make-syntax-table)))
    (modify-syntax-entry ?\" "\"" table)
    (modify-syntax-entry ?\\ "\\" table)

    ;; additional symbols
    (modify-syntax-entry ?_ "w" table)

    (modify-syntax-entry ?' "." table)
    (modify-syntax-entry ?: "." table)
    (modify-syntax-entry ?+  "." table)
    (modify-syntax-entry ?-  "." table)
    (modify-syntax-entry ?%  "." table)
    (modify-syntax-entry ?&  "." table)
    (modify-syntax-entry ?|  "." table)
    (modify-syntax-entry ?^  "." table)
    (modify-syntax-entry ?!  "." table)
    (modify-syntax-entry ?$  "/" table)
    (modify-syntax-entry ?=  "." table)
    (modify-syntax-entry ?<  "." table)
    (modify-syntax-entry ?>  "." table)
    (modify-syntax-entry ??  "." table)

    ;; Modify some syntax entries to allow nested block comments
    (modify-syntax-entry ?/ ". 124b" table)
    (modify-syntax-entry ?* ". 23n" table)
    (modify-syntax-entry ?\n "> b" table)
    (modify-syntax-entry ?\^m "> b" table)

    table))

(defconst ring-builtins
  '("package" "import" "class" "func" "load" "def" "len" "add" "del" "sysget" "clock"
  "lower" "upper" "input" "ascii" "char" "date" "time" "filename" "getchar" "system"
  "random" "timelist" "adddays" "diffdays" "version" "clockspersecond" "isstring"
  "isnumber" "islist" "type" "isnull" "isobject" "hex" "dec" "number" "string"
  "str2hex" "hex2str" "str2list" "list2str" "left" "right" "trim" "copy" 
  "substr" "lines" "strcmp" "eval" "raise" "assert" "isalnum" "isalpha"
  "iscntrl" "isdigit" "isgraph" "islower" "isprint" "ispunct" "isspace" 
  "isupper" "isxdigit" "locals" "globals" "functions" "cfunctions" 
  "islocal" "isglobal" "isfunction" "iscfunction" "packages" "ispackage"
  "classes" "isclass" "packageclasses" "ispackageclass" "classname" 
  "objectid" "attributes" "methods" "isattribute" "ismethod" 
  "isprivateattribute" "isprivatemethod" "addattribute" 
  "addmethod" "getattribute" "setattribute" "mergemethods" 
  "list" "find" "min" "max" "insert" "sort" "reverse" "binarysearch"
  "sin" "cos" "tan" "asin" "acos" "atan" "atan2" "sinh" "cosh" "tanh" 
  "exp" "log" "log10" "ceil" "floor" "fabs" "pow" "sqrt" "unsigned" 
  "decimals" "murmur3hash" "fopen" "fclose" "fflush" "freopen" 
  "tempfile" "tempname" "fseek" "ftell" "rewind" "fgetpos" 
  "fsetpos" "clearerr" "feof" "ferror" "perror" "rename" "remove"
  "fgetc" "fgets" "fputc" "fputs" "ungetc" "fread" "fwrite" 
  "dir" "read" "write" "fexists" "ismsdos" "iswindows" "iswindows64" 
  "isunix" "ismacosx" "islinux" "isfreebsd" "isandroid" "windowsnl" 
  "currentdir" "exefilename" "chdir" "exefolder" "callgc" "varptr"
  "intvalue" "object2pointer" "pointer2object" "nullpointer" "space"))

(defconst ring-keywords
  '("again" "and" "but" "bye" "call" "case" "catch" "changeringkeyword" "changeringoperator"
 "do" "done" "else" "elseif" "end" "exit" "for" "from" "get" "give" "if"
"in"  "loadsyntax" "loop" "new" "next" "not" "off" "ok" "on" "or" "other"
 "private" "put" "return" "see" "step" "switch" "to" "try" "while" "endif" 
 "endfor" "endwhile" "endswitch" "endtry" "function" "endfunction" "break"
 "continue" "endfunc" "endclass" "endpackage"))

(defconst ring-constants
  '("null" "true" "false"))

(defconst ring-typenames
  '("private"  ))

(defun ring-wrap-word-rx (s)
  (concat "\\<" s "\\>"))

(defun ring-keywords-rx (keywords)
  "build keyword regexp"
  (ring-wrap-word-rx (regexp-opt keywords t)))

(defconst ring-hat-type-rx (rx (group (and "^" (1+ word)))))
(defconst ring-dollar-type-rx (rx (group "$" (or (1+ word) (opt "$")))))
(defconst ring-number-rx
  (rx (and
       symbol-start
       (or (and (+ digit) (opt (and (any "eE") (opt (any "-+")) (+ digit))))
           (and "0" (any "xX") (+ hex-digit)))
       (opt (and (any "_" "A-Z" "a-z") (* (any "_" "A-Z" "a-z" "0-9"))))
       symbol-end)))

(defconst ring-font-lock-defaults
  `(
    ;; Keywords
    (,(ring-keywords-rx ring-keywords) 1 font-lock-keyword-face)

    ;; single quote characters
    ("\\('[[:word:]]\\)\\>" 1 font-lock-constant-face)

    ;; Variables
    (,(ring-keywords-rx ring-builtins) 1 font-lock-variable-name-face)

    ;; Constants
    (,(ring-keywords-rx ring-constants) 1 font-lock-constant-face)

    ;; Hash directives
    ("#\\w+" . font-lock-preprocessor-face)

    ;; At directives
    ("@\\w+" . font-lock-preprocessor-face)

    ;; Strings
    ("\\\".*\\\"" . font-lock-string-face)

    ;; Numbers
    (,(ring-wrap-word-rx ring-number-rx) . font-lock-constant-face)

    ;; Types
    (,(ring-keywords-rx ring-typenames) 1 font-lock-type-face)
    (,ring-hat-type-rx 1 font-lock-type-face)
    (,ring-dollar-type-rx 1 font-lock-type-face)

    ("---" . font-lock-constant-face)
    ))

;; add setq-local for older emacs versions
(unless (fboundp 'setq-local)
  (defmacro setq-local (var val)
    `(set (make-local-variable ',var) ,val)))

(defconst ring--defun-rx "\(.*\).*\{")

(defmacro ring-paren-level ()
  `(car (syntax-ppss)))

(defun ring-line-is-defun ()
  "return t if current line begins a procedure"
  (interactive)
  (save-excursion
    (beginning-of-line)
    (let (found)
      (while (and (not (eolp)) (not found))
        (if (looking-at ring--defun-rx)
            (setq found t)
          (forward-char 1)))
      found)))

(defun ring-beginning-of-defun (&optional count)
  "Go to line on which current function starts."
  (interactive)
  (let ((orig-level (ring-paren-level)))
    (while (and
            (not (ring-line-is-defun))
            (not (bobp))
            (> orig-level 0))
      (setq orig-level (ring-paren-level))
      (while (>= (ring-paren-level) orig-level)
        (skip-chars-backward "^{")
        (backward-char))))
  (if (ring-line-is-defun)
      (beginning-of-line)))

(defun ring-end-of-defun ()
  "Go to line on which current function ends."
  (interactive)
  (let ((orig-level (ring-paren-level)))
    (when (> orig-level 0)
      (ring-beginning-of-defun)
      (end-of-line)
      (setq orig-level (ring-paren-level))
      (skip-chars-forward "^}")
      (while (>= (ring-paren-level) orig-level)
        (skip-chars-forward "^}")
        (forward-char)))))

(defalias 'ring-parent-mode
 (if (fboundp 'prog-mode) 'prog-mode 'fundamental-mode))

;;;###autoload
(define-derived-mode ring-mode ring-parent-mode "ring"
 :syntax-table ring-mode-syntax-table
 :group 'ring
 (setq bidi-paragraph-direction 'left-to-right)
 (setq-local require-final-newline mode-require-final-newline)
 (setq-local parse-sexp-ignore-comments t)
 (setq-local comment-start-skip "\\(//+\\|/\\*+\\)\\s *")
 (setq-local comment-start "/*")
 (setq-local comment-end "*/")
 (setq-local indent-line-function 'js-indent-line)
 (setq-local font-lock-defaults '(ring-font-lock-defaults))
 (setq-local beginning-of-defun-function 'ring-beginning-of-defun)
 (setq-local end-of-defun-function 'ring-end-of-defun)

 (font-lock-fontify-buffer))

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.ring\\'" . ring-mode))

(provide 'ring-mode)
