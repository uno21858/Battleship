#include "naves.hpp"
#include <iostream>

Naves::Naves(int type, Vector2 position, float scale) : type(type), position(position), scale(scale) {
    const char* imagePath;

    // Selección de la imagen según el tipo
    switch (type) {
        case 1:
            imagePath = "../Graphics/ship1.png";  // Acorazado
        break;
        case 2:
            imagePath = "../Graphics/ship2.png";  // Lancha
        break;
        case 3:
            imagePath = "../Graphics/ship3.png";  // Submarino
        break;
        default:
            imagePath = "../Graphics/ship1.png";  // Por defecto
        break;
    }

    // Cargar la imagen y escalarla
    Image image = LoadImage(imagePath);  // Carga la imagen desde el archivo
    int newWidth = static_cast<int>(image.width * scale);
    int newHeight = static_cast<int>(image.height * scale);
    ImageResize(&image, newWidth, newHeight);  // Redimensiona la imagen
    texture = LoadTextureFromImage(image);     // Crea una textura desde la imagen
    UnloadImage(image);                        // Libera la imagen de la RAM (ya no se necesita)
}

Naves::~Naves() {
    UnloadTexture(texture);  // Libera la textura de la VRAM
}

void Naves::Draw() {
    DrawTextureV(texture, position, WHITE);  // Dibuja la textura en la posición especificada
}

bool Naves::isPressed(Vector2 mousePos, bool mousePressed) {
    // Define el área rectangular de la nave
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    if (CheckCollisionPointRec(mousePos, rect) && mousePressed) {
        std::cout << "Nave clickeada: Tipo " << type << std::endl;
        return true;
    }
    return false;
}

int Naves::getType() {
    return type;  // Devuelve el tipo de la nave
}
