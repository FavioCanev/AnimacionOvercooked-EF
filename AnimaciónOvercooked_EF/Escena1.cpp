#include <GL/glut.h>
#include <math.h>
#include <ctime>
#include <iostream>

using namespace std;

// estado de escena, ejes, animacion y camara
int escenaActual = 1;
int mostrarEjes = 0;
int animando = 1;
float tiempoAnim = 0;

float camaraX = 0;
float camaraY = 22;
float camaraZ = 62;
float centroX = 0;
float centroY = 14;
float centroZ = -20;
float angulo = 0;

static void caja(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidCube(1);
	glPopMatrix();
}

static void esfera(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidSphere(1, 32, 22);
	glPopMatrix();
}

// Dibuja letras en bloques 3D usando glutSolidCube para letreros (TIENDA, EXIT, AGUA)
// sin usar textos 2D ni texturas externas.
static void letra3D(char c, float g, float fondo)
{
	if (c == 'T') {
		caja(0, 0.42f, 0, 0.78f, g, fondo);
		caja(0, 0, 0, g, 0.92f, fondo);
	}
	else if (c == 'I') {
		caja(0, 0, 0, g, 0.92f, fondo);
		caja(0, 0.42f, 0, 0.46f, g, fondo);
		caja(0, -0.42f, 0, 0.46f, g, fondo);
	}
	else if (c == 'E') {
		caja(-0.24f, 0, 0, g, 0.92f, fondo);
		caja(0.05f, 0.40f, 0, 0.62f, g, fondo);
		caja(0.02f, 0.02f, 0, 0.54f, g, fondo);
		caja(0.05f, -0.40f, 0, 0.62f, g, fondo);
	}
	else if (c == 'N') {
		caja(-0.26f, 0, 0, g, 0.92f, fondo);
		caja(0.26f, 0, 0, g, 0.92f, fondo);
		glPushMatrix();
		glRotatef(30, 0, 0, 1);
		caja(0, 0, 0, g, 0.96f, fondo);
		glPopMatrix();
	}
	else if (c == 'D') {
		caja(-0.24f, 0, 0, g, 0.92f, fondo);
		caja(0.0f, 0.40f, 0, 0.52f, g, fondo);
		caja(0.0f, -0.40f, 0, 0.52f, g, fondo);
		caja(0.24f, 0, 0, g, 0.76f, fondo);
	}
	else if (c == 'A') {
		glPushMatrix();
		glTranslatef(-0.14f, 0, 0);
		glRotatef(-16, 0, 0, 1);
		caja(0, 0, 0, g, 0.96f, fondo);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.14f, 0, 0);
		glRotatef(16, 0, 0, 1);
		caja(0, 0, 0, g, 0.96f, fondo);
		glPopMatrix();
		caja(0, -0.08f, 0, 0.42f, g, fondo);
	}
	else if (c == 'X') {
		glPushMatrix();
		glRotatef(32, 0, 0, 1);
		caja(0, 0, 0, g, 1.05f, fondo);
		glPopMatrix();
		glPushMatrix();
		glRotatef(-32, 0, 0, 1);
		caja(0, 0, 0, g, 1.05f, fondo);
		glPopMatrix();
	}
	else if (c == 'G') {
		caja(-0.25f, 0, 0, g, 0.84f, fondo);
		caja(0.02f, 0.40f, 0, 0.58f, g, fondo);
		caja(0.02f, -0.40f, 0, 0.58f, g, fondo);
		caja(0.26f, -0.18f, 0, g, 0.44f, fondo);
		caja(0.14f, 0.0f, 0, 0.30f, g, fondo);
	}
	else if (c == 'U') {
		caja(-0.25f, 0.06f, 0, g, 0.80f, fondo);
		caja(0.25f, 0.06f, 0, g, 0.80f, fondo);
		caja(0.0f, -0.40f, 0, 0.56f, g, fondo);
	}
}

static void texto3D(const char* palabra, float x, float y, float z, float escala, float separacion, float grosor, float fondo)
{
	int largo = 0;
	while (palabra[largo] != '\0') largo++;
	float inicioX = x - ((largo - 1) * separacion * escala) / 2.0f;

	for (int i = 0; i < largo; i++) {
		glPushMatrix();
		glTranslatef(inicioX + i * separacion * escala, y, z);
		glScalef(escala, escala, 1.0f);
		letra3D(palabra[i], grosor, fondo);
		glPopMatrix();
	}
}

#include "Escena2.h"
#include "Escena3.h"
#include "Escena4.h"

