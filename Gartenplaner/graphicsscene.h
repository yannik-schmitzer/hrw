#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QDropEvent>
#include <QLabel>
#include <QPixmap>
#include <QMimeData>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit GraphicsScene(QObject *parent = nullptr);
    /**
     * @brief This method reacts on the pressed mouse.
     * @param mouseEvent is the corresponding event and contains details about it (i.e. positions).
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    /**
     * @brief This method reacts on the released mouse, after a press.
     * @param mouseEvent is the corresponding event and contains details about it (i.e. positions).
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    /**
     * @brief This method reacts on the moved mouse.
     * @param mouseEvent is the corresponding event and contains details about it (i.e. positions).
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    /**
     * @brief m_x and m_y to save position values
     */
    int m_x,m_y;

signals:
    /**
     * @brief mousePressed signal to mainwindow
     * @param xPos
     * @param yPos
     */
    void mousePressed(int xPos, int yPos);
    /**
     * @brief mouseReleased signal to mainwindow
     * @param xPos
     * @param yPos
     */
    void mouseReleased(int xPos, int yPos);
    /**
     * @brief mouseMoved signal to mainwindow
     * @param xPos
     * @param yPos
     */
    void mouseMoved(int xPos, int yPos);
};

#endif // GRAPHICSSCENE_H
