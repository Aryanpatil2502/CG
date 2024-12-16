//C4(B)

#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

void translate(int &x, int &y, int tx, int ty)
{
    x += tx;
    y += ty;
}

void scale(int &x, int &y, int sx, int sy)
{
    x *= sx;
    y *= sy;
}

void rotate(int &x, int &y, float angle)
{
    float rad = angle * (M_PI / 180);  // Convert angle to radians
    double xnew, ynew;
    xnew = x * cos(rad) - y * sin(rad);
    ynew = x * sin(rad) + y * cos(rad);

    x = xnew;
    y = ynew;
}

void drawTriangle(int triangle[3][2]) {
    line(triangle[0][0], triangle[0][1], triangle[1][0], triangle[1][1]);
    line(triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1]);
    line(triangle[2][0], triangle[2][1], triangle[0][0], triangle[0][1]);
}

void drawRhombus(int rhombus[4][2]) {
    line(rhombus[0][0], rhombus[0][1], rhombus[1][0], rhombus[1][1]);
    line(rhombus[1][0], rhombus[1][1], rhombus[2][0], rhombus[2][1]);
    line(rhombus[2][0], rhombus[2][1], rhombus[3][0], rhombus[3][1]);
    line(rhombus[3][0], rhombus[3][1], rhombus[0][0], rhombus[0][1]);
}

int main()
{
    int triangle[3][2] = {{200, 200}, {300, 200}, {200, 100}};
    int rhombus[4][2] = {{100, 200}, {250, 200}, {300, 200}, {250, 250}};

    // Get user input before graphics initialization
    int ch;
    cout << "\n1. Translate ";
    cout << "\n2. Scaling";
    cout << "\n3. Rotate";
    cout << "\nEnter your choice: ";
    cin >> ch;

    cout << "Do you want to perform the transformation on the triangle and rhombus? (y/n): ";
    char ans;
    cin >> ans;

    // Initialize the graphics system after input
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw original shapes
    setcolor(RED);
    drawTriangle(triangle);
    drawRhombus(rhombus);

    // Perform transformations based on user input
    if (ans == 'y' || ans == 'Y') {
        switch(ch)
        {
            case 1:
                // Translate both triangle and rhombus
                for(int i = 0; i < 3; i++) {
                    translate(triangle[i][0], triangle[i][1], 100, 150);
                }
                for(int i = 0; i < 4; i++) {
                    translate(rhombus[i][0], rhombus[i][1], 100, 150);
                }

                // Redraw shapes
                setcolor(BLUE);
                drawTriangle(triangle);
                drawRhombus(rhombus);
                break;

            case 2:
                // Scale both triangle and rhombus
                for(int i = 0; i < 3; i++) {
                    scale(triangle[i][0], triangle[i][1], 1.5, 2);
                }
                for(int i = 0; i < 4; i++) {
                    scale(rhombus[i][0], rhombus[i][1], 1.5, 2);
                }

                // Redraw shapes
                setcolor(BLUE);
                drawTriangle(triangle);
                drawRhombus(rhombus);
                break;

            case 3:
                // Rotate both triangle and rhombus
                for(int i = 0; i < 3; i++) {
                    rotate(triangle[i][0], triangle[i][1], 60);
                }
                for(int i = 0; i < 4; i++) {
                    rotate(rhombus[i][0], rhombus[i][1], 45);
                }

                // Redraw shapes
                setcolor(BLUE);
                drawTriangle(triangle);
                drawRhombus(rhombus);
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    delay(100000);
    closegraph();
}

