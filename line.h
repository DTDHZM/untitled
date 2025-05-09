#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{
public:
    void paint(QPainter &painter) override;
};

#endif // LINE_H
