#include "circle.h"
#include <QBrush>
#include <QPen>

unsigned long Circle::m_circleCounter = 0;

Circle::Circle(QObject *parent) : GraphicsObject(parent)
{
    // set name and increment counter
    ++m_circleCounter;
    QString name = QString("circle_%0").arg(m_circleCounter);
    this->setName(name);
    // new object
    m_graphicsEllipse = new QGraphicsEllipseItem;
}

Circle::Circle(qreal x, qreal y, qreal width, qreal height, QColor fillColor, QColor borderColor, QObject *parent)
{
    // set name and increment counter
    ++m_circleCounter;
    QString name = QString("circle_%0").arg(m_circleCounter);
    this->setName(name);
    // new object with constructor values
    m_graphicsEllipse = new QGraphicsEllipseItem;
    m_graphicsEllipse->setRect(x, y, width, height);
    m_graphicsEllipse->setBrush(QBrush(fillColor));
    m_graphicsEllipse->setPen(QPen(borderColor));
    m_graphicsEllipse->setZValue(0);
}

Circle::~Circle()
{
    delete m_graphicsEllipse;
}

QAbstractGraphicsShapeItem *Circle::graphicsShapeItem() const
{
    return m_graphicsEllipse;
}

QString Circle::toString()
{
    QString result = GraphicsObject::toString();
    result.append(" x:" + QString::number(m_graphicsEllipse->rect().x()));
    result.append(", y:" + QString::number(m_graphicsEllipse->rect().y()));
    result.append(", width:" + QString::number(m_graphicsEllipse->rect().width()));
    result.append(", height:" + QString::number(m_graphicsEllipse->rect().height()));
    result.append(", fillColor:" + QString::number(m_graphicsEllipse->brush().color().rgba(), 16));
    result.append(", borderColor:" + QString::number(m_graphicsEllipse->pen().color().rgba(), 16));
    return result;
}
