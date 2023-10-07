#include <glut.h>
#include "imageloader.h"
#include "texturemodel.h"
#include "model.h"
#include <math.h>


namespace program {
	Model name;
	TextureModel horizontalBox, verticalBox, sky, skyTop, table, ground, floor, horizontalWall, verticalWall, chair, board, bookshelf, buc, clock, chair2;
	Vector3 sky_t, skyTop_t, ground_t, horizontalWall_t, horizontalBox_t1, horizontalBox_t2, verticalBox_t1,
		verticalWall_t,
		table_t1, table_t2, table_t3, table_t4, table_t5, table_t6, table_t7, table_t8, table_t9, board_t, floor_t,
		chair_t1, chair_t2, chair_t3, chair_t4, chair_t5, chair_t6, chair_t7, chair_t8, chair_t9,
		chair2_t1,
		bookshelf_t, buc_t, clock_t;
	float lx = 0.0f, lz = 0.0f;
	float x = -5.0f, z = 5.0f;
	float angle = 0;
	float speed = 0.2f;
	float heightAngle = 0;
	float height_view = -0.5;

	void draw(TextureModel* m, Vector3 t) {
		glPushMatrix();
		glTranslatef(t.x, t.y, t.z);
		m->draw();
		glPopMatrix();
	}
	void makeSky() {
		sky.clear();
		sky.setTextureFromBMP("data/SkyBG.bmp");
		sky.addVertex(point3(-100, -100, -100));//0
		sky.addVertex(point3(100, -100, -100));//1
		sky.addVertex(point3(-100, 100, -100));//2
		sky.addVertex(point3(100, 100, -100));//3
		sky.addVertex(point3(-100, -100, 100));//4
		sky.addVertex(point3(100, -100, 100));//5
		sky.addVertex(point3(-100, 100, 100));//6
		sky.addVertex(point3(100, 100, 100));//7
		sky.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		sky_t = point3(0, 0, 0);
	}
	void makeSkyTop() {
		skyTop.clear();
		skyTop.setTextureFromBMP("data/SkyBG.bmp");
		skyTop.addVertex(point3(-100, 100, -100));
		skyTop.addVertex(point3(100, 100, -100));
		skyTop.addVertex(point3(100, 100, 100));
		skyTop.addVertex(point3(-100, 100, 100));
		skyTop.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		skyTop_t = point3(0, 0, 0);
	}
	void makeGround() {
		ground.clear();
		ground.setTextureFromBMP("data/floor1.bmp");
		ground.addVertex(point3(-100, -1.5, 100));
		ground.addVertex(point3(-100, -1.5, -100));
		ground.addVertex(point3(100, -1.5, -100));
		ground.addVertex(point3(100, -1.5, 100));
		ground.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 200), texCoord2(200, 200), texCoord2(200, 0), texCoord2(0, 0)));

		ground_t = point3(0, 0, 0);
	}
	void makeFloor() {
		floor.clear();
		floor.setTextureFromBMP("data/floor2.bmp");
		floor.addVertex(point3(-7, -1.499, 7));
		floor.addVertex(point3(-7, -1.499, -7));
		floor.addVertex(point3(7, -1.499, -7));
		floor.addVertex(point3(7, -1.499, 7));
		floor.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 20), texCoord2(20, 20), texCoord2(20, 0), texCoord2(0, 0)));

		floor_t = point3(0, 0, 0);
	}
	void makeHorizontalWall() {
		horizontalWall.clear();
		horizontalWall.setTextureFromBMP("data/wall01.bmp");
		horizontalWall.addVertex(point3(-7, 2.5, 7));
		horizontalWall.addVertex(point3(7, 2.5, 7));
		horizontalWall.addVertex(point3(7, -1.5, 7));
		horizontalWall.addVertex(point3(-7, -1.5, 7));
		horizontalWall.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 2), texCoord2(4, 2), texCoord2(4, 0), texCoord2(0, 0)));

		//horizontalWall_t = point3(-0.99, 0, -10.1);
	}
	void makeVerticalWall() {
		verticalWall.clear();
		verticalWall.setTextureFromBMP("data/wall01.bmp");
		verticalWall.addVertex(point3(7, 2.5, 7));
		verticalWall.addVertex(point3(7, 2.5, -7));
		verticalWall.addVertex(point3(7, -1.5, -7));
		verticalWall.addVertex(point3(7, -1.5, 7));
		verticalWall.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 2), texCoord2(2, 2), texCoord2(2, 0), texCoord2(0, 0)));

		//verticalWall_t = point3(-0.99, 0, -2.1);
	}
	
	void makeTable() {

		//Vẽ mặt bàn
		table.clear();
		table.setTextureFromBMP("data/table.bmp");
		table.addVertex(point3(-0.75, 0, 0.75)); // 0
		table.addVertex(point3(0.75, 0, 0.75)); // 1
		table.addVertex(point3(0.75, 0, -0.75)); // 2
		table.addVertex(point3(-0.75, 0, -0.75)); // 3
		table.addVertex(point3(-0.75, -0.15, 0.75)); // 4
		table.addVertex(point3(0.75, -0.15, 0.75)); // 5
		table.addVertex(point3(0.75, -0.15, -0.75)); // 6
		table.addVertex(point3(-0.75, -0.15, -0.75)); // 7

		//Vẽ chân bàn 1
		table.addVertex(point3(0.75, -0.15, 0.75)); //8
		table.addVertex(point3(0.75, -0.15, 0.7)); //9
		table.addVertex(point3(0.7, -0.15, 0.7)); //10
		table.addVertex(point3(0.7, -0.15, 0.75)); //11
		table.addVertex(point3(0.75, -0.75, 0.75)); //12
		table.addVertex(point3(0.75, -0.75, 0.7)); //13
		table.addVertex(point3(0.7, -0.75, 0.7)); //14
		table.addVertex(point3(0.7, -0.75, 0.75)); //15

		//Vẽ chân bàn 2
		table.addVertex(point3(-0.75, -0.15, 0.75)); //16
		table.addVertex(point3(-0.75, -0.15, 0.7)); //17
		table.addVertex(point3(-0.7, -0.15, 0.7)); //18
		table.addVertex(point3(-0.7, -0.15, 0.75)); //19
		table.addVertex(point3(-0.75, -0.75, 0.75)); //20
		table.addVertex(point3(-0.75, -0.75, 0.7)); //21
		table.addVertex(point3(-0.7, -0.75, 0.7)); //22
		table.addVertex(point3(-0.7, -0.75, 0.75)); //23

		//Vẽ chân bàn 3
		table.addVertex(point3(-0.75, -0.15, -0.75)); // 24
		table.addVertex(point3(-0.75, -0.15, -0.7)); // 25
		table.addVertex(point3(-0.7, -0.15, -0.7)); // 26
		table.addVertex(point3(-0.7, -0.15, -0.75)); // 27
		table.addVertex(point3(-0.75, -0.75, -0.75)); // 28
		table.addVertex(point3(-0.75, -0.75, -0.7)); // 29
		table.addVertex(point3(-0.7, -0.75, -0.7)); // 30
		table.addVertex(point3(-0.7, -0.75, -0.75)); // 31

		//Vẽ chân bàn 4
		table.addVertex(point3(0.75, -0.15, -0.75)); // 32
		table.addVertex(point3(0.75, -0.15, -0.7)); // 33
		table.addVertex(point3(0.7, -0.15, -0.7)); // 34
		table.addVertex(point3(0.7, -0.15, -0.75)); // 350
		table.addVertex(point3(0.75, -0.75, -0.75)); // 36
		table.addVertex(point3(0.75, -0.75, -0.7)); // 37
		table.addVertex(point3(0.7, -0.75, -0.7)); // 38
		table.addVertex(point3(0.7, -0.75, -0.75)); // 39
		

		table.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(1, 5, 6, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 1
		table.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(12, 13, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(8, 12, 15, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(9, 13, 14, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(8, 9, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(11, 10, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 2
		table.addQuad(quadIndex(16, 17, 18, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(20, 21, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(16, 20, 23, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(17, 21, 22, 18, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(16, 17, 21, 20, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(19, 18, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 3
		table.addQuad(quadIndex(24, 25, 26, 27, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(28, 29, 30, 31, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(24, 28, 31, 27, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(25, 29, 30, 26, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(24, 25, 29, 28, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(27, 25, 30, 31, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân bàn 4
		table.addQuad(quadIndex(32, 33, 34, 35, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(36, 37, 38, 39, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(32, 36, 39, 35, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(33, 37, 38, 34, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(32, 33, 37, 36, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		table.addQuad(quadIndex(35, 33, 38, 39, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		table_t1 = point3(-2, -0.8, 0);
		table_t2 = point3(0, -0.8, 0);
		table_t3 = point3(2, -0.8, 0);
		table_t4 = point3(-2, -0.8, -3);
		table_t5 = point3(0, -0.8, -3);
		table_t6 = point3(2, -0.8, -3);
		table_t7 = point3(-2, -0.8, 3);
		table_t8 = point3(0, -0.8, 3);
		table_t9 = point3(2, -0.8, 3);
	}

	void makeChair() {
		chair.clear();
		chair.setTextureFromBMP("data/table.bmp");
		chair.addVertex(point3(-0.45, -0.3, 0.45)); // 0
		chair.addVertex(point3(0.45, -0.3, 0.45)); // 1
		chair.addVertex(point3(0.45, -0.3, -0.45)); // 2
		chair.addVertex(point3(-0.45, -0.3, -0.45)); // 3
		chair.addVertex(point3(-0.45, -0.35, 0.45)); // 4
		chair.addVertex(point3(0.45, -0.35, 0.45)); // 5
		chair.addVertex(point3(0.45, -0.35, -0.45)); // 6
		chair.addVertex(point3(-0.45, -0.35, -0.45)); // 7

		//Vẽ chân ghế 1
		chair.addVertex(point3(0.45, -0.35, 0.45)); //8
		chair.addVertex(point3(0.45, -0.35, 0.4)); //9
		chair.addVertex(point3(0.4, -0.35, 0.4)); //10
		chair.addVertex(point3(0.4, -0.35, 0.45)); //11
		chair.addVertex(point3(0.45, -0.75, 0.45)); //12
		chair.addVertex(point3(0.45, -0.75, 0.4)); //13
		chair.addVertex(point3(0.4, -0.75, 0.4)); //14
		chair.addVertex(point3(0.4, -0.75, 0.45)); //15

		//Vẽ chân ghế 2
		chair.addVertex(point3(-0.45, -0.35, 0.45)); //16
		chair.addVertex(point3(-0.45, -0.35, 0.4)); //17
		chair.addVertex(point3(-0.4, -0.35, 0.4)); //18
		chair.addVertex(point3(-0.4, -0.35, 0.45)); //19
		chair.addVertex(point3(-0.45, -0.75, 0.45)); //20
		chair.addVertex(point3(-0.45, -0.75, 0.4)); //21
		chair.addVertex(point3(-0.4, -0.75, 0.4)); //22
		chair.addVertex(point3(-0.4, -0.75, 0.45)); //23

		//Vẽ chân ghế 3
		chair.addVertex(point3(-0.45, -0.35, -0.45)); //24
		chair.addVertex(point3(-0.45, -0.35, -0.4)); //25
		chair.addVertex(point3(-0.4, -0.35, -0.4)); //26
		chair.addVertex(point3(-0.4, -0.35, -0.45)); //27
		chair.addVertex(point3(-0.45, -0.75, -0.45)); //28
		chair.addVertex(point3(-0.45, -0.75, -0.4)); //29
		chair.addVertex(point3(-0.4, -0.75, -0.4)); //30
		chair.addVertex(point3(-0.4, -0.75, -0.45)); //31

		//Vẽ chân ghế 4
		chair.addVertex(point3(0.45, -0.35, -0.45)); //32
		chair.addVertex(point3(0.45, -0.35, -0.4)); //33
		chair.addVertex(point3(0.4, -0.35, -0.4)); //34
		chair.addVertex(point3(0.4, -0.35, -0.45)); //35
		chair.addVertex(point3(0.45, -0.75, -0.45)); //36
		chair.addVertex(point3(0.45, -0.75, -0.4)); //37
		chair.addVertex(point3(0.4, -0.75, -0.4)); //38
		chair.addVertex(point3(0.4, -0.75, -0.45)); //39

		//Vẽ lưng ghế
		chair.addVertex(point3(-0.4, 1, -0.4)); // 40
		chair.addVertex(point3(0.4, 1, -0.4)); // 41
		chair.addVertex(point3(0.45, 1, -0.45)); // 42
		chair.addVertex(point3(-0.45, 1, -0.45)); // 43
		chair.addVertex(point3(-0.4, -0.3, -0.4)); // 44
		chair.addVertex(point3(0.4, -0.3, -0.4)); // 45
		chair.addVertex(point3(0.45, -0.3, -0.45)); // 46
		chair.addVertex(point3(-0.45, -0.3, -0.45)); // 47


		//Vẽ mặt ghế
		chair.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(1, 5, 6, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 1
		chair.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(12, 13, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(8, 12, 15, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(9, 13, 14, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(8, 9, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(11, 10, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 2
		chair.addQuad(quadIndex(16, 17, 18, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(20, 21, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(16, 20, 23, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(17, 21, 22, 18, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(16, 17, 21, 20, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(19, 18, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		
		//chân 3
		chair.addQuad(quadIndex(24, 25, 26, 27, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(28, 29, 30, 31, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(24, 28, 31, 27, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(25, 29, 30, 26, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(24, 25, 29, 28, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(27, 25, 30, 31, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân bàn 4
		chair.addQuad(quadIndex(32, 33, 34, 35, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(36, 37, 38, 39, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(32, 36, 39, 35, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(33, 37, 38, 34, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(32, 33, 37, 36, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(35, 33, 38, 39, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//Vẽ lưng ghế
		chair.addQuad(quadIndex(40, 41, 42, 43, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(44, 45, 46, 47, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(40, 44, 47, 43, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(41, 45, 46, 42, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(40, 41, 45, 44, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair.addQuad(quadIndex(43, 42, 46, 47, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		
		chair_t1 = point3(-2, -0.8, 1.5);
		chair_t2 = point3(0, -0.8, 1.5);
		chair_t3 = point3(2, -0.8, 1.5);
		chair_t4 = point3(-2, -0.8, -1.5);
		chair_t5 = point3(0, -0.8, -1.5);
		chair_t6 = point3(2, -0.8, -1.5);
		chair_t7 = point3(-2, -0.8, -4.5);
		chair_t8 = point3(0, -0.8, -4.5);
		chair_t9 = point3(2, -0.8, -4.5);
		
	}

	void makeChair2() {
		chair2.clear();
		chair2.setTextureFromBMP("data/table.bmp");
		chair2.addVertex(point3(-0.45, -0.3, 0.45)); // 0
		chair2.addVertex(point3(0.45, -0.3, 0.45)); // 1
		chair2.addVertex(point3(0.45, -0.3, -0.45)); // 2
		chair2.addVertex(point3(-0.45, -0.3, -0.45)); // 3
		chair2.addVertex(point3(-0.45, -0.35, 0.45)); // 4
		chair2.addVertex(point3(0.45, -0.35, 0.45)); // 5
		chair2.addVertex(point3(0.45, -0.35, -0.45)); // 6
		chair2.addVertex(point3(-0.45, -0.35, -0.45)); // 7

		//Vẽ chân ghế 1
		chair2.addVertex(point3(0.45, -0.35, 0.45)); //8
		chair2.addVertex(point3(0.45, -0.35, 0.4)); //9
		chair2.addVertex(point3(0.4, -0.35, 0.4)); //10
		chair2.addVertex(point3(0.4, -0.35, 0.45)); //11
		chair2.addVertex(point3(0.45, -0.75, 0.45)); //12
		chair2.addVertex(point3(0.45, -0.75, 0.4)); //13
		chair2.addVertex(point3(0.4, -0.75, 0.4)); //14
		chair2.addVertex(point3(0.4, -0.75, 0.45)); //15

		//Vẽ chân ghế 2
		chair2.addVertex(point3(-0.45, -0.35, 0.45)); //16
		chair2.addVertex(point3(-0.45, -0.35, 0.4)); //17
		chair2.addVertex(point3(-0.4, -0.35, 0.4)); //18
		chair2.addVertex(point3(-0.4, -0.35, 0.45)); //19
		chair2.addVertex(point3(-0.45, -0.75, 0.45)); //20
		chair2.addVertex(point3(-0.45, -0.75, 0.4)); //21
		chair2.addVertex(point3(-0.4, -0.75, 0.4)); //22
		chair2.addVertex(point3(-0.4, -0.75, 0.45)); //23

		//Vẽ chân ghế 3
		chair2.addVertex(point3(-0.45, -0.35, -0.45)); //24
		chair2.addVertex(point3(-0.45, -0.35, -0.4)); //25
		chair2.addVertex(point3(-0.4, -0.35, -0.4)); //26
		chair2.addVertex(point3(-0.4, -0.35, -0.45)); //27
		chair2.addVertex(point3(-0.45, -0.75, -0.45)); //28
		chair2.addVertex(point3(-0.45, -0.75, -0.4)); //29
		chair2.addVertex(point3(-0.4, -0.75, -0.4)); //30
		chair2.addVertex(point3(-0.4, -0.75, -0.45)); //31

		//Vẽ chân ghế 4
		chair2.addVertex(point3(0.45, -0.35, -0.45)); //32
		chair2.addVertex(point3(0.45, -0.35, -0.4)); //33
		chair2.addVertex(point3(0.4, -0.35, -0.4)); //34
		chair2.addVertex(point3(0.4, -0.35, -0.45)); //35
		chair2.addVertex(point3(0.45, -0.75, -0.45)); //36
		chair2.addVertex(point3(0.45, -0.75, -0.4)); //37
		chair2.addVertex(point3(0.4, -0.75, -0.4)); //38
		chair2.addVertex(point3(0.4, -0.75, -0.45)); //39

		//Vẽ lưng ghế
		chair2.addVertex(point3(0.4, 1, 0.4)); // 40
		chair2.addVertex(point3(-0.4, 1, 0.4)); // 41
		chair2.addVertex(point3(-0.45, 1, 0.45)); // 42
		chair2.addVertex(point3(0.45, 1, 0.45)); // 43
		chair2.addVertex(point3(0.4, -0.3, 0.4)); // 44
		chair2.addVertex(point3(-0.4, -0.3, 0.4)); // 45
		chair2.addVertex(point3(-0.45, -0.3, 0.45)); // 46
		chair2.addVertex(point3(0.45, -0.3, 0.45)); // 47


		//Vẽ mặt ghế
		chair2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(1, 5, 6, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 1
		chair2.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(12, 13, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(8, 12, 15, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(9, 13, 14, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(8, 9, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(11, 10, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 2
		chair2.addQuad(quadIndex(16, 17, 18, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(20, 21, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(16, 20, 23, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(17, 21, 22, 18, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(16, 17, 21, 20, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(19, 18, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân 3
		chair2.addQuad(quadIndex(24, 25, 26, 27, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(28, 29, 30, 31, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(24, 28, 31, 27, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(25, 29, 30, 26, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(24, 25, 29, 28, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(27, 25, 30, 31, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//chân bàn 4
		chair2.addQuad(quadIndex(32, 33, 34, 35, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(36, 37, 38, 39, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(32, 36, 39, 35, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(33, 37, 38, 34, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(32, 33, 37, 36, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(35, 33, 38, 39, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//Vẽ lưng ghế
		chair2.addQuad(quadIndex(40, 41, 42, 43, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(44, 45, 46, 47, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(40, 44, 47, 43, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(41, 45, 46, 42, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(40, 41, 45, 44, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		chair2.addQuad(quadIndex(43, 42, 46, 47, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));


		chair2_t1 = point3(-5, -0.8, 6);

	}

	void makeBookShelf() {
		bookshelf.clear();
		bookshelf.setTextureFromBMP("data/bookshelf.bmp");
		bookshelf.addVertex(point3(-0.5, 2, 1.5)); // 0
		bookshelf.addVertex(point3(0.5, 2, 1.5)); // 1
		bookshelf.addVertex(point3(0.5, 2, -1.5)); // 2
		bookshelf.addVertex(point3(-0.5, 2, -1.5)); // 3
		bookshelf.addVertex(point3(-0.5, -0.8, 1.5)); // 4
		bookshelf.addVertex(point3(0.5, -0.8, 1.5)); // 5
		bookshelf.addVertex(point3(0.5, -0.8, -1.5)); // 6
		bookshelf.addVertex(point3(-0.5, -0.8, -1.5)); // 7

		bookshelf.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bookshelf.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bookshelf.addQuad(quadIndex(0, 3, 7, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bookshelf.addQuad(quadIndex(2, 1, 5, 6, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bookshelf.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		bookshelf.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		bookshelf_t = point3(6.25,-0.8,-5);
	}

	void makeBuc() {
		buc.clear();
		buc.setTextureFromBMP("data/buc.bmp");
		buc.addVertex(point3(-0.4, -0.6, 0.4)); // 0
		buc.addVertex(point3(0.4, -0.6, 0.4)); // 1
		buc.addVertex(point3(0.4, -0.6, -0.4)); // 2
		buc.addVertex(point3(-0.4, -0.6, -0.4)); // 3
		buc.addVertex(point3(-0.4, -0.8, 0.4)); // 4
		buc.addVertex(point3(0.4, -0.8, 0.4)); // 5
		buc.addVertex(point3(0.4, -0.8, -0.4)); // 6
		buc.addVertex(point3(-0.4, -0.8, -0.4)); // 7

		buc.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(0, 3, 7, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(1, 5, 6, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		buc.addVertex(point3(-0.25, -0.6, 0.25)); // 8
		buc.addVertex(point3(0.25, -0.6, 0.25)); // 9
		buc.addVertex(point3(0.25, -0.6, -0.25)); // 10
		buc.addVertex(point3(-0.25, -0.6, -0.25)); // 11
		buc.addVertex(point3(-0.3, 0.2, 0.3)); // 12
		buc.addVertex(point3(0.3, 0.2, 0.3)); // 13
		buc.addVertex(point3(0.3, 0.2, -0.3)); // 14
		buc.addVertex(point3(-0.3, 0.2, -0.3)); // 15

		buc.addQuad(quadIndex(8, 9, 10, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(12, 13, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(8, 12, 15, 11, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(9, 13, 14, 10, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(8, 9, 13, 12, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(11, 10, 14, 15, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		buc.addVertex(point3(-0.4, 0.2, 0.4)); //16
		buc.addVertex(point3(0.4, 0.2, 0.4)); //17
		buc.addVertex(point3(0.4, 0.2, -0.4)); //18
		buc.addVertex(point3(-0.4, 0.2, -0.4)); //19
		buc.addVertex(point3(-0.4, 0.3, 0.4)); //20
		buc.addVertex(point3(0.4, 0.3, 0.4)); //21
		buc.addVertex(point3(0.4, 0.5, -0.4)); //22
		buc.addVertex(point3(-0.4, 0.5, -0.4)); //23

		buc.addQuad(quadIndex(16, 17, 18, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(20, 21, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(16, 20, 23, 19, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(17, 21, 22, 18, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(16, 17, 21, 20, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		buc.addQuad(quadIndex(19, 18, 22, 23, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		buc_t = point3(-5, -0.8, 5);
	}

	void makeClock()
	{
		clock.clear();
		clock.setTextureFromBMP("data/dongho.bmp");
		clock.addVertex(point3(-6.2, 0.8, 6.94));//0
		clock.addVertex(point3(-5.55, 0.8, 6.94));//1
		clock.addVertex(point3(-6.2, 1.35, 6.94));//2
		clock.addVertex(point3(-5.55, 1.35, 6.94));//3
		clock.addVertex(point3(-6.2, 0.8, 7));//4
		clock.addVertex(point3(-5.55, 0.8, 7));//5
		clock.addVertex(point3(-6.2, 1.35, 7));//6
		clock.addVertex(point3(-5.55, 1.35, 7));//7
		clock.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		clock.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 0), texCoord2(0, 0), texCoord2(0, 0), texCoord2(0, 0))); //
		clock.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 0), texCoord2(0, 0), texCoord2(0, 0), texCoord2(0, 0))); //
		clock.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 0), texCoord2(0, 0), texCoord2(0, 0), texCoord2(0, 0))); //

		clock_t = point3(6, 0.75, 0);
	}

	void drawTables() {
		draw(&table, table_t1);
		draw(&table, table_t2);
		draw(&table, table_t3);
		draw(&table, table_t4);
		draw(&table, table_t5);
		draw(&table, table_t6);
		draw(&table, table_t7);
		draw(&table, table_t8);
		draw(&table, table_t9);
	}

	void drawChairs() {
		draw(&chair, chair_t1);
		draw(&chair, chair_t2);
		draw(&chair, chair_t3);
		draw(&chair, chair_t4);
		draw(&chair, chair_t5);
		draw(&chair, chair_t6);
		draw(&chair, chair_t7);
		draw(&chair, chair_t8);
		draw(&chair, chair_t9);
	}


	void makeBoard() {
		board.clear();
		board.setTextureFromBMP("data/board.bmp");
		board.addVertex(point3(-5, 1, 6.9));
		board.addVertex(point3(5, 1, 6.9));
		board.addVertex(point3(5, -0.8, 6.9));
		board.addVertex(point3(-5, -0.8, 6.9));
		board.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		//board_t = point3(0, 1.5, 0);
	}

	void resize(int width, int height) {
		if (height == 0) height = 1;
		const float ar = (float)width / (float)height;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, ar, 0.1f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();

		gluLookAt(x, -0.5, z,
			x + lx, height_view, z + lz,
			0.0f, 2.0f, 0.0f);

		glEnable(GL_TEXTURE_2D);


		draw(&sky, sky_t);
		draw(&skyTop, skyTop_t);
		for (int x1 = -5; x1 < 5; x1++) {
			for (int z1 = -5; z1 < 5; z1++) {
				Vector3 ground_t1;
				ground_t1.x = x1;
				ground_t1.z = z1;
				ground_t1.y = 0;

				draw(&ground, ground_t1);
			}
		}
		draw(&floor, floor_t);
		draw(&horizontalWall, horizontalWall_t);
		draw(&verticalWall, verticalWall_t);
		draw(&bookshelf, bookshelf_t);
		drawTables();
		drawChairs();
		draw(&board, board_t);
		draw(&buc, buc_t);
		draw(&clock, clock_t);
		draw(&chair2, chair2_t1);

		glutSwapBuffers();
		glFlush();
	}
	void processKeys(unsigned char key, int xx, int yy) {
		switch (key) {
		case '>':
			speed += 0.1;
			break;
		case '<':
			speed -= 0.1;
			break;
		case 'w':
			if (heightAngle < PI / 2) {
				heightAngle += 0.2;
				height_view = sin(heightAngle) - 1;
			}
			break;
		case 's':
			if (heightAngle > (-PI / 2)) {
				heightAngle -= 0.2;
				height_view = sin(heightAngle) - 1;
			}
			break;
		case 'a':
			angle -= 0.02f;
			lx = cos(angle);
			lz = sin(angle);
			break;
		case 'd':
			angle += 0.02f;
			lx = cos(angle);
			lz = sin(angle);
			break;
		default:
			break;
		}
		glutPostRedisplay();
	}
	void processSpecialKeys(int key, int xx, int yy) {

		float fraction = speed;

		switch (key) {
		case GLUT_KEY_LEFT:
			x += lz * fraction;
			z -= lx * fraction;
			break;
		case GLUT_KEY_RIGHT:
			x -= lz * fraction;
			z += lx * fraction;
			break;
		case GLUT_KEY_UP:
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		}glutPostRedisplay();
	}

	void init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		lx = cos(angle);
		lz = sin(angle);

		makeSky();
		makeSkyTop();
		makeGround();
		makeFloor();
		makeVerticalWall();
		makeHorizontalWall();
		makeBookShelf();
		makeBoard();
		makeTable();
		makeChair();
		makeBuc();
		makeClock();
		makeChair2();

	}
}
int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("ClassRoom3Dd");
	glEnable(GL_DEPTH_TEST);

	glutReshapeFunc(program::resize);
	glutKeyboardFunc(program::processKeys);
	glutSpecialFunc(program::processSpecialKeys);
	glutDisplayFunc(program::renderScene);
	program::init();

	glutMainLoop();
	return 0;
}