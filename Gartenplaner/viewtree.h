#ifndef VIEWTREE_H
#define VIEWTREE_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

namespace Ui {
class ViewTree;
}

class ViewTree : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit ViewTree(QWidget *parent = 0);
    ~ViewTree();
    /**
     * @brief mousePressEvent - ghosts dragging object
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::ViewTree *ui;
};

#endif // VIEWTREE_H
