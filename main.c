#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "include/raylib.h"
#include "include/particleBuffer.h"

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 400
#define RADIUS 4
#define SIZE 100

int main(void)
{
    // RAYLIB INIT
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ali's Particle Playground");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    // Buffer

    PARTICLE_BUFFER* buffer = init_particles_buffer();
    InitParticles(buffer);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (IsMouseButtonPressed(0))
        {
            printf("Clicked\r\n");
            log_particles(buffer);
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
    const int colorsLen   = 3;
    const int radius      = 8;
    const Color colors[3] = {GREEN, RED, VIOLET};
    time_t t;
    srand((unsigned)time(&t));
    
    int i;
    for (i = 0; i < SIZE; ++i)
    {
        Particle p = {{rand() % 801, rand() % 401}, 0, 0, rand() % 500, colors[rand() % 3]};
        add_particle(buffer, &p);
    }
}


void Update(PARTICLE_BUFFER* buffer)
{
    Particle* pArray = buffer->particles;
    int i;

    for (i = 0; i < buffer->size; ++i) {
        if(pArray[i].lifeTime > 0)
            pArray[i].lifeTime--;
    }


}

void Draw(PARTICLE_BUFFER* buffer)
{
    Particle* pArray = buffer->particles;
    int i;
    for (i = 0; i < buffer->size; ++i) {
        DrawCircle(pArray[i].pos.x, pArray[i].pos.y, RADIUS, pArray[i].color);
    }
}
