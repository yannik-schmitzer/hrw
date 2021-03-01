#ifndef VIEWTEXT_H
#define VIEWTEXT_H

#include <QWidget>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

namespace Ui {
class ViewText;
}

class ViewText : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent is the hierarchical preciding object and is null by default
     */
    explicit ViewText(QWidget *parent = 0);
    ~ViewText();
    /**
     * @brief mousePressEvent - ghosts dragging object
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);
private slots:
    /**
     * @brief on_lineEdit_textChanged changes draggable labels text
     * @param arg1
     */
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::ViewText *ui;
};

#endif // VIEWTEXT_H
