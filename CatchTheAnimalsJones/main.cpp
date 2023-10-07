#include "Game.h" // Asegúrate de incluir el encabezado de Game
#include "Player.h"

int main() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
    Player ply1;
    Game game; // Crea una instancia de la clase Game
    srand(static_cast<unsigned int>(time(nullptr)));
    while (!game.CheckWin() || !game.CheckGameOver() ) {
        game.Run();
    }
    getch();

    return 0;
}
