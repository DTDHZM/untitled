#include "FileHandler.h"
#include <QFile>
#include <QTextStream>

bool FileHandler::saveToFile(const QString& filePath, const LineStack& lineStack) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8"); // 设置编码为 UTF-8

    auto lines = lineStack.getAllLines();
    for (size_t i = 0; i < lines.size(); ++i) {
        const auto& line = lines[i];
        out << QString("line%1,%2,%3,%4,%5\n")
                   .arg(i + 1)
                   .arg(line.x1)
                   .arg(line.y1)
                   .arg(line.x2)
                   .arg(line.y2);
    }

    file.close();
    return true;
}

bool FileHandler::loadFromFile(const QString& filePath, LineStack& lineStack) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8"); // 设置编码为 UTF-8

    lineStack = LineStack(); // 清空原有栈

    while (!in.atEnd()) {
        QString lineStr = in.readLine();
        auto parts = lineStr.split(',');
        if (parts.size() == 5) {
            Line line;
            line.name = parts[0];
            line.x1 = parts[1].toInt();
            line.y1 = parts[2].toInt();
            line.x2 = parts[3].toInt();
            line.y2 = parts[4].toInt();
            lineStack.push(line);
        }
    }

    file.close();
    return true;
}
