#ifndef PARTICLES_H
#define PARTICLES_H

#include "../include/raylib.h"
#include "../include/ParticleList.h"
#include "../include/menu.h"

#define RADIUS 2
#define SIZE 100 


void create_particles(ParticleList*);
void update_particles(ParticleList*);
void lifetime_stuff(Particle*);
void apply_physics_quantities(Particle*);
void check_bounds(Particle*);
void change_color_on_button_click();
void change_velocity_on_button_click();
void draw_particles(ParticleList*);
void destroy_particles_list(ParticleList*);

#endif