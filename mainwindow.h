#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QToolBar>
#include <QActionGroup>
#include "paintwidget.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void changeCurrentShape(Shape::Code newShape);

private slots:
    void drawLineActionTriggered();
    void drawRectActionTriggered();

private:
    Ui::MainWindow *ui;
    PaintWidget *paintWidget;
};

#endif // MAINWINDOW_H
