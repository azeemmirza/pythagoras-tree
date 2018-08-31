#include <string>
#include <iostream>
#include "copyrights.h"
#include "headers/Canvas.h";
#include "headers/CONFIG.h";
#include "headers/LinderEngine.h";
#include "headers/Rewriter.h"

#include <map>

float aaa = 60;
void surface();





void pyth() {
	std::string axiom = "S";
	int iterations = 10;
	std::map <char, std::string> ruleSet;
	std::pair <char, std::string> R1('S', "X [ - M S ] [ + M S ]");
	ruleSet.insert(R1);

	
	// RuleEngine r(axiom, ruleSet, iterations);
	// std::string s = r.getResult();

	std::string s = rewriter(axiom, ruleSet, iterations);
	std::cout << s << std::endl;
	glColor3f(1, 1, 0);

	LinderEngine* e = LinderEngine::getInstance(s, 20, aaa);
	Point3 pp(0, 0, 0);
	pp.setSize(10.0); pp.draw();
	surface();
	glColor3f(0, 1, 1);
	e->run();

}

void surface() {
	float a = 100;
	glColorMaterial(GL_FRONT, GL_3D);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.87, 0.72, 0.52);
	glBegin(GL_POLYGON);
	glVertex3f(-a, 0, a);
	glVertex3f(-a, 0, -a);
	glVertex3f(a, 0, -a);
	glVertex3f(a, 0, a);
	glEnd();
}




void display() {

	glPushMatrix();
	glTranslatef(0, -20, -100);
	pyth();
	glPopMatrix();
	glFlush();

}



void initLighting()
{
	GLfloat qaAmbientLight[] = { 0, 0, 0, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat emitLight[] = { 1, 0.9, 0.9, 0.01 };
	GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaLightPosition[] = { 0, 0, -50, 1 };
	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}


void key(unsigned char c, int x, int y) {
	if (c == 'a') {
		aaa += 1;
	}
	else if (c == 's') {
		aaa += 1;

	}
}
void reshape(int w, int h) {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(-200, 200, -200, 200, -200, 200);
	//glOrtho(-30, 30, -30, 30, -30, 30);



	gluPerspective(90.0, (GLdouble)w / (GLdouble)h, 0, 200.0);
	//gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
}



/**
  * @function main
  * @params Argument Count [argc], Argument Vector [argv]
  */
int main (int argc, char argv) {

	int cvsWinWidth = WIN_SIZE_WIDTH;
	int cvsWinHeight = WIN_SIZE_HEIGHT;
	std::string cvsWinTitle = WIN_TITLE;

	Canvas cvs(1000, 1000, "Pythgoras Tree");

	std::cout << copyrights() << std::endl;
	//getchar();

	//initLighting();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutKeyboardFunc(key);
	glutMainLoop();

	return 0;

}