#include "viewtext.h"
#include "ui_viewtext.h"

ViewText::ViewText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewText)
{
    ui->setupUi(this);
}

ViewText::~ViewText()
{
    delete ui;
}

void ViewText::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
            if (!child)
                return;

        QMimeData *mimeData = new QMimeData;
        mimeData->setText(ui->labelText->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setHotSpot(event->pos() - child->pos());

        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
            child->close();
        } else {
            child->show();
            child->setText(ui->labelText->text());
        }
}

void ViewText::on_lineEdit_textChanged(const QString &arg1)
{
    ui->labelText->setText(ui->lineEdit->text());
}
