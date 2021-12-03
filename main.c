#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "include/raylib.h"
#include "include/particleBuffer.h"

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 400
#define RADIUS        2
#define SIZE          100

float float_rand( float min, float max );

int main(void)
{
    // RAYLIB INIT
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ali's Particle Playground");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    // Buffer

    PARTICLE_BUFFER* buffer = init_particles_buffer();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (IsMouseButtonPressed(0))
        {
            printf("Clicked\r\n");
            // log_particles(buffer);
            InitParticles(buffer);
        }


        if (IsMouseButtonDown(0)) {
            InitParticles(buffer);
        }
        Update(buffer);
        Draw(buffer);
        remove_finished_particles(buffer);

        EndDrawing();
    }

    destroy_particle_buffer(buffer);
    CloseWindow();

    return 0;
}

void InitParticles(PARTICLE_BUFFER* buffer)
{
    const int colorsLen        = 3;
    const int offset           = 32;
    const Color colors[3]      = { GREEN, RED, VIOLET };
    const Vector2 velocity     = { 1.0f, 0.0f };
    const Vector2 acceleration = { 0, 0.05 };
    const Vector2 mouse = GetMousePosition();
    time_t t;
    srand((unsigned)time(&t));

    int i;
    for (i = 0; i < SIZE / 2; ++i)
    {
        Particle p = {
        { mouse.x + offset * cos(float_rand(PI/2, -PI/2)), mouse.y + offset * sin(float_rand(0, PI))}, 
        velocity, 
        acceleration, 
        rand() % 255, colors[rand() % 3]};
        add_particle(buffer, &p);
    }

    for (i = SIZE / 2; i < SIZE; ++i)
    {
        Particle p = {
        { mouse.x + offset * cos(float_rand(PI/2, 2*PI/3)), mouse.y - offset * sin(float_rand(PI, 2*PI))}, 
        velocity, 
        acceleration, 
        rand() % 255, colors[rand() % 3]};
        add_particle(buffer, &p);
    }
}

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

void Update(PARTICLE_BUFFER* buffer)
{
    Particle* pArray = buffer->particles;
    int i;
    const Vector2 bounds = {800, 400};
    for (i = 0; i < buffer->size; ++i)
    {
        if (pArray[i].lifeTime > 0)
            pArray[i].lifeTime--;

        pArray[i].pos.x += pArray[i].vel.x;
        pArray[i].vel.x += pArray[i].acceleration.x;

        pArray[i].pos.y += pArray[i].vel.y;
        pArray[i].vel.y += pArray[i].acceleration.y;

        if (pArray[i].pos.x >= bounds.x)
        {
            pArray[i].vel.x *= -1;
        }

        if (pArray[i].pos.y >= bounds.y)
        {
            pArray[i].vel.y *= -1;
        }
    }
}

void Draw(PARTICLE_BUFFER* buffer)
{
    Particle* pArray = buffer->particles;
    int i;
    for (i = 0; i < buffer->size; ++i)
    {
        DrawCircle(pArray[i].pos.x, pArray[i].pos.y, RADIUS, pArray[i].color);
    }
}
