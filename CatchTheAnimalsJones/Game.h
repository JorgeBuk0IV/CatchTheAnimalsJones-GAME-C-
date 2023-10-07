#pragma once
#include "Entity.h"
#include "Player.h"
#include "Leon.h"
#include "Serpiente.h"
#include "Elefante.h"

class Game
{
private:
	Leon lion1;
	Player ply1;
	Elefante elft1;
	Serpiente srp1;
public:
	Game() {

	}
	~Game() {

	}
	void GameOver() {
		if (CheckGameOver()== true) {
			system("cls");
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2));     cout << "  GGG     A    M   M  EEEEE      OOO   V   V  EEEEE  RRRR " << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 1); cout << " G       A A   MM MM  E         O   O  V   V  E      R   R" << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 2); cout << " G  GG  AAAAA  M M M  EEE       O   O   V V   EEE    RRRR " << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 3); cout << " G   G A     A M   M  E         O   O    V    E      R  R" << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 4); cout << "  GGG  A     A M   M  EEEEE      OOO     V    EEEEE  R   R" << endl;
		}
		getch();
	}
	bool CheckGameOver() {
		return !ply1.IsAlive();
	}

	
		
	bool CheckWin() {
		return (lion1.CheckNotMove() && srp1.CheckNotMove() && elft1.CheckNotMove());
	}
	void Run() {
		while (!JuegTerminado())
		{
			
			ply1.Borrar();
			ply1.Move();
			ply1.Show();
			ply1.Hpscore();
			lion1.Borrar();
			lion1.Move();
			lion1.show();
			elft1.Borrar();
			elft1.Move();
			elft1.show();
			srp1.Borrar();
			srp1.Move();
			srp1.show();
			// Verificar colisiones y realizar acciones en caso de colisión
			if (CheckCollisionLion(ply1, lion1)) {
				// Realizar acciones cuando hay colisión con el león
				lion1.SetDX(0);
				lion1.SetDY(0);
			}
			if (CheckCollisionSerpiente(ply1, srp1)) {
				// Realizar acciones cuando hay colisión con la serpiente
				srp1.SetDX(0);
				srp1.SetDY(0);
			}
			if (CheckCollisionElefante(ply1, elft1)) {
				// Realizar acciones cuando hay colisión con el elefante
				elft1.SetDX(0);
				elft1.SetDY(0);
			}
			_sleep(10);
		}
		
		

		// Cuando el bucle while termina, el juego ha finalizado, mostrar Game Over
		if (CheckWin()) {
			system("cls");
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2));    cout << "  GGGGGG s   A     N   N  AAAAA   SSSS   TTTTT   EEEEE" << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 1); cout << " G         A A    NN  N  A   A   S        T     E    " << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 2); cout << " G   GG   AAAAA   N N N  AAAAA    SSS     T     EEE  " << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 3); cout << " G    G  A     A  N  NN  A   A      S     T     E    " << endl;
			Console::SetCursorPosition((ANCHO / 2), (ALTO / 2) + 4); cout << "  GGG    A     A  N   N  A   A   SSSS     T     EEEEE" << endl;
			getch();
			system("cls");

		}
		else { GameOver(); }
		}
	
	bool CheckCollisionLion(Player& player, Leon& animal) {
		// Coordenadas del jugador
		int playerX = player.GetX();
		int playerY = player.GetY();
		int playerWidth = player.GetWidth();
		int playerHeight = player.GetHeight();

		// Coordenadas del animal (Leon)
		int animalX = animal.GetX();
		int animalY = animal.GetY();
		int animalWidth = animal.GetWidth();
		int animalHeight = animal.GetHeight();

		// Verificar si hay superposición entre los rectángulos de colisión
		if (playerX < animalX + animalWidth &&
			playerX + playerWidth > animalX &&
			playerY < animalY + animalHeight &&
			playerY + playerHeight > animalY) {
			// Hubo colisión
			return true;
		}

		// No hubo colisión
		return false;
	}
	bool CheckCollisionSerpiente(Player& player, Serpiente& snake) {
		// Coordenadas del jugador
		int playerX = player.GetX();
		int playerY = player.GetY();
		int playerWidth = player.GetWidth();
		int playerHeight = player.GetHeight();

		// Coordenadas de la serpiente
		int snakeX = snake.GetX();
		int snakeY = snake.GetY();
		int snakeWidth = snake.GetWidth();
		int snakeHeight = snake.GetHeight();

		// Verificar colisión entre el jugador y la serpiente
		if (playerX < snakeX + snakeWidth &&
			playerX + playerWidth > snakeX &&
			playerY < snakeY + snakeHeight &&
			playerY + playerHeight > snakeY) {
			// Hubo colisión
			return true;
		}

		// No hubo colisión
		return false;
	}
	bool CheckCollisionElefante(Player& player, Elefante& elephant) {
		// Coordenadas del jugador
		int playerX = player.GetX();
		int playerY = player.GetY();
		int playerWidth = player.GetWidth();
		int playerHeight = player.GetHeight();

		// Coordenadas del elefante
		int elephantX = elephant.GetX();
		int elephantY = elephant.GetY();
		int elephantWidth = elephant.GetWidth();
		int elephantHeight = elephant.GetHeight();

		// Verificar colisión entre el jugador y el elefante
		if (playerX < elephantX + elephantWidth &&
			playerX + playerWidth > elephantX &&
			playerY < elephantY + elephantHeight &&
			playerY + playerHeight > elephantY) {
			// Hubo colisión
			return true;
		}

		// No hubo colisión
		return false;
	}
	
	
	bool JuegTerminado() {
		
			return (CheckWin() || CheckGameOver());
		
	}

};


