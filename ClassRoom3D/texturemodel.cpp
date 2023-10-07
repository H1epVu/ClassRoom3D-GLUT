//
// Ky thuat do hoa
// Ha Manh Toan hmtoan@ioit.ac.vn
//
#include "texturemodel.h"
#include "imageloader.h"

TexCoord2 texCoord2(float s, float t) {
	TexCoord2 tc;
	tc.s = s;
	tc.t = t;
	return tc;
}

TriangleIndex triangleIndex(int A, int B, int C, TexCoord2 tcA, TexCoord2 tcB, TexCoord2 tcC) {
	TriangleIndex t;
	t.A = A;
	t.B = B;
	t.C = C;
	t.tcA = tcA;
	t.tcB = tcB;
	t.tcC = tcC;
	return t;
}

QuadIndex quadIndex(int A, int B, int C, int D, TexCoord2 tcA, TexCoord2 tcB, TexCoord2 tcC, TexCoord2 tcD) {
	QuadIndex t;
	t.A = A;
	t.B = B;
	t.C = C;
	t.D = D;
	t.tcA = tcA;
	t.tcB = tcB;
	t.tcC = tcC;
	t.tcD = tcD;
	return t;
}

TextureModel::TextureModel() { texId =0; }
TextureModel::~TextureModel() { clear(); }
void TextureModel::clear() {
	if (texId!=0) glDeleteTextures(1, &texId);
	vertices.clear();
	triangles.clear();
	quads.clear();
}
void TextureModel::setTextureFromBMP(const char* file) {
	this->texId = textureFromBMP(file);
}
void TextureModel::addVertex(Point3 p) {
	this->vertices.push_back(p);
}
void TextureModel::addTriangle(TriangleIndex t) {
	this->triangles.push_back(t);
}
void TextureModel::addQuad(QuadIndex q) {
	this->quads.push_back(q);
}
void TextureModel::draw() const {
	glBindTexture(GL_TEXTURE_2D, texId);
	if (quads.size()>0) {
		glBegin(GL_QUADS);
		for (int i=0; i<quads.size(); i++) {
			const QuadIndex& q = quads[i];
			glTexCoord2f(q.tcA.s, q.tcA.t); glVertex3f(vertices[q.A].x, vertices[q.A].y, vertices[q.A].z);
			glTexCoord2f(q.tcB.s, q.tcB.t); glVertex3f(vertices[q.B].x, vertices[q.B].y, vertices[q.B].z);
			glTexCoord2f(q.tcC.s, q.tcC.t); glVertex3f(vertices[q.C].x, vertices[q.C].y, vertices[q.C].z);
			glTexCoord2f(q.tcD.s, q.tcD.t); glVertex3f(vertices[q.D].x, vertices[q.D].y, vertices[q.D].z);
		}
		glEnd();
	}
	if (triangles.size()>0) {
		glBegin(GL_TRIANGLES);
		for (int i=0; i<triangles.size(); i++) {
			const TriangleIndex& q = triangles[i];
			glTexCoord2f(q.tcA.s, q.tcA.t); glVertex3f(vertices[q.A].x, vertices[q.A].y, vertices[q.A].z);
			glTexCoord2f(q.tcB.s, q.tcB.t); glVertex3f(vertices[q.B].x, vertices[q.B].y, vertices[q.B].z);
			glTexCoord2f(q.tcC.s, q.tcC.t); glVertex3f(vertices[q.C].x, vertices[q.C].y, vertices[q.C].z);
		}
		glEnd();
	}
}