// Ajusta la camara inicial al encuadre de referencia de cada escena
void configurarCamara(int n) {
	angulo = 0;
	if (n == 1) {
		camaraX = 0;
		camaraY = 22;
		camaraZ = 62;
		centroX = 0;
		centroY = 14;
		centroZ = -20;
	}
	else if (n == 2) {
		camaraX = 4;
		camaraY = 18;
		camaraZ = 68;
		centroX = 0;
		centroY = 15;
		centroZ = -20;
	}
	else if (n == 3) {
		camaraX = 0;
		camaraY = 15;
		camaraZ = 42;
		centroX = 0;
		centroY = 13;
		centroZ = -20;
	}
	else if (n == 4) {
		camaraX = -1;
		camaraY = 22;
		camaraZ = 42;
		centroX = 0;
		centroY = 15;
		centroZ = -10;
	}
}

void iniciarVentana(int w, int h) {
	if (h == 0) h = 1;
	glViewport(0, 0, w, h); // area de la ventana donde se dibuja

	// Se usa la matriz de proyeccion y se reinicia
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// fijamos los parametros de la proyeccion en perspectiva
	gluPerspective(60, (float)w / (float)h, 1, 450);
}

void inicializarLuces() {
	GLfloat luz_ambiente[] = { 0.44, 0.44, 0.44, 1 };
	GLfloat luz_difusa[] = { 0.36, 0.36, 0.36, 1 };
	GLfloat luz_espectacular[] = { 0.15, 0.15, 0.15, 1 };

	float posicionLuz[] = { 20, 42, 52, 1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz_espectacular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

// nube esponjosa hecha con esferas 3D
void nube1(float x, float y, float z, float esc) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(esc, esc, esc);
	glColor3ub(252, 253, 255);
	esfera(-3.4f, 0.0f, 0.0f, 2.5f, 1.9f, 1.8f);
	esfera(-1.1f, 0.8f, 0.3f, 3.0f, 2.3f, 2.1f);
	esfera(1.4f, 0.6f, -0.2f, 2.9f, 2.2f, 2.0f);
	esfera(3.6f, -0.1f, 0.0f, 2.3f, 1.8f, 1.7f);
	glPopMatrix();
}

// ave en 3D con cuerpo y dos alas inclinadas
void ave1(float x, float y, float z, float esc) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(esc, esc, esc);
	glColor3ub(28, 32, 36);
	esfera(0, 0, 0, 0.35f, 0.28f, 0.55f);

	glPushMatrix();
	glRotated(28, 0, 0, 1);
	caja(-0.85f, 0.15f, 0, 1.7f, 0.18f, 0.45f);
	glPopMatrix();

	glPushMatrix();
	glRotated(-28, 0, 0, 1);
	caja(0.85f, 0.15f, 0, 1.7f, 0.18f, 0.45f);
	glPopMatrix();
	glPopMatrix();
}

