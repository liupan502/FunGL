#ifndef LINE_SGMENT
#define LINE_SGMENT
#include "Vertex.h"
class LineSegment{
private:
	int pointsIndex[2];
	double width;
public :
	void SetPointsIndex(const int* value);
	void GetPointsIndex(int* result);
	void SetWidth(double width);
	void GetWidth(double& width);
};
#endif