#ifndef HELPITEMS_H
#define HELPITEMS_H

#include <QWidget>

namespace Ui {
class HelpItems;
}

class HelpItems : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit HelpItems(QWidget *parent = 0);
    ~HelpItems();

private:
    Ui::HelpItems *ui;
};

#endif // HELPITEMS_H
