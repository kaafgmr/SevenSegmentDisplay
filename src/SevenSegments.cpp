#include "SevenSegments.hpp"
#include "NoEntiendo.hpp"

Segment::Segment(float posX, float posY, int width, int height)
{
	x = posX;
	y = posY;
	state = 0;
	w = width;
	h = height;
}

void Segment::Draw()
{
	NOE_DibujaCaja(x, y, w, h, 255 * state, 0, 0);
}

void Segment::changeState(int value)
{
	state = value;
}

float Segment::getPosX()
{
	return x;
}

float Segment::getPosY()
{
	return y;
}

Segment::~Segment()
{

}