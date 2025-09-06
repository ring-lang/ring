##############################################################################
# Generate Documentation from Configuration File                             #
#                                                                            #
# Authors:                                                                   #
#   - Mahmoud Fayed <msfclipper@yahoo.com> (2016-09-22)                      #
#   - Youssef Saeed <youssefelkholey@gmail.com> (2025-09-06)                 #
#               Improved Functions Documentation Generation                  #
##############################################################################

##############################################################################
# Configuration Variables - Set these before running the script              #
#                                                                            #
# C_OUTPUTFILE   : Output file name for generated documentation              #
#                  Example: "qtclassesdoc.txt"                               #
#                                                                            #
# C_CHAPTERNAME  : Title for the documentation chapter                       #
#                  Example: "RingQt Classes Reference"                       #
#                                                                            #
# cFile          : Content of the input configuration file                   #
#                  Example: read("qt.cf")                                    #
#                                                                            #
# lStart         : Documentation type flag                                   #
#                  False = Generate classes documentation                    #
#                  True  = Generate functions documentation                  #
#                                                                            #
# lGroupFunctions : Optional flag to group functions into sections           #
#                  False = List all functions together (default)             #
#                  True  = Group functions into separated sections           #
#                                                                            #
# funcAfterClass : Optional callback function after processing each class    #
#                  Example: func cClassName { return "additional content" }  #
##############################################################################

##############################################################################
# Example Configuration:                                                     #
##############################################################################
# C_OUTPUTFILE = "ringlibsdlfuncsdoc.txt"
# C_CHAPTERNAME = "RingLibSDL Functions Reference"
# cFile = read("libsdl.cf")
# lStart = True
# lGroupFunctions = True
# funcAfterClass = NULL

load "stdlibcore.ring"

# Ensure default value for lGroupFunctions if not set by user
if not islocal("lGroupFunctions")
	lGroupFunctions = false
ok

aList = str2list(cFile)

# Determines which type of documentation to generate
cOutput = NULL
if lStart	# True = Generate Functions Documentation
	cOutput = generate_functions_doc(aList)
else		# False = Generate Classes Documentation
	cOutput = generate_classes_doc(aList)
ok
write(C_OUTPUTFILE,cOutput)
see "Documentation generated in: " + C_OUTPUTFILE + nl

# Generates documentation for functions and constants
func generate_functions_doc(aList)
	# Create initial documentation header
	cDoc = ".. index:: " + windowsnl()
	cDoc += "     single: "+C_CHAPTERNAME+"; Introduction" + windowsnl() + windowsnl()
	cDoc += copy("=",len(C_CHAPTERNAME)) + windowsnl()
	cDoc += C_CHAPTERNAME + windowsnl()
	cDoc += copy("=",len(C_CHAPTERNAME)) + windowsnl() + windowsnl()
	cDoc += "
Introduction
============
In this chapter we have a list of the supported functions and constants by this extension.
"
	
	# Initialize data structures for parsing
	aConstants = []
	aSections = [ ["General", []] ] # Start with default "General" section
	nCurrentSection = 1
	aIgnoreBlockTags = ["code", "runcode", "struct", "filter", "funcstart", "class"]
	
	# Main parsing loop - process each line of the input
	x = 1
	while x <= len(aList)
		cLine = trim(aList[x])
		if len(cLine) = 0 x++ loop ok
		
		# Handle different types of blocks in the source file
		
		# Process constant blocks
		if lower(cLine) = "<constant>"
			x++ # Skip <constant> tag
			while x <= len(aList)
				cCurrentLine = trim(aList[x])
				if lower(cCurrentLine) = "</constant>" break ok
				if len(cCurrentLine) > 0 add(aConstants, cCurrentLine) ok
				x++
			end
			x++ # Skip </constant> tag
			loop
		ok
		
		# Process comment blocks - either section headers or blocks to ignore
		if lower(cLine) = "<comment>"
			# Check if this is a section header (3-line format)
			if x + 2 <= len(aList)
				cTitle = trim(aList[x+1])
				cEndTag = trim(aList[x+2])
				# Valid section header check
				if lower(cEndTag) = "</comment>" and not substr(cTitle, "(") and len(cTitle) > 0 and len(cTitle) < 50
					# It's a section header
					if lGroupFunctions
						if len(aSections) = 1 and len(aSections[1][2]) = 0
							aSections[1][1] = cTitle
						else
							add(aSections, [cTitle, []])
							nCurrentSection = len(aSections)
						ok
					else
						# If not grouping, keep title as default or set once
						if len(aSections[1][2]) = 0	
							aSections[1][1] = cTitle
						ok
					ok
					x += 3 # Skip entire header block
					loop
				ok
			ok
			# If not a header, skip the entire comment block
			x++ # Skip <comment> tag
			while x <= len(aList)
				if lower(trim(aList[x])) = "</comment>" break ok
				x++
			end
			x++ # Skip </comment> tag
			loop
		ok
		
		# Skip other block types that should be ignored
		for cTag in aIgnoreBlockTags
			if lower(cLine) = "<" + cTag + ">" or left(lower(cLine), len(cTag)+1) = "<"+cTag
				x++ # Skip start tag
				while x <= len(aList)
					if lower(trim(aList[x])) = "</" + cTag + ">" break ok
					x++
				end
				x++ # Skip end tag
				loop
			ok
		next
		
		# Process function definitions (lines with parentheses)
		if substr(cLine, "(") > 0 and substr(cLine, ")") > 0 and left(cLine, 1) != "<"
			cLine = substr(cLine,"@", "_") # Replace @ with _ for formatting
			add(aSections[nCurrentSection][2], cLine)
		ok
		x++ # Move to next line
	end
	
	# Generate the output documentation
	cDoc += "
