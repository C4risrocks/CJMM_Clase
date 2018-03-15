//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Moreno Marín Christian     ******//
//*************											******//
//*************			Visual 17						******//
//************************************************************//

/*Teclas para mover partes del brazo minúsculas mueven hacia un lado mayusculas al otro.
	H mueve el hombro
	C mueve el codo
	M mueve la muñeca
	J mueve el dedo Pulgar
	U mueve el dedo Indice
	I mueve el dedo Medio
	O mueve el dedo anular
	P mueve el dedo Meñique
	
	////////////VERSION ARREGLADA///////////////*/

#include "Main.h"

float angHombro = 0.0f;
float angCodo = 0.0f;
float angMuñeca = 0.0f;
float angIndice = 0.0f;
float angMedio = 0.0f;
float angAnular = 0.0f;
float angMeñique = 0.0f;
float angPulgar = 0.0f;

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
	
	//Hombro----------------------------------------------------------------------------------
	glRotatef(angHombro, 0, 0, 1);
	glPushMatrix();
	glScalef(1,2,2);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();
	
	//Bicep

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glScalef(3, 2, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();
	
	//Codo--------------------------------------------------------------------------------------
	glTranslatef(3.75, 0, 0);
	glRotatef(angCodo, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 2, 2);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();
	
	//Antebrazo
	glTranslatef(2.25, 0, 0);
	glPushMatrix();
	glScalef(4, 2, 2);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Muñeca--------------------------------------------------------------------------------------
	glRotatef(angMuñeca, 1, 0, 0);
	glTranslatef(2.25, 0, 0);
	glPushMatrix();
	glScalef(0.5, 2, 2);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();

	//Mano
	glTranslatef(1.25, 0, 0);
	glPushMatrix();
	glScalef(2, 2, 1);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//Dedo pulgar---------------------------------------------------------------------------------------
	glPushMatrix();
	//Falange1
	glTranslatef(0, 1.25, 0);
	glRotatef(angPulgar, 1, 0, 0);
	glPushMatrix();
	glScalef(0.4, 0.5, 0.4);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Falange2
	glTranslatef(0, 0.5, 0);
	glRotatef(angPulgar, 1, 0, 0);
	glPushMatrix();
	glScalef(0.4, 0.5, 0.4);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();////////////////////////////////////

	
				  
	//Dedo indice--------------------------------------------------------------------------------
	glPushMatrix();
	//Falange1
	glTranslatef(1.25, 0.85, 0);
	glRotatef(angIndice, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Falange2
	glTranslatef(0.5, 0, 0);
	glRotatef(angIndice, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	//Falange3
	glTranslatef(0.5, 0, 0);
	glRotatef(angIndice, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();//////////////////////////////////////

	
				  
	//Dedo medio--------------------------------------------------------------------------------------
	glPushMatrix();
	//Falange1 medio
	glTranslatef(2.25, 0.85, 0);
	glTranslatef(-1, -0.6, 0);
	glRotatef(angMedio, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Falange2 medio
	glTranslatef(0.55, 0, 0);
	glRotatef(angMedio, 0, -1, 0);
	glPushMatrix();
	glScalef(0.6, 0.3, 0.3);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	//Falange3 medio
	glTranslatef(0.6, 0, 0);
	glRotatef(angMedio, 0, -1, 0);
	glPushMatrix();
	glScalef(0.6, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();////////////////////////////////////

	
				  
	//Dedo Anular-----------------------------------------------------------------------------------------
	glPushMatrix();
	//Falange1 Anular
	glTranslatef(2.4, 0.25, 0);
	glTranslatef(-1.15, -0.6, 0);
	glRotatef(angAnular, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Falange2 Anular
	glTranslatef(0.5, 0, 0);
	glRotatef(angAnular, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	//Falange3 Anular
	glTranslatef(0.5, 0, 0);
	glRotatef(angAnular, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();/////////////////////////////////////////

	
				  
	//Dedo Meñique-----------------------------------------------------------------------------------
	glPushMatrix();
	//Falange1 Meñique
	glTranslatef(2.25, -0.35, 0);
	glTranslatef(-1, -0.5, 0);
	glRotatef(angMeñique, 0, -1, 0);
	glPushMatrix();
	glScalef(0.5, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Falange2 Meñique
	glTranslatef(0.4, 0, 0);
	glRotatef(angMeñique, 0, -1, 0);
	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	//Falange3 Meñique
	glTranslatef(0.25, 0, 0);
	glRotatef(angMeñique, 0, -1, 0);
	glPushMatrix();
	glScalef(0.2, 0.3, 0.3);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();

	





		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;

		case 'h':
			if (angHombro <= 80)
			angHombro += 1;
			break;
		case 'H':
			if (angHombro >= -80)
			angHombro -= 1;
			break;

		case 'c':
			if (angCodo <= 130)
				angCodo += 1;
			break;
		case 'C':
			if (angCodo >= 1)
				angCodo -= 1;
			break;

		case 'm':
			if (angMuñeca <= 90)
				angMuñeca += 1;
			break;
		case 'M':
			if (angMuñeca >= -30)
				angMuñeca -= 1;
			break;

		case 'u':
			if (angIndice <= 70)
				angIndice += 1;
			break;
		case 'U':
			if (angIndice >= 1)
				angIndice -= 1;
			break;

		case 'i':
			if (angMedio <= 70)
				angMedio += 1;
			break;
		case 'I':
			if (angMedio >= 1)
				angMedio -= 1;
			break;

		case 'o':
			if (angAnular <= 70)
				angAnular += 1;
			break;
		case 'O':
			if (angAnular >= 1)
				angAnular -= 1;
			break;

		case 'p':
			if (angMeñique <= 70)
				angMeñique += 1;
			break;
		case 'P':
			if (angMeñique >= 1)
				angMeñique -= 1;
			break;

		case 'j':
			if (angPulgar <= 70)
				angPulgar += 1;
			break;
		case 'J':
			if (angPulgar >= 1)
				angPulgar -= 1;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // 
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



