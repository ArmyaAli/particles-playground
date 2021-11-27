
#include "include/raylib.h"
#include <stdlib.h>

struct _particle
{
    Vector2 pos;
    float radius;
    Color color;
} typedef Particle;

Particle* InitParticles();
void Update(Particle* pArray);
void Draw(Particle* pArray);
void Randomize(Particle* pArray);

const int SIZE = 100;
float elapsedTime = 0;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Ali's Particle Playground");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    Particle* pArray = InitParticles();

    while (!WindowShouldClose()) 
    {
        elapsedTime += GetFrameTime();


        BeginDrawing();

        ClearBackground(RAYWHITE);

        if(IsMouseButtonPressed(0)) 
        {
            printf("%lf\r\n", elapsedTime);
            Randomize(pArray);
        }

        Draw(pArray);

        EndDrawing();
;
    }

    CloseWindow(); 
    

    return 0;
}

Particle* InitParticles() {
    const Color colors[3] = { GREEN, RED, VIOLET};
    const int radius = 8;
    Particle* pArray = malloc(SIZE*sizeof(Particle));
    int i;
    time_t t;
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; ++i) {
        pArray[i].color = colors[rand() % 4];
        pArray[i].pos.x = rand() % 801;
        pArray[i].pos.y = rand() % 401;
        pArray[i].radius = radius;
    }

    return pArray;
}

void Randomize(Particle* pArray) {

    int i;
    time_t t;
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; ++i) {
        pArray[i].pos.x = rand() % 801;
        pArray[i].pos.y = rand() % 401;
    }
}

void Update(Particle* pArray) {

}

void Draw(Particle* pArray) {
    int i;
    for(i = 0; i < SIZE; ++i) {
        DrawCircle(pArray[i].pos.x, pArray[i].pos.y, pArray[i].radius, pArray[i].color);            
    }
}