#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();
signals:
    /**
     * @brief NewProjectDialog_accepted signal to mainwindow
     * @param w
     * @param h
     */
    void NewProjectDialog_accepted(int w, int h);

private slots:
    /**
     * @brief on_buttonBox_accepted
     */
    void on_buttonBox_accepted();

private:
    Ui::NewProjectDialog *ui;
};

#endif // NEWPROJECTDIALOG_H
