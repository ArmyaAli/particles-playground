#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../include/raylib.h"
#include "../include/particleBuffer.h"

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 400


float float_rand( float min, float max );

int main(void)
{
    // RAYLIB INIT
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ali's Particle Playground");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    // Buffer
    char particleNumberText[32];
    PARTICLE_BUFFER* buffer = init_particles_buffer();

    while (!WindowShouldClose())
    {
        sprintf(particleNumberText, "# of Particles: %d", buffer->size);
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawFPS(8, 8);
        DrawText(particleNumberText, SCREEN_WIDTH - MeasureText(particleNumberText, 24) - 8, 8, 24, RED);

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

