#ifndef PARTICLES_H
#define PARTICLES_H

#include "../include/raylib.h"
#include "../include/particleBuffer.h"
#include "../include/menu.h"

#define RADIUS 2
#define SIZE 1000 


void create_particles(ParticleBuffer*);
void update_particles(ParticleBuffer*);
void lifetime_stuff(Particle*, int);
void apply_physics_quantities(Particle*, int);
void check_bounds(Particle*, int);
void change_color_on_button_click();
void change_velocity_on_button_click();
void draw_particles(ParticleBuffer*);
void destroy_particles(ParticleBuffer*);

#endif