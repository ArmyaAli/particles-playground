#ifndef P_BUFFER
#define P_BUFFER

#include <stdlib.h>
#include "raylib.h"

typedef struct _particle
{
    Vector2 pos;
    Vector2 vel;
    Vector2 acceleration;
    float lifeTime;
    Color color;
} Particle;

typedef struct _particleBuffer
{
    int size;
    int capacity;
    Particle* particles;
} ParticleBuffer;

ParticleBuffer* init_particles_buffer();

void add_particle(ParticleBuffer*, Particle*);
void remove_finished_particles(ParticleBuffer*);
void log_particles(ParticleBuffer*);
void destroy_particle_buffer(ParticleBuffer*);

#endif