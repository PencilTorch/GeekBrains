#include "Command.h"

int main() {
    Invoker inv;
    inv.ShowState();
    inv.onWard(1, Colors::RED);
    inv.ShowState();
    inv.onWard(1, Colors::BLUE);
    inv.ShowState();
    inv.onWard(1, Colors::WHITE);
    inv.ShowState();
    inv.onWard(0);
    inv.ShowState();
    inv.backWard();
    inv.ShowState();
    inv.backWard();
    inv.ShowState();
    inv.backWard();
    inv.ShowState();
    inv.backWard();
    inv.ShowState();

    return 0;
}