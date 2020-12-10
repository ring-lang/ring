#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "products_search"
	title = "Products Search"
	if aPageVars["txtsearchname"] = null
		products = get_products_filter("LOWER(name) like LOWER('%" + aPageVars["txtsearch"] + "%') or LOWER(description) like LOWER('%" + aPageVars["txtSearch"] + "%')")
	else
		s1 = " "
		s2 = " "
		if aPageVars['cbxcs'] != "on"
			s1 = "LOWER("
			s2 = ")"
		ok
		strFilter = " " + 
s1 + "name" + s2 + " like " + s1 + "'%" + aPageVars['txtsearchname'] + "%'" + s2 +
" and " +
s1 + "description" + s2 + " like " + s1 + "'%" + aPageVars['txtsearchdesc'] + "%'" + s2 +
" and " +
"price between " + aPageVars['txtsearchpricefrom'] + " AND " + aPageVars['txtsearchpriceto']

		products = get_products_filter(strFilter)
	ok

	func start()
		
		cTemp = getPage( "templates/products_search.html" , self )
		new hassounaPage{

			html(cTemp)

		}


