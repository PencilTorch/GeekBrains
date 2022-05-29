#include "Bridge.h"

int main() {
    DrawingBrush db;
    db.drawRectangle(200);

    DrawingPencil dp;
    dp.drawRectangle(200);

    std::cin.get();

    return 0;
}
