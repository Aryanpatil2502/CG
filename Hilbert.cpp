//C5(B)
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;


void move(int j, int h , int &x, int &y)
{
    //urdl - urd dal
    if(j==1)
    {
        y = y - h;  // move up
    }
    else if(j==2)
    {
        x = x + h;  // move right
    }
    else if(j==3)
    {
        y = y + h;  // move down
    }
    else if(j==4)
    {
        x = x - h;  // move left
    }
    lineto(x, y);  // draw line to the new coordinates
}

//urdl - urd dal
void hilbert(int u, int r, int d, int l, int h, int i, int &x, int &y)
{
    if(i > 0)
    {
        i--;
    
        hilbert(r, u, l, d, h, i, x, y);  //are you lady 
        move(u, h, x, y); //urd
  
        hilbert(u, r, d, l, h, i, x, y);  //urdl - urd dal
        move(r, h, x, y);  //urd
      
        hilbert(u, r, d, l, h, i, x, y);  //urdl - urd dal
        move(d, h, x, y);  //urd
    
        hilbert(l, d, r, u, h, i, x, y);   //lady are you 
       
    }
}

int main()
{
    int x = 100, y = 400, n, h = 10, u = 1, r = 2, d = 3, l = 4;
    int gd = DETECT, gm;
    
    cout << "Enter the number of approximations: ";
    cin >> n;
    
    // Initialize graphics
    initgraph(&gd, &gm, NULL);
    
    moveto(x, y);  // Move to the initial coordinates
    
    hilbert(u, r, d, l, h, n, x, y);  // Draw Hilbert curve
    
    delay(50000);  // Wait for a while to view the result
    closegraph();  // Close the graphics window
    
    return 0;
}

//Test case
//5
