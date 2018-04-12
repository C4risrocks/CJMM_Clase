//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************			Moreno Marin Christian			******//
//*************			Visual Studio 2017 			******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol,mercurio,venus,tierra,marte,jupiter,saturno,urano,neptuno=0;
int lunaTierra,lunaJupiter1, lunaJupiter2 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.074, 0.717, 0.89, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MercuryDiffuse[] = { 0.97, 0.72, 0.32, 1.0f };			// Luna
GLfloat MercurySpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MercuryShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.92, 0.043, 0.003, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.4, 0.125, 0.047, 1.0f };			// Marte
GLfloat VenusSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0, 0.313, 0.764, 1.0f };			// Marte
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnDiffuse[] = { 0.80, 0.75, 0.5, 1.0f };			// Marte
GLfloat SaturnSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SaturnShininess[] = { 50.0 };

GLfloat UranusDiffuse[] = { 0.97, 0.72, 0.32, 1.0f };			// Marte
GLfloat UranusSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranusShininess[] = { 50.0 };

GLfloat NeptuneDiffuse[] = { 0, 0, 1, 1.0f };			// Marte
GLfloat NeptuneSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NeptuneShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	//Sistema Solar
	glPushMatrix();
		//Sol
		glPushMatrix();
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
			glDisable(GL_LIGHTING);
			glutSolidSphere(1.9,30,30);  //Draw Sun (radio,H,V);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		//Mercurio
		glPushMatrix();
			glRotatef(mercurio, 0, 1, 0);//Traslación Mercurio
			glTranslatef(3.5, 0, 0);
			glColor3f(0.97, 0.72, 0.32);
			
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MercuryDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MercurySpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MercuryShininess);
			
			glRotatef(mercurio, 0, 1, 0);//Rotacion Mercurio
			glutWireSphere(0.2, 20, 20);
		glPopMatrix();

		//Venus
		glPushMatrix();
            glRotatef(venus, 0, 1, 0);//Traslación venus
            glTranslatef(6, 0, 0);
            glColor3f(0.4, 0.125, 0.047);
			
			glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
            
			glRotatef(venus, 0, 1, 0);//Rotacion venus
            glutWireSphere(0.5, 20, 20);
		glPopMatrix();

		//Tierra
		glPushMatrix();
            glRotatef(tierra, 0, 1, 0);//Traslación tierra
            glTranslatef(9, 0, 0);
                //Luna
                glPushMatrix();
                    glRotatef(lunaTierra,0.0,1.0,0.0);    //Traslacion Lunatierra
                    glTranslatef(1.4,0,0);
                    glRotatef(lunaTierra,0.0,1.0,0.0);    //Traslacion Lunatierra
                    glColor3f( 1.0,1.0,1.0 );    //Luna Blanca

					glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);

                    glutSolidSphere(0.1,30,30);  //Draw Moon (radio,H,V);
                glPopMatrix();
                //------------------------------------------------------------
            glColor3f(0.074, 0.717, 0.89);

			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);

            glRotatef(tierra, 0, 1, 0);//Rotacion Tierra
            glutWireSphere(0.5, 20, 20);
		glPopMatrix();

		//Marte
		glPushMatrix();
		glRotatef(marte, 0, 1, 0);//Traslación Marte
		glTranslatef(12, 0, 0);
		glColor3f(0.92, 0.043, 0.003);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);

		glRotatef(marte, 0, 1, 0);//Rotacion Mercurio
		glutWireSphere(0.3, 20, 20);
		glPopMatrix();

		//Jupiter
		glPushMatrix();
		glRotatef(jupiter, 0, 1, 0);//Traslación Jupiter
		glTranslatef(16, 0, 0);
            //Luna JUPITER1
            glPushMatrix();
                glRotatef(lunaJupiter1,0.0,1.0,0.0);    //Traslacion LunaJUPITER1
                glTranslatef(2.4,0,0);
                glRotatef(lunaJupiter1,0.0,1.0,0.0);    //Traslacion LunaJUPITER1

				glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);

                glColor3f( 1.0,1.0,1.0 );    //Luna Blanca
                glutSolidSphere(0.1,30,30);  //Draw Moon (radio,H,V);
            glPopMatrix();
            //------------------------------------------------------------
            //Luna JUPITER 2
            glPushMatrix();
                glRotatef(lunaJupiter2,0.0,1.0,0.0);    //Traslacion LunaJUPITER2
                glTranslatef(2.8,0,0);
                glRotatef(lunaJupiter2,0.0,1.0,0.0);    //Traslacion LunaJUPITER2
                glColor3f( 1.0,1.0,1.0 );    //Luna Blanca
                glutSolidSphere(0.1,30,30);  //Draw Moon (radio,H,V);
            glPopMatrix();
            //------------------------------------------------------------
		glColor3f(0, 0.313, 0.764);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);

		glRotatef(jupiter, 0, 1, 0);//Rotacion Jupiter
		glutWireSphere(1, 20, 20);
		glPopMatrix();

		//Saturno
		glPushMatrix();
		glRotatef(saturno, 0, 1, 0);//Traslación Saturno
		glTranslatef(22, 0, 0);
		glColor3f(0.80, 0.75, 0.5);
		glRotatef(saturno, 0, 1, 0);//Rotacion Saturno
		glPushMatrix();
		glRotatef(45, 1, 0, 0);
        glutWireTorus(0.3, 3, 15, 15);//Anillo Saturno
		glPopMatrix();
        glColor3f(0.764, 0.596, 0);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, SaturnShininess);

		glutWireSphere(0.8, 20, 20);
		glPopMatrix();
		
    
        //Urano
		glPushMatrix();
		glRotatef(urano, 0, 1, 0);//Traslación urano
		glTranslatef(27, 0, 0);
		glColor3f(0.97, 0.72, 0.32);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, UranusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, UranusSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, UranusShininess);

		glRotatef(urano, 0, 1, 0);//Rotacion urano
		glutWireSphere(0.8, 20, 20);
		glPopMatrix();

		//Neptuno
		glPushMatrix();
		glRotatef(neptuno, 0, 1, 0);//Traslación Neptuno
		glTranslatef(32, 0, 0);
		glColor3f(0, 0, 1);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptuneDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, NeptuneSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, NeptuneShininess);

		glRotatef(neptuno, 0, 1, 0);//Rotacion Neptuno
		glutWireSphere(0.7, 20, 20);
		glPopMatrix();


	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 8) % 360;
		venus = (venus - 7) % 360;
		tierra = (tierra - 6) % 360;
		marte = (marte - 5) % 360;
		jupiter = (jupiter - 4) % 360;
		saturno = (saturno - 3) % 360;
		urano = (urano - 2) % 360;
		neptuno = (neptuno - 1) % 360;
        
        lunaTierra = (lunaTierra - 4) % 360;
        
        lunaJupiter1 = (lunaJupiter1 - 4) % 360;
        lunaJupiter2 = (lunaJupiter2 - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
