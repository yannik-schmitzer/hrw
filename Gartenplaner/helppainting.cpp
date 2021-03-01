#include "helppainting.h"
#include "ui_helppainting.h"

HelpPainting::HelpPainting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpPainting)
{
    ui->setupUi(this);
}

HelpPainting::~HelpPainting()
{
    delete ui;
}
