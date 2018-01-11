#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void renderScene(void);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    /*
    Specify display color model :-
        GLUT_RGBA or GLUT_RGB – selects a RGBA window. This is the default color mode.
        GLUT_INDEX – selects a color index mode.

    The display mode also allows you to select either a single or double buffer window. The predefined constants for this are:

        GLUT_SINGLE – single buffer window
        GLUT_DOUBLE – double buffer window, required to have smooth animation.

    Specify if you want a window with a particular set of buffers:

        GLUT_ACCUM – The accumulation buffer
        GLUT_STENCIL – The stencil buffer
        GLUT_DEPTH – The depth buffer
    */
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);

    //Set the initial position and size of the screen
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);

    glutCreateWindow("GL Window");

    // register callback for rendering
    glutDisplayFunc(renderScene);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 0;
}

/* Rendering function
 * Any name can be given for this function but it has to be registered as a callback to GLUT
 */
void renderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //The primitive or primitives that will be created from vertices
    glBegin(GL_TRIANGLES);

    /*
     * The glVertex function commands are used within glBegin/glEnd pairs to specify point, line, and polygon vertices.
     * The current color, normal, and texture coordinates are associated with the vertex when glVertex is called
     */
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    //  glutSwapBuffers swaps the buffers of the current window if double buffered.
    glutSwapBuffers();
}
