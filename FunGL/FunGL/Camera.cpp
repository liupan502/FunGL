#include "Camera.h"
Camera::Camera()
{
	;
}
Camera::Camera(Vector4 eye,Vector4 target,Vector4 up)
{
	this->SetEye(eye);
	this->SetTarget(target);
	this->SetUp(up);
	UpdateViewMatrix();
}

Vector4 Camera::GetEye()
{
	return this->eyeLocation;
}

void Camera::SetEye(Vector4 eye)
{
	this->eyeLocation = eye;
	UpdateViewMatrix();
}

Vector4 Camera::GetTarget()
{
	return this->targetLocation;
}

void Camera::SetTarget(Vector4 target)
{
	this->targetLocation = target;
	UpdateViewMatrix();
}

Vector4 Camera::GetUp()
{
	return this->upDirection;
}

void Camera::SetUp(Vector4 up)
{
	this->upDirection = up;
	UpdateViewMatrix();
}

void Camera::UpdateViewMatrix()
{
	Vector4 cameraZAxis = eyeLocation - targetLocation;
	if(cameraZAxis.IsParallel(upDirection))
	{
		this->IsAvailable = false;
		return;
	}
	Vector4 cameraXAxis = upDirection.Cross(cameraZAxis);
	Vector4 cameraYAxis = cameraZAxis.Cross(cameraXAxis);
	
	Matrix44 tmpMatrix = Matrix44.Identity();
	tmpMatrix.value[0] = cameraXAxis.GetX();
	tmpMatrix.value[1] = cameraXAxis.GetY();
	tmpMatrix.value[2] = cameraXAxis.GetZ();
	tmpMatrix.value[3] = cameraXAxis.GetW();
	tmpMatrix.value[4] = cameraYAxis.GetX();
	tmpMatrix.value[5] = cameraYAxis.GetY();
	tmpMatrix.value[6] = cameraYAxis.GetZ();
	tmpMatrix.value[7] = cameraYAxis.GetW();
	tmpMatrix.value[8] = cameraZAxis.GetX();
	tmpMatrix.value[9] = cameraZAxis.GetY();
	tmpMatrix.value[10] = cameraZAxis.GetZ();
	tmpMatrix.value[11] = cameraZAxis.GetW();
	Matrix44 tmpInvert = tmpMatrix.Invert();
	Matrix44 translationMatrix;
	double params[3];
	params[0] = -eyeLocation.GetX();
	params[1] = -eyeLocation.GetY();
	params[2] = -eyeLocation.GetZ();
	translationMatrix.Init(GL_TRANSLATION,3,params);
	this->viewMatrix = tmpInvert*translationMatrix;
	
}



