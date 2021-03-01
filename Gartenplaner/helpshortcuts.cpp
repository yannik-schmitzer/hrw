#include "helpshortcuts.h"
#include "ui_helpshortcuts.h"

HelpShortcuts::HelpShortcuts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpShortcuts)
{
    ui->setupUi(this);
}

HelpShortcuts::~HelpShortcuts()
{
    delete ui;
}
