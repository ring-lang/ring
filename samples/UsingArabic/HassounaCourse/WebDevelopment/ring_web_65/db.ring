load "hassounapgdb.ring"
load "stdlib.ring"

pg_password = "123456"
pg_database = "mycoffeedb_ring"
pg_port     = "5433"

func get_products_asc()
	return get_data("select * from product order by publish_date asc")

func get_products_desc()
	return get_data("select * from product order by publish_date desc")

func get_products_filter(filter)
	return get_data("select * from product where " + filter)

func get_product(id)
	pro = get_data("select * from product where id=" + id)
	if len(pro)>0
		return pro[1]
	else
		return "error"
	ok

func get_user(username)
	user = get_data('SELECT id, first_name, last_name, address, address2, city, state, zip, email, username, password FROM "user"' + 
							" WHERE username='" + username + "'" )
	if len(user)>0
		return user[1]
	else
		return "error"
	ok

func check_user_pass(user, pass)
	return len( get_data('select first_name from "user" where username='    +
																									"'"   + 
																									user  +
																				"' AND password='"   + 
																						  sha256(pass) +
																									"'"   +
																				" AND is_active=true" ) )

func check_user_pass_normal(user, pass)
	return len( get_data('select first_name from "user" where username='    +
																									"'"   + 
																									user  +
																				"' AND password='"   + 
																						         pass  +
																									"'"   +
																				" AND is_active=true" ) )
	

func get_products_favorite(username)
	user_id = get_user_id(username)
	return get_data("SELECT * FROM product INNER JOIN user_product_favorites ON id=product_id WHERE user_id=" + user_id)

func get_user_id(username)
	user = get_user(username)
	if type(user) = "LIST" return user['id'] ok

func add_fav_pro(user_id, pro_id)
	query = get_data("SELECT * FROM user_product_favorites WHERE user_id=" + user_id + " AND product_id=" + pro_id)
	if len(query) < 1
		return run("INSERT INTO user_product_favorites VALUES(" + user_id + "," + pro_id + ")")
	ok

func add_order(username)
	user_id = get_user_id(username)
	ck_ord = get_data('select id from "order" where is_finished=false and user_id=' + user_id)
	if len(ck_ord) < 1
		return run("INSERT INTO " + '"order"' + " VALUES(DEFAULT, CURRENT_TIMESTAMP, FALSE, " + user_id + ")")
	else 
		return false
	ok 

func get_orders(username)
	user_id = get_user_id(username)
	return get_data('select id, to_char(order_date,'+ "'DD/MM/YYYY hh:mm AM'" + ') AS order_date, is_finished, user_id from "order" where user_id=' + user_id)

func order_is_found(order_id)
	get_ord = get_data('select id from "order" where id=' + order_id)
	if len(get_ord) > 0
		return True
	else
		return False
	ok

func order_is_finished(order_id)
	get_ord = get_data('select id from "order" where id=' + order_id + " and is_finished=TRUE")
	if len(get_ord) > 0
		return True
	else
		return False
	ok

func is_found_order_not_finished(username)
	user_id = get_user_id(username)
	get_ord = get_data('select id from "order" where user_id=' + user_id + " and is_finished=FALSE")
	if len(get_ord) > 0
		return True
	else
		return False
	ok

func get_order_not_finished(username)
	user_id = get_user_id(username)
	get_ord = get_data('select id from "order" where user_id=' + user_id + " and is_finished=FALSE")
	if len(get_ord) > 0
		return get_ord[1]['id']
	else
		return -1
	ok

func add_order_details(ord_id, pro_id, qty, price)
	ck_ord_detail = get_data("select * from order_details where order_id=" + ord_id + " and product_id=" + pro_id)
	if len(ck_ord_detail) > 0
		old_qty = number(ck_ord_detail[1]['quantity'])
		if type(qty) = type(' ') qty = number( qty ) ok
		new_qty = old_qty + qty
		return run("UPDATE order_details SET quantity=" + new_qty + " WHERE order_id=" + ord_id + " and product_id=" + pro_id)
	else
		return run("INSERT INTO order_details VALUES(" + ord_id + ',' + pro_id + ',' + qty + ',' + price + ")")
	ok

func order_details_is_found(order_id, product_id)
	ck_ord_detail = get_data("select * from order_details where order_id=" + order_id + " and product_id=" + product_id)
	if len(ck_ord_detail) > 0
		return True
	else 
		return False
	ok

func get_qty_for_order_details(order_id, product_id)
	ck_ord_detail = get_data("select * from order_details where order_id=" + order_id + " and product_id=" + product_id)
	if len(ck_ord_detail) > 0
		return ck_ord_detail[1]['quantity']
	else 
		return -1
	ok

func edit_qty_order_details(order_id, product_id, new_qty)
	if order_details_is_found(order_id, product_id)
		return run("UPDATE order_details SET quantity=" + new_qty + " WHERE order_id=" + order_id + " and product_id=" + product_id)
	else 
		return False
	ok

func get_order_details(order_id)
	strSelect = "
		SELECT 
			product.id, 
			product.name, 
			order_details.order_id, 
			order_details.product_id, 
			order_details.quantity, 
			order_details.price, 
			order_details.quantity*order_details.price AS subtotals 
		FROM order_details 
			INNER JOIN product 
				ON product.id = order_details.product_id WHERE order_id=" + order_id
		
	return get_data(strSelect)

//لزيادة الكمية بواحد
func add_qty_order_details(order_id, product_id)
	return run("UPDATE order_details SET quantity = quantity+1 WHERE order_id=" + order_id + " AND product_id=" + product_id)

//لنقصان الكمية بواحد
func sub_qty_order_details(order_id, product_id)
	return run("UPDATE order_details SET 
								quantity = CASE 
													WHEN quantity-1 > 0 THEN quantity-1
													ELSE 1
											  END  
					WHERE order_id=" + order_id + " AND product_id=" + product_id)

func remove_order_details(order_id, product_id)
	return run("DELETE FROM order_details WHERE order_id=" + order_id + " AND product_id=" + product_id)
