#include "line.h"

void Line::paint(QPainter &painter) {
    painter.drawLine(start, end);
}
