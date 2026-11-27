#pragma once
#include <GL/glut.h>
#include <math.h>
#include <ctime>
#include <iostream>

static void caja3(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidCube(1);
	glPopMatrix();
}

static void esfera3(float x, float y, float z, float ancho, float alto, float fondo)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(ancho, alto, fondo);
	glutSolidSphere(1, 32, 22);
	glPopMatrix();
}

// Estantes grises en 3D a ambos lados del pasillo (basados en estantesBebidas3 del grupo)
void estantesBebidas3() {
	for (int lado = -1; lado <= 1; lado += 2) {
		float x = lado * 31.0f;
		float dir = (lado < 0) ? 1.0f : -1.0f;

		// respaldo trasero y postes laterales del mueble (abiertos al frente para ver las repisas)
		glColor3ub(136, 140, 148);
		caja3(x - dir * 10.5f, 11.5f, -22.0f, 1.5f, 23.0f, 36.0f);
		glColor3ub(154, 158, 165);
		caja3(x - dir * 10.5f, 11.5f, -4.5f, 1.6f, 23.0f, 1.6f);
		caja3(x + dir * 10.2f, 11.5f, -4.5f, 1.4f, 23.0f, 1.4f);
		caja3(x, 11.5f, -39.5f, 21.0f, 23.0f, 1.4f);
		// techo del estante
		caja3(x, 22.8f, -22.0f, 21.5f, 1.0f, 36.0f);

		// 5 repisas horizontales con borde oscuro hacia el pasillo
		for (int nivel = 0; nivel < 5; nivel++) {
			float y = 2.0f + nivel * 4.5f;
			glColor3ub(175, 178, 184);
			caja3(x, y, -22.0f, 20.5f, 0.9f, 34.5f);
			glColor3ub(55, 58, 64);
			caja3(x + dir * 10.2f, y, -22.0f, 0.5f, 0.95f, 34.5f);
			caja3(x, y, -4.5f, 20.5f, 0.95f, 0.6f);
		}
	}
}

// Botella 3D de AGUA copiada de la escena 4 (reutilizada en el estante y en la mano del muneco)
void botellaAgua3(float x, float y, float z, float esc) {
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

	// letras 3D "AGUA" al frente de la etiqueta
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
	esfera3(0, 5.10f, 0, 0.52f, 0.16f, 0.52f);

	glPopMatrix();
}

void tienda3(int botellaEnEstante) {
	// piso 3D cuadriculado en blanco/gris claro y gris medio
	for (int ix = -5; ix < 5; ix++) {
		for (int iz = -5; iz < 6; iz++) {
			if ((ix + iz) % 2 == 0) glColor3ub(224, 226, 232);
			else glColor3ub(128, 134, 144);
			caja3(ix * 10.0f + 5.0f, -0.35f, iz * 10.0f + 5.0f, 10.0f, 0.7f, 10.0f);
		}
	}

	// paredes crema del interior en 3D y techo cerrado
	glColor3ub(224, 206, 172);
	caja3(0, 21, -50, 104, 42, 2.0f);  // pared del fondo
	caja3(-48, 21, 5, 2.0f, 42, 115);  // pared izquierda
	caja3(48, 21, 5, 2.0f, 42, 115);   // pared derecha
	caja3(0, 21, 62, 104, 42, 2.0f);   // pared detras de la camara
	glColor3ub(212, 194, 160);
	caja3(0, 42, 5, 104, 2.0f, 115);   // techo

	// columnas decorativas en la pared del fondo
	glColor3ub(192, 166, 126);
	caja3(-18, 21, -48.6f, 1.8f, 42, 1.0f);
	caja3(18, 21, -48.6f, 1.8f, 42, 1.0f);
	caja3(26, 21, -48.6f, 1.8f, 42, 1.0f);

	// puerta gris de salida en el centro del fondo
	glColor3ub(152, 154, 160);
	caja3(0, 13.0f, -48.6f, 15.0f, 26.0f, 1.0f);
	// marco de la puerta
	glColor3ub(122, 114, 102);
	caja3(-8.0f, 13.0f, -48.2f, 1.2f, 26.5f, 1.4f);
	caja3(8.0f, 13.0f, -48.2f, 1.2f, 26.5f, 1.4f);
	caja3(0.0f, 26.0f, -48.2f, 17.2f, 1.2f, 1.4f);
	// manija
	glColor3ub(82, 82, 86);
	caja3(5.6f, 11.5f, -47.8f, 0.7f, 1.8f, 0.7f);

	// letrero verde 3D "EXIT" encima de la puerta
	glColor3ub(34, 158, 72);
	caja3(0, 29.8f, -47.6f, 12.6f, 5.2f, 2.2f);
	glColor3ub(20, 75, 35);
	caja3(0, 32.5f, -47.6f, 13.0f, 0.5f, 2.4f);
	caja3(0, 27.1f, -47.6f, 13.0f, 0.5f, 2.4f);
	// letras 3D blancas EXIT
	glColor3ub(248, 250, 248);
	texto3D("EXIT", 0, 29.8f, -46.2f, 3.3f, 0.88f, 0.20f, 0.6f);

	estantesBebidas3();

	// botella de agua en la estanteria izquierda (nivel 3, visible sobre el hombro del muneco)
	if (botellaEnEstante == 1) {
		botellaAgua3(-24.2f, 15.95f, -7.2f, 0.95f);
	}
}

