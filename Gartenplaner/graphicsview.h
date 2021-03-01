#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QLabel>
#include <QMimeData>
#include <QDebug>

namespace Ui {
class GraphicsView;
}
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit GraphicsView(QWidget *parent = 0);
    /**
     * @brief dragEnterEvent when dragging starts
     * @param event
     */
    void dragEnterEvent(QDragEnterEvent *event) override;
    /**
     * @brief dragMoveEvent when mouse is moved while dragging
     * @param event
     */
    void dragMoveEvent(QDragMoveEvent *event) override;
    /**
     * @brief dragLeaveEvent when dragging leaves
     * @param event
     */
    void dragLeaveEvent(QDragLeaveEvent *event) override;

signals:
    /**
     * @brief dropEvent when dragging leads to dropping - signal to mainwindow
     * @param event
     */
    void dropEvent(QDropEvent *event) override;
};

#endif // GRAPHICSVIEW_H
