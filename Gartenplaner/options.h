#ifndef OPTIONS_H
#define OPTIONS_H

#include <QObject>
#include <QColor>

class Options : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Enumeration constants for possible Tools.
     */
    enum Tool { RECTANGLE, CIRCLE, SELECTION, NOTHING };
    /**
     * @brief Constructor
     */
    explicit Options(QObject *parent = nullptr);
    /**
     * @brief Returns the selected fill color.
     * @return The selected fill color.
     */
    QColor fillColor() const;
    /**
     * @brief Returns the selected border color.
     * @return The selected border color.
     */
    QColor borderColor() const;
    /**
     * @brief Returns the selected tool.
     * @return The selected Tool (@sa Options::Tool).
     */
    Options::Tool selectedTool() const;
public slots:
    /**
     * @brief Sets the selected fill color equal to the given value.
     * @param value is the new selected fill color.
     */
    void setFillColor(const QColor &value);
    /**
     * @brief Sets the selected border color equal to the given value.
     * @param value is the new selected border color.
     */
    void setBorderColor(const QColor &value);
    /**
     * @brief Sets the selected tool equal to the given value.
     * @param value is the new selected tool value.
     */
    void setSelectedTool(Options::Tool value);
signals:
    /**
     * @brief Sends, if the selected tool changed.
     * @param selectedTool is the selected tool.
     */
    void selectedToolChanged(Options::Tool selectedTool);
protected:
    /**
     * @brief Holds the selected tool.
     */
    Options::Tool m_selectedTool;
    /**
     * @brief Holds the selected fill color.
     */
    QColor m_fillColor = Qt::transparent;
    /**
     * @brief Holds the selected border color.
     */
    QColor m_borderColor = Qt::black;
};

#endif // OPTIONS_H
