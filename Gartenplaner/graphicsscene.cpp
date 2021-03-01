#include "graphicsscene.h"

GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent)
{

}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        QGraphicsScene::mousePressEvent(mouseEvent);
    }
    else if(mouseEvent->button() == Qt::RightButton)
    {
        QGraphicsScene::clearSelection();
        m_x = mouseEvent->scenePos().x();
        m_y = mouseEvent->scenePos().y();
        emit mousePressed(m_x, m_y);
    }
    else if(mouseEvent->button() == Qt::MiddleButton)
    {
        QGraphicsScene::clearSelection();
        QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
        QGraphicsRectItem *rec = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        QGraphicsEllipseItem *cir = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
        QGraphicsPixmapItem *pix = qgraphicsitem_cast<QGraphicsPixmapItem *>(item);

        if(rec)
        {
            int z = item->zValue();
            rec->setZValue(z+1);
        }
        if(cir)
        {
            int z = item->zValue();
            cir->setZValue(z+1);
        }
        if(pix)
        {
            int z = item->zValue();
            pix->setZValue(z+1);
        }
        else
        {
            mouseEvent->ignore();
        }

    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        QGraphicsScene::mouseReleaseEvent(mouseEvent);
    }
    else if(mouseEvent->button() == Qt::RightButton)
    {
        m_x = mouseEvent->scenePos().x();
        m_y = mouseEvent->scenePos().y();
        emit mouseReleased(m_x, m_y);
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseMoveEvent(mouseEvent);

    m_x = mouseEvent->scenePos().x();
    m_y = mouseEvent->scenePos().y();
    emit mouseMoved(m_x, m_y);
}
