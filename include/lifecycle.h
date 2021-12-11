#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "../include/raylib.h"
#include "../include/particleBuffer.h"
#include "../include/util.h"
#include "../include/particles.h"
#include "../include/menu.h"

void Init();
void Create(ParticleBuffer*);
void Update(ParticleBuffer*);
void Draw(ParticleBuffer*);
void Destroy(ParticleBuffer*);

#endif