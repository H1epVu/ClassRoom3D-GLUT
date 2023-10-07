#include "model.h"
#include <math.h>

void drawModelLines(Model* m) {
	glBegin(GL_LINES);
	for (int i=0; i<m->nEdges; i++) {
		glVertex3f(
			m->vertices[m->edges[i][0]].x,
			m->vertices[m->edges[i][0]].y,
			m->vertices[m->edges[i][0]].z);
		glVertex3f(
			m->vertices[m->edges[i][1]].x,
			m->vertices[m->edges[i][1]].y,
			m->vertices[m->edges[i][1]].z);
	}
	glEnd();
}

void regularPolygon(Model* m, double r, int n) {
	// n can phai <3
	m->nVertices = n;
	for (int i=0; i<n; i++) {
		double angle = i*(2*PI/n);
		m->vertices[i].z = 0;
		m->vertices[i].x = cos(angle)*r;
		m->vertices[i].y = sin(angle)*r;
	}

	m->nEdges = n;
	for (int i=0; i<n; i++) {
		m->edges[i][0] = i;
		m->edges[i][1] = (i+1)%n;
	}
}






Point3 point3(double x, double y, double z) {
	Point3 p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}
void drawModelLines(Model* m, Vector3 v) {
	glBegin(GL_LINES);
	for (int i=0; i<m->nEdges; i++) {
		glVertex3f(
			m->vertices[m->edges[i][0]].x+v.x,
			m->vertices[m->edges[i][0]].y+v.y,
			m->vertices[m->edges[i][0]].z+v.z);
		glVertex3f(
			m->vertices[m->edges[i][1]].x+v.x,
			m->vertices[m->edges[i][1]].y+v.y,
			m->vertices[m->edges[i][1]].z+v.z);
	}
	glEnd();
}
void regularPolygon(Model* m, int n, double A0x, double A0y) {
	m->nVertices = n;

	m->vertices[0].z = 0;
	m->vertices[0].x = A0x;
	m->vertices[0].y = A0y;

	for (int i=1; i<n; i++) {
		double angle = 2*PI*i/n;
		m->vertices[i].z = 0;
		m->vertices[i].x = A0x*cos(angle)-A0y*sin(angle);
		m->vertices[i].y = A0x*sin(angle)+A0y*cos(angle);
	}

	m->nEdges = n;
	for (int i=0; i<n; i++) {
		m->edges[i][0] = i;
		m->edges[i][1] = (i+1)%n;
	}
}
void regularPolygon1(Model* m, double r, int n, double startAngle) {

	m->nVertices = n;
	for (int i=0; i<n; i++) {
		double angle = 2*PI*i/n +startAngle;
		m->vertices[i].z = 0;
		m->vertices[i].x = sin(angle)*r;
		m->vertices[i].y = cos(angle)*r;
	}

	m->nEdges = n;
	for (int i=0; i<n; i++) {
		m->edges[i][0] = i;
		m->edges[i][1] = (i+1)%n;
	}
}
