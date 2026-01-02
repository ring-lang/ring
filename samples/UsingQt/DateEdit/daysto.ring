load "guilib.ring"

d1 = new QDate() { setDate(2026,01,02) }
? d1.day()
? d1.month()
? d1.year()

d2 = new QDate() { setDate(1922,04,20) }
? d2.day()
? d2.month()
? d2.year()

? d1.daysto(d2)
