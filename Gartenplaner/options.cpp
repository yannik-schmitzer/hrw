#include "options.h"

Options::Options(QObject *parent) : QObject(parent)
{

}

QColor Options::fillColor() const
{
    return m_fillColor;
}

void Options::setFillColor(const QColor &value)
{
    m_fillColor = value;
}

QColor Options::borderColor() const
{
    return m_borderColor;
}

void Options::setBorderColor(const QColor &value)
{
    m_borderColor = value;
}

Options::Tool Options::selectedTool() const
{
    return m_selectedTool;
}

void Options::setSelectedTool(Options::Tool value)
{
    // set a new val only
    if (value != this->selectedTool()){
        m_selectedTool = value;
        emit selectedToolChanged(m_selectedTool);
    }
}
