#include<Gl/glut.h>

#include<math.h>

#include<stdlib.h>

#include <stdio.h>

#include <mmsystem.h>

void display();
void init();
void reshape(int, int);
void timer(int);
void keyPressed(unsigned char key, int, int); // declare after include
void score_nums();
void score_calc(int);
void score_display();
void specialkey(int, int, int);

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1366, 768);

  glutCreateWindow("SHOOTOUT AT PULCHOWK");
  glutFullScreen();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyPressed);
  glutSpecialFunc(specialkey);
  glutTimerFunc(1000, timer, 0);
  init();

  glutMainLoop();

}
int counter = 0;
int zs = -2999;
int strigger = 0;
float x_position = 0;
float x_position22 = 0;
float y_position22 = 0;
float x_position2 = 0;
float x_position3 = 0;
float y_position2 = 0;
int state = 1;
int stater = 1, score;
int rec = 0;
float angler = 0;
int state2 = 1;
int state3 = 1;
int state4 = 1;
float shmangle = 0;
float angle = 0.0;
float ang = 0.0;
float radian = 0;
float zf = 0, xlr = 0;
int bulletstate = 0;
float bulletz = 550;
float bulletx = 0;
float bulletxa, bulletza;
float anglecir;

void display() {
  int x = 900, y = 506, z = 10000, z1 = 3000, z2 = 6000, z11 = 2999, z22 = 5999, z33 = 9999;
  float h1x = -90, h1z = -500, h2x = 120, h2z = -500, h3x = 130, h3z = -500, h4x = -100, h4z = -500, h5x = 150, h5z = -500, h6x = -120, h6z = -500, h7x = 160, h7z = -500, h8x = -130, h8z = -500, h9x = 165, h9z = -500, h10x = -130, h10z = -500, h11x = 160, h11z = -500, h12x = -125, h12z = -500, h13x = -40, h13z = -500, h14x = -40, h14z = -500, h15x = -115, h15z = -500, h16x = -40, h16z = -500, h17x = -100, h17z = -500, h18x = -40, h18z = -500, h19x = -90, h19z = -500, h20x = -47, h20z = -500, h21x = -60, h21z = -500, h22x = -75, h22z = -500, h23x = 40, h23z = -500, h24x = 150, h24z = -500, h25x = 40, h25z = -500, h26x = 130, h26z = -500, h27x = 40, h27z = -500, h28x = 100, h28z = -500, h29x = 40, h29z = -500, h30x = 70, h30z = -500, h31x = 60, h31z = -500, h32x = 40, h32z = -500;
  float g1x = -40, g1z = -500, g2x = 40, g2z = -500, g3x = 40, g3z = -500, g4x = -40, g4z = -500, g5x = 30, g5z = -500, g6x = -30, g6z = -500, g7x = -7, g7z = -500, g8x = 7, g8z = -500, g9x = 7, g9z = -500, g10x = -7, g10z = -500;
  float radius1 = 50, radius2 = 30, radius3 = 15;
  float s, c;

  float cogs, cogc;
  float xb, yb;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(angle, 0.0, 1.0, 0.0);
  glRotatef(angler, -cos(radian), 0.0, -tan(radian));
  glTranslatef(xlr, 0.0, zf);

  ang = angle; //conversion of angle into radian
  if (ang < 0) {
    ang = ang * -1;
    radian = 6.283 - ang * 0.017453;
  } else
    radian = ang * 0.017453;

  bulletz = bulletza + 550 * cos(radian) + zf;
  bulletx = bulletxa + 550 * sin(radian) - xlr;

  //hand and gun start
  s = sin(radian);
  c = -cos(radian);
  cogs = 500 * s - xlr;
  cogc = 500 * c - zf;
  h1x = cogs + 90 * c;
  h1z = cogc - 90 * s;
  h2x = cogs - 120 * c;
  h2z = cogc + 120 * s;
  h3x = cogs - 130 * c;
  h3z = cogc + 130 * s;
  h4x = cogs + 100 * c;
  h4z = cogc - 100 * s;
  h5x = cogs - 150 * c;
  h5z = cogc + 150 * s;
  h6x = cogs + 120 * c;
  h6z = cogc - 120 * s;
  h7x = cogs - 160 * c;
  h7z = cogc + 160 * s;
  h8x = cogs + 130 * c;
  h8z = cogc - 130 * s;
  h9x = cogs - 165 * c;
  h9z = cogc + 165 * s;
  h10x = cogs + 130 * c;
  h10z = cogc - 130 * s;
  h11x = cogs - 160 * c;
  h11z = cogc + 160 * s;
  h12x = cogs + 125 * c;
  h12z = cogc - 125 * s;
  h13x = cogs + 40 * c;
  h13z = cogc - 40 * s;
  h14x = cogs + 40 * c;
  h14z = cogc - 40 * s;
  h15x = cogs + 115 * c;
  h15z = cogc - 115 * s;
  h16x = cogs + 40 * c;
  h16z = cogc - 40 * s;
  h17x = cogs + 100 * c;
  h17z = cogc - 100 * s;
  h18x = cogs + 40 * c;
  h18z = cogc - 40 * s;
  h19x = cogs + 90 * c;
  h19z = cogc - 90 * s;
  h20x = cogs + 47 * c;
  h20z = cogc - 47 * s;
  h21x = cogs + 60 * c;
  h21z = cogc - 60 * s;
  h22x = cogs + 75 * c;
  h22z = cogc - 75 * s;
  h23x = cogs - 40 * c;
  h23z = cogc + 40 * s;
  h24x = cogs - 150 * c;
  h24z = cogc + 150 * s;
  h25x = cogs - 40 * c;
  h25z = cogc + 40 * s;
  h26x = cogs - 130 * c;
  h26z = cogc + 130 * s;
  h27x = cogs - 40 * c;
  h27z = cogc + 40 * s;
  h28x = cogs - 100 * c;
  h28z = cogc + 100 * s;
  h29x = cogs - 40 * c;
  h29z = cogc + 40 * s;
  h30x = cogs - 70 * c;
  h30z = cogc + 70 * s;
  h31x = cogs - 60 * c;
  h31z = cogc + 60 * s;
  h32x = cogs - 40 * c;
  h32z = cogc + 40 * s;

  g1x = cogs + 40 * c;
  g1z = cogc - 40 * s;
  g2x = cogs - 40 * c;
  g2z = cogc + 40 * s;
  g3x = cogs - 40 * c;
  g3z = cogc + 40 * s;
  g4x = cogs + 40 * c;
  g4z = cogc - 40 * s;
  g5x = cogs - 30 * c;
  g5z = cogc + 30 * s;
  g6x = cogs + 30 * c;
  g6z = cogc - 30 * s;
  g7x = cogs + 7 * c;
  g7z = cogc - 7 * s;
  g8x = cogs - 7 * c;
  g8z = cogc + 7 * s;
  g9x = cogs - 7 * c;
  g9z = cogc + 7 * s;
  g10x = cogs + 7 * c;
  g10z = cogc - 7 * s;

  //hand and gun end
  if (zf < 3000 && zf > 0)
    zs = -2999;
  if (zf < 6000 && zf > 3000)
    zs = -5999;
  if (zf < 10000 && zf > 6000)
    zs = -9999;

  if (zf < 3000 && bulletz > 3100) {
    bulletza = 0;
    bulletxa = 0;
    bulletstate = 0;
  }
  if (zf < 6000 && bulletz > 6100) {
    bulletza = 0;
    bulletxa = 0;
    bulletstate = 0;
  }

  if (zf < 10000 && bulletz > 10100) {
    bulletza = 0;
    bulletxa = 0;
    bulletstate = 0;
  }
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON); //left wall
  glVertex3f(-x, y, -z);
  glVertex3f(-x, -y, -z);
  glVertex3f(-x, -y, 0.0);
  glVertex3f(-x, y, 0.0);
  glEnd();
  glColor3f(0.4, 0.8, 0.6);
  glBegin(GL_POLYGON); //front wall
  glVertex3f(x, y, -z);
  glVertex3f(x, -y, -z);
  glVertex3f(-x, -y, -z);
  glVertex3f(-x, y, -z);
  glEnd();
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON); //right wall
  glVertex3f(x, y, -z);
  glVertex3f(x, -y, -z);
  glVertex3f(x, -y, 0.0);
  glVertex3f(x, y, 0.0);
  glEnd();
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POLYGON); //floor
  glVertex3f(-x, -y, 0.0);
  glVertex3f(-x, -y, -z);
  glVertex3f(x, -y, -z);
  glVertex3f(x, -y, 0.0);
  glEnd();
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON); //ceiling
  glVertex3f(-x, y, 0.0);
  glVertex3f(-x, y, -z);
  glVertex3f(x, y, -z);
  glVertex3f(x, y, 0.0);
  glEnd();
  glColor3f(0.5, 0.7, 0.7);

  glBegin(GL_POLYGON); //1st wall
  glVertex3f(x, y, -z1);
  glVertex3f(x, 200, -z1);
  glVertex3f(383, 200, -z1);
  glVertex3f(383, y, -z1);
  glEnd();
  glBegin(GL_POLYGON); //big
  glVertex3f(383, y, -z1);
  glVertex3f(383, -y, -z1);
  glVertex3f(-x, -y, -z1);
  glVertex3f(-x, y, -z1);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex3f(850, y, -z1);
  glVertex3f(850, -y, -z1);
  glVertex3f(x, -y, -z1);
  glVertex3f(x, y, -z1);
  glEnd();

  glColor3f(0.4, 0.8, 0.4);
  glBegin(GL_POLYGON); //2nd wall
  glVertex3f(x, y, -z2); //big
  glVertex3f(x, -y, -z2);
  glVertex3f(-383, -y, -z2);
  glVertex3f(-383, y, -z2);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex3f(-383, y, -z2);
  glVertex3f(-383, 200, -z2);
  glVertex3f(-x, 200, -z2);
  glVertex3f(-x, y, -z2);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex3f(-850, y, -z2);
  glVertex3f(-850, -y, -z2);
  glVertex3f(-x, -y, -z2);
  glVertex3f(-x, y, -z2);
  glEnd();

  glLineWidth(1.5); //first wall lines
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, -100, -z11);
  glVertex3f(380, -100, -z11);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, -400, -z11);
  glVertex3f(-683, 200, -z11);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, -400, -z11);
  glVertex3f(380, -400, -z11);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, 200, -z11);
  glVertex3f(380, 200, -z11);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(380, 200, -z11);
  glVertex3f(380, -400, -z11);
  glEnd();

  glLineWidth(1.5); //second wall lines
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-380, -100, -z22);
  glVertex3f(683, -100, -z22);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-380, -400, -z22);
  glVertex3f(-380, 200, -z22);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-380, -400, -z22);
  glVertex3f(683, -400, -z22);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-380, 200, -z22);
  glVertex3f(683, 200, -z22);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(683, 200, -z22);
  glVertex3f(683, -400, -z22);
  glEnd();

  glLineWidth(1.5); //third wall lines
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, -100, -z33);
  glVertex3f(683, -100, -z33);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, -400, -z33);
  glVertex3f(-683, 200, -z33);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, -400, -z33);
  glVertex3f(683, -400, -z33);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(-683, 200, -z33);
  glVertex3f(683, 200, -z33);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(683, 200, -z33);
  glVertex3f(683, -400, -z33);
  glEnd();

  if (zf < 3000 && bulletz > 2973 && bulletz < 2973 + 51) {

    if (x_position + 25 > bulletx && x_position - 25 < bulletx) {
      score += 1;
      strigger = 1;
    }

  }
  if (zf < 6000 && bulletz > 6100 - 25 && bulletz > 6100 + 25) {
    if (x_position + 25 > bulletx && x_position - 25 < bulletx) {
      score += 3;
      strigger = 1;
    }

  }

  if (zf < 10000 && bulletz > 10100 - 25 && bulletz > 10100 + 25) {
    if (x_position + 25 > bulletx && x_position - 25 < bulletx) {
      score += 5;
      strigger = 1;
    }

  }
  if (counter == 45) {

    if (strigger == 1) {
      PlaySound("C:\\sound\\targethit.wav", NULL, NULL | SND_ASYNC);
      strigger = 0;
    }

  }
  score_display();

  glColor3f(1, 0.0, 0.0); //circle 1
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x_position, -100, -2998); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius1; //two vertex of triangle
    yb = cos(anglecir) * radius1;
    glVertex3f(x_position + xb, yb - 100, -2998);
  }
  glEnd();

  glColor3f(0.0, 1, 0.0); //circle 2
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x_position, -100, -2997); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius2; //two vertex of triangle
    yb = cos(anglecir) * radius2;
    glVertex3f(x_position + xb, yb - 100, -2997);
  }
  glEnd();

  glColor3f(0.0, 0.0, 1); //circle 3
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x_position, -100, -2996); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius3; //two vertex of triangle
    yb = cos(anglecir) * radius3;
    glVertex3f(x_position + xb, yb - 100, -2996);
  }
  glEnd();

  //second target triangle

  glColor3f(1, 0.0, 0.0); //circle 1
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f((x_position22), y_position22 - 100, -5998); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius1; //two vertex of triangle
    yb = cos(anglecir) * radius1;
    glVertex3f((x_position22) + xb, y_position22 + yb - 100, -5998);
  }
  glEnd();

  glColor3f(0.0, 1, 0.0); //circle 2
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f((x_position22), y_position22 - 100, -5997); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius2; //two vertex of triangle
    yb = cos(anglecir) * radius2;
    glVertex3f((x_position22) + xb, y_position22 + yb - 100, -5997);
  }
  glEnd();

  glColor3f(0.0, 0.0, 1); //circle 3
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f((x_position22), y_position22 - 100, -5996); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius3; //two vertex of triangle
    yb = cos(anglecir) * radius3;
    glVertex3f((x_position22) + xb, y_position22 + yb - 100, -5996);
  }
  glEnd();

  //third target sine

  glColor3f(1, 0.0, 0.0); //circle 1
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f((x_position2), y_position2 - 100, -9998); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius1; //two vertex of triangle
    yb = cos(anglecir) * radius1;
    glVertex3f((x_position2) + xb, y_position2 + yb - 100, -9998);
  }
  glEnd();

  glColor3f(0.0, 1, 0.0); //circle 2
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f((x_position2), y_position2 - 100, -9997); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius2; //two vertex of triangle
    yb = cos(anglecir) * radius2;
    glVertex3f((x_position2) + xb, y_position2 + yb - 100, -9997);
  }
  glEnd();

  glColor3f(0.0, 0.0, 1); //circle 3
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f((x_position2), y_position2 - 100, -9996); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius3; //two vertex of triangle
    yb = cos(anglecir) * radius3;
    glVertex3f((x_position2) + xb, y_position2 + yb - 100, -9996);
  }
  glEnd();

  //third target shm

  glColor3f(1, 0.0, 0.0); //circle 1
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x_position3, -100, -9998); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius1; //two vertex of triangle
    yb = cos(anglecir) * radius1;
    glVertex3f(x_position3 + xb, yb - 100, -9998);
  }
  glEnd();

  glColor3f(0.0, 1, 0.0); //circle 2
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x_position3, -100, -9997); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius2; //two vertex of triangle
    yb = cos(anglecir) * radius2;
    glVertex3f(x_position3 + xb, yb - 100, -9997);
  }
  glEnd();

  glColor3f(0.0, 0.0, 1); //circle 3
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x_position3, -100, -9996); //center
  for (anglecir = 1.0 f; anglecir < 361.0 f; anglecir += 0.2) {
    xb = sin(anglecir) * radius3; //two vertex of triangle
    yb = cos(anglecir) * radius3;
    glVertex3f(x_position3 + xb, yb - 100, -9996);
  }
  glEnd();
  glColor3f(0.0, 0.0, 0.0); //sphere bullet
  glPushMatrix();
  glTranslated(bulletx, -100.0, -bulletz);
  glutSolidSphere(10, 50, 50);
  glPopMatrix();

  glBegin(GL_POLYGON); //hand with gun
  glColor3ub(255, 218, 185);
  glVertex3f(h1x, -300, h1z);
  glColor3ub(210, 180, 140);
  glVertex3f(h2x, -300, h2z);
  glVertex3f(h3x, -280, h3z);
  glColor3ub(255, 218, 185);
  glVertex3f(h4x, -280, h4z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h4x, -280, h4z);
  glColor3ub(210, 180, 140);
  glVertex3f(h3x, -280, h3z);
  glVertex3f(h5x, -260, h5z);
  glColor3ub(255, 218, 185);
  glVertex3f(h6x, -260, h6z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h6x, -260, h6z);
  glColor3ub(210, 180, 140);
  glVertex3f(h5x, -260, h5z);
  glVertex3f(h7x, -240, h7z);
  glColor3ub(255, 218, 185);
  glVertex3f(h8x, -240, h8z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h8x, -240, h8z);
  glColor3ub(210, 180, 140);
  glVertex3f(h7x, -240, h7z);
  glVertex3f(h9x, -220, h9z);
  glColor3ub(255, 218, 185);
  glVertex3f(h10x, -220, h10z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h10x, -220, h10z);
  glColor3ub(210, 180, 140);
  glVertex3f(h9x, -220, h9z);
  glVertex3f(h11x, -200, h11z);
  glColor3ub(255, 218, 185);
  glVertex3f(h12x, -200, h12z);
  glEnd();
  //fingers  left
  glBegin(GL_POLYGON);
  glVertex3f(h12x, -200, h12z);
  glColor3ub(242, 207, 172);
  glVertex3f(h13x, -200, h13z);
  glVertex3f(h14x, -180, h14z);
  glColor3ub(255, 218, 185);
  glVertex3f(h15x, -180, h15z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h15x, -180, h15z);
  glColor3ub(242, 207, 172);
  glVertex3f(h14x, -180, h14z);
  glVertex3f(h16x, -160, h16z);
  glColor3ub(255, 218, 185);
  glVertex3f(h17x, -160, h17z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h17x, -160, h17z);
  glColor3ub(242, 207, 172);
  glVertex3f(h16x, -160, h16z);
  glVertex3f(h18x, -140, h18z);
  glColor3ub(255, 218, 185);
  glVertex3f(h19x, -140, h19z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h19x, -140, h19z);
  glColor3ub(242, 207, 172);
  glVertex3f(h18x, -140, h18z);
  glVertex3f(h20x, -130, h20z);
  glColor3ub(255, 218, 185);
  glVertex3f(h21x, -128, h21z);
  glVertex3f(h22x, -130, h22z);
  glEnd();

  //fingers right
  glBegin(GL_POLYGON);
  glColor3ub(229, 196, 159);
  glVertex3f(h23x, -200, h23z);
  glColor3ub(210, 180, 140);
  glVertex3f(h11x, -200, h11z);
  glVertex3f(h24x, -180, h24z);
  glColor3ub(229, 196, 159);
  glVertex3f(h25x, -180, h25z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h25x, -180, h25z);
  glColor3ub(210, 180, 140);
  glVertex3f(h24x, -180, h24z);
  glVertex3f(h26x, -160, h26z);
  glColor3ub(229, 196, 159);
  glVertex3f(h27x, -160, h27z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h27x, -160, h27z);
  glColor3ub(210, 180, 140);
  glVertex3f(h26x, -160, h26z);
  glVertex3f(h28x, -140, h28z);
  glColor3ub(229, 196, 159);
  glVertex3f(h29x, -140, h29z);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(h29x, -140, h29z);
  glColor3ub(210, 180, 140);
  glVertex3f(h28x, -140, h28z);
  glVertex3f(h30x, -120, h30z);
  glColor3ub(229, 196, 159);
  glVertex3f(h31x, -118, h31z);
  glVertex3f(h32x, -115, h32z);

  glEnd();

  glColor3ub(30, 20, 20); //gun
  glBegin(GL_POLYGON);
  glVertex3f(g1x, -200, g1z);
  glVertex3f(g2x, -200, g2z);
  glVertex3f(g3x, -120, g3z);
  glVertex3f(g4x, -120, g4z);
  glEnd();
  glColor3ub(30, 30, 30);
  glBegin(GL_POLYGON);
  glVertex3f(g4x, -120, g4z);
  glVertex3f(g3x, -120, g3z);
  glVertex3f(g5x, -80, g5z);
  glVertex3f(g6x, -80, g6z);
  glEnd();
  glColor3ub(30, 20, 20);
  glBegin(GL_POLYGON);
  glVertex3f(g7x, -80, g7z);
  glVertex3f(g8x, -80, g8z);
  glVertex3f(g9x, -70, g9z);
  glVertex3f(g10x, -70, g10z);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void init() // works like clrscr
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glEnable(GL_DEPTH_TEST);

}
void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1.777778, 1.0, 15000.0); //16:9=1.77 aspect ration, 70 degree field of view angle
  glMatrixMode(GL_MODELVIEW);
}

