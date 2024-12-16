//C5 (C)

#include <iostream>
#include <graphics.h>
#include <cmath>  // Use cmath instead of math.h for modern C++

using namespace std;

void koch(int x1, int y1, int x2, int y2, int it)
{
    if (it > 0)
    {
        // Calculate the 1/3 and 2/3 points
        int x3 = (2 * x1 + x2) / 3;
        int y3 = (2 * y1 + y2) / 3;
        int x4 = (2 * x2 + x1) / 3;
        int y4 = (2 * y2 + y1) / 3;

        // Calculate the apex of the equilateral triangle
        float angle = 60 * (M_PI / 180);  // Convert 60 degrees to radians
        int x = x3 + (x4 - x3) * cos(angle) - (y4 - y3) * sin(angle);
        int y = y3 + (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

        // Recursive calls
        koch(x1, y1, x3, y3, it - 1);
        koch(x3, y3, x, y, it - 1);
        koch(x, y, x4, y4, it - 1);
        koch(x4, y4, x2, y2, it - 1);
    }
    else
    {
        // Base case: draw the lines between the points
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1 = 150, y1 = 200, x2 = 400, y2 = 300;
    initgraph(&gd, &gm, NULL);  // Initialize the graphics mode

    koch(x1, y1, x2, y2, 4);  // Draw the Koch curve with 4 iterations

    delay(10000);  // Wait for 10 seconds
    closegraph();  // Close the graphics window

    return 0;
}

