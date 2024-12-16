//C7
//GENERATED FULL BY CHATGPT 

#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Base class for scene objects
class SceneObject {
public:
    virtual void draw() = 0;  // Pure virtual function for drawing
};

// Derived class for the man
class Man : public SceneObject {
public:
    void draw() override {
        glColor3f(1.0, 0.0, 0.0); // Red color for the man (head and body)

        // Drawing the head (circle)
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(1.0 + 0.2 * cos(angle), 1.8 + 0.2 * sin(angle)); // Circle for the head
        }
        glEnd();

        // Drawing the body (a line)
        glBegin(GL_LINES);
        glVertex2f(1.0, 1.6); // Top of the body
        glVertex2f(1.0, 1.0); // Bottom of the body
        glEnd();

        // Drawing legs (lines)
        glBegin(GL_LINES);
        glVertex2f(1.0, 1.0); // Left leg start
        glVertex2f(0.7, 0.4); // Left leg end
        glVertex2f(1.0, 1.0); // Right leg start
        glVertex2f(1.3, 0.4); // Right leg end
        glEnd();
    }
};

// Derived class for the umbrella
class Umbrella : public SceneObject {
public:
    void draw() override {
        glColor3f(0.0, 0.0, 1.0); // Blue color for the umbrella

        // Drawing the umbrella top (a polygon)
        glBegin(GL_POLYGON);
        glVertex2f(0.8, 2.2);
        glVertex2f(1.2, 2.2);
        glVertex2f(1.0, 2.6); // Umbrella arc
        glEnd();

        // Drawing the umbrella handle (a line)
        glBegin(GL_LINES);
        glVertex2f(1.0, 1.6); // Top of the handle
        glVertex2f(1.0, 0.8); // Bottom of the handle
        glEnd();
    }
};

// Derived class for the rain
class Rain : public SceneObject {
public:
    void draw() override {
        glColor3f(0.0, 1.0, 0.0); // Green color for the rain

        // Drawing some raindrops (lines)
        for (int i = 0; i < 10; i++) {
            float x = (rand() % 500) / 100.0f;
            glBegin(GL_LINES);
            glVertex2f(x, 3.0); // Start of raindrop
            glVertex2f(x, 2.0); // End of raindrop
            glEnd();
        }
    }
};

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window

    // Create objects of derived classes
    SceneObject* man = new Man();
    SceneObject* umbrella = new Umbrella();
    SceneObject* rain = new Rain();

    // Draw the objects
    man->draw();
    umbrella->draw();
    rain->draw();

    delete man;
    delete umbrella;
    delete rain;

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background to black
    glEnable(GL_BLEND);  // Enable blending for transparency (if needed)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // Set the blending function
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Reset projection matrix

    // Set up the 2D orthographic projection
    gluOrtho2D(0, 5, 0, 5);  // Define the coordinate system
    glMatrixMode(GL_MODELVIEW);  // Switch back to modelview matrix
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);  // Set window size
    glutCreateWindow("Man Walking in the Rain with Umbrella");
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();  // Start the main loop
    return 0;
}


