load "guilib.ring"

QStandardPaths_GenericDataLocation = 11

oPath = new QStandardPaths
? oPath.writableLocation(QStandardPaths_GenericDataLocation)
