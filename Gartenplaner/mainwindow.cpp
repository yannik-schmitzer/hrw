#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "circle.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_drawingOptions(new Options),
    m_drawnObjectsMap(new DrawnObjectsMap),
    m_graphicsScene(new GraphicsScene),
    np(new NewProjectDialog),
    hw(new HelpWindowDialog)
{
    // init ui
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setFixedSize(200, 200);
    ui->graphicsView->setScene(m_graphicsScene);
    m_graphicsScene->setSceneRect(0, 0, 200, 200);
    ui->colorFillSelector->setColor(m_drawingOptions->fillColor());
    ui->colorBorderSelector->setColor(m_drawingOptions->borderColor());
    ui->actionOpen->setShortcut(QKeySequence::Open);
    ui->actionOpen->setIcon(this->style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionSave->setShortcut(QKeySequence::Save);
    ui->actionSave->setIcon(this->style()->standardIcon(QStyle::SP_DialogSaveButton));

    // connect widgets
    connect(
        m_drawingOptions, SIGNAL(selectedToolChanged(Options::Tool)),
        ui->toolSelector, SLOT(setSelectedTool(Options::Tool))
    );
    connect(
        ui->toolSelector, SIGNAL(selectedToolChanged(Options::Tool)),
        m_drawingOptions, SLOT(setSelectedTool(Options::Tool))
    );
    connect(
        ui->colorFillSelector, SIGNAL(selectedColorChanged(QColor)),
        m_drawingOptions, SLOT(setFillColor(QColor))
    );
    connect(
        ui->colorBorderSelector, SIGNAL(selectedColorChanged(QColor)),
        m_drawingOptions, SLOT(setBorderColor(QColor))
    );
    connect(
        ui->toolSelector, SIGNAL(selectedToolChanged(Options::Tool)),
        this, SLOT(updateUI_Tools())
    );
    connect(
        m_graphicsScene, SIGNAL(mousePressed(int,int)),
        this, SLOT(mousePressed(int,int))
    );
    connect(
        m_graphicsScene, SIGNAL(mouseReleased(int,int)),
        this, SLOT(mouseReleased(int,int))
    );
    connect(
        m_graphicsScene, SIGNAL(mouseMoved(int,int)),
        this, SLOT(mouseMoved(int,int))
    );
    connect(
        np, SIGNAL(NewProjectDialog_accepted(int,int)),
        this, SLOT(New_Project(int,int))
    );
    connect(
        ui->graphicsView, SIGNAL(dropEvent(QDropEvent*)),
        this, SLOT(dropEvent(QDropEvent*))
    );

    ui->flowerView->setVisible(true);
    ui->bushView->setVisible(false);
    ui->treeView->setVisible(false);
    ui->textView->setVisible(false);
    ui->toolSelector->setSelectedTool(Options::Tool::CIRCLE);
    ui->colorFillSelector->setColor(Qt::black);
    ui->colorFillSelector->setColor(Qt::blue);
    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    np->show();
    hw->hide();
}

MainWindow::~MainWindow()
{
    // delete constructed members
    delete ui;
    delete m_drawingOptions;
    delete m_drawnObjectsMap;
    delete m_graphicsScene;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    this->update();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Project", QCoreApplication::applicationDirPath(), "PNG (*.png)");
        if (!fileName.isNull())
        {
            QImage img(fileName);
            if(img.isNull())
            {
                return;
            }
            m_sceneW = img.width();
            m_sceneH = img.height();
            m_graphicsScene->clear();
            m_drawnObjectsMap->clear();
            ui->graphicsView->setFixedSize(m_sceneW, m_sceneH);
            m_graphicsScene->setSceneRect(0, 0, m_sceneW, m_sceneH);

            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
            m_graphicsScene->addItem(item);
        }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Project", QCoreApplication::applicationDirPath(), "PNG (*.png)");
    m_graphicsScene->clearSelection();

    QImage img(m_graphicsScene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    img.fill(Qt::transparent);

    QPainter painter (&img);
    m_graphicsScene->render(&painter);
    img.save(fileName);
}

void MainWindow::on_actionRectangle_triggered()
{
    m_drawingOptions->setSelectedTool(Options::Tool::RECTANGLE);
}

void MainWindow::on_actionCircle_triggered()
{
    m_drawingOptions->setSelectedTool(Options::Tool::CIRCLE);
}

void MainWindow::addGraphicsObject()
{
    // read values from the ui
    qreal x = m_startX;
    qreal y = m_startY;
    qreal w = m_w;
    qreal h = m_h;
    QColor fc = m_drawingOptions->fillColor();
    QColor bc = m_drawingOptions->borderColor();
    // new graphics object
    GraphicsObject *o;
    Options::Tool t = m_drawingOptions->selectedTool();
    if (t == Options::Tool::CIRCLE){
        if(w < 0 && h <0)
        {
            w = -w;
            h = -h;
            float left = qMin(m_startX,m_endX);
            float top = qMin(m_startY,m_endY);
            o = new Circle(left, top, w, h, fc, bc);
        }
        else if(w < 0)
        {
            w = -w;
            float left = qMin(m_startX,m_endX);
            o = new Circle(left, y, w, h, fc, bc);
        }
        else if(h < 0)
        {
            h = -h;
            float top = qMin(m_startY,m_endY);
            o = new Circle(x, top, w, h, fc, bc);
        }
        else
        {
            o = new Circle(x, y, w, h, fc, bc);
        }
    } else if (t == Options::Tool::RECTANGLE){
        if(w < 0 && h <0)
        {
            w = -w;
            h = -h;
            float left = qMin(m_startX,m_endX);
            float top = qMin(m_startY,m_endY);
            o = new Rectangle(left, top, w, h, fc, bc);
        }
        else if(w < 0)
        {
            w = -w;
            float left = qMin(m_startX,m_endX);
            o = new Rectangle(left, y, w, h, fc, bc);
        }
        else if(h < 0)
        {
            h = -h;
            float top = qMin(m_startY,m_endY);
            o = new Rectangle(x, top, w, h, fc, bc);
        }
        else
        {
            o = new Rectangle(x, y, w, h, fc, bc);
        }
    }
    o->graphicsShapeItem()->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    m_drawnObjectsMap->insert(o->graphicsShapeItem(), o);
    m_graphicsScene->addItem(o->graphicsShapeItem());
}

void MainWindow::updateUI_Tools()
{
    // restore initial values / show everything
    ui->actionCircle->setChecked(false);
    ui->actionRectangle->setChecked(false);
    // set ui-state depending on selected tool / hide specific
    switch (m_drawingOptions->selectedTool()){
        case Options::Tool::CIRCLE:
            ui->actionCircle->setChecked(true);
            break;
        case Options::Tool::RECTANGLE:
            ui->actionRectangle->setChecked(true);
            break;
        default: break;
    }
}

void MainWindow::mousePressed(int mouseX, int mouseY)
{
    m_startX = mouseX;
    m_startY = mouseY;
}

void MainWindow::mouseReleased(int mouseX, int mouseY)
{
    m_endX = mouseX;
    m_endY = mouseY;
    if(m_startX != m_endX && m_startY != m_endY)
    {
        switch (m_drawingOptions->selectedTool()){
           case Options::Tool::CIRCLE:
                   m_w = m_endX - m_startX;
                   m_h = m_endY - m_startY;
                   addGraphicsObject();
               break;
           case Options::Tool::RECTANGLE:
                   m_w = m_endX - m_startX;
                   m_h = m_endY - m_startY;
                   addGraphicsObject();
               break;
            default: break;
       }
    }
}

void MainWindow::mouseMoved(int mouseX, int mouseY)
{
    if (mouseX <0)
    {
        mouseX = -mouseX;
        QCursor::setPos(QCursor::pos().x()+mouseX,QCursor::pos().y());
    }
    if (mouseY <0)
    {
        mouseY = -mouseY;
        QCursor::setPos(QCursor::pos().x(),QCursor::pos().y()+mouseY);
    }

    if (mouseX >m_sceneW)
    {
        mouseX = -mouseX;
        QCursor::setPos(QCursor::pos().x()+mouseX+m_sceneW,QCursor::pos().y());
    }
    if (mouseY >m_sceneH)
    {
        mouseY = -mouseY;
        QCursor::setPos(QCursor::pos().x(),QCursor::pos().y()+mouseY+m_sceneH);
    }
}

void MainWindow::on_actionNew_triggered()
{
    if(np->isHidden())
    {
        np->show();
    }
    else
    {

    }
}

void MainWindow::New_Project(int w, int h)
{
    m_sceneW = w;
    m_sceneH = h;
    m_graphicsScene->clear();
    m_drawnObjectsMap->clear();
    ui->graphicsView->setFixedSize(m_sceneW, m_sceneH);
    m_graphicsScene->setSceneRect(0, 0, m_sceneW, m_sceneH);
}

void MainWindow::on_pushButtonFlowers_clicked()
{
    ui->flowerView->setVisible(true);
    ui->bushView->setVisible(false);
    ui->treeView->setVisible(false);
    ui->textView->setVisible(false);
}

void MainWindow::on_pushButtonBushes_clicked()
{
    ui->flowerView->setVisible(false);
    ui->bushView->setVisible(true);
    ui->treeView->setVisible(false);
    ui->textView->setVisible(false);
}

void MainWindow::on_pushButtonTrees_clicked()
{
    ui->flowerView->setVisible(false);
    ui->bushView->setVisible(false);
    ui->treeView->setVisible(true);
    ui->textView->setVisible(false);
}

void MainWindow::on_actionDelete_Object_triggered()
{
    foreach(QGraphicsItem *i, m_graphicsScene->selectedItems())
    {
        m_graphicsScene->removeItem(i);
    }
}

void MainWindow::on_pushButtonText_clicked()
{
    ui->flowerView->setVisible(false);
    ui->bushView->setVisible(false);
    ui->treeView->setVisible(false);
    ui->textView->setVisible(true);
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if(ui->pushButtonFlowers->isChecked() || ui->pushButtonBushes->isChecked() || ui->pushButtonTrees->isChecked())
        {
            if (event->mimeData()->hasFormat("application/x-dnditemdata"))
            {
                QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
                QDataStream dataStream(&itemData, QIODevice::ReadOnly);

                QPixmap pixmap;
                QPoint offset;
                dataStream >> pixmap >> offset;

                QGraphicsPixmapItem *pixItem = m_graphicsScene->addPixmap(pixmap);
                pixItem->setPos(event->pos());
                pixItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
                pixItem->setZValue(0);
            }
        }
    else if(ui->pushButtonText->isChecked())
    {
        {
            if (event->mimeData()->hasText())
            {
                QPoint offset;
                QGraphicsRectItem *proxyControl; //für die Textlabels habe ich im Prinzip genau das Gleiche gemacht
                QPen tPen(Qt::transparent);
                QBrush tBrush(Qt::transparent);

                QLabel *newIcon = new QLabel();
                newIcon->setText(event->mimeData()->text());
                newIcon->setStyleSheet("background-color: rgba(255,255,255,25%)");
                int w = newIcon->fontMetrics().width(newIcon->text()); //ich musste nur die größe des Textes herausfinden
                int h = newIcon->fontMetrics().height();
                newIcon->setAttribute(Qt::WA_DeleteOnClose);
                newIcon->move(event->pos() - offset);
                proxyControl = m_graphicsScene->addRect(event->pos().x() - offset.x()-1,event->pos().y() - offset.y()-1,w+1, h+1,tPen,tBrush);
                proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
                proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
                proxyControl->setZValue(1000000);
                QGraphicsProxyWidget * const proxy = m_graphicsScene->addWidget(newIcon);
                proxy->setParentItem(proxyControl);
            }
        }
    }
}

void MainWindow::on_actionTutorial_triggered()
{
    if(hw->isHidden())
    {
        hw->show();
    }
    else
    {
        hw->hide();
    }
}
