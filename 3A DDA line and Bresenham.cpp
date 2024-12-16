//C3 (A)

#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void Bresenham(int xcen, int ycen, int r) {
    int d, x, y;
    d = 3 - 2 * r;
    x = 0;
    y = r;

    while (y >= x) {
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        // Draw the eight symmetric points of the circle
        putpixel(xcen + x, ycen + y, YELLOW);
        putpixel(xcen - x, ycen + y, YELLOW);
        putpixel(xcen + x, ycen - y, YELLOW);
        putpixel(xcen - x, ycen - y, YELLOW);
        putpixel(xcen + y, ycen + x, YELLOW);
        putpixel(xcen - y, ycen + x, YELLOW);
        putpixel(xcen + y, ycen - x, YELLOW);
        putpixel(xcen - y, ycen - x, YELLOW);
        x++;
    }
}

void DDAline(int x1, int y1, int x2, int y2) {
    float dx, dy, len, x, y;
    int i = 1;
    x = x1;
    y = y1;

    // Calculate differences
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    len = max(dx, dy);

    // Calculate step values
    float xic = (x2 - x1) / len;
    float yic = (y2 - y1) / len;

    // Draw the line pixel by pixel
    while (i <= len) {
        putpixel(round(x), round(y), RED);
        x = x + xic;
        y = y + yic;
        i++;
    }
}

int main() {
    int gd = DETECT, gm;
    int xcen, ycen, r;

    // Ask the user for circle details
    cout << "Enter the coordinates of circle: ";
    cin >> xcen >> ycen >> r;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    

    // Draw two concentric circles with different radii
    Bresenham(xcen, ycen, r);
    Bresenham(xcen, ycen, r / 2);

    // Draw a triangle inscribed inside the circle
    DDAline(xcen, ycen - r, xcen - (0.866 * r), ycen + (r / 2));  // Left side
    DDAline(xcen, ycen - r, xcen + (0.866 * r), ycen + (r / 2));  // Right side
    DDAline(xcen - (0.866 * r), ycen + (r / 2), xcen + (0.866 * r), ycen + (r / 2)); // Base

    // Delay for visibility (1000 ms = 1 second)
    delay(1000);

    // Close graphics mode
    closegraph();

    return 0;
}

//TEST CASE
//300 300 100
