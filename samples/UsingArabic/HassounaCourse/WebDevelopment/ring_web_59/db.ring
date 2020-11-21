load "hassounapgdb.ring"

password = "123456"
database = "mycoffeedb_ring"
port     = "5433"

func get_products_asc()
	return get_data("select * from product order by publish_date asc")

func get_products_desc()
	return get_data("select * from product order by publish_date desc")

func get_product(id)
	pro = get_data("select * from product where id=" + id)
	if len(pro)>0
		return pro[1]
	else
		return "error"
	ok

