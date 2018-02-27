/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: javargas
 *
 * Created on February 12, 2017, 11:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"


using namespace std;
int flag = 0, flag1 = 0;
GLfloat Y = 0, X = 1;

void draw_SphereTurtle() {

    glTranslated(0.0, 0, 0);
    glutWireSphere(1, 16, 6);
    glTranslated(-1.0, .2, 0);
    glutWireSphere(.5, 16, 6);
    glTranslated(-0.5, -.2, 0);
    glutWireSphere(.5, 16, 6);

}

void draw_turtle() {

    double x[] = {0, -.4, -.37, -.2, -.2, -.45, -.45, -.6, -.75, -.77, -.4, -.5, -.52, -.4, -.75, -.77, -.6, -.4, -.2, .0};
    double y[] = {1, .9, .73, .6, .45, .45, .5, .6, .5, .2, .2, .06, -.25, -.4, -.5, -.8, -.9, -.9, -.7, -.7};
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(1.f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 20; i++) {
        glVertex3d(x[i], y[i], 0);
    }
    for (int i = 19; i > -1; i--) {
        glVertex3d(-1 * x[i], y[i], 0);

    }
    glEnd();


}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*glColor3f(1.0, 0.0, 0.0);
    glutWireTorus(0.25, 0.75, 28, 28);
    glColor3f(0.0, 0.0, 1.0);
    glutWireCube(.60);*/
    if (flag == 1) {
        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f); // green
        glVertex3f(0.0f, -0.99f, 0.0f);
        glVertex3f(0.0f, .99f, 0.0f);


        glColor3f(1.0f, 0.0f, 0.0f); // red
        glVertex3f(-0.99f, 0.0f, 0.0f);
        glVertex3f(0.99f, 0.0f, 0.0f);


        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex3f(0.0f, 0.0f, -0.99f);
        glVertex3f(0.0f, 0.0f, 0.99f);

        glEnd();
    }
    if (flag1) {
        draw_turtle();
    } else {
        draw_SphereTurtle();
    }
    glLoadIdentity();
    gluLookAt(Y, X, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutSwapBuffers();

    glutSwapBuffers();

}

void reshape(int width, int height) {
    if (width < height) {
        glViewport(0, 0, width, width);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, 1, 1.0, 128.0);
        glMatrixMode(GL_MODELVIEW);

        gluLookAt(Y, X, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    } else {
        glViewport(0, 0, height, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, 1, 1.0, 128.0);
        glMatrixMode(GL_MODELVIEW);

        gluLookAt(Y, X, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }

}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'h':
            printf("help\n\n");
            printf("c - Toggle culling\n");
            printf("q/escape - Quit\n\n");
            break;
        case 'c':
            if (glIsEnabled(GL_CULL_FACE))
                glDisable(GL_CULL_FACE);
            else
                glEnable(GL_CULL_FACE);
            break;
        case '1':
            glRotatef(1.0, 5., 0., 0.);
            break;
        case '2':
            glRotatef(1.0, 0., 1., 0.);
            break;
        case 'q':
            exit(0);
            break;
        case 'a':
            if (flag) {
                flag = 0;
            } else {
                flag = 1;

            }
            break;
        case 'u':
            Y += 0.1;

            break;
        case 'd':
            Y -= 0.1;

            break;
        case 'r':
            X += 0.1;

            break;
        case 'l':
            X -= 0.1;

            break;
        case '3':
            if (flag1) {
                flag1 = 0;
            } else {
                flag1 = 1;

            }
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("tecnunLogo");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}