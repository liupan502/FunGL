#ifndef VERTEX_H
#define VERTEX_H
#include "Matrix44.h"
#include "VectorUtil.h"
class Vertex{
private :
	// vertex poisition
	Vector4 poisition;

	// normal vector
	Vector4 normal;

	// color
	Vector4 color;

public:
	Vertex();
	Vertex(Vector4 data);
	Vertex(Vertex& otherVertex);
	Vector4 GetPoisition(void);
	void SetPoisition(Vector4 poisition);
	Vector4 GetNormal(void);
	void SetNormal(Vector4 normal);
	Vector4 GetColor(void); 
	void SetColor(Vector4 color);
	
};
#endif