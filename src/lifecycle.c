#include "../include/lifecycle.h";

void Create(PARTICLE_BUFFER* buffer)
{
    if(IsMouseButtonDown(0) && !collision_exists())
        create_particles(buffer);
}

void Update(PARTICLE_BUFFER* buffer)
{
    update_particles(buffer); 
    update_menu();
}

void Draw(PARTICLE_BUFFER* buffer)
{
    draw_particles(buffer);
    draw_menu();
}

void Destroy(PARTICLE_BUFFER* buffer) 
{
    destroy_particles(buffer);
}