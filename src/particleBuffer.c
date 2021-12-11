#include "../include/particleBuffer.h"

ParticleBuffer* init_particles_buffer()
{
    ParticleBuffer* buffer = calloc(1, sizeof(ParticleBuffer));
    buffer->particles       = NULL;
    buffer->capacity        = 0;
    return buffer;
}

void add_particle(ParticleBuffer* buffer, Particle* p)
{
    if (buffer->particles == NULL)
    {
        buffer->particles    = calloc(10, sizeof(Particle));
        buffer->capacity     = 10;
        buffer->particles[0] = *p;
        ++buffer->size;
    }
    else
    {
        if (buffer->size + 1 > buffer->capacity)
        {
            buffer->capacity                      = buffer->capacity * 2;
            buffer->particles                     = realloc(buffer->particles, buffer->capacity * sizeof(Particle));
            buffer->particles[++buffer->size - 1] = *p;
        }
        else
        {
            buffer->particles[++buffer->size - 1] = *p;
        }
    }
}

void remove_finished_particles(ParticleBuffer* buffer)
{
    // we need to scan through the buffer and look for particles with lifeTime = 0;
    // then we need to remove them from the buffer
    // if we remove we also need to shift the rest
    if (buffer->size == 0)
        return;

    Particle* pArray = buffer->particles;

    int i;
    for (i = 0; i < buffer->size; ++i)
    {
        if (pArray[i].lifeTime == 0)
        {
            int j;
            for(j = i; j < buffer->size; ++j)
                pArray[j] = pArray[j + 1];
            --buffer->size;
        }
    }
}

void log_particles(ParticleBuffer* buffer)
{
    Particle* pArray = buffer->particles;

    printf("Capacity: %d Size: %d\n", buffer->capacity, buffer->size);

    int i;
    for (i = 0; i < buffer->size; ++i)
    {
        printf("index: %d x: %d y: %d vel: %lf acc: %lf lT: %lf color: (%d, %d, %d, %d)\n", i, pArray[i].pos.x,
               pArray[i].pos.y, pArray[i].vel, pArray[i].acceleration, pArray[i].lifeTime, pArray[i].color.r,
               pArray[i].color.g, pArray[i].color.b, pArray[i].color.a);
    }

    printf("\n\n");
}

void destroy_particle_buffer(ParticleBuffer* buffer)
{
    free(buffer->particles);
    free(buffer);
}