Reference
=========
"
	
	# Add constants section if any constants were found
	if len(aConstants) > 0
		cDoc += windowsnl() + "Constants" + windowsnl()
		cDoc += "---------" + windowsnl() + windowsnl()
		for cItem in aConstants cDoc += "* ``" + cItem + "``" + windowsnl() next
	ok
	
	# Add the main "Functions" header
	cFunctionsTitle = "Functions"
	cDoc += windowsnl() + cFunctionsTitle + windowsnl()
	cDoc += copy("-", len(cFunctionsTitle)) + windowsnl()

	# Add each collected section
	if lGroupFunctions
		# Group into subsections
		for i = 1 to len(aSections)
			aSection = aSections[i]
			cSectionTitle = aSection[1]
			aItems = aSection[2]
			if len(aItems) > 0
				cUnderline = "~"
				cDoc += windowsnl() + cSectionTitle + windowsnl()
				cDoc += copy(cUnderline, len(cSectionTitle)) + windowsnl() + windowsnl()
				for cItem in aItems cDoc += "* ``" + cItem + "``" + windowsnl() next
			ok
		next
	else
		# No grouping, list all functions under "Functions" without subsections
		cDoc += windowsnl()
		for i = 1 to len(aSections)
			aSection = aSections[i]
			aItems = aSection[2]
			for cItem in aItems cDoc += "* ``" + cItem + "``" + windowsnl() next
		next
	ok
	return cDoc

# Generates documentation for classes
func generate_classes_doc(aList)
	# Create initial documentation header
	cDoc = ".. index:: " + windowsnl()
	cDoc += "     single: "+C_CHAPTERNAME+"; Introduction" + windowsnl() + windowsnl()
	cDoc += copy("=",len(C_CHAPTERNAME)) + windowsnl()
	cDoc += C_CHAPTERNAME + windowsnl()
	cDoc += copy("=",len(C_CHAPTERNAME)) + windowsnl() + windowsnl()
	cDoc += "
Introduction
============
In this chapter we have a list of the supported functions by this extension "
	cDoc += "
Reference
=========
"
	
	# Process the content using the recursive helper function
	cDoc += generate_classes_doc_helper(aList)
	return cDoc

# Recursive helper function to process class documentation
func generate_classes_doc_helper(aList)
	cDoc = ""
	lInClassSection = false
	for x = 1 to len(aList)
		cLine = trim(aList[x])
		
		# Handle file inclusion directives
		if left(lower(cLine),10)="<loadfile>"
			cSubFileName = trim(substr(cLine,11))
			cSubFileText = read(cSubFileName)
			cCurrentDir = currentdir()
			chdir(justfilepath(cSubFileName))
			
			# Recursively process the included file
			cDoc += generate_classes_doc_helper(str2list(cSubFileText))
			
			chdir(cCurrentDir)
			loop
		ok
		
		# Process class definitions
		if left(lower(cLine),7)="<class>"
			lInClassSection = true
			x++
			do
				cLine = trim(aList[x])
				if left(cLine,5) = "name:"
					cClassNameAlone = trim(substr(cLine,6))
					cClassName = cClassNameAlone + " Class"
					cDoc += Windowsnl() + ".. index::" + windowsnl()
					cDoc +="	pair: "+C_CHAPTERNAME+"; "
					cDoc += cClassName + WindowsNl()
					cDoc += windowsnl() + cClassName + windowsnl()
					cDoc += Copy("=",len(cClassName)) + windowsnl() + windowsnl()
					if funcAfterClass != NULL
						cDoc += call funcAfterClass(cClassNameAlone)
					ok
				ok
				if left(cLine,7) = "parent:"
					cClassName = trim(substr(cLine,8))
					cDoc += windowsnl() + "Parent Class : " + cClassName + WindowsNl() + WindowsNl()
				ok
				if left(cLine,5) = "para:"
					cClassName = trim(substr(cLine,6))
					cDoc += windowsnl() + "Parameters : " + cClassName + WindowsNl() + WindowsNl()
				ok
				x++
			again left(lower(aList[x]),8) !="</class>"
			loop
		ok
		
		# Skip blocks that should be ignored
		aAvoidBlocks = ["comment","code","funcstart","runcode","struct"]
		lIsInsideAvoidBlock = false
		for cAvoid in aAvoidBlocks
			if left(lower(cLine),len(cAvoid)+2)="<"+cAvoid+">"
				x++
				do
					cLine = trim(aList[x])
					x++
				again left(lower(aList[x]),len(cAvoid)+3) !="</" + cAvoid + ">"
				lIsInsideAvoidBlock = true
				exit
			ok
		next
		if lIsInsideAvoidBlock loop ok
		
		# Skip specific lines to avoid
		if isAvoidLine("constant",cLine) loop ok
		if isAvoidLine("ignorecpointertype",cLine) loop ok
		if isAvoidLine("register",cLine) loop ok
		if isAvoidLine("filter",cLine) loop ok
		if isAvoidLine("/comment",cLine) loop ok
		if isAvoidLine("/code",cLine) loop ok
		if isAvoidLine("/runcode",cLine) loop ok
		if isAvoidLine("/struct",cLine) loop ok
		
		# Process class methods and properties
		if lInClassSection
			if (cLine != NULL ) and len(cLine) > 1
				# Replace @ with _ for formatting
				cLine = substr(cLine,"@","_")
				cDoc += "* " + cLine + windowsnl()
			ok
		ok
	next
	return cDoc

# Helper function to check if a line should be avoided
func isAvoidLine cStr,cLine
	if ( left(lower(cLine),len(cStr)+2)="<"+cStr + ">" ) or ( left(lower(cLine),len(cStr)+3)="</"+cStr + ">"  )
		return true
	ok
	return false
