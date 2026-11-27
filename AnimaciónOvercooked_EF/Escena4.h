#pragma once
#include <GL/glut.h>
#include <math.h>
#include <ctime>
#include <iostream>

static void caja4(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidCube(1);
	glPopMatrix();
}

static void esfera4(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidSphere(1, 32, 22);
	glPopMatrix();
}

// Paisaje exterior REAL en 3D detras de la ventana abierta (cielo, sol, mar con olas y arena)
void paisajeExterior4() {
	// paredes del cielo 3D afuera de la tienda
	glBegin(GL_QUADS);
	glColor3ub(122, 202, 248);
	glVertex3d(-190, -10, -135); glVertex3d(190, -10, -135);
	glColor3ub(98, 182, 240);
	glVertex3d(190, 95, -135); glVertex3d(-190, 95, -135);
	glEnd();

	// sol 3D afuera visible por el cuadrante superior derecho de la ventana
	glPushMatrix();
	glTranslated(-6.0, 36.5, -105.0);
	glColor3ub(254, 226, 46);
	glutSolidSphere(6.2, 40, 40);
	for (int i = 0; i < 8; i++) {
		glPushMatrix();
		glRotated(i * 45.0, 0, 0, 1);
		caja4(0, 8.2f, 0, 0.9f, 3.6f, 0.9f);
		glPopMatrix();
	}
	glPopMatrix();

	// playa 3D afuera (arena + mar turquesa + olas 3D + mar profundo) a la altura visible por la ventana
	glColor3ub(226, 198, 138);
	caja4(0, 11.5f, -44.0f, 240, 12.0f, 36.0f);

	glColor3ub(36, 176, 188);
	caja4(0, 12.2f, -72.0f, 240, 12.0f, 24.0f);

	glColor3ub(24, 134, 192);
	caja4(0, 12.6f, -104.0f, 240, 12.0f, 44.0f);

	// olas 3D visibles por los paneles inferiores de la ventana
	for (int f = 0; f < 3; f++) {
		float zOla = -58.0f - f * 12.0f;
		for (int i = -6; i <= 6; i++) {
			float px = i * 8.0f;
			glColor3ub(28, 162, 190);
			esfera4(px, 18.2f, zOla, 5.0f, 0.9f, 1.5f);
			glColor3ub(246, 250, 255);
			esfera4(px, 18.9f, zOla + 0.4f, 4.4f, 0.35f, 0.7f);
		}
	}
}

void tienda4() {
	// piso 3D cuadriculado mas ancho hacia los lados (x = -95..95)
	for (int ix = -9; ix < 10; ix++) {
		for (int iz = -3; iz < 7; iz++) {
			if ((ix + iz) % 2 == 0) glColor3ub(224, 226, 232);
			else glColor3ub(128, 134, 144);
			caja4(ix * 10.0f, -0.35f, iz * 10.0f, 10.0f, 0.7f, 10.0f);
		}
	}

	// pared del fondo ampliada dividida en 4 bloques alrededor de la ventana (-21..-3, y 16..34)
	glColor3ub(224, 206, 172);
	caja4(0, 8.0f, -24.0f, 192.0f, 16.0f, 2.0f);     // debajo de ventana
	caja4(0, 39.0f, -24.0f, 192.0f, 10.0f, 2.0f);    // encima de ventana
	caja4(-58.5f, 25.0f, -24.0f, 75.0f, 18.0f, 2.0f); // izquierda de ventana
	caja4(46.5f, 25.0f, -24.0f, 99.0f, 18.0f, 2.0f);  // derecha de ventana

	// paredes laterales y techo ampliados en 3D para que el muneco tenga espacio a los lados
	caja4(-95, 22, 22, 2.0f, 44, 96);
	caja4(95, 22, 22, 2.0f, 44, 96);
	caja4(0, 22, 68, 192, 44, 2.0f);
	glColor3ub(212, 194, 160);
	caja4(0, 44, 22, 192, 2.0f, 96);

	// marco de madera 3D y cruz de la ventana (hueco en x=-21..-3, y=16..34)
	glColor3ub(142, 88, 48);
	caja4(-12.0f, 34.0f, -24.0f, 19.6f, 1.4f, 2.4f); // marco superior
	caja4(-12.0f, 16.0f, -24.0f, 19.6f, 1.4f, 2.4f); // marco inferior
	caja4(-21.0f, 25.0f, -24.0f, 1.4f, 19.4f, 2.4f); // marco izquierdo
	caja4(-3.0f, 25.0f, -24.0f, 1.4f, 19.4f, 2.4f);  // marco derecho
	caja4(-12.0f, 25.0f, -24.0f, 1.1f, 18.0f, 1.8f); // cruz vertical
	caja4(-12.0f, 23.5f, -24.0f, 18.0f, 1.1f, 1.8f); // cruz horizontal

	// 3 repisas de madera 3D a la derecha en la pared del fondo
	for (int i = 0; i < 3; i++) {
		float y = 20.0f + i * 5.6f;
		glColor3ub(178, 122, 72);
		caja4(17.5f, y, -21.2f, 22.0f, 1.1f, 4.6f);
		glColor3ub(118, 76, 40);
		caja4(17.5f, y, -18.85f, 22.0f, 1.15f, 0.25f);
	}

	// mostrador en 3D en primer plano (dejando espacio libre a los lados)
	glColor3ub(166, 112, 68);
	caja4(0, 4.6f, 2.5f, 82.0f, 9.2f, 10.0f);
	glColor3ub(182, 126, 78);
	caja4(0, 9.4f, 2.5f, 84.0f, 0.7f, 11.4f);
	glColor3ub(114, 72, 38);
	caja4(0, 9.05f, 8.15f, 84.0f, 0.35f, 0.35f);
}

