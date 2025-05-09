#include "rect.h"

void Rect::paint(QPainter &painter) {
    painter.drawRect(QRect(start, end));
}
