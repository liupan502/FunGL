#include "Triangle.h"
#include <iostream>

Triangle::Triangle()
{
	this->pointsIndex[0] = -1;
	this->pointsIndex[1] = -1;
	this->pointsIndex[2] = -1;
}
void Triangle::GetPointsIndex(int pointindex[3])
{
	memcpy(pointindex,this->pointsIndex,3*sizeof(int));
}

void Triangle::SetPointsIndex(const int pointindex[3])
{
	memcpy(this->pointsIndex,pointindex,3*sizeof(int));
}