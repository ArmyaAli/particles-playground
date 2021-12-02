#include "./include/particleBuffer.h"

PARTICLE_BUFFER* init() {
    PARTICLE_BUFFER* buffer = calloc(1, sizeof(PARTICLE_BUFFER));
    buffer->particles = NULL;
    buffer->capacity = 0;
    return buffer;
}

void add_particle(PARTICLE_BUFFER* buffer, Particle* p) {
    if(buffer->particles == NULL) {
        buffer-> particles = calloc(10, sizeof(Particle));
        buffer->capacity = 10;
        ++buffer->size;
        buffer->particles[0] = *p;
    } else {
        if(buffer->size + 1 == buffer->capacity) {
            buffer-> particles = realloc(buffer->particles, buffer->capacity * 2);
            buffer-> capacity = buffer->capacity * 2;
            buffer->particles[++buffer->size - 1] = *p;
        } else {
            buffer->particles[++buffer->size - 1] = *p;
        }
    }
}

void destroy_particle_buffer(PARTICLE_BUFFER* buffer) {
    free(buffer->particles);
    free(buffer);
}