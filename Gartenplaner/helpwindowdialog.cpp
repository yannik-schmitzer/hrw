#include "helpwindowdialog.h"
#include "ui_helpwindowdialog.h"

HelpWindowDialog::HelpWindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindowDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Tutorial");
    this->setFixedSize(800,600);
    ui->widgetMenu->setVisible(true);
    ui->widgetPainting->setVisible(false);
    ui->widgetItems->setVisible(false);
    ui->widgetShortcuts->setVisible(false);
}

HelpWindowDialog::~HelpWindowDialog()
{
    delete ui;
}

void HelpWindowDialog::on_pushButtonMenu_clicked()
{
    ui->widgetMenu->setVisible(true);
    ui->widgetPainting->setVisible(false);
    ui->widgetItems->setVisible(false);
    ui->widgetShortcuts->setVisible(false);
}

void HelpWindowDialog::on_pushButtonPainting_clicked()
{
    ui->widgetMenu->setVisible(false);
    ui->widgetPainting->setVisible(true);
    ui->widgetItems->setVisible(false);
    ui->widgetShortcuts->setVisible(false);
}

void HelpWindowDialog::on_pushButtonItems_clicked()
{
    ui->widgetMenu->setVisible(false);
    ui->widgetPainting->setVisible(false);
    ui->widgetItems->setVisible(true);
    ui->widgetShortcuts->setVisible(false);
}

void HelpWindowDialog::on_pushButtonShortcuts_clicked()
{
    ui->widgetMenu->setVisible(false);
    ui->widgetPainting->setVisible(false);
    ui->widgetItems->setVisible(false);
    ui->widgetShortcuts->setVisible(true);
}
