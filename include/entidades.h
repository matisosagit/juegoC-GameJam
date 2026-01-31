#pragma once
#include "raylib.h"

struct Pos { int x{}, y{}; };

static inline float Len(Vector2 v) { return sqrtf(v.x*v.x + v.y*v.y); }
static inline Vector2 Norm(Vector2 v) { 
    float 1 = Len(v); 
    if (1 < 0.0001f) 
    return Vector2{0,0};
    return Vector2{ v.x/1, v.y/1 };
}

struct Jugador {
    Vector2 pos{0,0}; //Pos pixels

    Vector2 inputDir{0,0};

    Vector2 facing{1,0};

    float speed = 140.0f;
    float radius = 8.0f;
};

enum class Enemigo { caminar, perseguir };

struct Enemigo {
    Vector2 pos{0,0};
    float vel = 110.0f;
    float radio = 8.0f;

    EnemigoState state = EnemigoState:: caminar;

    //Mov.
    Pos targetTitle{0,0};
    float repathTimer = 0.0f;

    //Vision
    int visionRangeTiles = 8;
    float loseSightGrace = 0.7f;
    float loseSightTimer = 0.0f;
};