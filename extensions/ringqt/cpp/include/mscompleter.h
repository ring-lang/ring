// Based on code from : https://www.mimec.org/blog/qcompleter-with-multi-selection

#ifndef MSCOMPLETER_H
#define MSCOMPLETER_H

#include <QCompleter>

extern "C" {
#include "ring.h"
}

class MultiSelectCompleter : public QCompleter
{
    Q_OBJECT
public:
    MultiSelectCompleter( const QStringList& items, QObject* parent );
    ~MultiSelectCompleter();

public:
    char cSplitOperator ;
    QString pathFromIndex( const QModelIndex& index ) const;
    QStringList splitPath( const QString& path ) const;
};


#endif 