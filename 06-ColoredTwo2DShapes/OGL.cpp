#include <GL/freeglut.h>

//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen

int main(int argc,char** argv)
{
	//function prototypes
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
	void initialize(void);
	void uninitialize(void);

	//code
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(800,600); //to declare initial window size
	glutInitWindowPosition(100,100); //to declare initial window position
	glutCreateWindow("Two Coloured 2D Shapes : Triangle And Square"); //open the window with "Two Coloured 2D Shapes : Triangle And Square" in the title bar

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

//	return(0); 
}

void display(void)
{

	//code

	//to clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	//###### TRIANGLE ######

	glLoadIdentity();
	glTranslatef(-1.5f,0.0f,-6.0f);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f); //red : colour of apex of triangle
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glColor3f(0.0f,1.0f,0.0f); //green : colour of left-bottom of triangle
		glVertex3f(-1.0f,-1.0f,0.0f); //left-bottom tip of triangle

		glColor3f(0.0f,0.0f,1.0f); //blue : colour of right-bottom of triangle
		glVertex3f(1.0f,-1.0f,0.0f); //right-bottom tip of triangle
	glEnd();

	//###### SQUARE ######

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);

	glBegin(GL_QUADS);
		//blue : Colour of square
		glColor3f(0.0f,0.0f,1.0f);
		// square
		glVertex3f(1.0f,1.0f,0.0f); //right-top of square
		glVertex3f(-1.0f,1.0f,0.00f); //left-top of square
		glVertex3f(-1.0f,-1.0f,0.0f); //left-bottom of square
		glVertex3f(1.0f,-1.0f,0.00f); //right-bottom of square
	glEnd();

	//to process buffered OpenGL Routines
	glFlush();
}

void initialize(void)
{
	//code
	//to select clearing (background) clear
	glClearColor(0.0f,0.0f,0.0f,0.0f); //black
}

void keyboard(unsigned char key,int x,int y)
{
	//code
	switch(key)
	{
	case 27: // Escape
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if(bFullscreen==false)
		{
			glutFullScreen();
			bFullscreen=true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen=false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button,int state,int x,int y)
{
	//code
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void resize(int width,int height)
{
    //code
	if(height==0)
		height=1;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void uninitialize(void)
{
	//code
}
