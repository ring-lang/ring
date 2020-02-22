/*
	Testing the ChangeRingKeyword command
	(1) Adding comments after the command
	(2) Using the command many times in the same line
*/

ChangeRingKeyword see print // any comment

print "One" +nl

print "Two" +nl


ChangeRingKeyword print see
see"Three!"+nl

ChangeRingKeyword see print # any comment

print "One" +nl

print "Two" +nl


ChangeRingKeyword print see
see"Three!"+nl

ChangeRingKeyword see print ChangeRingKeyword print see ChangeRingKeyword see print

print "One" +nl

print "Two" +nl

ChangeRingKeyword print see

see"Three!"+nl

ChangeRingKeyword see print print "Done!" + nl ChangeRingKeyword print see