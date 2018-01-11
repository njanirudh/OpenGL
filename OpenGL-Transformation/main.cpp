#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void changeSize(int w, int h);
void renderScene(void);
void drawSnowMan();

float angle = 0.0f;


int main(int argc, char **argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("OpenGL-Reshape");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

    // here is the idle func registration
    glutIdleFunc(renderScene);


    // enter GLUT event processing loop
    glutMainLoop();

    return 1;
}


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45,ratio,5,1000);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera
    gluLookAt(	0.0f, 0.0f, 10.0f,
                0.0f, 0.0f,  0.0f,
                0.0f, 1.0f,  0.0f);

    //Rotate the Obj
    glRotatef(angle, 1.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f,-2.0f, 0.0f);
    glVertex3f( 2.0f, 0.0f, 0.0);
    glVertex3f( 0.0f, 2.0f, 0.0);
    glEnd();

    angle+=0.01f;

    glutSwapBuffers();
}
