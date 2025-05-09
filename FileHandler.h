﻿#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "LineStack.h"

class FileHandler {
public:
    static bool saveToFile(const QString& filePath, const LineStack& lineStack);
    static bool loadFromFile(const QString& filePath, LineStack& lineStack);
};

#endif // FILEHANDLER_H
