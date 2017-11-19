/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <QApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QUrl>

// Load Ring

extern "C" {
#include "ring.h"
}

#include "ring_qt.h"

#include "ring_string.c"
#include "ring_item.c"
#include "ring_items.c"
#include "ring_list.c"
#include "ring_scanner.c"
#include "ring_parser.c"
#include "ring_stmt.c"
#include "ring_expr.c"
#include "ring_codegen.c"
#include "ring_vm.c"
#include "ring_vmexpr.c"
#include "ring_vmvars.c"
#include "ring_vmlists.c"
#include "ring_vmfuncs.c"
#include "ring_vmoop.c"
#include "ring_vmcui.c"
#include "ring_vmtrycatch.c"
#include "ring_vmstrindex.c"
#include "ring_vmjump.c"
#include "ring_vmduprange.c"
#include "ring_vmperformance.c"
#include "ring_vmexit.c"
#include "ring_vmstackvars.c"
#include "ring_vmstate.c"
#include "ring_api.c"
#include "ring_vmmath.c"
#include "ring_vmfile.c"
#include "ring_state.c"
#include "ring_vmrefmeta.c"
#include "ring_vmlistfuncs.c"
#include "ring_vmos.c"
#include "ring_ext.c"
#include "ring_hashlib.c"
#include "ring_hashtable.c"
#include "ring_vmgc.c"
#include "ring_objfile.c"

void ringapp_delete_file(QString path,const char *cFile) ;

RING_FUNC(ring_loadlib)
{
    // Just a prototype to pass functions calls to loadlib() from Ring Object File
    // We don't need loadlib() because ring_qt.cpp is already embedded in the Qt project
}

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QString path ;
    path = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) ;
    QDir::setCurrent(path);

    // Delete the application files
    ringapp_delete_file(path,"ringapp.ringo");

    // Copy Ring Object File (ringapp.ringo) from Resources to Temp Folder
    QString path2 ;
    path2 = path+"/ringapp.ringo";
    QFile::copy(":/resources/ringapp",path2);
 	
    // Call Ring and run the Application
    RingState *pRingState;
    pRingState = ring_state_new();
    ring_vm_funcregister("loadlib",ring_loadlib);
    ring_state_runobjectfile(pRingState,"ringapp.ringo");
    ring_state_delete(pRingState);

    return 0;

}

void ringapp_delete_file(QString path,const char *cFile)
{
    char mytarget[100];
    sprintf(mytarget,"%s/%s",path.toStdString().c_str(),cFile);
    QFile myfile;
    myfile.setFileName(mytarget);
    myfile.setPermissions(QFile::ReadOther | QFile::WriteOther);
    myfile.remove();
}


