#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QToolBar>
#include <QActionGroup>
#include <QStatusBar>
#include <QLabel>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建工具栏
    QToolBar *bar = new QToolBar(this);
    addToolBar(bar);

    // 创建动作组
    QActionGroup *group = new QActionGroup(bar);

    // 直线动作
    QAction *drawLineAction = new QAction(QIcon(":/picture/line.png"), "Line", bar);
    drawLineAction->setCheckable(true);
    drawLineAction->setChecked(true);
    drawLineAction->setToolTip("画线");
    drawLineAction->setStatusTip("画线");
    group->addAction(drawLineAction);
    bar->addAction(drawLineAction);

    // 矩形动作
    QAction *drawRectAction = new QAction(QIcon(":/picture/rect.png"), "Rectangle", bar);
    drawRectAction->setCheckable(true);
    drawRectAction->setToolTip("画面");
    drawRectAction->setStatusTip("画面");
    group->addAction(drawRectAction);
    bar->addAction(drawRectAction);

    // 创建画板
    paintWidget = new PaintWidget(this);
    setCentralWidget(paintWidget);

    // 信号与槽连接
    connect(drawLineAction, &QAction::triggered, this, &MainWindow::drawLineActionTriggered);
    connect(drawRectAction, &QAction::triggered, this, &MainWindow::drawRectActionTriggered);
    connect(this, &MainWindow::changeCurrentShape, paintWidget, &PaintWidget::setCurrentShape);

    // 状态栏
    statusBar()->addWidget(new QLabel("Ready"));
}

void MainWindow::drawLineActionTriggered() {
    emit changeCurrentShape(Shape::Line);
}

void MainWindow::drawRectActionTriggered() {
    emit changeCurrentShape(Shape::Rect);
}

MainWindow::~MainWindow() {
    delete ui;
}
