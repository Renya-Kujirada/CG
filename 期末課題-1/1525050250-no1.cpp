/*
1525050250

【プログラムの使い方】
・マウス左ボタン押下で「K」のみがらせん運動を行う。
・マウス右ボタン押下で「J」のみが自転しながら、y軸正方向に平行移動する。
・マウス左と右のボタンを同時に押すと、両方の動きをし、両方離れているときは停止する。

【プログラムの説明】
各辺の長さが1の立方体をvoid solidで表現し、立方体の大きさをglScaledで伸縮したものを組み合わせることで、文字を構成した。
「K」の文字は、横：0.5、縦：1.0、奥行き：0.2の長さに変えた8つの立方体を組み合わせて作成した。
「J」の文字は、横：1.0、縦：0,5、奥行き：0.2の長さに変えた3つの立方体と、
横：0.5、縦：0.5、奥行き：0.2の長さに変えた6つの立方体を組み合わせて作成した。

また、図形には青色のライトを座標（7.0, 5.0, -6.0）に、
緑色のライトを座標（-7.0, 5.0, -6.0）に置いている。

□苦労した点
・「K」の文字を作成する際、Kの文字の斜め部分「／」を表現するために立方体を-45回転させ、
　さらにKの文字の直線部分「｜」との間に隙間ができないようにうまく計算して立方体を設置した点。(プログラム中の5、6番目に設置している立体)
　また、斜め部分は二つの立方体をつなげて表現しているが、斜めに回転した二つの立方体をつなぎ合わせる際も、
  離れずに、かつ、うまく一体化するようにように計算して隙間の無いようにした点。

・マウスの左右のクリックに各々の図形の運動を連動させる際は、図形を回転させるときに左右で連動して回転しないように、
  左右のマウスのボタンに対応した変数s, tを使用することで、独立に運動させるように工夫を凝らした点。

□アピールポイント
・「K」は、最初はらせん運動をし、半径10の軌道になると、そのまま半径10の軌道で回転し続けるようにした。

・「J」は、自転しながらy軸正の方向に平行移動し、右端（x軸の15）までいくと、左端（x軸の-15）から出現し、
   同様の運動を繰り返すようにすることで、作品の周期性を保った。

・キーボードの「r」のボタンを押すと、「リセット」する（二つの文字「K」と「J」を初期状態に戻す）機能を実装している。

・キーボードの「q」、「Q」または「ESCキー」を押すと、プログラムを終了する機能を実装した。

・キーボードによる機能操作は、ユーザーが分かりやすいようにプロンプトで表示してある。

・ユーザーが見やすいように、プログラム起動時に開くウィンドウサイズを640×480に設定した。
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLdouble vertex[][3] = {
	{ -0.5, 0.5, 0.5 },
	{ -0.5, -0.5, 0.5 },
	{ 0.5, -0.5, 0.5 },
	{ 0.5, 0.5, 0.5 },
	{ -0.5, 0.5, -0.5 },
	{ -0.5, -0.5, -0.5 },
	{ 0.5, -0.5, -0.5 },
	{ 0.5, 0.5, -0.5 }
};

int face[][4] = {
	{ 0, 1, 2, 3 },
	{ 4, 5, 1, 0 },
	{ 4, 0, 3, 7 },
	{ 1, 5, 6, 2 },
	{ 3, 2, 6, 7 },
	{ 7, 6, 5, 4 }
};

GLdouble normal[][3] = {
	{ 0.0, 0.0, -1.0 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, -1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ -1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 }
};

GLfloat light0pos[] = { 7.0, 5.0, -6.0, 1.0 };
GLfloat light1pos[] = { -7.0, 5.0, -6.0, 1.0 };
GLfloat blue[] = { 0.0, 0.0, 0.8, 1.0 };
GLfloat green[] = { 0.0, 0.8, 0.0, 1.0 };

int s = 0, t = 0;
double r1 = 0.0, r2 = 0.0, t1 = 0.0, t2 = 0.0;

void idle(void)
{
	glutPostRedisplay();
}

void solid() {
	int i, j;
	glBegin(GL_QUADS);
	for (i = 0; i < 6; i++) {
		glNormal3dv(normal[i]);
		for (j = 0; j < 4; j++) {
			glVertex3dv(vertex[face[i][j]]);
		}
	}
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(1.0, 3.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, light1pos);


	glPushMatrix();		/*Kの初期設定*/
	 glRotated(r1, 0.0, 1.0, 0.0);
	 glTranslated(t1, 0.0, 0.0);

	  glPushMatrix();
	   glTranslated(-2.5, 2.0, 0.0);
	   glScaled(0.5, 0.75, 0.2);
	   solid();			// 1
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-2.5, 1.25, 0.0);
	   glScaled(0.5, 0.75, 0.2);
	   solid();			// 2
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-2.5, 0.5, 0.0);
	   glScaled(0.5, 0.75, 0.2);
	   solid();			// 3
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-2.5, -0.25, 0.0);
	   glScaled(0.5, 0.75, 0.2);
	   solid();			// 4
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-2.2, 1.0, 0.0);
	   glRotated(-45.0, 0.0, 0.0, 1.0);
	   glScaled(0.5, 1.0, 0.2);
	   solid();			// 5
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-1.5, 1.7, 0.0);
	   glRotated(-45.0, 0.0, 0.0, 1.0);
	   glScaled(0.5, 1.0, 0.2);
	   solid();			// 6
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-2.2, 0.6, 0.0);
	   glRotated(45.0, 0.0, 0.0, 1.0);
	   glScaled(0.5, 1.0, 0.2);
	   solid();			// 7
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(-1.5, -0.1, 0.0);
	   glRotated(45.0, 0.0, 0.0, 1.0);
	   glScaled(0.5, 1.0, 0.2);
	   solid();			// 8
	  glPopMatrix();
	  
	 glPopMatrix();		/*Kの描画終了*/


	 glPushMatrix();		/*Jの初期設定*/
	  glTranslated(t2, 0.0, 0.0);
	  glRotated(r2, 0.0, 1.0, 0.0);

	  glPushMatrix();
	   glTranslated(4.0, 2.0, 0.0);
	   glScaled(1.0, 0.5, 0.2);
	   solid();			// 1
	  glPopMatrix();
	
	  glPushMatrix();
	   glTranslated(3.0, 2.0, 0.0);
	   glScaled(1.0, 0.5, 0.2);
	   solid();			// 2
	  glPopMatrix();
	
	  glPushMatrix();
	   glTranslated(3.5, 1.5, 0.0);
	   glScaled(0.5, 0.5, 0.2);
	   solid();			// 3
	  glPopMatrix();
	   
	  glPushMatrix();
	   glTranslated(3.5, 1.0, 0.0);
	   glScaled(0.5, 0.5, 0.2);
	   solid();			// 4
	  glPopMatrix();
	
	  glPushMatrix();
	   glTranslated(3.5, 0.5, 0.0);
	   glScaled(0.5, 0.5, 0.2);
	   solid();			// 5
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(3.5, 0.0, 0.0);
	   glScaled(0.5, 0.5, 0.2);
	   solid();			// 6
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(3.5, -0.5, 0.0);
	   glScaled(0.5, 0.5, 0.2);
	   solid();			// 7
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(3.0, -0.5, 0.0);
	   glScaled(0.5, 0.5, 0.2);
	   solid();			// 8
	  glPopMatrix();

	  glPushMatrix();
	   glTranslated(2.5, -0.25, 0.0);
	   glScaled(0.5, 1.0, 0.2);
	   solid();			// 9
	  glPopMatrix();
	
	 glPopMatrix();		/*Jの描画終了*/

	if (s == 1) {
		r1 += 0.8;
		if (r1 == 360)	r1 = 0.0;
		if(t1 <= 10)	t1 += 0.01;
	}

	if (t == 1) {
		r2 += 0.8;
		t2 += 0.02;
		if (r2 == 360)	r2 = 0.0;
		if (t2 >= 15.0)	t2 = -15.0;
	}

	glutSwapBuffers();

}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 50.0);

	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			s = 1;
			glutIdleFunc(idle);
		}
		else {
			s = 0;
			if(t == 0) glutIdleFunc(0);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			t = 1;
			glutIdleFunc(idle);
		}
		else {
			t = 0;
			if(s == 0) glutIdleFunc(0);
		}
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'r': r1 = 0.0, r2 = 0.0, t1 = 0.0, t2 = 0.0;
			  break;
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
	default:
		break;
	}
}

void init(void)
{
	glClearColor(1., 1., 1., 1.);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, blue);
	glLightfv(GL_LIGHT0, GL_SPECULAR, blue);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, green);
	glLightfv(GL_LIGHT1, GL_SPECULAR, green);

}

int main(int argc, char *argv[])
{
	printf("リセット : 'r'\n終了　　 : 'q' or 'Q' or 'ESC key'");

	glutInitWindowSize(640, 480);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
