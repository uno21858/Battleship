#include "raylib.h"
#include "Tablero.hpp"
#include "naves.hpp"

// Tamaño del grid
const int rows = 10;
const int cols = 10;
const int cellSize = 130;

// Función para dibujar el grid
void DrawGameGrid(int offsetX, int offsetY) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            // Posición de la celda
            int x = offsetX + col * cellSize;
            int y = offsetY + row * cellSize;

            // Dibujar los detalles de la celda
            DrawRectangleLines(x - 2, y - 2, cellSize + 4, cellSize + 4, DARKGRAY); // Detalle más oscuro
            DrawRectangleLines(x - 1, y - 1, cellSize + 2, cellSize + 2, GRAY);     // Detalle gris intermedio
            DrawRectangleLines(x, y, cellSize, cellSize, LIGHTGRAY);                // Detalle principal
        }
    }
}

// Función principal del tablero
void ShowGameBoard() {
    const int screenWidth = 1300;
    const int screenHeight = 1400;

    InitWindow(screenWidth, screenHeight, "Battleship");
    SetWindowIcon(LoadImage("../Graphics/icon.png")); // Cargar ícono (asegúrate de corregir la ruta)

    // Crear las naves una vez (persisten durante el juego)
    Naves ship1(1, {100, 100}, 0.25); // Nave1
    Naves ship2(2, {300, 300}, 0.25); // Nave2

    while (!WindowShouldClose()) { // Detectar el botón para cerrar
        BeginDrawing();
        ClearBackground(DARKBLUE);

        // Dibujar el grid del tablero
        DrawGameGrid(0, 97);

        // Dibujar las naves
        ship1.Draw();
        ship2.Draw();

        EndDrawing();
    }

    CloseWindow(); // Cerrar ventana y liberar recursos
}
