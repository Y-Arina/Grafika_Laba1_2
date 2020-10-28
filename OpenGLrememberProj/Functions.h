#pragma once
#include <corecrt_math.h>

//нахождение вектора по точкам 
void VectorByPoints(double x1[3], double x2[3], double* res)
{
	 res[0] = x2[0] - x1[0];
	 res[1] = x2[1] - x1[1];
	 res[2] = x2[2] - x1[2];
}
//нахождение нормали двух векторов
void NormalVector(double* n, double a[3], double b[3])
{
	n[0] = a[1] * b[2] - b[1] * a[2];
	n[1] = (-1) * a[0] * b[2] + b[0] * a[2];
	n[2] = a[0] * b[1] - b[0] * a[1];
}
//верхняя часть фигуры
void UpFlatFigure(GLuint image)
{
	double A[] = { -1.5,0,2 };
	double B[] = { -2.5,2,2 };
	double C[] = { -0.5,2,2 };
	double D[] = { 1.5,2,2 };
	double E[] = { 1,0,2 };
	double F[] = { -3.5,0.5,2 };
	double G[] = { -2.5,-2,2 };
	double I[] = { 2.5,-2,2 };
	double J[] = { 4,0.5,2 };

	double a[3];
	double b[3];
	double n[3];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_TRIANGLES);

	glColor3f(0.5f, 1.0f, 1.0f);

	VectorByPoints(C, B, a);
	VectorByPoints(C, A, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0.3, 0.4);
	glVertex3dv(A);
	glTexCoord2f(0.2, 0.8);
	glVertex3dv(B);
	glTexCoord2f(0.4, 0.8);
	glVertex3dv(C);

	VectorByPoints(C, A, a);
	VectorByPoints(C, E, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0.4, 0.8);
	glVertex3dv(C);
	glTexCoord2f(0.3, 0.4);
	glVertex3dv(A);
	glTexCoord2f(0.55, 0.4);
	glVertex3dv(E);

	VectorByPoints(C, E, a);
	VectorByPoints(C, D, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0.55, 0.4);
	glVertex3dv(E);
	glTexCoord2f(0.6, 0.8);
	glVertex3dv(D);
	glTexCoord2f(0.4, 0.8);
	glVertex3dv(C);

	VectorByPoints(E, I, a);
	VectorByPoints(E, J, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0.55, 0.4);
	glVertex3dv(E);
	glTexCoord2f(1, 0.5);
	glVertex3dv(J);
	glTexCoord2f(0.8, 0);
	glVertex3dv(I);

	VectorByPoints(A, F, a);
	VectorByPoints(A, G, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0.3, 0.4);
	glVertex3dv(A);
	glTexCoord2f(0, 0.5);
	glVertex3dv(F);
	glTexCoord2f(0.2, 0);
	glVertex3dv(G);

	glEnd();

	//впуклость 
	float x = 0, y = -7, r = 5.6, h = 2;

	glBegin(GL_POLYGON);
	VectorByPoints(E, A, a);
	VectorByPoints(E, I, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0.3, 0.4);
	glVertex3dv(A);
	glTexCoord2f(0.55, 0.4);
	glVertex3dv(E);
	glTexCoord2f(0.8, 0);
	glVertex3dv(I);

	float x_t = 0.8, y_t = 0;
	int k = 0;

	for (float t = 4.25; t <= 5.18; t += 0.001)
	{
		float x1 = x - cos(t) * r;
		float y1 = y - sin(t) * r;

		glTexCoord2f(x_t, y_t);
		glVertex3d(x1, y1, h);

		x_t -= 0.6 / ((5.18 - 4.25) / 0.001);
		if (k <= 465)
			y_t += 0.1 / 465;
		else
			y_t -= 0.1 / 465;
		k++;
	}

	glTexCoord2f(0.2, 0);
	glVertex3dv(G);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
