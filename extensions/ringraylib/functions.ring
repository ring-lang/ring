func RayLibColor r,b,g,a
	return GetColor( Bytes2Int(  Char(r) + Char(g) + Char(b) + Char(a) ) )
