#include "DisplayObject.h"

int DisplayObject::AddLines(Vertex* pointsBuf,int pointsNum,bool bStrip)
{
	if(pointsNum < 2)
		return 0;
	int addedLinesNum = 0;
	Vertex startPoint,endPoint;
	startPoint = pointsBuf[0];
	endPoint = pointsBuf[1];
	for(int i = 1;;i++)
	{
		addedLinesNum = i;
		if(bStrip)
		{
			int pointIndex[2];
			LineSegment line;
			line.SetWidth(1.0);
			pointIndex[0] = points.size();
			points.push_back(startPoint);
			pointIndex[1] = points.size();
			line.SetPointsIndex(pointIndex);
			this->lines.push_back(line);
			startPoint = endPoint;
			if(i+1 >= pointsNum)
				break;
			endPoint = pointsBuf[i+1];
		}
		else
		{
			int pointIndex[2];
			LineSegment line;
			line.SetWidth(1.0);
			pointIndex[0] = points.size();
			points.push_back(startPoint);
			pointIndex[1] = points.size();
			points.push_back(endPoint);
			line.SetPointsIndex(pointIndex);
			lines.push_back(line);
			if(2*i+1 >= pointsNum)
				break;
			startPoint = pointsBuf[2*i];
			endPoint = pointsBuf[2*i+1];
		}
			
	}

	if(bStrip)
	{
		points.push_back(startPoint);
	}

	return addedLinesNum;
}


int DisplayObject::AddTriangles(Vertex* pointsBuf,int pointsNum,bool bStrip)
{
	int addTrianglesNum = 0;
	/*if(pointsNum < 3)
		return addTrianglesNum;
	Vertex p1,p2,p3;
	p1 = pointsBuf[0];
	p2 = pointsBuf[1];
	p3 = pointsBuf[2];
	addTrianglesNum = 1;
	for(;;addTrianglesNum++)
	{
		Triangle addTriangle;
		int pointIndex[3];
		if(bStrip)
		{
			pointIndex[0] = points.size();
			points.push_back(p1);
			pointIndex[1] = pointIndex[0]+1;			
			pointIndex[2] = pointIndex[0]+2;
			if(addTrianglesNum+2 >= pointsNum)
				break;
			p1 = p3;
			p3 = pointsBuf[addTrianglesNum+2];
			addTriangle.SetPointsIndex(pointIndex);
			triangles.push_back(triangle);
		}
		else
		{
			pointIndex[0] = points.size();
			points.push_back(p1);
			pointIndex[1] = points.size();
			points.push_back(p2);
			pointIndex[2] = points.size();
			points.push_back(p3);
			if(addTrianglesNum+3 >= pointsNum)
				break;
			p1 = pointsBuf[3*addTrianglesNum];
			p2 = pointsBuf[3*addTrianglesNum+1];
			p3 = pointsBuf[3*addTrianglesNum+2];
			addTriangle.SetPointsIndex(pointIndex);
			triangles.push_back(addTriangle);
		}
		
	}
	if(bStrip)
	{
		points.push_back(p1);
		points.push_back(p2);
	}*/

	return addTrianglesNum;
}