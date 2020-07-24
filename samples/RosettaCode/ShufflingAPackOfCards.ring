/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Shuffling a pack of cards
 +     Date         : 2017.08.13.
 +     Author       : Gal Zsolt (~ CalmoSoft ~)
 +     Email        : calmosoft@gmail.com
+---------------------------------------------------------------------------------------------------------
*/
cards = 52
pack = list(cards)

for i = 1 to cards
    pack[i] = i
next 
for n = cards to 2 step -1
    rnd = random(n) + 1
    temp = pack[n]
    pack[n] = pack[rnd]
    pack[rnd] = temp
next
for i = 1 to cards
    see "" + pack[i] + " "
next 
