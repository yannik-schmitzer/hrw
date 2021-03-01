#ifndef VIEWFLOWER_H
#define VIEWFLOWER_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

namespace Ui {
class ViewFlower;
}

class ViewFlower : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit ViewFlower(QWidget *parent = 0);
    ~ViewFlower();
    /**
     * @brief mousePressEvent - ghosts dragging object
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::ViewFlower *ui;
};

#endif // VIEWFLOWER_H