// Billete 3D verde para la escena de la compra
void billete4() {
	glPushMatrix();
	glColor3ub(78, 168, 76);
	caja4(0, 0, 0, 2.8f, 0.16f, 1.4f);
	glColor3ub(144, 214, 132);
	caja4(0, 0.04f, 0, 2.1f, 0.14f, 0.95f);
	glColor3ub(46, 118, 48);
	esfera4(0, 0.09f, 0, 0.42f, 0.08f, 0.36f);
	glPopMatrix();
}

// Botella 3D de AGUA en la posicion dada
void botellaAgua4(float x, float y, float z, float esc) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(esc, esc, esc);

	// cuerpo celeste de la botella
	glColor3ub(122, 198, 240);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1.18, 1.18, 3.3, 28, 6);
	glPopMatrix();

	// franja blanca de la etiqueta
	glColor3ub(248, 250, 252);
	glPushMatrix();
	glTranslated(0, 0.9, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1.21, 1.21, 1.5, 28, 4);
	glPopMatrix();

	// letras 3D "AGUA" al frente de la etiqueta ajustadas al ancho de la botella
	glColor3ub(22, 26, 32);
	texto3D("AGUA", 0, 1.65f, 1.25f, 0.45f, 0.88f, 0.22f, 0.14f);

	// hombro, cuello y tapa azul oscuro
	glColor3ub(152, 214, 246);
	glPushMatrix();
	glTranslated(0, 3.3, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1.18, 0.45, 0.8, 24, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.1, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 0.45, 0.45, 0.45, 20, 4);
	glPopMatrix();

	glColor3ub(28, 72, 148);
	glPushMatrix();
	glTranslated(0, 4.55, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 0.52, 0.52, 0.55, 20, 4);
	glPopMatrix();
	esfera4(0, 5.10f, 0, 0.52f, 0.16f, 0.52f);

	glPopMatrix();
}

