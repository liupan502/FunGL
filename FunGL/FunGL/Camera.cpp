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
}



