#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QList>
#include "shape.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

public slots:
    void setCurrentShape(Shape::Code s) { currShapeCode = s; }

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;

private:
    Shape::Code currShapeCode;
    Shape *currentShape;
    bool isDrawing;
    QList<Shape*> shapes;
};

#endif // PAINTWIDGET_H
