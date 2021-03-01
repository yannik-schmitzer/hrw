#include "rectangle.h"
#include <QBrush>
#include <QPen>

unsigned long Rectangle::m_rectangleCounter = 0;

Rectangle::Rectangle(QObject *parent) : GraphicsObject(parent)
{
    // set name and increment counter
    ++m_rectangleCounter;
    QString name = QString("rect_%0").arg(m_rectangleCounter);
    this->setName(name);
    // new object
    m_graphicsRect = new QGraphicsRectItem;
}

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal height, QColor fillColor, QColor borderColor, QObject *parent) : GraphicsObject(parent)
{
    // set name and increment counter
    ++m_rectangleCounter;
    QString name = QString("rect_%0").arg(m_rectangleCounter);
    this->setName(name);
    // new object with constructor values
    m_graphicsRect = new QGraphicsRectItem;
    m_graphicsRect->setRect(x, y, width, height);
    m_graphicsRect->setBrush(QBrush(fillColor));
    m_graphicsRect->setPen(QPen(borderColor));
    m_graphicsRect->setZValue(0);
}

Rectangle::~Rectangle()
{
    delete m_graphicsRect;
}

QAbstractGraphicsShapeItem *Rectangle::graphicsShapeItem() const
{
    return m_graphicsRect;
}

QString Rectangle::toString()
{
    QString result = GraphicsObject::toString();
    result.append(" x:" + QString::number(m_graphicsRect->rect().x()));
    result.append(", y:" + QString::number(m_graphicsRect->rect().y()));
    result.append(", width:" + QString::number(m_graphicsRect->rect().width()));
    result.append(", height:" + QString::number(m_graphicsRect->rect().height()));
    result.append(", fillColor:" + QString::number(m_graphicsRect->brush().color().rgba(), 16));
    result.append(", borderColor:" + QString::number(m_graphicsRect->pen().color().rgba(), 16));
    return result;
}
