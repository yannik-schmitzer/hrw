#include "drawingtoolselector.h"
#include "ui_drawingtoolselector.h"

DrawingToolSelector::DrawingToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingToolSelector)
{
    ui->setupUi(this);
}

DrawingToolSelector::~DrawingToolSelector()
{
    delete ui;
}

void DrawingToolSelector::on_pushButtonCircle_clicked()
{
    m_selectedTool = Options::Tool::CIRCLE;
    emit selectedToolChanged(m_selectedTool);
}

void DrawingToolSelector::on_pushButtonRect_clicked()
{
    m_selectedTool = Options::Tool::RECTANGLE;
    emit selectedToolChanged(m_selectedTool);
}

Options::Tool DrawingToolSelector::selectedTool() const
{
    return m_selectedTool;
}

void DrawingToolSelector::setSelectedTool(const Options::Tool selectedTool)
{
    if (m_selectedTool != selectedTool){
        // set new tool
        m_selectedTool = selectedTool;
        // uncheck everything
        ui->pushButtonCircle->setChecked(false);
        ui->pushButtonRect->setChecked(false);
        // check selected tool
        switch (m_selectedTool){
            case Options::Tool::RECTANGLE: {
                ui->pushButtonRect->setChecked(true);
                break;
            }
            case Options::Tool::CIRCLE: {
                ui->pushButtonCircle->setChecked(true);
                break;
            }
            default: break;
        }
        emit selectedToolChanged(m_selectedTool);
    }
}
