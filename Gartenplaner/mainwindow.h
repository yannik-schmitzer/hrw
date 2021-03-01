#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QResizeEvent>
#include <QFileDialog>
#include "rectangle.h"
#include "options.h"
#include "drawnobjectsmap.h"
#include "graphicsscene.h"
#include "newprojectdialog.h"
#include "helpwindowdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param parent is null by default, could be another (window-)widget.
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
      * @brief Destuctor.
      */
    ~MainWindow();

 protected:
    /**
     * @brief Reacts on Window-Resizing.
     * @details Resizes the GraphicsScene to fit in GraphicsView.
     * @param event is the resize event.
     */
    void resizeEvent(QResizeEvent *event);
 private slots:
    /**
     * @brief Adds a GraphicsObject to the Canvas, using the currently selected DrawingOptions.
     * @details This method is called in MainWindow::on_actionAddObject_triggered and in MainWindow::on_pushButtonAdd_clicked. <br>
     * The current MainWindow::m_drawingOptions are used to create a new Draw::GraphicsObject. <br>
     * If no drawable Tool is selected, nothing happens.
     */
    void addGraphicsObject();
    /**
     * @brief Partly updates the ui for tool related components.
     * @details This method updates the (graphical) selection in the Toolbar and in the menu.
     */
    void updateUI_Tools();
    /**
     * @brief On "Open"-Action reacting slot.
     * @details Leads to a Debugger-Log.
     */
    void on_actionOpen_triggered();
    /**
     * @brief On "Open"-Action reacting slot.
     * @details Leads to a Debugger-Log.
     */
    void on_actionSave_triggered();
    /**
     * @brief On "Rectangle"-Action reacting slot.
     * @details Sets the tool in MainWindow::m_drawingOptions to rectangle.
     */
    void on_actionRectangle_triggered();
    /**
     * @brief On "Circle"-Action reacting slot.
     * @details Sets the tool in MainWindow::m_drawingOptions to circle.
     */
    void on_actionCircle_triggered();
    /**
     * @brief mousePressed from graphicsscene
     * @param mouseX
     * @param mouseY
     */
    void mousePressed(int mouseX, int mouseY);
    /**
     * @brief mouseReleased from graphicsscene
     * @param mouseX
     * @param mouseY
     */
    void mouseReleased(int mouseX, int mouseY);
    /**
     * @brief mouseMoved from graphicsscene
     * @param mouseX
     * @param mouseY
     */
    void mouseMoved(int mouseX, int mouseY);
    /**
     * @brief on_actionNew_triggered - opens dialog for new project
     */
    void on_actionNew_triggered();
    /**
     * @brief New_Project sets new view/scene
     * @param w
     * @param h
     */
    void New_Project(int w, int h);
    /**
     * @brief on_pushButtonFlowers_clicked - changes shown widget
     */
    void on_pushButtonFlowers_clicked();
    /**
     * @brief on_pushButtonBushes_clicked - changes shown widget
     */
    void on_pushButtonBushes_clicked();
    /**
     * @brief on_pushButtonTrees_clicked - changes shown widget
     */
    void on_pushButtonTrees_clicked();
    /**
     * @brief on_actionDelete_Object_triggered - deletes selected object
     */
    void on_actionDelete_Object_triggered();
    /**
     * @brief on_pushButtonText_clicked - changes shown widget
     */
    void on_pushButtonText_clicked();
    /**
     * @brief dropEvent from graphicsview - creates dropped object
     * @param event
     */
    void dropEvent(QDropEvent *event);
    /**
     * @brief on_actionTutorial_triggered - opens dialog for tutorial
     */
    void on_actionTutorial_triggered();

private:
    /**
     * @brief hold all GUI elements
     * @details the form classes (classes with a *.ui-file) reference their ui-files via the ui-object
     */
    Ui::MainWindow *ui;
    /**
     * @brief Holds the app's current drawing state.
     * @details The selected border color, fill color and tool are saved in this object (@sa Draw::Options).
     */
    Options *m_drawingOptions;
    /**
     * @brief Holds all GraphicObjects, which were added to the m_graphicsScene
     * @details This map is used in print functions like MainWindow::on_actionPrint_triggered or Mai<br>
     * Window::on_pushButtonPrintObjects_clicked
     */
    DrawnObjectsMap *m_drawnObjectsMap;
    /**
     * @brief Holds the graphics scene
     * @details The scene (list of drawable objects, @sa GraphicsObject) is rendered in Canvas/GraphicsView
     */
    GraphicsScene *m_graphicsScene;
    /**
     * @brief Holds the New Project dialog
     */
    NewProjectDialog *np;
    /**
     * @brief Holds the Help Window dialog
     */
    HelpWindowDialog *hw;

    /**
     * @brief m_startX,m_startY,m_endX,m_endY,m_w,m_h
     */
    int m_startX,m_startY,m_endX,m_endY,m_w,m_h = 0;
    /**
     * @brief m_sceneW, m_sceneH
     */
    int m_sceneW, m_sceneH = 300;
};

#endif // MAINWINDOW_H
