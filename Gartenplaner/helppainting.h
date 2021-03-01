#ifndef HELPPAINTING_H
#define HELPPAINTING_H

#include <QWidget>

namespace Ui {
class HelpPainting;
}

class HelpPainting : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit HelpPainting(QWidget *parent = 0);
    ~HelpPainting();

private:
    Ui::HelpPainting *ui;
};

#endif // HELPPAINTING_H
