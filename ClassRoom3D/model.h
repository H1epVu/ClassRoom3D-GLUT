#ifndef MODEL_H
#define MODEL_H
//
// Ky thuat do hoa
// Ha Manh Toan hmtoan@ioit.ac.vn
//
#include <glut.h>
#include <stdio.h>

#define MAX_VERTICES 10000
#define MAX_LINES 10000
#define PI 3.14159265358979323846
//#define PI 3.14
typedef struct Point3 {
	double x, y, z;
}Point3;
typedef Point3 Vector3;
typedef struct Model {
	int nVertices; // số lượng đỉnh
	Point3 vertices[MAX_VERTICES]; // danh sách các đỉnh
	int nEdges; // số lượng cạnh
	int edges[MAX_LINES][2]; // danh sách các cạnh
}Model;
void drawModelLines(Model* m);
void regularPolygon(Model* m, double r, int n);

Point3 point3(double x, double y, double z);
void drawModelLines(Model* m, Vector3 v);
void regularPolygon(Model* m, int n, double A0x, double A0y);
void regularPolygon1(Model* m, double r, int n, double startAngle);


#endif // !MODEL_H
