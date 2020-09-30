func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "VisualizeSortSample Package"
	? copy("=",C_LINESIZE)
	? "VisualizeSortSample package for the Ring programming language"
	? "See the folder : ring/samples/Drawing/VisualizeSort"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/Drawing/VisualizeSort")
	system("ring Visualize-Sort.ring")
	chdir(cDir)