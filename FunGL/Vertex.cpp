#include "Vertex.h"

Vector4 Vertex::GetPoisition(void)
{
	return this->poisition;
}
void Vertex::SetPoisition(Vector4 poisition)
{
	this->poisition = poisition;
}

Vector4 Vertex::GetColor(void)
{
	return this->color;
}

void Vertex::SetColor(Vector4 color)
{
	this->color = color;
}

Vector4 Vertex::GetNormal(void)
{
	return this->normal;
}

void Vertex::SetNormal(Vector4 normal)
{
	this->normal = normal;
}

