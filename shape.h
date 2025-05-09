#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPainter>

class Shape
{
public:
    enum Code { Line, Rect };
    Shape();
    virtual ~Shape() = default;
    void setStart(const QPoint &s) { start = s; }
    void setEnd(const QPoint &e) { end = e; }
    QPoint startPoint() const { return start; }
    QPoint endPoint() const { return end; }
    virtual void paint(QPainter &painter) = 0;

protected:
    QPoint start;
    QPoint end;
};

#endif // SHAPE_H
