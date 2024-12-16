//C1

#include<iostream>
#include<graphics.h>
using namespace std;

struct edge {
    int x1, y1, x2, y2, flag;
};

int main() {
    int gd = DETECT, gm, n, i, j, k;
    struct edge ed[10], temped;
    float dx, dy, m[10], x_int[10], inter_x[10];
    int x[10], y[10], ymax = 0, ymin = 480, yy, temp;

    // Read the number of vertices of the polygon
    cout << "Enter the no. of vertices of the graph: ";
    cin >> n;

    // Check if the number of vertices is valid (greater than or equal to 3)
    if (n < 3) {
        cout << "A polygon must have at least 3 vertices. Exiting." << endl;
        return 0;
    }

    // Read the vertices of the polygon and find ymax and ymin
    cout << "Enter the vertices (x y) format:" << endl;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        // Update ymax and ymin
        if (y[i] > ymax)
            ymax = y[i];
        if (y[i] < ymin)
            ymin = y[i];

        // Store the vertices in the edge structure
        ed[i].x1 = x[i];
        ed[i].y1 = y[i];
    }

    // Initialize graphics
    initgraph(&gd, &gm, NULL);

    // Store the edge information
    cout << "\nEdge Information:\n";
    for (i = 0; i < n - 1; i++) {
        ed[i].x2 = ed[i + 1].x1;
        ed[i].y2 = ed[i + 1].y1;
        ed[i].flag = 0;
        cout << "(" << ed[i].x1 << ", " << ed[i].y1 << ") (" << ed[i].x2 << ", " << ed[i].y2 << ")\n";
    }

    // Closing the polygon by connecting the last vertex to the first vertex
    ed[i].x2 = ed[0].x1;
    ed[i].y2 = ed[0].y1;
    ed[i].flag = 0;
    cout << "(" << ed[i].x1 << ", " << ed[i].y1 << ") (" << ed[i].x2 << ", " << ed[i].y2 << ")\n";

    // Check for y1 > y2 and swap the coordinates if necessary
    cout << "\nUpdated Edge Information:\n";
    for (i = 0; i < n; i++) {
        if (ed[i].y1 < ed[i].y2) {
            // Swap x1, y1 with x2, y2
            temp = ed[i].x1;
            ed[i].x1 = ed[i].x2;
            ed[i].x2 = temp;
            temp = ed[i].y1;
            ed[i].y1 = ed[i].y2;
            ed[i].y2 = temp;
        }
        cout << "(" << ed[i].x1 << ", " << ed[i].y1 << ") (" << ed[i].x2 << ", " << ed[i].y2 << ")\n";
    }

    // Draw the polygon
    for (i = 0; i < n; i++) {
        line(ed[i].x1, ed[i].y1, ed[i].x2, ed[i].y2);
    }

    // Calculate 1/slope of each edge
    for (i = 0; i < n; i++) {
        dx = ed[i].x2 - ed[i].x1;
        dy = ed[i].y2 - ed[i].y1;

        // Calculate slope (m) or handle vertical lines
        if (dy == 0) {
            m[i] = 0;
        } else {
            m[i] = dx / dy;
        }

        inter_x[i] = ed[i].x1;
    }

    yy = ymax;

    // Working with active edges
    while (yy > ymin) {
        // Mark edges as active or not based on y values
        for (i = 0; i < n; i++) {
            if (yy > ed[i].y2 && yy <= ed[i].y1)
                ed[i].flag = 1; // Active edge
            else
                ed[i].flag = 0; // Not an active edge
        }

        // Collect x intersection points of active edges
        j = 0;
        for (i = 0; i < n; i++) {
            if (ed[i].flag == 1) {
                if (yy == ed[i].y1) {
                    x_int[j] = ed[i].x1;
                    j++;
                } else {
                    x_int[j] = inter_x[i] + (-m[i]);
                    inter_x[i] = x_int[j];
                    j++;
                }
            }
        }

        // Sorting the x intersections
        for (i = 0; i < j; i++) {
            for (k = 0; k < j - 1; k++) {
                if (x_int[k] > x_int[k + 1]) {
                    temp = (int)x_int[k];
                    x_int[k] = x_int[k + 1];
                    x_int[k + 1] = temp;
                }
            }
        }

        // Extracting pairs of values to draw lines
        for (i = 0; i < j; i = i + 2) {
            setcolor(GREEN);
            line((int)x_int[i], yy, (int)x_int[i + 1], yy);
        }

        yy--; // Move to the next y level
        delay(50);
    }

    delay(10000);
    closegraph();
    return 0;
}



/*
no of vertices 5
Enter the vertices 80 20, 100 80, 150 60,130 200,40 250
*/
