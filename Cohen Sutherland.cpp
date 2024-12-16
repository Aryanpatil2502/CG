//C2 

#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;

int getcode(int x, int y)
{
    int code = 0;
    if (y > ymax) {
        code = TOP;
    }
    if (y < ymin) {
        code = BOTTOM;
    }
    if (x > xmax) {
        code = RIGHT;
    }
    if (x < xmin) {
        code = LEFT;
    }
    return code;
}

int main()
{
    int gd = DETECT, gm;
    
    // Input clipping window boundaries
    cout << "Enter the window Min & Max Size: ";
    cin >> xmin >> ymin >> xmax >> ymax;
    
    // Input coordinates of the line
    int x1, y1, x2, y2;
    cout << "Enter coordinates of the line (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    
    initgraph(&gd, &gm, NULL);
    
    // Draw clipping window first
    rectangle(xmin, ymin, xmax, ymax);
    
    // Draw the initial line
    line(x1, y1, x2, y2);

    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    int accept = 0;

    while (true)
    {
        float m = float((y2 - y1) / (x2 - x1));  // slope of the line

        if (outcode1 == 0 && outcode2 == 0)  // if both points are inside the window
        {
            accept = 1;
            break;
        }
        else if ((outcode1 & outcode2) != 0)  // if both points are outside the window in the same region
        {
            break;
        }
        else  // part of the line is inside the window
        {
            int x, y;
            int temp;
            // Choose the point outside the window
            if (outcode1 != 0) {
                temp = outcode1;
            } else {
                temp = outcode2;
            }

            // Find the intersection point with the boundary
            if (temp & TOP) {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (temp & BOTTOM) {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (temp & RIGHT) {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }
            else if (temp & LEFT) {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }

            // Replace the point outside the window with the intersection point
            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    // After clipping, display the results
    cout << "After clipping: ";
    setcolor(YELLOW);

    // Do not clear the screen until we are ready to show results
    // Only clear the screen if you want to refresh the background
    //cleardevice();  // Comment out this line if you want to keep the window visible during drawing.

    // Draw the clipping window again
    rectangle(xmin, ymin, xmax, ymax);  
    
    // Draw the clipped line (or original line if not clipped)
    if (accept) {
        line(x1, y1, x2, y2);  // Draw the clipped line in yellow
    }
    else {
        cout << "Line is completely outside the clipping window!" << endl;
    }

    // Increase delay to ensure window stays open
    delay(40000);  // Increase the delay to 40 seconds (40000 milliseconds) to observe the result

    // Close the graphics window after the delay
    closegraph();
    return 0;
}

//Test Case 
//Clipping Window: xmin = 100, ymin = 100, xmax = 400, ymax = 300
//Line: x1 = 50, y1 = 50, x2 = 450, y2 = 350
