#ifndef MENU
#define MENU

#include "../include/raylib.h"

void draw_menu();
void update_menu();

int check_button_collision();
int check_increment_button_collision();
int check_decrement_button_collision();
int collision_exists();

#endif