#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "../include/raylib.h"
#include "../include/particleBuffer.h"
#include "../include/util.h"
#include "../include/particles.h"


void Create(PARTICLE_BUFFER*);
void Update(PARTICLE_BUFFER*);
void Draw(PARTICLE_BUFFER*);
void Destroy(PARTICLE_BUFFER*);

#endif