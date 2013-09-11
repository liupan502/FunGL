#include "Matrix44.h"
#include "Math.h"
void CreateIdentityMatrix(double* matrix);
void CreateRoateMatrix(double params[3],double* matrix);
void CreateRoateX(double angle,double* matrix);
void CreateRoateY(double angle,double* matrix);
void CreateRoateZ(double angle,double* matrix);
void CreateTranslationMatrix(double params[3],double* matrix);
void CreateScaleMatrix(double params[3],double* matrix);
void RegularInvert(double* srcMatrix,double* resultMatrix);
void QuickInvert(double* srcMatrix,double* resultMatrix);
double ComputeDeterminant(int size,double* data);
void GetCofactor(int rowIndex ,int colIndex,double* src,double* dest,int size);
double  ToRadian(double angle);
double  ToAngle(double radian);
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

Matrix44 Matrix44::Invert(bool bRegular)
{
	Matrix44 result;
	if(bRegular)
		RegularInvert(this->value,result.value);
	else
		QuickInvert(this->value,result.value);	
	return result;
}

void Matrix44::Init(MatrixMode mode,int paramsNum,double* params)
{
	switch(mode)
	{
	case GL_ROATE:
			if(paramsNum == 3)
				CreateRoateMatrix(params,value);
			break;
	case GL_TRANSLATION:
		if(paramsNum == 3)
			CreateTranslationMatrix(params,value);
		break;
	case GL_SCALE:
		if(paramsNum == 3)
			CreateScaleMatrix(params,value);
	default : ;
	};
}

double ToRadian(double angle)
{
	return angle/180.0*PI;
}

double ToAngle(double radian)
{
	return radian/PI*180.0;
}

void CreateIdentityMatrix(double* matrix)
{	
	for(int i= 0;i<4;i++)
		for(int j = 0;j<4;j++)
			if(i == j)
				matrix[i*4+j] = 1.0;
			else
				matrix[i*4+j] = 0;
}

/***************************************
||1		0	 0	 ||
||0	  cos	-sin||
||0   sin	 cos||
***************************************/
void CreateRoateX(double angle,double* matrix)
{
	double radian = ToRadian(angle);
	CreateIdentityMatrix(matrix);
	matrix[5] = cos(radian);
	matrix[6] = -sin(radian);
	matrix[9] = sin(radian);
	matrix[10] = cos(radian);

}

/**************************************
|| cos		0		sin||
|| 0		1		0	||
|| -sin	0		cos||
***************************************/
void CreateRoateY(double angle,double* matrix)
{
	double radian = ToRadian(angle);
	CreateIdentityMatrix(matrix);
	matrix[0] = cos(radian);
	matrix[2] = sin(radian);
	matrix[8] = -sin(radian);
	matrix[10] = cos(radian);
}

/**
||cos	-sin  0||
||sin	cos   0||
||0		0		1||
**/
void CreateRoateZ(double angle,double* matrix)
{
	double radian = ToRadian(angle);
	CreateIdentityMatrix(matrix);
	matrix[0] = cos(radian);
	matrix[1] = -sin(radian);
	matrix[5] = sin(radian);
	matrix[6] = cos(radian);
}

void CreateRoateMatrix(double params[3],double* matrix )
{
	int index = 0;
	for(int i = 0;i<3;i++)
	{
		if(params[i] != 0)
			break;
	}
	switch(index)
	{
	case 0:
		CreateRoateX(params[index],matrix);break;
	case 1:
		CreateRoateY(params[index],matrix);break;
	case 2:
		CreateRoateZ(params[index],matrix);break;
	default:break;
	}
}

void CreateTranslationMatrix(double params[3],double* matrix)
{
	CreateIdentityMatrix(matrix);
	matrix[3] = params[0];
	matrix[7] = params[1];
	matrix[11] = params[2];
}

void CreateScaleMatrix(double params[3],double* matrix)
{
	CreateIdentityMatrix(matrix);
	matrix[0] = params[0];
	matrix[5] = params[1];
	matrix[10] = params[2];
}

void RegularInvert(double* srcMatrix,double* resultMatrix)
{
	double det = ComputeDeterminant(4,srcMatrix);
	double* tmp = new double[9];
	for(int rowIndex = 0;rowIndex <4;rowIndex++)
		for(int colIndex = 0;colIndex <4;colIndex++)
		{
			
			GetCofactor(rowIndex,colIndex,srcMatrix,tmp,3);
			double subDet = pow(-1,(double)((rowIndex+colIndex)%2))*ComputeDeterminant(3,tmp);
			srcMatrix[rowIndex*4+colIndex] = subDet/det;
		}
		delete tmp;
}

void QuickInvert(double* srcMatrix,double* resultMatrix)
{
	;
}

double ComputeDeterminant(int size,double* data)
{
	if(size < 2)
		return 0;
	else if(size == 2)
	{
		return data[0]*data[3] - data[1]*data[2];
	}
	else
	{
		double det = 0.0;
		double* tmpData = (double*) malloc(sizeof(double)*(size-1)*(size-1));
		if(!tmpData)
			return 0.0;
		for(int i = 0;i<size;i++)
		{
			GetCofactor(0,i,data,tmpData,size-1);
			det = det+pow(-1,(double)(i%2))*ComputeDeterminant(size-1,tmpData);
		}
		free(tmpData);
		return det;
	}
 
}

void GetCofactor(int rowIndex,int colIndex,double* src,double *dest,int size)
{
	for(int i = 0;i<=size;i++)
	{
		if(i == rowIndex )
			continue;
		memcpy(dest+i*size,src+i*(size+1),colIndex*sizeof(double));
		memcpy(dest+i*size+colIndex,src+i*(size+1)+colIndex+1,(size-colIndex)*sizeof(double));
	}
}

Matrix44 Identity()
{
	Matrix44 result ;
	for(int i= 0;i<4;i++)
		for(int j = 0;j<4;j++)
		{
			if(i == j)
				result.value[i*4+j] = 1.0;
			else
				result .value[i*4+j] = 0.0;
		}
		return result;
}
