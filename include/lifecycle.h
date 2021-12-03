#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "../include/raylib.h"
#include "../include/particleBuffer.h"
#include "../include/util.h"

#define RADIUS 2
#define SIZE   32

void InitParticles(PARTICLE_BUFFER* buffer);
float float_rand( float min, float max );
void Update(PARTICLE_BUFFER* buffer);
void Draw(PARTICLE_BUFFER* buffer);

#endif