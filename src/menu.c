#include "../include/menu.h";

#define MENU_X 32
#define MENU_Y 64

void update_menu() 
{

}

void draw_menu()
{
    const int buttonGap = 100;
    int i;
    for(i = 0; i < 3; ++i) {
        DrawRectangle(MENU_X, MENU_Y + i * buttonGap, 100, 50, GRAY);
    }
}