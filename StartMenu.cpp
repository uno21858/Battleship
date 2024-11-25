#include "raylib.h"
#include "button.hpp"
#include <cstdio>
#include <iostream>
#include <unistd.h> // Para obtener la ruta del archivo ejecutable

int ShowStartMenu() {
    // Busca donde está el archivo ejecutable
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current working directory: %s\n", cwd);

    // Inicializar la ventana
    const int screenWidth = 1024;
    const int screenHeight = 1024;
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Battleship menu");
    SetWindowIcon(LoadImage("../Graphics/icon.png"));  // Configurar icono

    Texture2D background = LoadTexture("../Graphics/Menu.png"); // Fondo del menú

    // Crear botones
    Button startButton("../Graphics/StartButton.png", { 100, 600}, 0.35);  // Botón de inicio
    Button exitButton("../Graphics/ExitButton.png", { 600, 600}, 0.345);  // Botón de salida
    bool exit = false;

    // Variable que controla la acción seleccionada: 1 para jugar, 0 para salir
    int action = 0;

    // Main game loop
    while (WindowShouldClose() == false && exit == false) {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        // Detectar si se presiona un botón
        if (startButton.isPressed(mousePosition, mousePressed)) {
            action = 1;  // Jugar
            break;
        }
        if (exitButton.isPressed(mousePosition, mousePressed)) {
            action = 0;  // Salir
            break;
        }

        // Dibujar el menú
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawTexture(background, 0, 0, WHITE);

        startButton.Draw();
        exitButton.Draw();
        EndDrawing();
    }

    // Desinicializar la ventana y recursos
    CloseWindow();
    return action;
}