void timer(int) //clears screen in 1000milli sec/60
{
  glutPostRedisplay();
  glutTimerFunc(1000 / 240, timer, 0);
  if (bulletstate == 1) {
    bulletza += (50 * cos(radian));
    bulletxa += (50 * sin(radian));
  }

  counter++;

  switch (state) //for first target
  {
  case 1:
    if (x_position < 323) //it makes the object change coordinate so that it moves
    {

      x_position += 3;
    } else
      state = -1;
    break;
  case -1:
    if (x_position >= -623) {

      x_position -= 3;
    } else
      state = 1;
    break;
  }

  switch (state2) //for 3rd wall target sine horizontal
  {
  case 1:
    if (x_position2 < 623) //it makes the object change coordinate so that it moves
    {
      x_position2 += 1;
    } else
      state2 = -1;
    break;
  case -1:
    if (x_position2 >= -623) {
      x_position2 -= 1;
    } else
      state2 = 1;
    break;
  }
  switch (state3) //for 2nd wall target
  {
  case 1:
    if (x_position22 < 623) //it makes the object change coordinate so that it moves
    {
      x_position22 += 1;
    } else
      state3 = -1;
    break;
  case -1:
    if (x_position22 >= -323) {
      x_position22 -= 1;
    } else
      state3 = 1;
    break;
  }
  switch (state4) //for 2nd wall target vertical movement
  {
  case 1:
    if (y_position22 <= 100)
      y_position22 += 1;
    else
      state4 = -1;
    break;
  case -1:
    if (y_position22 >= -100)
      y_position22 -= 1;
    else
      state4 = 1;
    break;
  }

  y_position2 = 100 * sin(x_position2 / 50);
  if (shmangle >= 6.283) {
    shmangle = 0;
  }

  x_position3 = 623 * sin(shmangle);
  shmangle += 0.01;

  if (rec == 1) {
    switch (stater) {
    case 1:
      if (angler < 10)
        angler += 1;
      else
        stater = -1;
      break;
    case -1:
      if (angler > 0)
        angler -= 1;
      else
        rec = 0;
      break;
    }
  }
}
void keyPressed(unsigned char key, int x, int y) //moving object with keyboard
{

  switch (key) {

  case 'w':
    zf += (50 * (cos(radian)));
    xlr -= (50 * (sin(radian)));
    glutPostRedisplay();
    break;
  case 's':
    zf -= (50 * (cos(radian)));
    xlr += (50 * (sin(radian)));
    glutPostRedisplay();
    break;
  case 'a':
    zf += (50 * (sin(radian)));
    xlr += (50 * (cos(radian)));
    glutPostRedisplay();
    break;
  case 'd':

    zf -= (50 * (sin(radian)));
    xlr -= (50 * (cos(radian)));
    glutPostRedisplay();
    break;

  }

}
void specialkey(int key, int x, int y) //moving object with keyboard
{
  switch (key) {
  case GLUT_KEY_LEFT:
    angle -= 5;
    glutPostRedisplay();
    break;
  case GLUT_KEY_RIGHT:
    angle += 5;
    glutPostRedisplay();
    break;
  case GLUT_KEY_UP:
    bulletstate = 1;
    rec = 1;
    stater = 1;
    PlaySound("C:\\sound\\finalgun.wav", NULL, NULL | SND_ASYNC);
    glutPostRedisplay();
    break;
  }

}

