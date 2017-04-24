/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <QApplication>
#include <QFile>

#include "QFile"
#include "QTextStream"

#include <QStandardPaths>
#include <QUrl>

#include <QDir>

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

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QString path ;
    path = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) ;
    QDir::setCurrent(path);

    // Copy Files from Resources to Temp Folder

    // Add test.ring
    QString path2 ;
    path2 = path+"/test.ring";
    QFile::copy(":/resources/myfile4",path2);

    // Add ring_qt.ring
    QString path3 ;
    path3 = path+"/ring_qt.ring";
    QFile::copy(":/resources/myfile5",path3);

    // Add qt.rh
    QString path4 ;
    path4 = path+"/qt.rh";
    QFile::copy(":/resources/myfile6",path4);

    // Add guilib.ring
    QString path5 ;
    path5 = path+"/guilib.ring";
    QFile::copy(":/resources/myfile7",path5);


    // Call Ring and run the Application

    RingState *pRingState;

    pRingState = ring_state_init();

    char** files;
    files = (char **) malloc(2 * sizeof(char*));
    for (size_t i = 0; i < 2; i += 1)
        files[i] = (char *) malloc(255 * sizeof(char));
    strcpy(files[0],"ring");
    strcpy(files[1],path2.toStdString().c_str());

    ring_state_main(2,files);

    // Free Memory 

    ring_state_delete(pRingState);

    free(files[1]);
    free(files[0]);
    free(files);

    // Delete the application files

    ringapp_delete_file(path,"test.ring");
    ringapp_delete_file(path,"ring_qt.ring");
    ringapp_delete_file(path,"qt.rh");
    ringapp_delete_file(path,"guilib.ring");

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
