#ifndef HELPSHORTCUTS_H
#define HELPSHORTCUTS_H

#include <QWidget>

namespace Ui {
class HelpShortcuts;
}

class HelpShortcuts : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit HelpShortcuts(QWidget *parent = 0);
    ~HelpShortcuts();

private:
    Ui::HelpShortcuts *ui;
};

#endif // HELPSHORTCUTS_H
