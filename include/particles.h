#ifndef PARTICLES_H
#define PARTICLES_H

#include "../include/raylib.h"
#include "../include/particleBuffer.h"

#define RADIUS 2
#define SIZE   32

void create_particles(PARTICLE_BUFFER*);
void update_particles(PARTICLE_BUFFER*);
void draw_particles(PARTICLE_BUFFER*);
void destroy_particles(PARTICLE_BUFFER*);
#endif