#ifndef VECTOR_H
#define VECTOR_H

class Vector4{
private:
	double x;
	double y;
	double z;
	double w;
public:
	Vector4(double x = 0.0,double y = 0.0,double z = 0.0,double w = 0.0);
	double GetX();void SetX(double value);
	double GetY();void SetY(double value);
	double GetZ();void SetZ(double value);
	double GetW();void SetW(double value);
	double Length();

	/************************************************************************/
	/* this method works just when the Vector4 reprsent a 3d-vector not a 3d-point
		that is the value of w is zero not one.
	*/
	/************************************************************************/
	Vector4 Cross(Vector4 v);

	bool IsParallel(Vector4 v);
friend	Vector4 operator+(Vector4 v1,Vector4 v2);

	/*		 result = v1 - v2		*/
friend	Vector4 operator-(Vector4 v1,Vector4 v2);
friend	Vector4 operator*(Vector4 v,double scale);
friend	Vector4 operator*(double scale,Vector4 v);

	
};

//class Vector3{
//private :
//	Vector4 data;
//public:
//	double GetX();void SetX(double value);
//	double GetY();void SetY(double value);
//	double GetZ();void SetZ(double value);
//};
#endif