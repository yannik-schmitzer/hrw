#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "graphicsobject.h"
#include <QGraphicsRectItem>

class Rectangle : public GraphicsObject
{
public:
    /**
     * @brief Rectangle
     * @param parent is the hierarchical preciding object.
     */
    Rectangle(QObject *parent = nullptr);
    /**
     * @brief Constructor.
     * @param x is the x-Position on the Canvas.
     * @param y is the y-Position on the Canvas.
     * @param width is the width.
     * @param height is the height.
     * @param fillColor is the fill color.
     * @param borderColor is the border color.
     * @param parent is the hierarchical preciding object.
     */
    Rectangle(qreal x, qreal y, qreal width, qreal height, QColor fillColor, QColor borderColor, QObject *parent = nullptr);
    /**
     * @brief Destructor.
     */
    ~Rectangle();
    /**
     * @brief This method return the Canvas API-Object.
     * @return The Rectangle's drawable object (Canvas-API).
     * @sa Draw::GraphicsObject::graphicsShapeItem
     */
    virtual QAbstractGraphicsShapeItem *graphicsShapeItem() const;
    /**
     * @brief Creates a readable QString.
     * @return A QString with the Rectangle's properties.
     */
    virtual QString toString();
    /**
     * @brief Holds the drawable object.
     */
    static unsigned long m_rectangleCounter;
protected:
    /**
     * @brief Classes' instance counter.
     */
    QGraphicsRectItem *m_graphicsRect;
};

#endif // RECTANGLE_H
