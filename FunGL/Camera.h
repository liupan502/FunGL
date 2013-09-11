#ifndef CAMERA_H
#define CAEMRA_H
#include "Matrix44.h"
#include "Vector.h"
class Camera
{
private :
	Matrix44 viewMatrix;
	bool IsAvailable;
	void UpdateViewMatrix();
public :
	Vector4 eyeLocation;
	Vector4 targetLocation;
	Vector4 upDirection;
	Camera();
	Camera(Vector4 eye,Vector4 target,Vector4 up);
	Vector4 GetEye();void SetEye(Vector4 v);
	Vector4 GetTarget();void SetTarget(Vector4 v);
	Vector4 GetUp();void SetUp(Vector4 v);

};
#endif