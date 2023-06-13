#include <windows.h>
#include <gl/glut.h>
#include <string>

GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 10.0 };


GLfloat light_position1[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat light_position2[] = { -1.0, -1.0, -1.0, 0.0 };



GLfloat light1[] = {9,0,0,1.};  // up
GLfloat light2[] = {0.,0.,1.,1.}; // down


float speed = 0.1;

GLfloat white_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
void init(void) // --------------------------
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);   // no3 el zel
    //material
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position1);   // pos of light
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1);     // ent4aer el do2
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2);

    glLightfv(GL_LIGHT0, GL_SPECULAR, light1);   // en3kas el do2
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2);

    glEnable(GL_LIGHTING);    // on the LIGHTING
    glEnable(GL_LIGHT0);      // on light 0 and control it
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);    // el 3omk
}

void display1Func()
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPushMatrix();

        // Display "3D Car" text
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, 0.8); // Adjusted x-coordinate
        std::string text1 = "3D Car";
        for (int i = 0; i < text1.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);



        // Display help text
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, 0.6); // Adjusted x-coordinate
        std::string text2 = "Help :";
        for (int i = 0; i < text2.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text2[i]);



        // Display movement instructions
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, 0.4); // Adjusted x-coordinate
        std::string text3 = "Press  'W'  to Move the car ahead";
        for (int i = 0; i < text3.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text3[i]);



        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, 0.2); // Adjusted x-coordinate
        std::string text4 = "Press  'S'  to Move the car back";
        for (int i = 0; i < text4.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text4[i]);



        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, 0.0); // Adjusted x-coordinate
        std::string text5 = "Press  'D'  to Move the car right";
        for (int i = 0; i < text5.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text5[i]);



        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, -0.2); // Adjusted x-coordinate
        std::string text6 = "Press  'A'  to Move the car left";
        for (int i = 0; i < text6.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text6[i]);



        // Display start message
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(-0.8, -0.4); // Adjusted x-coordinate
        std::string text7 = "Press [Space] to Start";
        for (int i = 0; i < text7.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text7[i]);


        glPopMatrix();

        glFlush();

}
bool vi = true;
void display()
{
    if (vi==true) {
        display1Func();
    } else {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glPushMatrix();
        glPushMatrix();

        // body
        glScalef(4,1,2); // Main Body
        glutSolidCube(0.5);  // ab3ad el mok3b
        glTranslatef(-.05,.3,0);  // matrex t7rek on (x,y,z)

        glScalef(0.6,3,2);
        glutSolidCube(.25);
        glTranslatef(-.12,.001,-.001);

        glScalef(1,1.8,2.48);
        glRotatef(230, 0, 0, 250);
        glutSolidCube(.1);
        glPopMatrix();
        glTranslatef(0,0,.5);
        glPushMatrix();
        glTranslatef(-.4,-.2,0);


        glutSolidTorus(.1,.2,100,100);       // wheel
        glTranslatef(1,0,0);

        glutSolidTorus(.1,.2,100,100);       // wheel
        glPopMatrix();
        glTranslatef(0,0,-1);
        glPushMatrix();
        glTranslatef(-.4,-.2,0);

        glutSolidTorus(.1,.2,100,100);       // wheel
        glTranslatef(1,0,0);
        glutSolidTorus(.1,.2,100,100);       // wheel
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();
        glFlush();

    }
}



void GL_keyboard(unsigned char key, int x, int y)  // GLUT keyboard function
{
    switch(key)
    {
            case ' ':
            vi=false;

            display();

            break;
            case 'w':
            case 'W':

            glTranslatef(-speed,0.0,0.0);
            display();
            break;
            case 'S':
            case 's':
                glTranslatef(speed,0.0,0.0);
                display();
                break;
            case 'A':
            case 'a':
            glRotatef(10,0,1,0);
            glutPostRedisplay();

            break;
            case 'D':
            case 'd':
            glRotatef(-10,0,1,0);
            glutPostRedisplay();

            break;
            case '+':
                speed+=0.005;
            break;
            case '-':
                if(speed<=0){
                   speed =0.005;
                }else{
                speed-=0.005;
                }

            break;


    }
}
void reshape(int w, int h)   // --------------------------
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); // determin the new area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,  // customize the 3D with directions
                2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-2.5*(GLfloat)w/(GLfloat)h,
                2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 0., 1., -1., 1., 0., 1., 0.);  // pos of camera
}

void mousefun(int button , int state,int x,int y){
if(button==GLUT_LEFT_BUTTON&&state ==GLUT_DOWN){

    glRotatef(10,0,0,1);
    glutPostRedisplay();


}

if(button==GLUT_RIGHT_BUTTON&&state ==GLUT_DOWN){

    glRotatef(-10,0,0,1);
    glutPostRedisplay();

}

}
int main() {

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   // --------------------------
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Car");
    init();


    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mousefun);

    glutKeyboardFunc(GL_keyboard);

    glutMainLoop();

    return 0;
}