//нижняя часть фигуры
void DownFlatFigure(GLuint image)
{
	double A[] = { -1.5,0,0 };
	double B[] = { -2.5,2,0 };
	double C[] = { -0.5,2,0 };
	double D[] = { 1.5,2,0 };
	double E[] = { 1,0,0 };
	double F[] = { -3.5,0.5,0 };
	double G[] = { -2.5,-2,0 };
	double I[] = { 2.5,-2,0 };
	double J[] = { 4,0.5,0 };

	double a[3];
	double b[3];
	double n[3];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_TRIANGLES);

	glColor3f(0.5f, 1.0f, 1.0f);

	VectorByPoints(C, B, a);
	VectorByPoints(C, A, b);
	NormalVector(n, a, b);
	n[2] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0.3, 0.4);
	glColor4f(0, 1, 1, 1);
	glVertex3dv(A);
	glTexCoord2f(0.2, 0.8);
	glColor4f(1, 0, 1, 0);
	glVertex3dv(B);
	glTexCoord2f(0.4, 0.8);
	glColor4f(1, 1, 0, 0);
	glVertex3dv(C);

	VectorByPoints(C, A, a);
	VectorByPoints(C, E, b);
	NormalVector(n, a, b);
	n[2] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0.4, 0.8);
	glColor4f(1, 1, 0, 0);
	glVertex3dv(C);
	glTexCoord2f(0.3, 0.4);
	glColor4f(0, 1, 1, 1);
	glVertex3dv(A);
	glTexCoord2f(0.55, 0.4);
	glColor4f(0, 1, 1, 1);
	glVertex3dv(E);

	VectorByPoints(C, E, a);
	VectorByPoints(C, D, b);
	NormalVector(n, a, b);
	n[2] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0.55, 0.4);
	glColor4f(0, 1, 1, 1);
	glVertex3dv(E);
	glTexCoord2f(0.6, 0.8);
	glColor4f(1, 0, 1, 0);
	glVertex3dv(D);
	glTexCoord2f(0.4, 0.8);
	glColor4f(1, 1, 0, 0);
	glVertex3dv(C);

	VectorByPoints(E, I, a);
	VectorByPoints(E, J, b);
	NormalVector(n, a, b);
	n[2] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0.55, 0.4);
	glColor4f(0, 1, 1, 1);
	glVertex3dv(E);
	glTexCoord2f(1, 0.5);
	glColor3f(2, 0.5, 1);
	glVertex3dv(J);
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.8, 0);
	glVertex3dv(I);

	VectorByPoints(A, F, a);
	VectorByPoints(A, G, b);
	NormalVector(n, a, b);
	n[2] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0.3, 0.4);
	glColor4f(0, 1, 1, 1);
	glVertex3dv(A);
	glTexCoord2f(0, 0.5);
	glColor3f(2, 0.5, 1);
	glVertex3dv(F);
	glTexCoord2f(0.1, 0);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3dv(G);

	glEnd();
	// впуклость
	float x = 0, y = -7, r = 5.6;

	glBegin(GL_POLYGON);
	glColor4f(0, 1, 1, 1);
	VectorByPoints(E, A, a);
	VectorByPoints(E, I, b);
	NormalVector(n, a, b);
	n[2] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0.3, 0.4);
	glVertex3dv(A);
	glTexCoord2f(0.55, 0.4);
	glVertex3dv(E);
	glTexCoord2f(0.8, 0);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3dv(I);
	float x_t = 0.8, y_t = 0;
	int k = 0;
	for (float t = 4.25; t <= 5.18; t += 0.001)
	{
		float x1 = x - cos(t) * r;
		float y1 = y - sin(t) * r;

		glTexCoord2f(x_t, y_t);
		glVertex3d(x1, y1, 0);
		x_t -= 0.6 / ((5.18 - 4.25) / 0.001);
		if (k <= 465)
			y_t += 0.1 / 465;
		else
			y_t -= 0.1 / 465;
		k++;
	}

	glTexCoord2f(0.2, 0);
	glVertex3dv(G);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