void munecoDeNieve4(float mx, float my, float mz, float rotM, float brazoBillete, float brazoBotella, int tieneBillete, int tieneBotella) {
	glPushMatrix();
	glTranslated(mx, my, mz);
	glScaled(5.6, 5.6, 5.6);
	glRotated(rotM, 0, 1, 0);

	glColor3ub(39, 63, 91);
	esfera4(0, 0.43f, 0, 0.89f, 0.43f, 0.64f);
	glColor3ub(197, 38, 28);
	esfera4(0, 1.09f, 0, 0.93f, 0.92f, 0.66f);
	glColor3ub(213, 231, 242);
	esfera4(0, 1.11f, 0.43f, 0.63f, 0.73f, 0.31f);
	glColor3ub(29, 37, 45);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera4(lado * 0.25f, 1.32f, 0.72f, 0.067f, 0.08f, 0.045f);
		esfera4(lado * 0.24f, 0.92f, 0.72f, 0.067f, 0.08f, 0.045f);
	}

	// brazo derecho animado con el billete en la mano (deja el billete sobre la mesa)
	glPushMatrix();
	glTranslated(-0.91f, 1.38f, 0.46f);
	glRotated(brazoBillete * 58.0f, 1, 0, 0);
	glTranslated(0, 0, brazoBillete * 0.65f);
	glColor3ub(215, 49, 33);
	esfera4(0.08f, -0.15f, -0.22f, 0.30f, 0.38f, 0.28f);
	glColor3ub(239, 159, 99);
	esfera4(0.0f, 0.02f, 0.08f, 0.22f, 0.24f, 0.19f);
	esfera4(0.14f, 0.12f, 0.14f, 0.10f, 0.12f, 0.11f);
	if (tieneBillete == 1) {
		glPushMatrix();
		glTranslated(0.02f, 0.15f, 0.22f);
		glScaled(0.22, 0.22, 0.22);
		glRotated(15, 1, 0, 0);
		billete4();
		glPopMatrix();
	}
	glPopMatrix();

	// brazo izquierdo animado para agarrar la botella de agua del mostrador
	glPushMatrix();
	glTranslated(0.82f, 1.21f, 0.18f);
	glRotated(-brazoBotella * 65.0f, 1, 0, 0);
	glTranslated(0, 0, brazoBotella * 0.55f);
	glColor3ub(215, 49, 33);
	esfera4(0, 0, 0, 0.30f, 0.37f, 0.28f);
	glColor3ub(223, 239, 248);
	esfera4(0.08f, -0.16f, 0.25f, 0.23f, 0.23f, 0.19f);
	esfera4(-0.06f, -0.06f, 0.31f, 0.10f, 0.12f, 0.11f);
	if (tieneBotella == 1) {
		glPushMatrix();
		glTranslated(0.08f, -0.05f, 0.42f);
		glRotated(brazoBotella * 65.0f, 1, 0, 0);
		botellaAgua4(0, -0.15f, 0.05f, 0.20f);
		glPopMatrix();
	}
	glPopMatrix();

	// cabeza
	glColor3ub(251, 250, 242);
	esfera4(0, 2.63f, 0, 0.88f, 0.84f, 0.75f);
	glColor3ub(49, 42, 37);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera4(lado * 0.31f, 2.76f, 0.67f, 0.088f, 0.103f, 0.059f);
		glPushMatrix();
		glTranslatef(lado * 0.33f, 3.02f, 0.57f);
		glRotatef(lado * -13.0f, 0, 0, 1);
		caja4(0, 0, 0, 0.31f, 0.075f, 0.07f);
		glPopMatrix();
	}
	glColor3ub(244, 134, 39);
	glPushMatrix();
	glTranslatef(0, 2.67f, 0.73f);
	glutSolidCone(0.17, 0.43, 24, 10);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glColor3ub(99, 112, 118);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	for (int punto = -10; punto <= 10; punto++) {
		float x = punto * 0.052f;
		float y = 2.30f + 0.66f * x * x;
		float z = 0.75f * sqrtf(1 - x * x / (0.88f * 0.88f)
			- (y - 2.63f) * (y - 2.63f) / (0.84f * 0.84f));
		glVertex3f(x, y, z + 0.012f);
	}
	glEnd();
	glLineWidth(1);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void dinosaurio4(float brazoDer, int tieneBillete) {
	// Piter de espaldas en primer plano a la izquierda comprando sobre el mostrador
	glPushMatrix();
	glTranslated(-11.5, 0.8, 17.5);
	glScaled(6.2, 6.2, 6.2);
	glRotated(142, 0, 1, 0);

	glColor3ub(39, 64, 91);
	esfera4(0, 0.42f, 0, 0.96f, 0.42f, 0.69f);
	glColor3ub(112, 174, 46);
	esfera4(0, 1.12f, 0, 1.03f, 0.94f, 0.71f);
	esfera4(0.93f, 1.21f, 0.15f, 0.28f, 0.38f, 0.26f);

	// brazo derecho animado para tomar el billete de la mesa
	glPushMatrix();
	glTranslated(-0.95, 1.50, 0.45);
	glRotated(-45.0f - brazoDer * 35.0f, 1, 0, 0);
	glTranslated(-brazoDer * 0.25f, 0, brazoDer * 0.95f);
	esfera4(0, 0, 0, 0.28f, 0.38f, 0.26f);
	glColor3ub(143, 202, 66);
	esfera4(0, 0.18f, 0.34f, 0.25f, 0.24f, 0.22f);
	esfera4(0.14f, 0.26f, 0.36f, 0.11f, 0.13f, 0.10f);
	if (tieneBillete == 1) {
		glPushMatrix();
		glTranslated(0.0f, 0.28f, 0.48f);
		glScaled(0.20, 0.20, 0.20);
		billete4();
		glPopMatrix();
	}
	glPopMatrix();

	glColor3ub(215, 234, 242);
	esfera4(0, 1.10f, 0.49f, 0.64f, 0.75f, 0.29f);
	glColor3ub(28, 40, 44);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera4(lado * 0.25f, 1.33f, 0.77f, 0.07f, 0.08f, 0.04f);
		esfera4(lado * 0.24f, 0.91f, 0.77f, 0.07f, 0.08f, 0.04f);
	}

	// mano izquierda normal
	glColor3ub(143, 202, 66);
	esfera4(0.99f, 1.05f, 0.43f, 0.24f, 0.24f, 0.21f);
	esfera4(0.83f, 1.14f, 0.50f, 0.11f, 0.13f, 0.10f);

	glColor3ub(125, 188, 54);
	esfera4(0, 2.73f, -0.10f, 0.99f, 0.90f, 0.78f);
	glColor3ub(105, 159, 45);
	esfera4(0, 2.27f, 0.39f, 0.77f, 0.33f, 0.90f);
	glColor3ub(49, 75, 29);
	esfera4(0, 2.43f, 0.53f, 0.80f, 0.17f, 0.86f);
	glColor3ub(142, 203, 65);
	esfera4(0, 2.69f, 0.60f, 0.84f, 0.34f, 0.87f);

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
		esfera4(lado * 0.42f, 2.96f, 0.96f, 0.19f, 0.081f, 0.17f);
		glColor3ub(237, 222, 162);
		glPushMatrix();
		glTranslatef(lado * 0.42f, 2.98f, 0.96f);
		glRotatef(-78, 1, 0, 0);
		glutSolidCone(0.143, 0.27, 22, 8);
		glPopMatrix();
		glColor3ub(32, 38, 29);
		esfera4(lado * 0.43f, 3.14f, 0.50f, 0.104f, 0.125f, 0.08f);
		glColor3ub(236, 245, 221);
		esfera4(lado * 0.43f - 0.025f, 3.18f, 0.569f, 0.025f, 0.025f, 0.018f);
		glColor3ub(85, 133, 43);
		esfera4(lado * 0.22f, 2.86f, 1.29f, 0.074f, 0.039f, 0.038f);
	}

	glPopMatrix();
}

