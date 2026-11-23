#pragma once
#include <GL/glut.h>
#include <math.h>
#include <ctime>
#include <iostream>

static void caja2(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidCube(1);
	glPopMatrix();
}

static void esfera2(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidSphere(1, 32, 22);
	glPopMatrix();
}

void cielo2() {
	// cielo 3D envolvente alrededor de la escena (con techo para que no salga franja al mirar arriba)
	glBegin(GL_QUADS);
	glColor3ub(122, 198, 246);
	glVertex3d(-220, -20, -180); glVertex3d(220, -20, -180);
	glColor3ub(102, 180, 238);
	glVertex3d(220, 220, -180); glVertex3d(-220, 220, -180);

	glColor3ub(122, 198, 246);
	glVertex3d(-220, -20, 180); glVertex3d(-220, -20, -180);
	glColor3ub(102, 180, 238);
	glVertex3d(-220, 220, -180); glVertex3d(-220, 220, 180);

	glColor3ub(122, 198, 246);
	glVertex3d(220, -20, -180); glVertex3d(220, -20, 180);
	glColor3ub(102, 180, 238);
	glVertex3d(220, 220, 180); glVertex3d(220, 220, -180);

	glColor3ub(122, 198, 246);
	glVertex3d(220, -20, 180); glVertex3d(-220, -20, 180);
	glColor3ub(102, 180, 238);
	glVertex3d(-220, 220, 180); glVertex3d(220, 220, 180);

	glColor3ub(102, 180, 238);
	glVertex3d(-220, 220, -180); glVertex3d(220, 220, -180);
	glVertex3d(220, 220, 180); glVertex3d(-220, 220, 180);
	glEnd();

	// 3 montanas conicas grandes en 3D detras de la tienda
	glPushMatrix();
	glColor3ub(138, 98, 62);
	glTranslated(-74, -1, -130);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(72, 74, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(82, 144, 58);
	glTranslated(-4, -1, -142);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(78, 86, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(82, 144, 58);
	glTranslated(70, -1, -134);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(72, 78, 40, 20);
	glPopMatrix();
}

void playa2() {
	// arena trasera mas clara y arena delantera mas oscura (en 3D)
	glPushMatrix();
	glColor3ub(232, 206, 144);
	glTranslated(0, -0.75, -85);
	glScaled(360, 1.5, 190);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(204, 178, 114);
	glTranslated(0, -0.70, 88);
	glScaled(360, 1.5, 156);
	glutSolidCube(1);
	glPopMatrix();

	// borde sutil entre la franja de arena delantera y la de atras
	glColor3ub(78, 66, 46);
	caja2(0, 0.04f, 10, 340, 0.14f, 0.45f);
}

void tienda2() {
	glPushMatrix();
	glTranslated(-18, 0.5, -24);
	glScaled(0.65, 0.65, 0.65);

	// base de cemento gris (vereda de la tienda)
	glPushMatrix();
	glColor3ub(188, 192, 198);
	glScaled(100, 3, 80);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(148, 152, 158);
	glTranslated(0, -0.6, 0);
	glScaled(103, 1.8, 83);
	glutSolidCube(1);
	glPopMatrix();

	// columnas del frente y atras en marron oscuro
	glColor3ub(136, 106, 86);
	caja2(42, 15, 25, 2.8f, 30, 2.8f);
	caja2(-42, 15, 25, 2.8f, 30, 2.8f);
	caja2(46, 15, 9, 4.5f, 30, 4.5f);
	caja2(-46, 15, 9, 4.5f, 30, 4.5f);
	caja2(46, 15, -38, 4.5f, 30, 4.5f);
	caja2(-46, 15, -38, 4.5f, 30, 4.5f);

	// techo principal y bloque del letrero TIENDA (rojo izquierda, crema derecha)
	glPushMatrix();
	glColor3ub(168, 134, 88);
	glTranslated(0, 30, -10);
	glScaled(105, 1.8, 76);
	glutSolidCube(1);
	glPopMatrix();

	// caja 3D del letrero TIENDA al frente del techo (rojo izquierda/centro, crema derecha)
	glColor3ub(218, 36, 40);
	caja2(-15.5f, 35.0f, 12.0f, 67.0f, 10.5f, 8.0f);
	glColor3ub(252, 238, 196);
	caja2(33.0f, 35.0f, 12.0f, 30.0f, 10.5f, 8.0f);
	// marco negro alrededor del letrero
	glColor3ub(30, 24, 24);
	caja2(0.0f, 40.4f, 12.0f, 99.0f, 0.9f, 8.4f);
	caja2(0.0f, 29.6f, 12.0f, 99.0f, 0.9f, 8.4f);
	caja2(-49.2f, 35.0f, 12.0f, 0.9f, 11.4f, 8.4f);
	caja2(48.2f, 35.0f, 12.0f, 0.9f, 11.4f, 8.4f);

	// letras 3D "TIENDA" sobre el letrero (con la A entrando en la zona crema)
	glColor3ub(22, 20, 20);
	texto3D("TIENDA", -1.5f, 35.0f, 16.5f, 6.4f, 1.85f, 0.21f, 0.9f);

	// paredes beige originales de la tienda (con huecos de puerta y ventana)
	glColor3ub(196, 156, 120);
	caja2(31, 15, 9, 35, 30, 1.8f);
	caja2(10, 28, 9, 35, 3.5f, 1.8f);
	caja2(-25, 7, 9, 46, 12, 1.8f);
	caja2(-9.6f, 15, 9, 15.5f, 30, 1.8f);
	caja2(-40.2f, 15, 9, 15.5f, 30, 1.8f);
	caja2(-25, 27, 9, 46, 6, 1.8f);
	caja2(-47.5f, 15, -14.5f, 1.8f, 30, 48);
	caja2(47.5f, 15, -14.5f, 1.8f, 30, 48);
	caja2(0, 15, -38, 95, 30, 1.8f);

	// ventana 3D en el hueco izquierdo (-24.9, 18.5, 9)
	glColor3ub(38, 32, 30);
	caja2(-24.9f, 24.0f, 9.0f, 16.0f, 1.1f, 2.4f);
	caja2(-24.9f, 13.0f, 9.0f, 16.0f, 1.1f, 2.4f);
	caja2(-32.5f, 18.5f, 9.0f, 1.1f, 11.5f, 2.4f);
	caja2(-17.3f, 18.5f, 9.0f, 1.1f, 11.5f, 2.4f);
	// vidrio celeste 3D saturado y reflejos blancos diagonales en 3D
	glColor3ub(64, 164, 236);
	caja2(-24.9f, 18.5f, 8.9f, 14.4f, 10.2f, 0.5f);
	glColor3ub(246, 252, 255);
	glPushMatrix();
	glTranslated(-27.2f, 19.6f, 9.4f);
	glRotated(-42, 0, 0, 1);
	caja2(0, 0, 0, 1.1f, 7.6f, 0.25f);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-24.0f, 18.0f, 9.4f);
	glRotated(-42, 0, 0, 1);
	caja2(0, 0, 0, 1.0f, 9.5f, 0.25f);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-21.2f, 16.4f, 9.4f);
	glRotated(-42, 0, 0, 1);
	caja2(0, 0, 0, 0.9f, 5.0f, 0.25f);
	glPopMatrix();

	// puerta 3D con rejas en el hueco derecho (5.8, 14.0, 9)
	glColor3ub(106, 92, 84);
	caja2(5.8f, 14.0f, 9.0f, 15.2f, 24.8f, 1.3f);
	glColor3ub(38, 32, 30);
	// marco de puerta y barras verticales de madera
	caja2(-1.6f, 14.0f, 9.3f, 0.8f, 25.0f, 1.8f);
	caja2(13.2f, 14.0f, 9.3f, 0.8f, 25.0f, 1.8f);
	caja2(5.8f, 26.2f, 9.3f, 15.6f, 0.8f, 1.8f);
	for (int i = -2; i <= 2; i++) {
		caja2(5.8f + i * 2.8f, 14.0f, 9.75f, 0.45f, 24.2f, 0.35f);
	}
	// reja superior de la puerta
	for (int j = 0; j < 3; j++) {
		caja2(5.8f, 20.0f + j * 2.5f, 9.85f, 14.6f, 0.45f, 0.35f);
	}
	// manija
	caja2(0.2f, 12.2f, 10.1f, 0.7f, 1.8f, 0.7f);

	// muebles interiores 3D visibles al rotar la camara o mirar dentro
	glColor3ub(168, 114, 68);
	caja2(0, 5.5f, -15, 58, 8, 8);
	glColor3ub(145, 148, 154);
	caja2(-28, 12, -31, 22, 20, 6);
	caja2(28, 12, -31, 22, 20, 6);

	glPopMatrix();
}

