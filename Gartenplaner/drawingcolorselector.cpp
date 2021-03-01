#include "drawingcolorselector.h"
#include "ui_drawingcolorselector.h"
#include <QColorDialog>

DrawingColorSelector::DrawingColorSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingColorSelector)
{
    ui->setupUi(this);
}

DrawingColorSelector::~DrawingColorSelector()
{
    delete ui;
}

QColor DrawingColorSelector::color()
{
    return ui->pushButtonColor->color();
}

void DrawingColorSelector::on_pushButtonColor_clicked()
{
    // open Color Dialog
    QColor newColor = QColorDialog::getColor(ui->pushButtonColor->color(), this, "Choose Color", QColorDialog::ShowAlphaChannel);
    // Check if the new color was confirmed (cancel press returns #000, but isValid()===false)
    if (newColor.isValid() && this->color() != newColor){
        this->setColor(newColor);
    }
}

void DrawingColorSelector::setColor(QColor color)
{
    ui->pushButtonColor->setColor(color);
    emit selectedColorChanged(color);
}
