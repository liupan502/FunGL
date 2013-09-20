#include "LineSegment.h"
#include <iostream>

LineSegment::LineSegment()
{
	;
}

LineSegment::LineSegment(const LineSegment& otherLineSegment)
{
	memcpy(this->pointsIndex,otherLineSegment.pointsIndex,2*sizeof(int));
	this->width = otherLineSegment.width;
}

void LineSegment::GetPointsIndex(int* result)
{
	if(result)
		memcpy(result,this->pointsIndex,2*sizeof(int));
}

void LineSegment::SetPointsIndex(const int* value)
{
	memcpy(this->pointsIndex,value,2*sizeof(int));
}

void LineSegment::GetWidth(double& width)
{
	width = this->width;
}

void LineSegment::SetWidth(double width)
{
	this->width = width;
}
