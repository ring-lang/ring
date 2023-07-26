class constantsParent

	func init
		aAttributes = attributes(self)
		for cAttribute in aAttributes 
			AddMethod(self, "set"+cAttribute, 
				func value { raise("Can't change a constant")}
			)
		next 