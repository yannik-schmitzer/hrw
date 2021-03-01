#ifndef HELPMENU_H
#define HELPMENU_H

#include <QWidget>

namespace Ui {
class HelpMenu;
}

class HelpMenu : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit HelpMenu(QWidget *parent = 0);
    ~HelpMenu();

private:
    Ui::HelpMenu *ui;
};

#endif // HELPMENU_H
