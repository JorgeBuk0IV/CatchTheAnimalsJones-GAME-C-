#pragma once
#include "Entity.h"
class Serpiente : public Entity
{
public:
	Serpiente() {
		width = 21;
		height = 6;
		x = 0;
		y = FckngRandom(Console::WindowTop + 1, Console::WindowHeight - height * 6);
		
		
	}
	void SetDX(int dx) {
		this->dx = dx;
	}
	void SetDY(int dy) {
		this->dy = dy;
	}
	int GetDX() {
		return dx;
	}
	int GetDY() {
		return dy;
	}
	void show() {
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		    Console::SetCursorPosition(x, y);     cout << " ____  ";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 1); cout << "/ . .\\ ";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 2); cout << "\\  ---< ";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 3); cout << " \\  /  ";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 4); cout << "   /_________/   ";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 5); cout << " _/-=:_______/   ";
	}
	void Move() {
		x += dx;
		if (x + width > Console::WindowWidth)
		{
			dx *= -1;
			x = Console::WindowWidth - width - 1;
		}
		if (x <= Console::WindowLeft) {
			dx *= -1;
			x = Console::WindowLeft;
		}
	}
	bool CheckNotMove() {
		return GetDX() == 0 && GetDY() == 0;
	}
};






