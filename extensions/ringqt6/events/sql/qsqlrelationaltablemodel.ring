aClasses +	[	:name = "GSqlRelationalTableModel" ,
			:realname = "QSqlRelationalTableModel",
			:initpara = "QObject *parent, QSqlDatabase db",
			:events = [
					[ 	:signal = "beforeDelete(int)" ,
						:slot = "beforeDeleteSlot()" ,
						:event = "beforeDelete"
					] ,
					[ 	:signal = "beforeInsert(QSqlRecord&)" ,
						:slot = "beforeInsertSlot()" ,
						:event = "beforeInsert"
					] ,
					[ 	:signal = "beforeUpdate(int,QSqlRecord&)" ,
						:slot = "beforeUpdateSlot()" ,
						:event = "beforeUpdate"
					] ,
					[ 	:signal = "primeInsert(int,QSqlRecord&)" ,
						:slot = "primeInsertSlot()" ,
						:event = "primeInsert"
					]
				  ]
		] 
