#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphicsobject.h"
#include <QGraphicsEllipseItem>

class Circle : public GraphicsObject
{
public:
    /**
     * @brief Constructor.
     * @param parent is the hierarchical preciding object.
     */
    Circle(QObject *parent = nullptr);
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
    Circle(qreal x, qreal y, qreal width, qreal height, QColor fillColor, QColor borderColor, QObject *parent = nullptr);
    /**
     * @brief Destructor.
     */
    ~Circle();
    /**
     * @brief This method return the Canvas API-Object.
     * @return The Circle's drawable object (Canvas-API).
     * @sa Draw::GraphicsObject::graphicsShapeItem
     */
    virtual QAbstractGraphicsShapeItem *graphicsShapeItem() const;
    /**
     * @brief Creates a readable QString.
     * @return A QString with the Circle's properties.
     */
    virtual QString toString();
protected:
    /**
     * @brief Holds the drawable object.
     */
    QGraphicsEllipseItem *m_graphicsEllipse;
    /**
     * @brief Classes' instance counter.
     */
    static unsigned long m_circleCounter;
};

#endif // CIRCLE_H
