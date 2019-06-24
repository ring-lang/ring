func RayLibColor r,b,g,a
	return GetColor( Bytes2Int(  Char(a) + Char(g) + Char(b) + Char(r) ) )
