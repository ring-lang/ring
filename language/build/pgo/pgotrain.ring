/*
**  PGO training run for the Clang + LTO + PGO build (buildclang_lto_pgo.bat in this folder)
**  Runs every command of language/tests/tests.ring using the instrumented ring.exe,
**  so the compiler learns which code paths are hot.
**  Usage: ring pgotrain.ring <ring.exe> <copy of tests/scripts folder> <tests.ring file>
**  Uses core functions only (no standard library needed)
*/

if len(sysargv) < 5
	? "Usage: ring pgotrain.ring <ring.exe> <scripts folder copy> <tests.ring>"
	bye
ok

cExe     = sysargv[3]
cScripts = sysargv[4]
cTests   = sysargv[5]

# Defines aTests (the same list used by tests/test.ring)
eval(read(cTests))

chdir(cScripts)
nCount = 0
t1 = clock()
for aTest in aTests
	cCommand = trim(aTest[:command])
	if lower(left(cCommand, 5)) != "ring "
		loop
	ok
	cCommand = '"' + cExe + '" ' + substr(cCommand, 6)
	# Tests that don't provide stdin must not wait for keyboard input
	if not substr(cCommand, "<")
		cCommand += " < nul"
	ok
	system(cCommand + " > nul 2>&1")
	nCount++
next
? "PGO training: " + nCount + " test programs executed in " +
  ((clock()-t1)/clockspersecond()) + " seconds"
