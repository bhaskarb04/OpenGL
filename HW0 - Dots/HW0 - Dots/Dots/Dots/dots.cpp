#include "glut.h"

/************** myInit ***************/
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

/************** myDisplay ************/
void myDisplay(void)
{
	// Clear the colors on the screen from a previous display
	glClear(GL_COLOR_BUFFER_BIT);

	// Now, draw something
	glBegin(GL_POINTS);
		glVertex2i(100, 50);
		glVertex2i(100, 130);
		glVertex2i(150, 130);
    glEnd();

	// this allows opengl to wait for the draw buffer to be ready in the background for the next frame
	// therefore, while the current buffer is being drawn in the current frame, a buffer is set ready to draw on frame+1
	// this call is effective only when GL_DOUBLE is enabled in glutInitDisplayMode in the main function
	// It is recommended to use glutSwapBuffers and double buffering always
	glutSwapBuffers();
}

/************** main *****************/
int main(int argc, char** argv)
{
	//	Initialize opengl & glut
	glutInit(&argc, argv);

	// Initialize display mode:
	// GLUT_SINGLE defines single buffering (i.e., display -> calculations -> display so on)
	// GLUT_DOUBLE defines double buffering (i.e., display something while do calculations in the background)
	// GLUT_RGB defines RGB color mode
	// GLUT_INDEX defines indexed color mode
	// GLUT_DEPTH defines that the display mode is 3D and depth is required
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Tell opengl how big your window size should be
	glutInitWindowSize(640, 480);

	// Tell opengl where on screen does the opengl window need to appear
	glutInitWindowPosition(100, 150);
    
	// Now tell opengl to create the opengl window
	glutCreateWindow("My first attempt");
    
    // init() consists of all the user defined initialization functions & variables
	// example, whether the lighting is enabled, what is the background color, etc
	myInit();

	// tell opengl window to draw the scene that you define in the function myDisplay()
	glutDisplayFunc(myDisplay);

	// Enter the opengl event processing loop
	// no draw events will be processed without glutMainLoop()
	// glut goes into an infinite loop that never returns. Hence the program doesnt return
	glutMainLoop();

	return 0;
}
