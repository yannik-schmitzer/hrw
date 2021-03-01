#ifndef DRAWINGCOLORSELECTOR_H
#define DRAWINGCOLORSELECTOR_H

#include <QWidget>
#include <QColor>

namespace Ui {
class DrawingColorSelector;
}

class DrawingColorSelector : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param parent is the hierarchical preciding object.
     */
    explicit DrawingColorSelector(QWidget *parent = 0);
    /**
     * @brief Destructor.
     */
    ~DrawingColorSelector();
    /**
     * @brief Returns the selected color.
     * @return The selected color.
     */
    QColor color();
public slots:
    /**
     * @brief Sets the selected color.
     * @param The desired color value.
     */
    void setColor(QColor color);
signals:
    /**
     * @brief Notifies that the selected color has changed.
     * @param color is the new color value.
     */
    void selectedColorChanged(QColor color);
private slots:
    /**
     * @brief Listener for clicks on color button.
     * @details Opens a QColorPickerDialog.
     */
    void on_pushButtonColor_clicked();
private:
    /**
     * @brief Holds the widgets ui-components.
     */
    Ui::DrawingColorSelector *ui;
};

#endif // DRAWINGCOLORSELECTOR_H