void score_display() {

  int score1, score2;
  score2 = score % 10;
  score1 = (score - score2) / 10;

  glColor3f(0.0, 1.0, 1.0);
  glBegin(GL_QUADS);
  switch (score2) {
  case 1: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs);
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);
    break;
  }

  case 2: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(180, 380, zs); //4
    glVertex3f(160, 380, zs);
    glVertex3f(160, 320, zs);
    glVertex3f(180, 320, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }

  case 3: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }

  case 4: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(180, 460, zs); //5
    glVertex3f(160, 460, zs);
    glVertex3f(160, 400, zs);
    glVertex3f(180, 400, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }

  case 5: {

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(180, 460, zs); //5
    glVertex3f(160, 460, zs);
    glVertex3f(160, 400, zs);
    glVertex3f(180, 400, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }
  case 6: {

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(180, 380, zs); //4
    glVertex3f(160, 380, zs);
    glVertex3f(160, 320, zs);
    glVertex3f(180, 320, zs);

    glVertex3f(180, 460, zs); //5
    glVertex3f(160, 460, zs);
    glVertex3f(160, 400, zs);
    glVertex3f(180, 400, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }

  case 7: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }

  case 8: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(180, 380, zs); //4
    glVertex3f(160, 380, zs);
    glVertex3f(160, 320, zs);
    glVertex3f(180, 320, zs);

    glVertex3f(180, 460, zs); //5
    glVertex3f(160, 460, zs);
    glVertex3f(160, 400, zs);
    glVertex3f(180, 400, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;
  }
  case 9: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(180, 460, zs); //5
    glVertex3f(160, 460, zs);
    glVertex3f(160, 400, zs);
    glVertex3f(180, 400, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    glVertex3f(250, 390, zs); //7
    glVertex3f(190, 390, zs);
    glVertex3f(190, 370, zs);
    glVertex3f(250, 370, zs);
    break;

  }

  case 0: {
    glVertex3f(280, 460, zs);
    glVertex3f(260, 460, zs); //1
    glVertex3f(260, 400, zs);
    glVertex3f(280, 400, zs);

    glVertex3f(280, 380, zs); //2
    glVertex3f(260, 380, zs);
    glVertex3f(260, 320, zs);
    glVertex3f(280, 320, zs);

    glVertex3f(250, 310, zs); //3
    glVertex3f(190, 310, zs);
    glVertex3f(190, 290, zs);
    glVertex3f(250, 290, zs);

    glVertex3f(180, 380, zs); //4
    glVertex3f(160, 380, zs);
    glVertex3f(160, 320, zs);
    glVertex3f(180, 320, zs);

    glVertex3f(180, 460, zs); //5
    glVertex3f(160, 460, zs);
    glVertex3f(160, 400, zs);
    glVertex3f(180, 400, zs);

    glVertex3f(250, 490, zs); //6
    glVertex3f(190, 490, zs);
    glVertex3f(190, 470, zs);
    glVertex3f(250, 470, zs);

    break;
  }

  }

  glEnd();

  glColor3f(0.0, 1.0, 1.0);
  glBegin(GL_QUADS);
  switch (score1) {
  case 1: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    break;
  }

  case 2: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(50, 380, zs); //4
    glVertex3f(30, 380, zs);
    glVertex3f(30, 320, zs);
    glVertex3f(50, 320, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }

  case 3: {
    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }

  case 4: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(50, 460, zs); //5
    glVertex3f(30, 460, zs);
    glVertex3f(30, 400, zs);
    glVertex3f(50, 400, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }

  case 5: {

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(50, 460, zs); //5
    glVertex3f(30, 460, zs);
    glVertex3f(30, 400, zs);
    glVertex3f(50, 400, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }
  case 6: {

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(50, 380, zs); //4
    glVertex3f(30, 380, zs);
    glVertex3f(30, 320, zs);
    glVertex3f(50, 320, zs);

    glVertex3f(50, 460, zs); //5
    glVertex3f(30, 460, zs);
    glVertex3f(30, 400, zs);
    glVertex3f(50, 400, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }

  case 7: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }

  case 8: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(50, 380, zs); //4
    glVertex3f(30, 380, zs);
    glVertex3f(30, 320, zs);
    glVertex3f(50, 320, zs);

    glVertex3f(50, 460, zs); //5
    glVertex3f(30, 460, zs);
    glVertex3f(30, 400, zs);
    glVertex3f(50, 400, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;
  }
  case 9: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(50, 460, zs); //5
    glVertex3f(30, 460, zs);
    glVertex3f(30, 400, zs);
    glVertex3f(50, 400, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    glVertex3f(120, 390, zs); //7
    glVertex3f(60, 390, zs);
    glVertex3f(60, 370, zs);
    glVertex3f(120, 370, zs);

    break;

  }

  case 0: {

    glVertex3f(150, 460, zs); //1
    glVertex3f(130, 460, zs);
    glVertex3f(130, 400, zs);
    glVertex3f(150, 400, zs);

    glVertex3f(150, 380, zs); //2
    glVertex3f(130, 380, zs);
    glVertex3f(130, 320, zs);
    glVertex3f(150, 320, zs);

    glVertex3f(120, 310, zs); //3
    glVertex3f(60, 310, zs);
    glVertex3f(60, 290, zs);
    glVertex3f(120, 290, zs);

    glVertex3f(50, 380, zs); //4
    glVertex3f(30, 380, zs);
    glVertex3f(30, 320, zs);
    glVertex3f(50, 320, zs);

    glVertex3f(50, 460, zs); //5
    glVertex3f(30, 460, zs);
    glVertex3f(30, 400, zs);
    glVertex3f(50, 400, zs);

    glVertex3f(120, 490, zs); //6
    glVertex3f(60, 490, zs);
    glVertex3f(60, 470, zs);
    glVertex3f(120, 470, zs);

    break;

  }

  }

  glEnd();
}
