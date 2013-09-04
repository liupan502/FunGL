#ifndef MATRIX_44_H
#define MATRIX_44_H

#include <iostream>
const int COLSIZE = 4;
const int ROWSIZE = 4;
#define PI 3.1415926
enum MatrixMode{
	GL_ROATE,				// Ðý×ª¾ØÕó
	GL_TRANSLATION,		// Æ½ÒÆ¾ØÕó
	GL_SCALE					// Ëõ·Å¾ØÕó
};
class Matrix44
{
public:
	double value[16];
public :
	
	friend	Matrix44 operator+(const Matrix44& m1,const Matrix44& m2);

	friend   Matrix44 operator*(const double scale,const Matrix44& m1);

	friend   Matrix44 operator-(const Matrix44& m1,const Matrix44& m2);

	friend   Matrix44 operator*(const Matrix44& m1,const Matrix44& m2);

	void operator=(const Matrix44& m1)
	{
		for(int i=0;i<COLSIZE;i++)
			for(int j=0;j<ROWSIZE;j++)
				this->value[i*COLSIZE+j] = m1.value[i*COLSIZE+j];
	};

	Matrix44 Invert(bool bRegular = true);

	void Init(MatrixMode mode,int paramNum,double* params);
	
	
};

#endif