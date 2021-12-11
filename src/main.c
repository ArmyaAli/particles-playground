#define RAYGUI_IMPLEMENTATION

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../include/raylib.h"
#include "../include/particleBuffer.h"
#include "../include/raygui.h"  

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 400

int main(void)
{
    // RAYLIB INIT
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ali's Particle Playground");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    
    ParticleBuffer* buffer = init_particles_buffer();
    Init();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Create(buffer);
        Update(buffer);
        Draw(buffer);
        EndDrawing();
    }

    destroy_particle_buffer(buffer);
    CloseWindow();

    return 0;
}

