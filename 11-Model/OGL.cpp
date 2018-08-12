#include <GL/freeglut.h>

#include "OGL.h"

//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen

GLfloat angle=0.0f;

// Lights
bool bLight = false; //for whether lighting is ON/OFF, by default 'off'
GLfloat LightAmbient[] = { 0.5f,0.5f,0.5f,1.0f };
GLfloat LightDiffuse[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightPosition[] = { 0.0f,0.0f,2.0f,1.0f };

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
	glutCreateWindow("Model Rendering : Utah Teapot"); //open the window with "Model Rendering : Utah Teapot" in the title bar

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

	// ###### TEAPOT ######
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-1.5f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); //to position it correctly than originally obtained
	glRotatef(angle,0.0f,0.0f,1.0f); //due to above rotation, its 'up' vector is not 'y' but 'z'
	glBegin(GL_TRIANGLES);
	for (int i = 0;i<sizeof(face_indicies) / sizeof(face_indicies[0]);i++)
	{
		for (int j = 0;j<3;j++)
		{
			int vi = face_indicies[i][j];
			int ni = face_indicies[i][j + 3]; //Normal index
			int ti = face_indicies[i][j + 6]; //Texture index
			glNormal3f(normals[ni][0], normals[ni][1], normals[ni][2]);
			glTexCoord2f(textures[ti][0], textures[ti][1]);
			glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		}
	}
	glEnd();
	
	//to process buffered OpenGL Routines
	glutSwapBuffers();
}

void initialize(void)
{
	//code
	glShadeModel(GL_SMOOTH);
	//set background clearing color to black
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	//set-up depth buffer
	glClearDepth(1.0f);
	//enable depth testing
	glEnable(GL_DEPTH_TEST);
	//depth test to do
	glDepthFunc(GL_LEQUAL);
	//set really nice percpective calculations ?
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	//Lights
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient); //setup ambient light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse); //setup diffuse light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition); //position the light
	glEnable(GL_LIGHT1);  //enable above configured LIGHT1 
}

void keyboard(unsigned char key,int x,int y)
{
	//code
	switch(key)
	{
	case 27: //Escape
		glutLeaveMainLoop();
		break;
	case 'L':
	case 'l':
		if (bLight == false)
		{
			bLight = true;
			glEnable(GL_LIGHTING);
		}
		else
		{
			bLight = false;
			glDisable(GL_LIGHTING);
		}
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

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spin(void)
{
	//code
	angle=angle+1.0f;
	if(angle>=360.0f)
		angle=angle-360.0f;

	glutPostRedisplay();
}

void uninitialize(void)
{
	//code
}
