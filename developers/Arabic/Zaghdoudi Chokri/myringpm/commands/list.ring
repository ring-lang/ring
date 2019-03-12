/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/
func AffichPckgsInstallE
	aFiles 		= ListAllFiles("packages","ring")
	aPckgsInfoFiles = []
	for cFile in aFiles
		if JustFileName(cFile) = "package.ring"
			aPckgsInfoFiles + cFile
		ok
	next
	for cFile in aPckgsInfoFiles
		eval(read(cFile))
		? "Nom du Package: " + aPckgInfo[:name]
	next
	if len(aPckgsInfoFiles) = 0
		? "Acun package nest installe !"
		return
	ok
