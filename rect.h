#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect : public Shape
{
public:
    void paint(QPainter &painter) override;
};

#endif // RECT_H
