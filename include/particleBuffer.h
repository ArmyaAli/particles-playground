#ifndef P_BUFFER
#define P_BUFFER

#include <stdlib.h>
#include "raylib.h"

typedef struct _particle
{
    struct _position
    {
        int x;
        int y;
    } pos;

    float vel;
    float acceleration;
    float lifeTime;
    Color color;
} Particle;

typedef struct _pBuffer
{
    int size;
    int capacity;
    Particle* particles;
} PARTICLE_BUFFER;


PARTICLE_BUFFER* init_particles_buffer();

void add_particle(PARTICLE_BUFFER*, Particle*);
void remove_finished_particles(PARTICLE_BUFFER*);
void log_particles(PARTICLE_BUFFER*);
void destroy_particle_buffer(PARTICLE_BUFFER*);

#endif