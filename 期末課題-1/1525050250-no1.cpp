/*
1525050250

�y�v���O�����̎g�����z
�E�}�E�X���{�^�������ŁuK�v�݂̂��点��^�����s���B
�E�}�E�X�E�{�^�������ŁuJ�v�݂̂����]���Ȃ���Ay���������ɕ��s�ړ�����B
�E�}�E�X���ƉE�̃{�^���𓯎��ɉ����ƁA�����̓��������A��������Ă���Ƃ��͒�~����B

�y�v���O�����̐����z
�e�ӂ̒�����1�̗����̂�void solid�ŕ\�����A�����̂̑傫����glScaled�ŐL�k�������̂�g�ݍ��킹�邱�ƂŁA�������\�������B
�uK�v�̕����́A���F0.5�A�c�F1.0�A���s���F0.2�̒����ɕς���8�̗����̂�g�ݍ��킹�č쐬�����B
�uJ�v�̕����́A���F1.0�A�c�F0,5�A���s���F0.2�̒����ɕς���3�̗����̂ƁA
���F0.5�A�c�F0.5�A���s���F0.2�̒����ɕς���6�̗����̂�g�ݍ��킹�č쐬�����B

�܂��A�}�`�ɂ͐F�̃��C�g�����W�i7.0, 5.0, -6.0�j�ɁA
�ΐF�̃��C�g�����W�i-7.0, 5.0, -6.0�j�ɒu���Ă���B

����J�����_
�E�uK�v�̕������쐬����ہAK�̕����̎΂ߕ����u�^�v��\�����邽�߂ɗ����̂�-45��]�����A
�@�����K�̕����̒��������u�b�v�Ƃ̊ԂɌ��Ԃ��ł��Ȃ��悤�ɂ��܂��v�Z���ė����̂�ݒu�����_�B(�v���O��������5�A6�Ԗڂɐݒu���Ă��闧��)
�@�܂��A�΂ߕ����͓�̗����̂��Ȃ��ĕ\�����Ă��邪�A�΂߂ɉ�]������̗����̂��Ȃ����킹��ۂ��A
  ���ꂸ�ɁA���A���܂���̉�����悤�ɂ悤�Ɍv�Z���Č��Ԃ̖����悤�ɂ����_�B

�E�}�E�X�̍��E�̃N���b�N�Ɋe�X�̐}�`�̉^����A��������ۂ́A�}�`����]������Ƃ��ɍ��E�ŘA�����ĉ�]���Ȃ��悤�ɁA
  ���E�̃}�E�X�̃{�^���ɑΉ������ϐ�s, t���g�p���邱�ƂŁA�Ɨ��ɉ^��������悤�ɍH�v���Â炵���_�B

���A�s�[���|�C���g
�E�uK�v�́A�ŏ��͂点��^�������A���a10�̋O���ɂȂ�ƁA���̂܂ܔ��a10�̋O���ŉ�]��������悤�ɂ����B

�E�uJ�v�́A���]���Ȃ���y�����̕����ɕ��s�ړ����A�E�[�ix����15�j�܂ł����ƁA���[�ix����-15�j����o�����A
   ���l�̉^�����J��Ԃ��悤�ɂ��邱�ƂŁA��i�̎�������ۂ����B

�E�L�[�{�[�h�́ur�v�̃{�^���������ƁA�u���Z�b�g�v����i��̕����uK�v�ƁuJ�v��������Ԃɖ߂��j�@�\���������Ă���B

�E�L�[�{�[�h�́uq�v�A�uQ�v�܂��́uESC�L�[�v�������ƁA�v���O�������I������@�\�����������B

�E�L�[�{�[�h�ɂ��@�\����́A���[�U�[��������₷���悤�Ƀv�����v�g�ŕ\�����Ă���B

�E���[�U�[�����₷���悤�ɁA�v���O�����N�����ɊJ���E�B���h�E�T�C�Y��640�~480�ɐݒ肵���B
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


	glPushMatrix();		/*K�̏����ݒ�*/
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
	  
	 glPopMatrix();		/*K�̕`��I��*/


	 glPushMatrix();		/*J�̏����ݒ�*/
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
	
	 glPopMatrix();		/*J�̕`��I��*/

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
	printf("���Z�b�g : 'r'\n�I���@�@ : 'q' or 'Q' or 'ESC key'");

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
