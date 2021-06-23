// MultiSelect Completer
// Based on code from : https://www.mimec.org/blog/qcompleter-with-multi-selection

extern "C" {
#include "ring.h"
}

#include <QCompleter>
#include <QLineEdit>

#include "mscompleter.h"

MultiSelectCompleter::MultiSelectCompleter( const QStringList& items, QObject* parent )
    : QCompleter( items, parent )
{
}

MultiSelectCompleter::~MultiSelectCompleter()
{
}

QString MultiSelectCompleter::pathFromIndex( const QModelIndex& index ) const
{
    QString path = QCompleter::pathFromIndex( index );

    QString text = static_cast<QLineEdit*>( widget() )->text();

    int nLastPos = 0;
    char cOperators[8] = ",+-*/%(";
   
    for (int t = 0 ; t < strlen(cOperators) ; t++ ) {
        int pos = text.lastIndexOf( cOperators[t] );
        if ( pos >= nLastPos ) {
            nLastPos = pos;
            path = text.left( pos ) + cOperators[t] + ' ' + QCompleter::pathFromIndex( index );
        }
    }
    return path;
}

char MultiSelectCompleter::getsplitOperator( const QString& path ) const
{
    int  nLastPos = 0;
    char cOperators[8] = ",+-*/%(";
    char cSplitOperator = ',' ;
   
    for (int t = 0 ; t < strlen(cOperators) ; t++ ) {
        int pos = path.lastIndexOf( cOperators[t] );
        if ( pos >= nLastPos ) {
            nLastPos = pos;
            cSplitOperator = cOperators[t] ;
        }
    }
    return cSplitOperator;
}

QStringList MultiSelectCompleter::splitPath( const QString& path ) const
{

    int pos = path.lastIndexOf( this->getsplitOperator(path) ) + 1;

    while ( pos < path.length() && path.at( pos ) == QLatin1Char( ' ' ) )
        pos++;

    return QStringList( path.mid( pos ) );
}