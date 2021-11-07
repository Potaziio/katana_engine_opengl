#include "../include/Window.hpp"

int main(int argc, char* args[])
{
    Window mainWindow(1200, 800, "Katana Engine"); 
    mainWindow.run();
    mainWindow.loop();
    mainWindow.clearGLFW();

    return 0;
}
