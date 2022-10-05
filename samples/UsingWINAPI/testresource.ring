/*
 * Author: Mounir IDRASSI <mounir@idrix.fr>
 * Date: May 7th 2022
 *
 * Sample application that demonstrate how to read embedded resource from an executable built with ring2exe
 * A text file called testresource.rc must be created on the same folder as testresource.ring and it should contain
 * the following lines:
 *           SOURCECODE           RCDATA                    "testresource.ring"
 *           MYICON				  ICON						"testresource.ico"
 *
 * Then we can call ring2exe to compile the sample: ring2exe testresource.ring
 */

if NOT IsWindows()
	? "this application is only for Windows"
	return
ok

load "winapi.ring"

while true

	see "

	Main Menu
	===========
	[1] Open embedded source code in notepad
	[2] Display executable icon
	[0] Exit

	Choice: "
	give nMenu
	see nl

	Switch nMenu
	On 1 openSource()
	On 2 openIcon()
	On "0" return
	Other see "	bad option" + nl
	Off

end

func openSource

	try
		/* the resource name is "SOURCECODE" and the resource type is RT_RCDATA */
		code = rwaReadBinaryResource(NULL, "SOURCECODE", RT_RCDATA)
		if Len(code)
			/* store it in temporary file and then open it in notepad */
			tempFolder = rGetTempPath()
			/* we use a custom prefix "xyz" */
			tempFilePath = rGetTempFileName(tempFolder, "xyz", 0)
			/* add .ring extension */
			tempFilePath += ".ring"
			Write(tempFilePath, code)
			rShellExecute (NULL, "open", "notepad.exe", tempFilePath, NULL, SW_SHOWNORMAL)
		else
			See "	Failed to read the source code from the embedded resources" + nl
		ok
	catch
		See "	An error occured: " + cCatchError + nl
	done

func openIcon

	try
		/* the icon name is "MYICON". RT_GROUP_ICON is the standard type for exe icons */
		icon = rwaReadBinaryResource(NULL, "MYICON", RT_GROUP_ICON)
		if Len(icon)
			/* store it in temporary file and then open it */
			tempFolder = rGetTempPath()
			/* we use a custom prefix "xyz" */
			tempFilePath = rGetTempFileName(tempFolder, "xyz", 0)
			/* add .ico extension */
			tempFilePath += ".ico"
			Write(tempFilePath, icon)
			result = rShellExecute (NULL, "open", "mspaint.exe", tempFilePath, NULL, SW_SHOWNORMAL)
			if result <= 32
				See "	ShellExecute failed with error " + result + nl
			ok
		else
			See "	Failed to read the icon from the embedded resources" + nl
		ok
	catch
		See "	An error occured: " + cCatchError + nl
	done