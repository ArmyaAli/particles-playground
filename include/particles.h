#ifndef PARTICLES_H
#define PARTICLES_H

#include "../include/raylib.h"
#include "../include/particleBuffer.h"
#include "../include/menu.h"

#define RADIUS 2
#define SIZE   32

void create_particles(PARTICLE_BUFFER*);
void update_particles(PARTICLE_BUFFER*);
void lifetime_stuff(Particle*, int);
void apply_physics_quantities(Particle*, int);
void check_bounds(Particle*, int);
void change_color_on_button_click();
void change_velocity_on_button_click();
void draw_particles(PARTICLE_BUFFER*);
void destroy_particles(PARTICLE_BUFFER*);

#endif