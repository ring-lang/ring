While true
	see "Enter file name : " give cFileName see read(cFileName)
	see nl see "Continue (Y/N)" give option
	if upper(option) = "N" exit ok
end
