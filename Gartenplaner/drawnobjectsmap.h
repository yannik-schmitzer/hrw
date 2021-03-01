#ifndef DRAWNOBJECTSMAP_H
#define DRAWNOBJECTSMAP_H

#include <QMap>
#include <QAbstractGraphicsShapeItem>
#include "graphicsobject.h"

class DrawnObjectsMap : public QMap<QAbstractGraphicsShapeItem*, GraphicsObject*>
{
public:
    /**
     * @brief Constructor.
     */
    DrawnObjectsMap();
    /**
     * @brief Prints all Draw::GraphicsObjects via Debug-Console.
     * @sa Draw::GraphicsObject::print
     */
    void print();
};

#endif // DRAWNOBJECTSMAP_H
