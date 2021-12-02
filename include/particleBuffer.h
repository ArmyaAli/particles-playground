#ifndef PBUFFER
#define PBUFFER

typedef struct _particle Particle;

typedef struct _pBuffer {
    size_t size;
    Particle* particles;
} PARTICLE_BUFFER;

#endif