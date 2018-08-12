#include <GL/freeglut.h>

#include "OGL.h"

//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen

GLfloat angleTri=0.0f; //angle of rotation of Pyramid
GLfloat angleSquare=0.0f; //angle of rotation of Cube

GLuint	Texture_Kundali; //texture object for Kundali texture
GLuint	Texture_Stone; //texture object for Stone texture

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
	glutCreateWindow("Textured Pyramid And Cube"); //open the window with "Textured Pyramid And Cube" in the title bar

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
	glBindTexture(GL_TEXTURE_2D, Texture_Stone);
	glBegin(GL_TRIANGLES);
		//NOTE : EACH FACE OF A PYRAMID (EXCEPT THE BASE/BOTTOM) IS A TRIANGLE

		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,1.0f); //left-bottom tip of triangle

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,1.0f); //right-bottom tip of triangle

		//****RIGHT FACE****
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,1.0f); //left-bottom tip of triangle

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,-1.0f); //right-bottom tip of triangle

		//****BACK FACE****
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,-1.0f); //left-bottom tip of triangle

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f); //right-bottom tip of triangle

		//****LEFT FACE****
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); //apex of triangle

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f); //left-bottom tip of triangle

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,1.0f); //right-bottom tip of triangle
	glEnd();

	// ###### CUBE ######

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(angleSquare,1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, Texture_Kundali);
	glBegin(GL_QUADS);
		//NOTE : EACH FACE OF A CUBE IS A SQUARE

	    //****TOP FACE****
	    glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f); //right-top of top face

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f); //left-top of top face

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f); //left-bottom of top face

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f); //right-bottom of top face

		//****BOTTOM FACE****
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f); //right-top of bottom face

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f); //left-top of bottom face

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f); //left-bottom of bottom face

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f); //right-bottom of bottom face

		//****FRONT FACE****
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f); //right-top of front face

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f); //left-top of front face

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f); //left-bottom of front face

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f); //right-bottom of front face

		//****BACK FACE****
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f); //right-top of back face

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f); //left-top of back face

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f); //left-bottom of back face

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f); //right-bottom of back face

		//****LEFT FACE****
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f); //right-top of left face

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f); //left-top of left face

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f); //left-bottom of left face

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f); //right-bottom of left face

		//****RIGHT FACE****
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f); //right-top of right face

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f); //left-top of right face

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f); //left-bottom of right face

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f); //right-bottom of right face

	glEnd();
	
	//to process buffered OpenGL Routines
	glutSwapBuffers();
}

void initialize(void)
{
	// function declarations
	int LoadGLTextures(GLuint *, TCHAR[]);

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

	LoadGLTextures(&Texture_Kundali, MAKEINTRESOURCE(IDBITMAP_KUNDALI));
	LoadGLTextures(&Texture_Stone, MAKEINTRESOURCE(IDBITMAP_STONE));

	glEnable(GL_TEXTURE_2D); //enable texture mapping
}

int LoadGLTextures(GLuint *texture,TCHAR imageResourceId[])
{
	//variable declarations
	HBITMAP hBitmap;
	BITMAP bmp;
	int iStatus = FALSE;

	//code
	glGenTextures(1, texture); //1 image
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceId, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	if (hBitmap) //if bitmap exists ( means hBitmap is not null )
	{
		iStatus = TRUE;
		GetObject(hBitmap, sizeof(bmp), &bmp);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4); //pixel storage mode (word alignment/4 bytes)
		glBindTexture(GL_TEXTURE_2D, *texture); //bind texture
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		//generate mipmapped texture (3 bytes, width, height & data from bmp)
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);

		DeleteObject(hBitmap); //delete unwanted bitmap handle
	}
	return(iStatus);
}

void keyboard(unsigned char key,int x,int y)
{
	//code
	switch(key)
	{
	case 27: //Escape
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

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

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
