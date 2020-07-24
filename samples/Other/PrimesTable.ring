# Project : Primes Table
# Date    : 05/11/2019-09:00:00
# Update  : 05/11/2019-09:59:32
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : quiwox@gmail.com

load "guilib.ring"
load "stdlib.ring"

size = 10
table = null

app = new qApp {

      StyleFusion()
      win = new qWidget() {
            setWindowTitle('Primes Table')
            move(490,100)
            resize(700,450)
            setstylesheet('background-color:white')
            pInit()
            showPrimesTable()
            show()
            }
            exec()
      }

func showPrimesTable()

     for n = 1 to 100
         row = floor(n/size)
         col = (n % size)
         temp = row * size + col
         if isPrime(temp)
            item = new qTableWidgetItem(string(temp))
            Table.setitem(row,col,item)
         ok
     next

func pInit()

     Table = new qtablewidget(win) {

             move(100,20)
             resize(500,400)
             setcolumncount(11) 
             setrowcount(10)

             for x = 1 to Table.rowcount()
                 for y = 1 to Table.columncount()
                     item1 = new qtablewidgetitem("")
                     Table.setitem(x-1,y-1, item1)
                 next
             next

             for n = 1 to size+1
                 setColumnwidth(n-1,30)
             next

             for n = 0 to size
                 setHorizontalHeaderItem(n, new QTableWidgetItem(string(n)))
             next

             for n = 0 to 7
                 setVerticalHeaderItem(n, new QTableWidgetItem(string(n)))
             next

             show()
    }
