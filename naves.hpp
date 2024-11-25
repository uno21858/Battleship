#pragma once
#include <raylib.h>

class Naves {
public:
    Naves(int type, Vector2 position, float scale);
    ~Naves();
    void Draw();
    bool isPressed(Vector2 mousePos, bool mousePressed);
    int getType();

private:
    Texture2D texture; // Cambiamos de "image" a "texture" para seguir el mismo estándar que `Button`.
    int type;
    Vector2 position;
    float scale;
};