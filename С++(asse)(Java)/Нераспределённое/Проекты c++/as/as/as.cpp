#include <ostream>
#include "Winuser.h"

// Gets the position of the mouse pointer and prints it to the console
void mousePosition()
{
POINT pt;
GetCursorPos(&pt); // Captures current mouse position
std::cout << "X Coordinate : " << pt.x << std::endl;
std::cout << "Y Coordinate : " << pt.y << std::endl;
}

int main()
{
mousePosition();
return 0;
}