void munecoDeNieve3(float x, float y, float z, float rotY, float cabNod, float bocaAbierta, float brazoDerAng, int tieneBotella) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(5.5, 5.5, 5.5);
	glRotated(rotY, 0, 1, 0);

	glColor3ub(39, 63, 91);
	esfera3(0, 0.43f, 0, 0.89f, 0.43f, 0.64f);
	glColor3ub(197, 38, 28);
	esfera3(0, 1.09f, 0, 0.93f, 0.92f, 0.66f);
	glColor3ub(213, 231, 242);
	esfera3(0, 1.11f, 0.43f, 0.63f, 0.73f, 0.31f);
	glColor3ub(29, 37, 45);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera3(lado * 0.25f, 1.32f, 0.72f, 0.067f, 0.08f, 0.045f);
		esfera3(lado * 0.24f, 0.92f, 0.72f, 0.067f, 0.08f, 0.045f);
	}

	// brazo derecho animado (puede levantar para tomar la botella y llevarla pegada a la mano)
	glPushMatrix();
	glTranslated(-0.83f, 1.30f, 0.15f);
	glRotated(-brazoDerAng, 1, 0, 0);
	glColor3ub(215, 49, 33);
	esfera3(0, -0.11f, 0, 0.29f, 0.42f, 0.28f);
	glColor3ub(239, 159, 99);
	esfera3(-0.08f, -0.27f, 0.27f, 0.22f, 0.24f, 0.19f);
	esfera3(0.06f, -0.17f, 0.33f, 0.10f, 0.12f, 0.11f);
	if (tieneBotella == 1) {
		glPushMatrix();
		glTranslated(-0.08f, -0.22f, 0.42f);
		glRotated(brazoDerAng * 0.6f, 1, 0, 0);
		botellaAgua3(0, -0.35f, 0, 0.17f);
		glPopMatrix();
	}
	glPopMatrix();

	// brazo izquierdo normal
	glColor3ub(215, 49, 33);
	esfera3(0.82f, 1.21f, 0.18f, 0.30f, 0.37f, 0.28f);
	glColor3ub(223, 239, 248);
	esfera3(0.90f, 1.05f, 0.43f, 0.23f, 0.23f, 0.19f);
	esfera3(0.76f, 1.15f, 0.49f, 0.10f, 0.12f, 0.11f);

	// cabeza articulada con asentimiento y boca animada al hablar
	glPushMatrix();
	glTranslated(0, 2.0f, 0);
	glRotated(cabNod, 1, 0, 0);
	glTranslated(0, -2.0f, 0);

	glColor3ub(251, 250, 242);
	esfera3(0, 2.63f, 0, 0.88f, 0.84f, 0.75f);
	glColor3ub(49, 42, 37);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera3(lado * 0.31f, 2.76f, 0.67f, 0.088f, 0.103f, 0.059f);
		glPushMatrix();
		glTranslatef(lado * 0.33f, 3.02f, 0.57f);
		glRotatef(lado * -13.0f, 0, 0, 1);
		caja3(0, 0, 0, 0.31f, 0.075f, 0.07f);
		glPopMatrix();
	}
	glColor3ub(244, 134, 39);
	glPushMatrix();
	glTranslatef(0, 2.67f, 0.73f);
	glutSolidCone(0.17, 0.43, 24, 10);
	glPopMatrix();

	// boca abierta animada cuando habla el muneco
	if (bocaAbierta > 0.05f) {
		glColor3ub(55, 34, 32);
		esfera3(0, 2.34f, 0.71f, 0.19f, 0.05f + 0.11f * bocaAbierta, 0.09f);
	}
	else {
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
	}

	glPopMatrix();
	glPopMatrix();
}

