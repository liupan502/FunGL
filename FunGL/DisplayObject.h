#ifndef DISPLAY_OBJECT
#define  DISPLAY_OBJECT
#include <vector>
#include "LineSegment.h"
#include "Triangle.h"
class DisplayObject{
private:
	std::vector<Vertex> points;
	std::vector<LineSegment> lines;
	//std::vector<Triangle> triangles;
public:
	// return number of lines that is added to the object successfully.
	int AddLines(Vertex* pointsBuf,int pointsNum,bool bStrip = true);

	// return number of triangles that is added to the object successfully.
	int AddTriangles(Vertex* pointsBuf,int pointsNum,bool bStrip = true);
};
#endif