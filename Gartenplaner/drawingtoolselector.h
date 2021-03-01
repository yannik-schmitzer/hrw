#ifndef DRAWINGTOOLSELECTOR_H
#define DRAWINGTOOLSELECTOR_H

#include <QWidget>
#include "options.h"

namespace Ui {
class DrawingToolSelector;
}

class DrawingToolSelector : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param parent is the hierarchical preciding object.
     */
    explicit DrawingToolSelector(QWidget *parent = 0);
    /**
     * @brief Destructor.
     */
    ~DrawingToolSelector();
    /**
     * @brief Returns the selected tool.
     * @return The selected tool.
     */
    Options::Tool selectedTool() const;
public slots:
    /**
     * @brief Sets the selected tool.
     * @param selectedTool is the new tool value.
     */
    void setSelectedTool(const Options::Tool selectedTool);
signals:
    /**
     * @brief Notifies if the tool value has changed.
     * @param selectedTool is the new tool value.
     */
    void selectedToolChanged(Options::Tool selectedTool);
private slots:
    /**
     * @brief Reacts on Circle Button click.
     * @details Sets the selected tool to Circle.
     */
    void on_pushButtonCircle_clicked();
    /**
     * @brief Reacts on Rectangle Button click.
     * @details Sets the selected tool to Rectange.
     */
    void on_pushButtonRect_clicked();
protected:
    /**
     * @brief Holds the selected tool.
     */
    Options::Tool m_selectedTool;
private:
    /**
     * @brief Holds the widgets ui-components.
     */
    Ui::DrawingToolSelector *ui;
};

#endif // DRAWINGTOOLSELECTOR_H
