aClasses + [
		:name = "GFileDialog" ,
		:realname = "QFileDialog" ,
		:events = [
				[ 	:signal = "currentChanged(const QString)" ,
					:slot = "currentChangedSlot()" ,
					:event = "currentChanged"
				],
				[ 	:signal = "currentUrlChanged(const QUrl)" ,
					:slot = "currentUrlChangedSlot()" ,
					:event = "currentUrlChanged"
				],
				[ 	:signal = "directoryEntered(const QString)" ,
					:slot = "directoryEnteredSlot()" ,
					:event = "directoryEntered"
				],
				[ 	:signal = "directoryUrlEntered(const QUrl)" ,
					:slot = "directoryUrlEnteredSlot()" ,
					:event = "directoryUrlEntered"
				],
				[ 	:signal = "fileSelected(const QString)" ,
					:slot = "fileSelectedSlot()" ,
					:event = "fileSelected"
				],
				[ 	:signal = "filesSelected(const QStringList)" ,
					:slot = "filesSelectedSlot()" ,
					:event = "filesSelected"
				],
				[ 	:signal = "filterSelected(const QString)" ,
					:slot = "filterSelectedSlot()" ,
					:event = "filterSelected"
				],
				[ 	:signal = "urlSelected(const QUrl)" ,
					:slot = "urlSelectedSlot()" ,
					:event = "urlSelected"
				],
				[ 	:signal = "urlsSelected(const QList<QUrl>)" ,
					:slot = "urlsSelectedSlot()" ,
					:event = "urlsSelected"
				]
		]
	]
