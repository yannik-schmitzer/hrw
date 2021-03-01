#include "helpitems.h"
#include "ui_helpitems.h"

HelpItems::HelpItems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpItems)
{
    ui->setupUi(this);
}

HelpItems::~HelpItems()
{
    delete ui;
}