//верхняя окружность 
void UpCircles(GLuint image)
{
	float x = -0.5, y = 2, r = 2, z = 0;
	float xt = 0.4, yt = 0.8, rt = 0.2;

	double O[3] = { x,y,z };
	double n[3];
	double a[3];
	double b[3];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 1.0f, 1.0f);
	glTexCoord2f(xt, yt);
	glVertex2f(x, y);
	for (float t = 3.14; t <= 6.30; t += 0.01)
	{
		double x1 = x - cos(t) * r;
		double x2 = x - cos(t + 0.01) * r;
		double y1 = y - sin(t) * r;
		double y2 = y - sin(t + 0.01) * r;

		double A1[3] = { x1,y1,z };
		double B1[3] = { x2,y2,z };

		float xt1 = xt - cos(t) * rt;
		float yt1 = yt - sin(t) * rt;
		
		VectorByPoints(O, A1, a);
		VectorByPoints(O, B1, b);
		NormalVector(n, a, b);
		glNormal3dv(n);

		glTexCoord2f(xt1, yt1);
		glVertex2f(x - cos(t) * r, y - sin(t) * r);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
//нижняя окружность 
void DownCircles(GLuint image)
{
	float x = -0.5, y = 2, r = 2, z = 0;
	float xt = 0.4, yt = 0.8, rt = 0.2;

	double O[3] = { x,y,z };
	double n[3];
	double a[3];
	double b[3];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(xt, yt);
	glColor4f(1, 1, 0, 0);
	glVertex2f(x, y);
	glColor4f(1, 0, 1, 0);
	for (float t = 3.14; t <= 6.30; t += 0.01)
	{
		double x1 = x - cos(t) * r;
		double x2 = x - cos(t + 0.01) * r;
		double y1 = y - sin(t) * r;
		double y2 = y - sin(t + 0.01) * r;

		float xt1 = xt - cos(t) * rt;
		float yt1 = yt - sin(t) * rt;

		double A1[3] = { x1,y1,z };
		double B1[3] = { x2,y2,z };

		VectorByPoints(O, A1, a);
		VectorByPoints(O, B1, b);
		NormalVector(n, a, b);
		n[2] *= -1;
		glNormal3dv(n);
		glTexCoord2f(xt1, yt1);
		glVertex2f(x - cos(t) * r, y - sin(t) * r);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
//боковые стороны фигуры
void Sides_ofthe_Shape(GLuint image)
{
	double A1[] = { -1.5,0,0 };
	double A2[] = { -1.5,0,2 };
	double B1[] = { -2.5,2,0 };
	double B2[] = { -2.5,2,2 };
	double D1[] = { 1.5,2,0 };
	double D2[] = { 1.5,2,2 };
	double E1[] = { 1,0,0 };
	double E2[] = { 1,0,2 };
	double J1[] = { 4,0.5,0 };
	double J2[] = { 4,0.5,2 };
	double I1[] = { 2.5,-2,0 };
	double I2[] = { 2.5,-2,2 };
	double G1[] = { -2.5,-2,0 };
	double G2[] = { -2.5,-2,2 };
	double F1[] = { -3.5,0.5,0 };
	double F2[] = { -3.5,0.5,2 };

	double a[3];
	double b[3];
	double n[3];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_QUADS);

	VectorByPoints(E2, E1, a);
	VectorByPoints(E2, D2, b);
	NormalVector(n, a, b);
	n[1] *= -1;
	glNormal3dv(n);
	glColor4f(1, 0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3dv(D1);
	glTexCoord2f(0, 1);
	glVertex3dv(D2);
	glColor4f(0, 1, 1, 1);
	glTexCoord2f(1, 1);
	glVertex3dv(E2);
	glTexCoord2f(1, 0);
	glVertex3dv(E1);

	VectorByPoints(J2, J1, a);
	VectorByPoints(J2, E2, b);
	NormalVector(n, a, b);
	n[0] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0, 0);
	glVertex3dv(E1);
	glTexCoord2f(0, 1);
	glVertex3dv(E2);
	glColor3f(2, 0.5, 1);
	glTexCoord2f(1, 1);
	glVertex3dv(J2);
	glTexCoord2f(1, 0);
	glVertex3dv(J1);

	VectorByPoints(I2, I1, a);
	VectorByPoints(I2, J2, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0, 0);
	glVertex3dv(J1);
	glTexCoord2f(0, 1);
	glVertex3dv(J2);
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord2f(1, 1);
	glVertex3dv(I2);
	glTexCoord2f(1, 0);
	glVertex3dv(I1);

	VectorByPoints(F2, F1, a);
	VectorByPoints(F2, G2, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord2f(0, 0);
	glVertex3dv(G1);
	glTexCoord2f(0, 1);
	glVertex3dv(G2);
	glColor3f(2, 0.5, 1);
	glTexCoord2f(1, 1);
	glVertex3dv(F2);
	glTexCoord2f(1, 0);
	glVertex3dv(F1);

	VectorByPoints(A2, A1, a);
	VectorByPoints(A2, F2, b);
	NormalVector(n, a, b);
	n[0] *= -1;
	glNormal3dv(n);
	glTexCoord2f(0, 0);
	glVertex3dv(F1);
	glTexCoord2f(0, 1);
	glVertex3dv(F2);
	glColor4f(0, 1, 1, 1);
	glTexCoord2f(1, 1);
	glVertex3dv(A2);
	glTexCoord2f(1, 0);
	glVertex3dv(A1);

	VectorByPoints(B2, B1, a);
	VectorByPoints(B2, A2, b);
	NormalVector(n, a, b);
	glNormal3dv(n);
	glTexCoord2f(0, 0);
	glVertex3dv(A1);
	glTexCoord2f(0, 1);
	glVertex3dv(A2);
	glColor4f(1, 0, 1, 0);
	glTexCoord2f(1, 1);
	glVertex3dv(B2);
	glTexCoord2f(1, 0);
	glVertex3dv(B1);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//выпуклость 
	float x = -0.5, y = 2, h = 2, r = 2;
	float xt = 0.5, rt = 0.5;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_QUAD_STRIP);
	glColor4f(1, 0, 1, 0);
	for (float t = 3.14; t <= 6.28; t += 0.001)
	{
		float x1 = x - cos(t) * r;
		float y1 = y - sin(t) * r;
		float x2 = x - cos(t + 0.01) * r;
		float y2 = y - sin(t + 0.01) * r;

		float xt1 = xt - cos(t) * rt;
		float xt2 = xt - cos(t + 0.01) * rt;

		double a1[3] = { x1,y1,h };
		double b1[3] = { x2,y2,h };
		double d1[3] = { x1,y1,0 };
		
		VectorByPoints(b1, a1, a);
		VectorByPoints(b1, d1, b);
		NormalVector(n, a, b);
		glNormal3dv(n);
		glTexCoord2f(xt1, 0);
		glVertex3d(x1, y1, 0);
		glTexCoord2f(xt1, 1);
		glVertex3d(x1, y1, h);
		glTexCoord2f(xt2, 1);
		glVertex3d(x2, y2, h);
		glTexCoord2f(xt2, 0);
		glVertex3d(x2, y2, 0);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//впуклость 
	float x_1 = 0, y_1 = -7, r_1 = 5.6, h_1 = 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);

	glBegin(GL_QUAD_STRIP);
	glColor3f(0.5, 0.5, 0.5);
	for (float t = 4.25; t <= 5.17; t += 0.001)
	{
		float x1 = x_1 - cos(t) * r_1;
		float y1 = y_1 - sin(t) * r_1;
		float x2 = x_1 - cos(t + 0.01) * r_1;
		float y2 = y_1 - sin(t + 0.01) * r_1;

		float xt1 = xt - cos(t) * rt;
		float xt2 = xt - cos(t + 0.01) * rt;

		double a11[3] = { x1,y1,h_1 };
		double b11[3] = { x2,y2,h_1 };
		double d11[3] = { x1,y1,0 };

		VectorByPoints(b11, a11, a);
		VectorByPoints(b11, d11, b);
		NormalVector(n, a, b);
		n[1] *= -1;
		glNormal3dv(n);
		glTexCoord2f(xt1, 0);
		glVertex3d(x1, y1, 0);
		glTexCoord2f(xt1, 1);
		glVertex3d(x1, y1, h);
		glTexCoord2f(xt2, 1);
		glVertex3d(x2, y2, h);
		glTexCoord2f(xt2, 0);
		glVertex3d(x2, y2, 0);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


