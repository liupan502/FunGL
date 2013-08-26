#include "Matrix44.h"

Matrix44 operator+(const Matrix44& m1,const Matrix44& m2)
{
	Matrix44 result;
	for(int i = 0;i<ROWSIZE;i++)
		for(int j = 0;j<COLSIZE;j++)
			result.value[i*COLSIZE+j]  = m1.value[i*COLSIZE+j]+m2.value[i*COLSIZE+j];
	return result;
}

Matrix44 operator*(const double scale,const Matrix44& m1)
{
	Matrix44 result;
	for(int i = 0;i<ROWSIZE;i++)
		for(int j = 0;j<COLSIZE;j++)
			result.value[i*COLSIZE+j] = scale*m1.value[i*COLSIZE+j];
	return result;
}

Matrix44 operator-(const Matrix44& m1,const Matrix44& m2)
{
	return m1+(-1)*m2;
}

Matrix44 operator*(const Matrix44& m1,const Matrix44& m2)
{
	Matrix44 result;
	for(int i = 0;i<ROWSIZE;i++)
		for(int j = 0;j<COLSIZE;j++)
		{
			result.value[i*COLSIZE+j] = 0;
			for(int k = 0;k<ROWSIZE;k++)
			{
				result.value[i*COLSIZE+j] += m1.value[i*COLSIZE+k]*m2.value[k*COLSIZE+j];
			}
		}
	return result;
}