#include "graphicsobject.h"

unsigned long GraphicsObject::m_graphicsObjectCounter = 0;

GraphicsObject::GraphicsObject(QObject *parent)
{
    // set name and increment counter
    ++m_graphicsObjectCounter;
    QString name = QString("graphicObject_%0").arg(m_graphicsObjectCounter);
    this->setName(name);
}

QString GraphicsObject::name() const
{
    return m_name;
}

void GraphicsObject::setName(const QString &name)
{
    m_name = name;
}

QString GraphicsObject::toString()
{
    return QString("(" + m_name + ")");
}
