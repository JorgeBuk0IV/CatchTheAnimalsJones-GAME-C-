#pragma once
#define ANCHO 120
#define ALTO 60
#include "Libraries.h"


class Entity
{
protected:
	int x, y;
	int dx, dy;
	int height;
	int width;
	

public:
	Entity() {
		dx = dy = 1;
	}
	virtual int GetX() {
		return x;
	}
	virtual int GetY() {
		return y;
	}
	virtual int GetDX() {
		return dx;
	}
	virtual int GetDY() {
		return dy;
	}
	virtual void SetX(int x) {
		this->x = x;
	}
	virtual void SetY(int y) {
		this->y = y;
	}
	virtual void SetDX(int dx) {
		this->dx = dx;
	}
	virtual void SetDY(int dy) {
		this->dy= dy;
	}
	virtual void  Borrar() {
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
			Console::SetCursorPosition(x + i, y + j); cout << " ";
			}
		}
	}
	int FckngRandom(int ub, int lb) {
		return (rand() % (ub - lb) + 1) + lb;
	}
	virtual int GetWidth() {
		return width;
	}
	virtual int GetHeight() {
		return height;
	}
	virtual bool CheckNotMove() {
		if (GetDX() == 0 && GetDY() == 0) {
			return true;
		}
	}
};


