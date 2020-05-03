#include <GL/glut.h>
#include <math.h> 
#include <time.h>
#include <cstdlib>
#include <iostream>
#define PI 3.14159265

const int maxsize = 40;

struct point {
	float x;
	float y;
};

class Triang {
	point points[maxsize];
	int size;
public:
	Triang(int n) {
		size = n;
		//points = new point[n];
		for (int i = 0; i < n; i++) {
			points[i].x = ((float)(rand()) / RAND_MAX)*1.8 - 1;
			points[i].y = ((float)(rand()) / RAND_MAX)*1.8 - 1;
		}
	}

	void sort() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size-1; j++) {
				if (points[j].x > points[j + 1].x) {
					float b = points[j].x;
					points[j].x = points[j + 1].x; 
					points[j + 1].x = b; 
				}
			}
		}
	}

	float getX(int index) {
		return points[index].x;
	}

	float getY(int index) {
		return points[index].y;
	}
};

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	int n=8;
	Triang t(n);
	t.sort();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < n - 2; i++) {
		float a = (float)(rand()) / RAND_MAX;
		float b = (float)(rand()) / RAND_MAX;
		float c = (float)(rand()) / RAND_MAX;
		glColor3f(a, b, c);
		glVertex2f(t.getX(i), t.getY(i));
		glVertex2f(t.getX(i+1), t.getY(i+1));
		glVertex2f(t.getX(i+2), t.getY(i+2));
	}
	glEnd();
	glFlush();
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ex 5");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}