void dibujarEscena4(float t) {
	// Animacion Escena 4:
	// 0-1.2s inicio con billete en mano; 1.2-3.4s deja billete en la mesa;
	// 3.4-5.6s dinosaurio levanta brazo derecho y toma el billete;
	// 5.6-7.6s muneco toma la botella de agua; 7.6-12.0s muneco se va hacia un lado
	float ciclo = fmodf(t, 13.5f);
	float mx = 5.0f, my = 2.6f, mz = -5.8f, rotM = -12.0f;
	float brazoBillete = 0.0f;
	float brazoBotella = 0.0f;
	float brazoDino = 0.0f;

	int billMuneco = 0;
	int billMesa = 0;
	int billDino = 0;
	int botMesa = 1;
	int botMuneco = 0;

	if (ciclo < 1.2f) {
		billMuneco = 1;
	}
	else if (ciclo < 2.8f) {
		float u = (ciclo - 1.2f) / 1.6f;
		brazoBillete = u;
		billMuneco = 1;
	}
	else if (ciclo < 3.4f) {
		float u = (ciclo - 2.8f) / 0.6f;
		brazoBillete = 1.0f - u;
		billMesa = 1;
	}
	else if (ciclo < 4.6f) {
		float u = (ciclo - 3.4f) / 1.2f;
		brazoDino = u;
		billMesa = 1;
	}
	else if (ciclo < 5.6f) {
		float u = (ciclo - 4.6f) / 1.0f;
		brazoDino = 1.0f - u;
		billDino = 1;
	}
	else if (ciclo < 6.8f) {
		float u = (ciclo - 5.6f) / 1.2f;
		brazoBotella = u;
		billDino = 1;
	}
	else if (ciclo < 7.6f) {
		float u = (ciclo - 6.8f) / 0.8f;
		brazoBotella = 1.0f - 0.22f * u;
		billDino = 1;
		botMesa = 0;
		botMuneco = 1;
	}
	else if (ciclo < 12.0f) {
		float u = (ciclo - 7.6f) / 4.4f;
		brazoBotella = 0.78f;
		billDino = 1;
		botMesa = 0;
		botMuneco = 1;
		if (u < 0.14f) {
			rotM = -12.0f + (72.0f + 12.0f) * (u / 0.14f);
		}
		else {
			float v = (u - 0.14f) / 0.86f;
			rotM = 72.0f;
			mx = 5.0f + 78.0f * v;
			my = 2.6f + 1.4f * fabsf(sinf((ciclo - 7.6f) * 7.0f));
		}
	}
	else {
		brazoBotella = 0.78f;
		billDino = 1;
		botMesa = 0;
		botMuneco = 1;
		rotM = 72.0f;
		mx = 83.0f;
	}

	paisajeExterior4();
	tienda4();

	if (billMesa == 1) {
		glPushMatrix();
		glTranslated(0.5f, 9.85f, 3.2f);
		billete4();
		glPopMatrix();
	}
	if (botMesa == 1) {
		botellaAgua4(10.5f, 9.75f, 4.2f, 1.0f);
	}

	munecoDeNieve4(mx, my, mz, rotM, brazoBillete, brazoBotella, billMuneco, botMuneco);
	dinosaurio4(brazoDino, billDino);
}
