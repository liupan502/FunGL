#ifndef MATRIX_44_H
#define MATRIX_44_H
const int COLSIZE = 4;
const int ROWSIZE = 4;
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
};

#endif