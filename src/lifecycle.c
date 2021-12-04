#include "../include/lifecycle.h";

char particleNumberText[32];

void Create(PARTICLE_BUFFER* buffer)
{
    if(IsMouseButtonDown(0) && !collision_exists())
        create_particles(buffer);
}

void Update(PARTICLE_BUFFER* buffer)
{

    sprintf(particleNumberText, "# of Particles: %d", buffer->size);
    update_particles(buffer); 
    update_menu();
}

void Draw(PARTICLE_BUFFER* buffer)
{
    DrawFPS(8, 8);
    DrawText(particleNumberText, 800 - MeasureText(particleNumberText, 24) - 8, 8, 24, RED);
    draw_particles(buffer);
    draw_menu();
}

void Destroy(PARTICLE_BUFFER* buffer) 
{
    destroy_particles(buffer);
}