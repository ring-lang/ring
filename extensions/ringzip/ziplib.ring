if iswindows()
	LoadLib("ring_libzip.dll")
but ismacosx()
	LoadLib("libring_libzip.dylib")
else
	LoadLib("libring_libzip.so")
ok

Load "ring_libzip.rh"

func zip_addfile oZip,cFile
	zip_entry_open(oZip,cFile)
	zip_entry_fwrite(oZip,cFile)
	zip_entry_close(oZip)

class zip

	func SetFileName cName
		cZipFileName = cName

	func GetFileName
		return cZipFileName
	
	func Open cMode
		oZip = zip_openfile(GetFileName(),cMode)	

	func Close 
		zip_close(oZip)

	func AddFile cFileName
		zip_addfile(oZip,cFileName)

	func ExtractAllFiles cFolder
		zip_extract_allfiles(GetFileName(),"myfolder")

	func FilesCount
		return zip_filescount(oZip)

	func GetFileNameByIndex nIndex
		return zip_getfilenamebyindex(oZip,nIndex)

	func NewEntry
		return new ZipEntry(oZip)

	private 

		cZipFileName = ""
		oZip	

class ZipEntry

	func init oZipPara
		oZip = oZipPara

	func Open cFileName 
		zip_entry_open(oZip,cFileName)

	func WriteFile cFileName 
		zip_entry_fwrite(oZip,cFileName)

	func WriteString cString
		zip_entry_write(oZip,cString)

	func Close 
		zip_entry_close(oZip)

	private 
		oZip
