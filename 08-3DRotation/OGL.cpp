#include <GL/freeglut.h>

//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen

GLfloat angleTri=0.0f; //angle of rotation of Pyramid
GLfloat angleSquare=0.0f; //angle of rotation of Cube

int main(int argc,char** argv)
{
	//function prototypes
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
    void spin(void);
	void initialize(void);
	void uninitialize(void);

	//code
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(800,600); //to declare initial window size
	glutInitWindowPosition(100,100); //to declare initial window position
	glutCreateWindow("3D Rotation : Pyramid And Cube"); //open the window with "3D Rotation : Pyramid And Cube" in the title bar

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glutCloseFunc(uninitialize);

	glutMainLoop();

//	return(0); 
}

void display(void)
{
	//code
	//to clear all pixels
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ###### PYRAMID ######

	glLoadIdentity();
	glTranslatef(-1.5f,0.0f,-6.0f);
	glRotatef(angleTri,0.0f,1.0f,0.0f);

	glBegin(GL_TRIANGLES);
		//NOTE : EACH FACE OF A PYRAMID (EXCEPT THE BASE/BOTTOM) IS A TRIANGLE

	    //****FRONT FACE****
		glColor3f(1.0f,0.0f,0.0f); //red : Colour of apex triangle
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glColor3f(0.0f,1.0f,0.0f); //green : Colour of left-bottom tip of triangle
		glVertex3f(-1.0f,-1.0f,1.0f); //left-bottom tip of triangle

		glColor3f(0.0f,0.0f,1.0f); //blue : Colour of right-bottom tip of triangle
		glVertex3f(1.0f,-1.0f,1.0f); //right-bottom tip of triangle

		//****RIGHT FACE****
		glColor3f(1.0f,0.0f,0.0f); //red : Colour of apex of triangle
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glColor3f(0.0f,0.0f,1.0f); //blue : Colour of left-bottom tip of triangle
		glVertex3f(1.0f,-1.0f,1.0f); //left-bottom tip of triangle

		glColor3f(0.0f,1.0f,0.0f); //green : Colour of right-bottom tip of triangle
		glVertex3f(1.0f,-1.0f,-1.0f); //right-bottom tip of triangle

		//****BACK FACE****
		glColor3f(1.0f,0.0f,0.0f); //red : Colour of apex triangle
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glColor3f(0.0f,1.0f,0.0f); //green : Colour of left-bottom tip of triangle
		glVertex3f(1.0f,-1.0f,-1.0f); //left-bottom tip of triangle

		glColor3f(0.0f,0.0f,1.0f); //blue : Colour of right-bottom tip of triangle
		glVertex3f(-1.0f,-1.0f,-1.0f); //right-bottom tip of triangle

		//****LEFT FACE****
		glColor3f(1.0f,0.0f,0.0f); //red : Colour of apex of triangle
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glColor3f(0.0f,0.0f,1.0f); //blue : Colour of left-bottom tip of triangle
		glVertex3f(-1.0f,-1.0f,-1.0f); //left-bottom tip of triangle

		glColor3f(0.0f,1.0f,0.0f); //green : Colour of rigt-bottom tip of triangle
		glVertex3f(-1.0f,-1.0f,1.0f); //right-bottom tip of triangle
	glEnd();

	// ###### CUBE ######

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);
	glScalef(0.75f,0.75f,0.75f);
	glRotatef(angleSquare,1.0f,1.0f,1.0f);

	glBegin(GL_QUADS);
		//NOTE : EACH FACE OF A CUBE IS A SQUARE

	    //****TOP FACE****
		glColor3f(1.0f,0.0f,0.0f); //red : Colour of top face
		glVertex3f(1.0f,1.0f,-1.0f); //right-top of top face
		glVertex3f(-1.0f,1.0f,-1.0f); //left-top of top face
		glVertex3f(-1.0f,1.0f,1.0f); //left-bottom of top face
		glVertex3f(1.0f,1.0f,1.0f); //right-bottom of top face

		//****BOTTOM FACE****
		glColor3f(0.0f,1.0f,0.0f); //green : Colour of bottom face
		glVertex3f(1.0f,-1.0f,-1.0f); //right-top of bottom face
		glVertex3f(-1.0f,-1.0f,-1.0f); //left-top of bottom face
		glVertex3f(-1.0f,-1.0f,1.0f); //left-bottom of bottom face
		glVertex3f(1.0f,-1.0f,1.0f); //right-bottom of bottom face

		//****FRONT FACE****
		glColor3f(0.0f,0.0f,1.0f); //blue : Colour of front face
		glVertex3f(1.0f,1.0f,1.0f); //right-top of front face
		glVertex3f(-1.0f,1.0f,1.0f); //left-top of front face
		glVertex3f(-1.0f,-1.0f,1.0f); //left-bottom of front face
		glVertex3f(1.0f,-1.0f,1.0f); //right-bottom of front face

		//****BACK FACE****
		glColor3f(1.0f,1.0f,0.0f); //yellow : Colour of back face
		glVertex3f(1.0f,1.0f,-1.0f); //right-top of back face
		glVertex3f(-1.0f,1.0f,-1.0f); //left-top of back face
		glVertex3f(-1.0f,-1.0f,-1.0f); //left-bottom of back face
		glVertex3f(1.0f,-1.0f,-1.0f); //right-bottom of back face

		//****LEFT FACE****
		glColor3f(0.0f,1.0f,1.0f); //cyan : Colour of left face
		glVertex3f(-1.0f,1.0f,1.0f); //right-top of back face
		glVertex3f(-1.0f,1.0f,-1.0f); //left-top of back face
		glVertex3f(-1.0f,-1.0f,-1.0f); //left-bottom of back face
		glVertex3f(-1.0f,-1.0f,1.0f); //right-bottom of back face

		//****RIGHT FACE****
		glColor3f(1.0f,0.0f,1.0f); //magenta : Colour of right face
		glVertex3f(1.0f,1.0f,-1.0f); //right-top of back face
		glVertex3f(1.0f,1.0f,1.0f); //left-top of back face
		glVertex3f(1.0f,-1.0f,1.0f); //left-bottom of back face
		glVertex3f(1.0f,-1.0f,-1.0f); //right-bottom of back face

	glEnd();
	
	//to process buffered OpenGL Routines
	glutSwapBuffers();
}

void initialize(void)
{
	//code
	glShadeModel(GL_SMOOTH);
	// set background clearing color to black
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	// set-up depth buffer
	glClearDepth(1.0f);
	// enable depth testing
	glEnable(GL_DEPTH_TEST);
	// depth test to do
	glDepthFunc(GL_LEQUAL);
	// set really nice percpective calculations ?
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
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

void spin(void)
{
	// code
	angleTri=angleTri+1.0f;
	if(angleTri>=360.0f)
		angleTri=angleTri-360.0f;

	angleSquare=angleSquare+1.0f;
	if(angleSquare>=360.0f)
		angleSquare=angleSquare-360.0f;

	glutPostRedisplay();
}

void uninitialize(void)
{
	//code
}
