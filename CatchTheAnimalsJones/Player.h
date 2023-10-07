#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	int Hp; //   Hp -> Steps
	string name;
	int points;
	bool itsAlive;
	

public:
	Player() {
		width = 10;
		height = 4;
		x = (ANCHO / 2) - (width / 2);
		y = Console::WindowTop + height;
		points = 0;
		Hp = 200;
		name = "Jones";
	}
	int CantPoints() {
		return points;
	}
	void GetAnimal() {
		points += 1;
	}
	void SetHp(int x) {
		Hp = x;
	}
	int GetHp(){
		return Hp;
	}
	void Move() {
		bool moved = false;
		if (_kbhit()) {
			char tecla = toupper(getch());

			// Verificar si la tecla presionada representa un movimiento válido
			if (tecla == 'A' && x - dx > Console::WindowLeft) {
				x -= dx;
				moved = true;
				
			}
			else if (tecla == 'D' && x + dx + width < Console::WindowWidth) {
				x += dx;
				moved = true;
			}
			else if (tecla == 'W' && y - dy > Console::WindowTop) {
				y -= dy;
				moved = true;
			}
			else if (tecla == 'S' && y + dy + height < Console::WindowHeight) {
				y += dy;
				moved = true;
			}
		}
		if (moved == true) {
			Damage();
		}
			  
	}

	void Show() {

		 Console::SetCursorPosition(x, y);    cout << "       _ ";
		 Console::SetCursorPosition(x, y +1); cout << " [..]  | ";
		 Console::SetCursorPosition(x, y+2);  cout << "/[  ] -0 ";
		 Console::SetCursorPosition(x, y+3);  cout << " |  |  | ";
	}
	void Damage() {
		SetHp(GetHp() -  1);
		if (GetHp() == 0) {
			Dead();
		}
	}

	void Dead() {
		itsAlive = false;
	}

	bool IsAlive() {
		return Hp > 0;
	}
	void Hpscore() {
		Console::SetCursorPosition(110, 0 + height);
		cout << "Hp: " << GetHp() << " ";  // Se muestra el valor actual de HP sin borrar lo anterior
	}

};



