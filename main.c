
#include "include/raylib.h"
#include <stdlib.h>

struct _particle
{
    Vector2 pos;
    float radius;
    Color color;
    float dt;
    float vel;
} typedef Particle;

void InitParticles();

void Update(Particle *pArray, float elapsedTime);
void Draw(Particle *pArray);
void RandomizeParticles(Particle *pArray);

int SIZE = 4;
float acceleration = 2;
Particle* pArray = NULL;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Ali's Particle Playground");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (IsMouseButtonPressed(0))
        {
            InitParticles();
            printf("Clicked\r\n");
        }

        if(pArray) {
            Draw(pArray);
            Update(pArray, GetFrameTime());
        }

        EndDrawing();
    }

    free(pArray);

    CloseWindow();

    return 0;
}

void InitParticles()
{
    const int colorsLen = 3;
    const int radius = 8;

    const Color colors[3] = {GREEN, RED, VIOLET};
    int i;
    
    if(pArray == NULL) {
        printf("here\r\n");
        pArray = malloc(SIZE * sizeof(Particle));
        time_t t;

        srand((unsigned)time(&t));

        for (i = 0; i < SIZE; ++i)
        {
            pArray[i].color = colors[rand() % colorsLen];
            pArray[i].pos.x = rand() % 801;
            pArray[i].pos.y = rand() % 401;
            pArray[i].radius = radius;
            pArray[i].vel = 1.0f;
        }

        return;
    }

    printf("not here\r\n");
    SIZE *= 2;
    pArray = realloc(pArray, SIZE * sizeof(Particle)); // double the particles 

    for (i = SIZE / 2; i < SIZE; ++i)
    {
        pArray[i].color = colors[rand() % colorsLen];
        pArray[i].pos.x = rand() % 801;
        pArray[i].pos.y = rand() % 401;
        pArray[i].radius = radius;
        pArray[i].vel = 1.0f;
    }


}

void RandomizeParticles(Particle *pArray)
{
    int i;
    time_t t;
    srand((unsigned)time(&t));

    for (i = 0; i < SIZE; ++i)
    {
        pArray[i].pos.x = rand() % 801;
        pArray[i].pos.y = rand() % 401;
    }
}

void Update(Particle *pArray, float t)
{
    int i;
    for (i = 0; i < SIZE; ++i)
    {
        pArray[i].dt += t;
        pArray[i].pos.y += pArray[i].vel * 0.5 * acceleration * pArray[i].dt * pArray[i].dt;
        if (pArray[i].pos.y > (400 + pArray[i].radius) || pArray[i].pos.y < 0 + pArray[i].radius)
        {
            pArray[i].vel *= -1.0f;
        }
    }
}

void Draw(Particle *pArray)
{
    int i;
    for (i = 0; i < SIZE; ++i)
    {
        DrawCircle(pArray[i].pos.x, pArray[i].pos.y, pArray[i].radius, pArray[i].color);
    }
}