void dinosaurio3(float x, float y, float z, float rotY, float cabNod, float bocaAng) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(5.5, 5.5, 5.5);
	glRotated(rotY, 0, 1, 0);

	glColor3ub(39, 64, 91);
	esfera3(0, 0.42f, 0, 0.96f, 0.42f, 0.69f);
	glColor3ub(112, 174, 46);
	esfera3(0, 1.12f, 0, 1.03f, 0.94f, 0.71f);
	esfera3(-0.93f, 1.24f, 0.14f, 0.28f, 0.36f, 0.26f);
	esfera3(0.93f, 1.21f, 0.15f, 0.28f, 0.38f, 0.26f);
	glColor3ub(215, 234, 242);
	esfera3(0, 1.10f, 0.49f, 0.64f, 0.75f, 0.29f);
	glColor3ub(28, 40, 44);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera3(lado * 0.25f, 1.33f, 0.77f, 0.07f, 0.08f, 0.04f);
		esfera3(lado * 0.24f, 0.91f, 0.77f, 0.07f, 0.08f, 0.04f);
	}

	glColor3ub(143, 202, 66);
	for (int lado = -1; lado <= 1; lado += 2) {
		esfera3(lado * 0.99f, 1.05f, 0.43f, 0.24f, 0.24f, 0.21f);
		esfera3(lado * 0.83f, 1.14f, 0.50f, 0.11f, 0.13f, 0.10f);
	}

	// cabeza articulada con asentimiento y boca movil
	glPushMatrix();
	glTranslated(0, 2.0f, 0);
	glRotated(cabNod, 1, 0, 0);
	glTranslated(0, -2.0f, 0);

	glColor3ub(125, 188, 54);
	esfera3(0, 2.73f, -0.10f, 0.99f, 0.90f, 0.78f);

	// mandibula inferior que baja al hablar
	glPushMatrix();
	glTranslated(0, 2.40f, 0.0f);
	glRotated(bocaAng, 1, 0, 0);
	glTranslated(0, -2.40f, 0.0f);
	glColor3ub(105, 159, 45);
	esfera3(0, 2.27f, 0.39f, 0.77f, 0.33f, 0.90f);
	glColor3ub(49, 75, 29);
	esfera3(0, 2.43f, 0.53f, 0.80f, 0.17f, 0.86f);
	glPopMatrix();

	// hocico superior, dientes, cuernos y ojos
	glPushMatrix();
	glTranslated(0, 2.55f, 0.0f);
	glRotated(-bocaAng * 0.55f, 1, 0, 0);
	glTranslated(0, -2.55f, 0.0f);
	glColor3ub(142, 203, 65);
	esfera3(0, 2.69f, 0.60f, 0.84f, 0.34f, 0.87f);

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
		esfera3(lado * 0.42f, 2.96f, 0.96f, 0.19f, 0.081f, 0.17f);
		glColor3ub(237, 222, 162);
		glPushMatrix();
		glTranslatef(lado * 0.42f, 2.98f, 0.96f);
		glRotatef(-78, 1, 0, 0);
		glutSolidCone(0.143, 0.27, 22, 8);
		glPopMatrix();
		glColor3ub(32, 38, 29);
		esfera3(lado * 0.43f, 3.14f, 0.50f, 0.104f, 0.125f, 0.08f);
		glColor3ub(236, 245, 221);
		esfera3(lado * 0.43f - 0.025f, 3.18f, 0.569f, 0.025f, 0.025f, 0.018f);
		glColor3ub(85, 133, 43);
		esfera3(lado * 0.22f, 2.86f, 1.29f, 0.074f, 0.039f, 0.038f);
	}
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void dibujarEscena3(float t) {
	// Animacion Escena 3:
	// 0-3s habla dino / asiente muneco; 3-6s habla muneco / asiente dino;
	// 6-9.2s muneco va por botella al estante izq y la agarra; 9.2-14.5s ambos voltean y saltan a la camara
	float ciclo = fmodf(t, 16.0f);
	float mx = -12.0f, my = 0.2f, mz = 8.0f, rotM = 60.0f;
	float dx = 12.0f, dy = 0.2f, dz = 8.0f, rotD = -60.0f;
	float bocaD = 0.0f, nodD = 0.0f;
	float bocaM = 0.0f, nodM = 0.0f;
	float brazoM = 0.0f;
	int botEstante = 1;
	int botMuneco = 0;

	if (ciclo < 3.0f) {
		bocaD = 12.0f * fabsf(sinf(ciclo * 9.0f));
		nodM = 6.5f * sinf(ciclo * 4.5f);
	}
	else if (ciclo < 6.0f) {
		bocaM = fabsf(sinf((ciclo - 3.0f) * 9.0f));
		nodD = 6.5f * sinf((ciclo - 3.0f) * 4.5f);
	}
	else if (ciclo < 7.0f) {
		float u = ciclo - 6.0f;
		rotM = 60.0f + (-142.0f - 60.0f) * u;
	}
	else if (ciclo < 8.4f) {
		float u = (ciclo - 7.0f) / 1.4f;
		rotM = -142.0f;
		mx = -12.0f + (-18.0f + 12.0f) * u;
		mz = 8.0f + (-2.2f - 8.0f) * u;
		my = 0.2f + 1.2f * fabsf(sinf((ciclo - 7.0f) * 6.5f));
		brazoM = 95.0f * u;
	}
	else if (ciclo < 9.2f) {
		float u = (ciclo - 8.4f) / 0.8f;
		rotM = -142.0f;
		mx = -18.0f;
		mz = -2.2f;
		brazoM = 95.0f - 45.0f * u;
		botEstante = 0;
		botMuneco = 1;
	}
	else if (ciclo < 10.2f) {
		float u = ciclo - 9.2f;
		mx = -18.0f;
		mz = -2.2f;
		rotM = -142.0f + (0.0f + 142.0f) * u;
		rotD = -60.0f + (0.0f + 60.0f) * u;
		brazoM = 50.0f;
		botEstante = 0;
		botMuneco = 1;
	}
	else if (ciclo < 14.5f) {
		float u = (ciclo - 10.2f) / 4.3f;
		rotM = 0.0f;
		rotD = 0.0f;
		brazoM = 50.0f;
		botEstante = 0;
		botMuneco = 1;
		mx = -18.0f + (-7.0f + 18.0f) * u;
		mz = -2.2f + (26.5f + 2.2f) * u;
		my = 0.2f + 1.8f * fabsf(sinf((ciclo - 10.2f) * 7.0f));
		dx = 12.0f + (8.5f - 12.0f) * u;
		dz = 8.0f + (26.5f - 8.0f) * u;
		dy = 0.2f + 1.8f * fabsf(sinf((ciclo - 10.2f) * 7.0f + 0.8f));
	}
	else {
		rotM = 0.0f;
		rotD = 0.0f;
		brazoM = 50.0f;
		botEstante = 0;
		botMuneco = 1;
		mx = -7.0f; mz = 26.5f;
		dx = 8.5f; dz = 26.5f;
	}

	tienda3(botEstante);

	// sombras suaves en el piso siguiendo a cada personaje
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	float sx[2] = { mx, dx };
	float sz[2] = { mz, dz };
	for (int k = 0; k < 2; k++) {
		glBegin(GL_TRIANGLE_FAN);
		glColor4ub(63, 45, 29, 82);
		glVertex3f(sx[k], 0.05f, sz[k]);
		glColor4ub(63, 45, 29, 0);
		for (int punto = 0; punto <= 40; punto++) {
			float ang = punto * 6.2831853f / 40;
			glVertex3f(sx[k] + 7.5f * cosf(ang), 0.05f, sz[k] + 4.8f * sinf(ang));
		}
		glEnd();
	}
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);

	munecoDeNieve3(mx, my, mz, rotM, nodM, bocaM, brazoM, botMuneco);
	dinosaurio3(dx, dy, dz, rotD, nodD, bocaD);
}
