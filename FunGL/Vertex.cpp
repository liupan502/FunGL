#include "Vertex.h"


Vertex::Vertex(Vector4 data)
{
	this->poisition = data;
}

Vertex::Vertex()
{
	;
}

Vertex::Vertex(const Vertex& otherVertex)
{
	this->color = otherVertex.color;
	this->normal = otherVertex.normal;
	this->poisition = otherVertex.poisition;
}

Vector4 Vertex::GetPoisition(void)
{
	return poisition;
}
void Vertex::SetPoisition(Vector4 poisition)
{
	this->poisition = poisition;
}

Vector4 Vertex::GetColor(void)
{
	return color;
}

void Vertex::SetColor(Vector4 color)
{
	this->color = color;
}

Vector4 Vertex::GetNormal(void)
{
	return normal;
}

void Vertex::SetNormal(Vector4 normal)
{
	this->normal = normal;
}



