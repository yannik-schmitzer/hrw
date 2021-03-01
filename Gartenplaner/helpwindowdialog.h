#ifndef HELPWINDOWDIALOG_H
#define HELPWINDOWDIALOG_H

#include <QDialog>

namespace Ui {
class HelpWindowDialog;
}

class HelpWindowDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit HelpWindowDialog(QWidget *parent = 0);
    ~HelpWindowDialog();

private slots:
    /**
     * @brief on_pushButtonMenu_clicked - changes the shown widget
     */
    void on_pushButtonMenu_clicked();
    /**
     * @brief on_pushButtonPainting_clicked - changes the shown widget
     */
    void on_pushButtonPainting_clicked();
    /**
     * @brief on_pushButtonItems_clicked - changes the shown widget
     */
    void on_pushButtonItems_clicked();
    /**
     * @brief on_pushButtonShortcuts_clicked - changes the shown widget
     */
    void on_pushButtonShortcuts_clicked();

private:
    Ui::HelpWindowDialog *ui;
};

#endif // HELPWINDOWDIALOG_H
