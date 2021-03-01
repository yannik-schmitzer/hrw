#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>
#include <QColor>

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief Constructor.
     * @param parent is the hierarchical preciding object.
     */
    explicit ColorButton(QWidget *parent = 0);
    /**
     * @brief Returns the displayed color.
     * @return The displayed color.
     */
    QColor color() const;
public slots:
    /**
     * @brief Sets the displayed color. And repaints the button (@sa ColorButton::paintEvent).
     * @param color is the new color.
     */
    void setColor(const QColor &color);
protected:
    /**
     * @brief Holds the displayed color.
     */
    QColor m_color;
    /**
     * @brief Overwrites the PushButton's paint-Method and draw a colored rectangle inside the ColorButton.
     * @param paintEvent is the qt render cycle event.
     */
    void paintEvent(QPaintEvent *paintEvent);
};

#endif // COLORBUTTON_H
