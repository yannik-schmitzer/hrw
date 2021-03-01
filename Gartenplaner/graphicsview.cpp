#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent)
{

}

void GraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else if(event->mimeData()->hasText())
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
        qDebug()<<"Fehler beim Drag-Enter-Event";
    }
}

void GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else if(event->mimeData()->hasText())
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
        qDebug()<<"Fehler beim Drag-Move-Event";
    }
}

void GraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->ignore();
}
