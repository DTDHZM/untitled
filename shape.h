#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QString>

class Shape
{
public:
    virtual ~Shape() {}
    virtual void paint(QPainter &painter) = 0;
    virtual QString toString() const = 0; // 添加虚拟方法 toString
    virtual void fromString(const QString &data) = 0; // 添加虚拟方法 fromString
};

#endif // SHAPE_H
