#pragma once
#include "Entity.h"
class Elefante : public Entity
{
public:
	Elefante() {
		width = 18;
		height = 7;
		x = 0;
		y = FckngRandom(Console::WindowTop + 1, Console::WindowHeight - height *4);

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
		    Console::SetCursorPosition(x, y);     cout << "        __    __";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 1); cout << "       / \\~~~/ \\";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 2); cout << "      ,----( .. )";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 3); cout << "    /     \\__ _|";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 4); cout << "   /|      (\\  |";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 5); cout << "  ^ \\ /___\\ /\\ |";
			Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
			Console::SetCursorPosition(x, y + 6); cout << "     | __| |__ |";

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






 
