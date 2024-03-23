
#include "Vector2.h"


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(int x, int y) {
	this->x = x;
	this->y = y;
}

int Vector2::GetX() {
	return this->x;
}

int Vector2::GetY() {
	return this->y;
}

void Vector2::Set(int x, int y) {
	this->x = x;
	this->y = y;
}

void Vector2::SetX(int x) {
	this->x = x;
}

void Vector2::SetY(int y) {
	this->y = y;
}

string Vector2::ToString() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