void dinosaurio2() {
	// Dinosaurio del grupo en primer plano a la derecha mirando hacia la tienda
	glPushMatrix();
	glTranslated(28, 0.2, 16);
	glScaled(5, 5, 5);
	glRotated(-125, 0, 1, 0);

	glColor3ub(39, 64, 91);
	esfera2(0, 0.42f, 0, 0.96f, 0.42f, 0.69f);
	glColor3ub(112, 174, 46);
	esfera2(0, 1.12f, 0, 1.03f, 0.94f, 0.71f);
	esfera2(-0.93f, 1.24f, 0.14f, 0.28f, 0.36f, 0.26f);
	esfera2(0.93f, 1.21f, 0.15f, 0.28f, 0.38f, 0.26f);
	glColor3ub(215, 234, 242);
	esfera2(0, 1.10f, 0.49f, 0.64f, 0.75f, 0.29f);
	glColor3ub(28, 40, 44);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera2(lado * 0.25f, 1.33f, 0.77f, 0.07f, 0.08f, 0.04f);
		esfera2(lado * 0.24f, 0.91f, 0.77f, 0.07f, 0.08f, 0.04f);
	}

	glColor3ub(143, 202, 66);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera2(lado * 0.99f, 1.05f, 0.43f, 0.24f, 0.24f, 0.21f);
		esfera2(lado * 0.83f, 1.14f, 0.50f, 0.11f, 0.13f, 0.10f);
	}

	glColor3ub(125, 188, 54);
	esfera2(0, 2.73f, -0.10f, 0.99f, 0.90f, 0.78f);
	glColor3ub(105, 159, 45);
	esfera2(0, 2.27f, 0.39f, 0.77f, 0.33f, 0.90f);
	glColor3ub(49, 75, 29);
	esfera2(0, 2.43f, 0.53f, 0.80f, 0.17f, 0.86f);
	glColor3ub(142, 203, 65);
	esfera2(0, 2.69f, 0.60f, 0.84f, 0.34f, 0.87f);

	glColor3ub(249, 246, 220);
	for (int diente = -3; diente <= 3; diente++) {
		float x = diente * 0.19f;
		float z = 0.63f + 0.80f * sqrtf(1 - x * x / (0.79f * 0.79f));
		glPushMatrix();
		glTranslatef(x, 2.51f + 0.15f * x * x, z);
		glRotatef(90, 1, 0, 0);
		glutSolidCone(0.079, 0.15, 16, 6);
		glPopMatrix();
	}

	for (int lado = -1; lado <= 1; lado += 2) {
		glColor3ub(123, 181, 54);
		esfera2(lado * 0.42f, 2.96f, 0.96f, 0.19f, 0.081f, 0.17f);
		glColor3ub(237, 222, 162);
		glPushMatrix();
		glTranslatef(lado * 0.42f, 2.98f, 0.96f);
		glRotatef(-78, 1, 0, 0);
		glutSolidCone(0.143, 0.27, 22, 8);
		glPopMatrix();
		glColor3ub(32, 38, 29);
		esfera2(lado * 0.43f, 3.14f, 0.50f, 0.104f, 0.125f, 0.08f);
		glColor3ub(236, 245, 221);
		esfera2(lado * 0.43f - 0.025f, 3.18f, 0.569f, 0.025f, 0.025f, 0.018f);
		glColor3ub(85, 133, 43);
		esfera2(lado * 0.22f, 2.86f, 1.29f, 0.074f, 0.039f, 0.038f);
	}

	glPopMatrix();
}

void dibujarEscena2() {
	glPushMatrix();
	playa2();
	cielo2();
	tienda2();
	dinosaurio2();
	glPopMatrix();
}
