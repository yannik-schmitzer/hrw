#ifndef VIEWBUSH_H
#define VIEWBUSH_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

namespace Ui {
class ViewBush;
}

class ViewBush : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit ViewBush(QWidget *parent = 0);
    ~ViewBush();
    /**
     * @brief mousePressEvent - ghosts dragging object
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::ViewBush *ui;
};

#endif // VIEWBUSH_H
