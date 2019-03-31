/*
IS442 – Zyad Abdullah
*/
load "guilib.ring"

new qApp
{
        SetDialogIcon("notepad.png")
        msginfo(:Ring,:Welcome)
        see confirmMsg(:Ring,"Are you sure?") + nl
        see InputBoxNum(:Ring,"Enter Number(double) :") + nl
        see InputBox(:Ring,"Enter Value :") + nl
        see InputBoxInt(:Ring,"Enter Number(int)") + nl
        see InputBoxPass(:Ring,"Enter Password") +nl
}
