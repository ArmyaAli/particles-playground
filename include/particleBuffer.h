#ifndef P_BUFFER
#define P_BUFFER

#include <stdlib.h>

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
} Particle;

typedef struct _pBuffer
{
    int size;
    int capacity;
    Particle* particles;
} PARTICLE_BUFFER;

PARTICLE_BUFFER* init();
void add_particle(PARTICLE_BUFFER*, Particle*);
void remove_finished_particles(PARTICLE_BUFFER*);
void log_particles(PARTICLE_BUFFER*);
void destroy_particle_buffer(PARTICLE_BUFFER*);

#endif