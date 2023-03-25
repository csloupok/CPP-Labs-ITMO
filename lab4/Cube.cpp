#include "Cube.h"

int main() {
    Cube cube;
    cube.read();
    cube.console();
    cube.scramble();
    cube.console();
    cube.solve();
    cube.console();
    return 0;
}