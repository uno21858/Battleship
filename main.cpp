#include "raylib.h"
#include "StartMenu.hpp"  // Incluir el encabezado del menú
#include "Tablero.hpp"    // Incluir el encabezado del tablero (debes crearlo si no existe)

int main() {
    while (true) {
        // Mostrar el menú principal
        int action = ShowStartMenu();

        if (action == 1) {
            // Si selecciona "Jugar", mostrar el tablero del juego
            ShowGameBoard();
        } else if (action == 0) {
            // Si selecciona "Salir", terminar el programa
            break;
        }
    }
    return 0;
}