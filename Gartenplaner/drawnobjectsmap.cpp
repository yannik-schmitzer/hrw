#include "drawnobjectsmap.h"
#include <QDebug>

DrawnObjectsMap::DrawnObjectsMap()
{

}

void DrawnObjectsMap::print()
{
    // init iterator
    QMap<QAbstractGraphicsShapeItem*, GraphicsObject*>::const_iterator i = this->constBegin();
    while (i != this->constEnd()) {
        // print each item (GraphicsObject) via Debug-Console
        qDebug() << (*i)->toString();
        ++i;
    }
}
