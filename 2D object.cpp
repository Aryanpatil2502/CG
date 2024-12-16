//C4(A)

//NOTE - 
//1)FOR SCALING ORIGINAL LINE AND SCALED LINE WILL OVERLAP EACH OTHER SO ONLY SCALED LINE WILL BE VISIBLE
//2) FOR TRANSLATION ENTER BIG TX AND TY TO SEE BOTH LINES SEPERATED
//3) DO WHILE IS REMOVED BECAUSE CODE WILL NOT WORK WITH IT AS CIN SHOULD COME BEFORE INITGRAPH

#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

class Transformation {
public:
    int x1, y1, x2, y2;

    void accept() {
        // Accept input coordinates here before initgraph()
        cout << "Enter x1: ";
        cin >> x1;
        cout << "Enter y1: ";
        cin >> y1;
        cout << "Enter x2: ";
        cin >> x2;
        cout << "Enter y2: ";
        cin >> y2;
    }

    void drawLine() {
        // This function will draw the initial line after initgraph()
        line(x1, y1, x2, y2);
        
    }

    void translate(int tx, int ty) {
        
        line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
        delay(1000);  // reduced delay for better experience
    }

    void scale(int sx, int sy) {
        
        line(x1 * sx, y1 * sy, x2 * sx, y2 * sy);
        delay(1000);  // reduced delay for better experience
    }

    void Rotation(double angle) {
        int rx1, ry1, rx2, ry2;
        double s, c;
        
        angle = angle * (M_PI / 180);  // Convert angle to radians
        c = cos(angle);
        s = sin(angle);

        // Find midpoint
        int mx = (x1 + x2) / 2;
        int my = (y1 + y2) / 2;

        // Translate to origin
        int tx1 = x1 - mx;
        int ty1 = y1 - my;
        int tx2 = x2 - mx;
        int ty2 = y2 - my;

        // Rotate the coordinates
        rx1 = floor(tx1 * c - ty1 * s);
        ry1 = floor(tx1 * s + ty1 * c);
        rx2 = floor(tx2 * c - ty2 * s);
        ry2 = floor(tx2 * s + ty2 * c);

        // Translate back to original position
        rx1 += mx;
        ry1 += my;
        rx2 += mx;
        ry2 += my;

        line(rx1, ry1, rx2, ry2);
    }
};

int main() {
    // Create the Transformation object
    Transformation t;

    // Accept all the inputs before initgraph() is called
    t.accept();

    // Get the menu choices before initializing the graphics system
    int ch;
    char ans = 'y';  // Initialize the ans variable

    cout << "\n1. Translate";
    cout << "\n2. Scaling";
    cout << "\n3. Rotate";
    cout << "\nEnter your choice: ";
    cin >> ch;
    int tx, ty;
    int sx, sy;
    double angle;
    if(ch==1){
        
        cout << "Enter tx: ";
        cin >> tx;
        cout << "Enter ty: ";
        cin >> ty;
    }
    else if(ch==2){
        
        cout << "Enter sx: ";
        cin >> sx;
        cout << "Enter sy: ";
        cin >> sy;
    }
    else if(ch==3){
        
        cout << "Enter the angle: ";
        cin >> angle;
    }
    cout << "\nDo you want to continue (y/n)? ";
    cin >> ans;

    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw the initial line after initgraph() is called
    t.drawLine();
    

    // Perform the appropriate transformation based on the user's choice
    if (ans == 'y' || ans == 'Y') {
        switch (ch) {
            case 1: t.translate(tx,ty);
                    break;
            case 2: t.scale(sx,sy);
                    break;
            case 3: t.Rotation(angle);
                    break;
            default: cout << "Invalid choice. Try again!";
        }
    }

    delay(10000);  // reduced delay for better experience
    closegraph();
}

//test case -
//50 50 150 150 
//translate - 200 200
//scale - 2 2
//rotate - 30
