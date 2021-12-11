#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "../include/raylib.h"
#include "../include/ParticleList.h"
#include "../include/util.h"
#include "../include/particles.h"
#include "../include/menu.h"

void Init();
void Create(ParticleList*);
void Update(ParticleList*);
void Draw(ParticleList*);
void Destroy(ParticleList*);

#endif