#include "colorbutton.h"
#include <QPainter>
#include <QPixmap>

ColorButton::ColorButton(QWidget *parent) : QPushButton(parent), m_color(Qt::black)
{

}

QColor ColorButton::color() const
{
    return m_color;
}

void ColorButton::setColor(const QColor &color)
{
    m_color = color;
    this->repaint();
}

void ColorButton::paintEvent(QPaintEvent *paintEvent)
{
    // use parents paint method
    QPushButton::paintEvent(paintEvent);
    // extend with own procedure: draw colored rectangle
    QPainter p(this);
    p.save();
    p.setPen(Qt::black);
    p.drawRect(0, 0, width(), height());
    p.fillRect(1, 1, width()-1, height()-1, m_color);
    p.restore();
}