void cielo() {
	// cielo 3D envolvente (paredes lejanas en los 4 lados y arriba para que al girar no haya cortes)
	glBegin(GL_QUADS);
	glColor3ub(120, 198, 246);
	glVertex3d(-220, -20, -180); glVertex3d(220, -20, -180);
	glColor3ub(98, 178, 238);
	glVertex3d(220, 220, -180); glVertex3d(-220, 220, -180);

	glColor3ub(120, 198, 246);
	glVertex3d(-220, -20, 180); glVertex3d(-220, -20, -180);
	glColor3ub(98, 178, 238);
	glVertex3d(-220, 220, -180); glVertex3d(-220, 220, 180);

	glColor3ub(120, 198, 246);
	glVertex3d(220, -20, -180); glVertex3d(220, -20, 180);
	glColor3ub(98, 178, 238);
	glVertex3d(220, 220, 180); glVertex3d(220, 220, -180);

	glColor3ub(120, 198, 246);
	glVertex3d(220, -20, 180); glVertex3d(-220, -20, 180);
	glColor3ub(98, 178, 238);
	glVertex3d(-220, 220, 180); glVertex3d(220, 220, 180);

	glColor3ub(98, 178, 238);
	glVertex3d(-220, 220, -180); glVertex3d(220, 220, -180);
	glVertex3d(220, 220, 180); glVertex3d(-220, 220, 180);
	glEnd();

	// sol 3D arriba al centro con sus conos de rayos (modelo original del grupo)
	glPushMatrix();
	glTranslated(0, -32, -108);
	glScaled(1.6, 1.6, 1.6);

	glPushMatrix();
	glColor3ub(255, 232, 52);
	glTranslated(0, 50, 0);
	glutSolidSphere(4.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(0, 46.2, 0);
	glRotated(90, 1, 0, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(2.7, 47.4, 0);
	glRotated(90, 1, 0, 0);
	glRotated(45, 0, 1, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(-2.7, 47.4, 0);
	glRotated(90, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(3.8, 50.0, 0);
	glRotated(90, 1, 0, 0);
	glRotated(90, 0, 1, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(-3.8, 50.0, 0);
	glRotated(90, 1, 0, 0);
	glRotated(-90, 0, 1, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(2.7, 52.7, 0);
	glRotated(90, 1, 0, 0);
	glRotated(135, 0, 1, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(-2.7, 52.7, 0);
	glRotated(90, 1, 0, 0);
	glRotated(-135, 0, 1, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 242, 118);
	glTranslated(0, 53.8, 0);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1.3, 3.8, 40, 20);
	glPopMatrix();

	glPopMatrix();

	// nubes en 3D a izquierda y derecha
	nube1(-46, 44, -98, 2.3f);
	nube1(44, 46, -98, 2.6f);
	nube1(54, 44, -95, 2.0f);

	// 5 aves 3D volando bajo la nube de la derecha
	ave1(28, 30, -82, 1.3f);
	ave1(34, 32.5f, -82, 1.3f);
	ave1(32, 27.5f, -82, 1.2f);
	ave1(38, 29, -82, 1.2f);
	ave1(33, 24.5f, -82, 1.1f);
}

void playa() {
	// mar profundo (atras) en 3D
	glPushMatrix();
	glColor3ub(22, 150, 198);
	glTranslated(0, -0.2, -92);
	glScaled(360, 0.8, 115);
	glutSolidCube(1);
	glPopMatrix();

	// zona turquesa de orilla en 3D
	glPushMatrix();
	glColor3ub(32, 194, 194);
	glTranslated(0, -0.05, -22);
	glScaled(360, 0.8, 36);
	glutSolidCube(1);
	glPopMatrix();

	// 4 filas de olas esculpidas en 3D con espuma blanca encima
	for (int fila = 0; fila < 4; fila++) {
		float zBase = -3.0f - fila * 11.0f;
		for (int i = -18; i <= 18; i++) {
			float px = i * 8.0f + (fila % 2) * 3.0f;
			float pz = zBase + 3.0f * sinf(px * 0.08f + fila);
			// lomo de la ola en 3D
			glColor3ub(28, 178, 192);
			esfera(px, 0.25f, pz, 5.4f, 0.75f, 1.4f);
			// cresta de espuma blanca 3D
			glColor3ub(246, 250, 255);
			esfera(px, 0.78f, pz + 0.35f, 4.8f, 0.32f, 0.65f);
		}
	}

	// arena seca en todo el frente y arena mojada junto a la orilla
	glPushMatrix();
	glColor3ub(228, 200, 148);
	glTranslated(0, -0.75, 48);
	glScaled(360, 1.5, 110);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(204, 174, 122);
	glTranslated(0, -0.68, -1);
	glScaled(360, 1.5, 16);
	glutSolidCube(1);
	glPopMatrix();

	// rocas 3D en los costados de la playa (del avance original del grupo)
	glColor3ub(116, 120, 108);
	esfera(76, 1.5f, -18, 6, 4.8f, 10);
	esfera(70, 1.2f, -15, 4.5f, 2.7f, 4.5f);
	esfera(65, 1.2f, -24, 4.5f, 3.6f, 5.5f);
	esfera(-76, 1.4f, -14, 4, 3.2f, 4);
	esfera(-70, 1.2f, -18, 2.5f, 1.8f, 2.5f);
}

void dinosaurio() {
	// Dinosaurio modelo del grupo (centrado en 0,0,0 mirando hacia +Z)
	glPushMatrix();

	glColor3ub(39, 64, 91);
	esfera(0, 0.42f, 0, 0.96f, 0.42f, 0.69f);
	glColor3ub(112, 174, 46);
	esfera(0, 1.12f, 0, 1.03f, 0.94f, 0.71f);
	esfera(-0.93f, 1.24f, 0.14f, 0.28f, 0.36f, 0.26f);
	esfera(0.93f, 1.21f, 0.15f, 0.28f, 0.38f, 0.26f);

	// mandil claro con 4 botones oscuros
	glColor3ub(215, 234, 242);
	esfera(0, 1.10f, 0.49f, 0.64f, 0.75f, 0.29f);
	glColor3ub(28, 40, 44);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera(lado * 0.25f, 1.33f, 0.77f, 0.07f, 0.08f, 0.04f);
		esfera(lado * 0.24f, 0.91f, 0.77f, 0.07f, 0.08f, 0.04f);
	}

	// manos verde claro
	glColor3ub(143, 202, 66);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera(lado * 0.99f, 1.05f, 0.43f, 0.24f, 0.24f, 0.21f);
		esfera(lado * 0.83f, 1.14f, 0.50f, 0.11f, 0.13f, 0.10f);
	}

	// cabeza, hocico y dientes
	glColor3ub(125, 188, 54);
	esfera(0, 2.73f, -0.10f, 0.99f, 0.90f, 0.78f);
	glColor3ub(105, 159, 45);
	esfera(0, 2.27f, 0.39f, 0.77f, 0.33f, 0.90f);
	glColor3ub(49, 75, 29);
	esfera(0, 2.43f, 0.53f, 0.80f, 0.17f, 0.86f);
	glColor3ub(142, 203, 65);
	esfera(0, 2.69f, 0.60f, 0.84f, 0.34f, 0.87f);

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
		esfera(lado * 0.42f, 2.96f, 0.96f, 0.19f, 0.081f, 0.17f);
		glColor3ub(237, 222, 162);
		glPushMatrix();
		glTranslatef(lado * 0.42f, 2.98f, 0.96f);
		glRotatef(-78, 1, 0, 0);
		glutSolidCone(0.143, 0.27, 22, 8);
		glPopMatrix();
		glColor3ub(32, 38, 29);
		esfera(lado * 0.43f, 3.14f, 0.50f, 0.104f, 0.125f, 0.08f);
		glColor3ub(236, 245, 221);
		esfera(lado * 0.43f - 0.025f, 3.18f, 0.569f, 0.025f, 0.025f, 0.018f);
		glColor3ub(85, 133, 43);
		esfera(lado * 0.22f, 2.86f, 1.29f, 0.074f, 0.039f, 0.038f);
	}

	glPopMatrix();
}

void otrasCosas() {
	// sombrilla y toalla del grupo puestas a un lado de la playa
	glPushMatrix();
	glTranslated(-52, 0, 22);
	glScaled(0.65, 0.65, 0.65);

	glPushMatrix();
	glColor3ub(138, 78, 34);
	glTranslated(0, 12, 0);
	glScaled(0.9, 26, 0.9);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslated(0, 25, 0);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(18, 12, 40, 20);
	glPopMatrix();

	glColor3ub(209, 0, 0);
	for (int k = 0; k < 4; k++) {
		glPushMatrix();
		glTranslated(0, 25.05, 0);
		glRotated(-90, 1, 0, 0);
		glRotated(k * 45.0, 0, 0, 1);
		glScaled(1.06, 0.3, 1);
		glutSolidCone(18, 12, 40, 20);
		glPopMatrix();
	}

	glPushMatrix();
	glColor3ub(255, 89, 89);
	glTranslated(5, 0.3, 18);
	glScaled(15, 0.5, 26);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void ejes() {
	if (mostrarEjes == 0) return;
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(100, 0, 0);
	glColor3ub(0, 255, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 100, 0);
	glColor3ub(0, 0, 255);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 100);
	glEnd();
	glPopMatrix();
}

void dibujarEscena1() {
	glPushMatrix();
	glRotated(angulo, 0, 1, 0);
	cielo();
	playa();
	otrasCosas();
	ejes();

	// Animacion Escena 1:
	// 0-5s mira al mar; 5-6s gira 180 grados en 1s; 6-11.2s salta hacia la camara hasta taparla
	float ciclo = fmodf(tiempoAnim, 13.5f);
	float px = -8.0f;
	float py = 0.05f;
	float pz = 20.0f;
	float rotY = 180.0f;

	if (ciclo < 5.0f) {
		rotY = 180.0f;
	}
	else if (ciclo < 6.0f) {
		float u = ciclo - 5.0f;
		rotY = 180.0f - 180.0f * u;
	}
	else if (ciclo < 11.2f) {
		float u = (ciclo - 6.0f) / 5.2f;
		rotY = 0.0f;
		px = -8.0f * (1.0f - u);
		pz = 20.0f + 35.8f * u;
		float salto = 2.4f * fabsf(sinf((ciclo - 6.0f) * 6.5f));
		py = 0.05f + 7.8f * u + salto * (1.0f - 0.65f * u);
	}
	else {
		rotY = 0.0f;
		px = 0.0f;
		py = 7.85f;
		pz = 55.8f;
	}

	// sombra suave en la arena bajo Piter
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	glBegin(GL_TRIANGLE_FAN);
	glColor4ub(130, 106, 65, 90);
	glVertex3f(px, 0.08f, pz);
	glColor4ub(130, 106, 65, 0);
	for (int p = 0; p <= 32; p++) {
		float a = p * 6.2831853f / 32;
		glVertex3f(px + 7.2f * cosf(a), 0.08f, pz + 5.0f * sinf(a));
	}
	glEnd();
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslated(px, py, pz);
	glScaled(5, 5, 5);
	glRotated(rotY, 0, 1, 0);
	dinosaurio();
	glPopMatrix();

	glPopMatrix();
}

void DibujarEscena2() {
	glPushMatrix();
	glRotated(angulo, 0, 1, 0);
	dibujarEscena2(tiempoAnim);
	ejes();
	glPopMatrix();
}

void DibujarEscena3() {
	glPushMatrix();
	glRotated(angulo, 0, 1, 0);
	dibujarEscena3(tiempoAnim);
	ejes();
	glPopMatrix();
}

void DibujarEscena4() {
	glPushMatrix();
	glRotated(angulo, 0, 1, 0);
	dibujarEscena4(tiempoAnim);
	ejes();
	glPopMatrix();
}

void dibujar() {
	if (escenaActual <= 2) {
		glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
	}
	else {
		glClearColor(0.92f, 0.88f, 0.78f, 1.0f);
	}
	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camaraX, camaraY, camaraZ, centroX, centroY, centroZ, 0, 1, 0);

	if (escenaActual == 1) dibujarEscena1();
	else if (escenaActual == 2) DibujarEscena2();
	else if (escenaActual == 3) DibujarEscena3();
	else if (escenaActual == 4) DibujarEscena4();

	glutSwapBuffers();
}

// Timer del grupo: avanza el tiempo de la animacion cada 20 ms mientras no este pausada
void Timer(int t) {
	if (animando == 1) {
		tiempoAnim += 0.02f;
	}
	glutPostRedisplay();
	glutTimerFunc(20, Timer, 0);
}

void Teclado(int tecla, int x, int y) {
	switch (tecla) {
	case 101: // flecha arriba
		camaraY += 2;
		break;
	case 103: // flecha abajo
		camaraY -= 2;
		break;
	case 100: // flecha izquierda
		angulo -= 3;
		break;
	case 102: // flecha derecha
		angulo += 3;
		break;
	// RePag / AvPag: acerca o aleja la camara para revisar todo el 3D (no estaba en el avance anterior)
	case 104:
		camaraZ -= 3;
		break;
	case 105:
		camaraZ += 3;
		break;
	}
	glutPostRedisplay();
}

// Uso glutKeyboardFunc aparte de glutSpecialFunc porque esta lee letras y numeros normales (1-4, Espacio, E, R)
// mientras que glutSpecialFunc solo lee flechas y teclas especiales.
void TecladoNormal(unsigned char tecla, int x, int y) {
	if (tecla >= '1' && tecla <= '4') {
		escenaActual = tecla - '0';
		tiempoAnim = 0;
		configurarCamara(escenaActual);
	}
	else if (tecla == ' ') {
		animando = 1 - animando;
	}
	else if (tecla == 'e' || tecla == 'E') {
		mostrarEjes = 1 - mostrarEjes;
	}
	else if (tecla == 'r' || tecla == 'R') {
		tiempoAnim = 0;
		configurarCamara(escenaActual);
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	cout << "Controles:\n";
	cout << "  1, 2, 3, 4  : Cambiar de escena (reinicia su animacion y camara)\n";
	cout << "  Espacio     : Pausar o reanudar la animacion\n";
	cout << "  E           : Mostrar u ocultar ejes X, Y, Z\n";
	cout << "  R           : Reiniciar animacion y camara de la escena actual\n";
	cout << "  Flechas     : Girar y subir/bajar la camara en 3D\n";
	cout << "  RePag/AvPag : Acercar o alejar la camara\n";

	glutInit(&argc, argv); // inicia el GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1000, 700); // define las dimensiones de la ventana
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Animacion Overcooked 3D - Escenas 1 a 4"); // crea la ventana
	configurarCamara(1);
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(Teclado);
	glutKeyboardFunc(TecladoNormal);
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();
	return 0;
}
