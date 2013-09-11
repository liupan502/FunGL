#include "Vector.h"
#include "Math.h"
Vector4::Vector4(double x ,double y,double z,double w)
{
	this->SetX(x);
	this->SetY(y);
	this->SetZ(z);
	this->SetW(w);
}
Vector4::Vector4()
{
	this->SetX(0.0);
	this->SetY(0.0);
	this->SetZ(0.0);
	this->SetW(0.0);
}
double Vector4 ::GetX()
{
	return this->x;
}

void Vector4::SetX(double value)
{
	this->x = value;
}

double Vector4::GetY()
{
	return this->y;
}

void Vector4::SetY(double value)
{
	this->y = value;
}

double Vector4::GetZ()
{
	return this->z;
}

void Vector4::SetZ(double value)
{
	 this->z = value;
}

double Vector4::GetW()
{
	return this->w;
}

void Vector4::SetW(double value)
{
	this->w = value;
}

double Vector4::Length()
{
	return sqrt(pow(x,2.0)+pow(y,2.0)+pow(z,2.0)+pow(w,2.0));
}

double operator*(Vector4 v1,Vector4 v2)
{
	return v1.GetX()*v2.GetX()+v1.GetY()*v2.GetY()+v1.GetZ()*v2.GetZ()+v1.GetW()*v2.GetW();
}

Vector4 operator*(Vector4 v,double scale)
{
	Vector4 result;
	result.SetX(scale*v.GetX());
	result.SetY(scale*v.GetY());
	result.SetZ(scale*v.GetZ());
	result.SetW(scale*v.GetW());
	return result;
}

Vector4 operator* (double scale,Vector4 v)
{
	return v*scale;
}

Vector4 operator+(Vector4 v1,Vector4 v2)
{
	Vector4 result;
	result.SetX(v1.GetX()+v2.GetX());
	result.SetY(v1.GetY()+v2.GetY());
	result.SetZ(v1.GetZ()+v2.GetZ());
	result.SetW(v1.GetW()+v2.GetW());
	return result;
}

Vector4 operator-(Vector4 v1,Vector4 v2)
{
	Vector4 result;
	result.SetX(v1.GetX() - v2.GetX());
	result.SetY(v1.GetY() - v2.GetY());
	result.SetZ(v1.GetZ() - v2.GetZ());
	result.SetW(v1.GetW() - v2.GetW());
	return result;
}

Vector4 Vector4::Cross(Vector4 v)
{
	Vector4 result; 
	if(this->GetW() != 0||v.GetW()!= 0)
		return result;
	result.SetW(0.0);
	double xValue = this->GetY()*v.GetZ()-this->GetZ()*v.GetY();result.SetX(xValue);
	double yValue = this->GetZ()*v.GetX()-this->GetX()*v.GetZ();result.SetY(yValue);
	double zValue = this->GetX()*v.GetY()-this->GetY()*v.GetX();result.SetZ(zValue);
}

bool Vector4::IsParallel(Vector4 v)
{
	double length1 = this->Length();
	double length2 = v.Length();
	double dotProduct = (Vector4)(*this)*v;
	if(fabs(dotProduct/(length1*length2)) == 1.0)
		return true;
	else
		return false;
}
