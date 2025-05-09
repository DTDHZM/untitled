#include "paintwidget.h"
#include "line.h"
#include "rect.h"
#include <QMouseEvent>
PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent),
      currShapeCode(Shape::Line),
      currentShape(nullptr),
      isDrawing(false)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void PaintWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    foreach (Shape *shape, shapes) {
        shape->paint(painter);
    }

    if (currentShape && isDrawing) {
        currentShape->paint(painter);
    }
}

void PaintWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        switch (currShapeCode) {
        case Shape::Line:
            currentShape = new Line;
            break;
        case Shape::Rect:
            currentShape = new Rect;
            break;
        }
        currentShape->setStart(event->pos());
        currentShape->setEnd(event->pos());
        isDrawing = true;
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
    if (isDrawing && currentShape) {
        currentShape->setEnd(event->pos());
        update();
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && currentShape) {
        shapes.append(currentShape);
        currentShape = nullptr;
        isDrawing = false;
        update();
    }
}
