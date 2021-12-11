#ifndef P_LIST
#define P_LIST

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

typedef struct _pListNode 
{
    Particle p;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct _pListLinkedList
{
    int size;
    Node* head;
    Node* tail;
} ParticleList;


ParticleList* init_particles_list();
void add_particle(ParticleList*, Particle*);
void remove_finished_particles(ParticleList*);
void log_particles(ParticleList*);
void destroy_particle_list(ParticleList*);

#endif