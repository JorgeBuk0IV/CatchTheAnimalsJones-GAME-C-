#pragma once
#include "Entity.h"
class Leon : public Entity
{

public:
	Leon() {
		width = 17;
		height = 6;
		x = 0;
		y = FckngRandom(Console::WindowTop + 1, Console::WindowHeight - height * 4);

	}
	void show() {
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		Console::SetCursorPosition(x, y);     cout << "  ,-. __ .-,";
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		Console::SetCursorPosition(x, y + 1); cout << "- -;`. ' `.'";
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		Console::SetCursorPosition(x, y + 2); cout << "  / ( ^__^ )";
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		Console::SetCursorPosition(x, y + 3); cout << "  ; `(_`'_)' \\";
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		Console::SetCursorPosition(x, y + 4); cout << " ' ` .`--'_, ;";
		Console::ForegroundColor = ConsoleColor(FckngRandom(0, 5));
		Console::SetCursorPosition(x, y + 5); cout << "~~`-..._)))(((.'";

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
	void SetDX(int dx) {
		this->dx = dx;
	}
	 void SetDY(int dy) {
		this->dy = dy;
	}
	bool CheckNotMove() {
		return GetDX() == 0 && GetDY() == 0;
	}
	 int GetDX() {
		return dx;
	}
	 int GetDY() {
		return dy;
	}
	
};






