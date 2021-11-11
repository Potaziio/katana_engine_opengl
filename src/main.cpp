#include "../include/Window.hpp"

int main(int argc, char* args[])
{
    Window mainWindow(1400, 1000, "Katana Engine"); 
    mainWindow.run();
    mainWindow.loop();
    mainWindow.clearEverything();
    
    return 0;
}
