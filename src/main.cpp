#include <iostream>
#include "engine/engineMain.h"

int main()  {
    Engine engine = Engine("SlimeJump");
    engine.createWindow();
    std::cout << "Hello World" << std::endl;
    return 0;
}