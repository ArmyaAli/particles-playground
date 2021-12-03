#include "../include/menu.h";

#define MENU_X 32
#define MENU_Y 64
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 64
#define BUTTON_GAP 100

Color highlight = {130,130,130,255};

void update_menu()
{
    int collision = check_button_collision();
    if(collision != -1) {
        highlight.a = 127;
        printf("%d", collision);
    } else 
        highlight.a = 255;
}

void draw_menu()
{
    int i;
    for (i = 0; i < 3; ++i)
    {
        DrawRectangle(MENU_X, MENU_Y + i * BUTTON_GAP, BUTTON_WIDTH, BUTTON_HEIGHT, highlight);
    }
}

int check_button_collision()
{
    Vector2 mouse = GetMousePosition();

    if(mouse.x >= MENU_X && mouse.x <= MENU_X + BUTTON_WIDTH) {
        if(mouse.y >= MENU_Y && mouse.y <= BUTTON_HEIGHT + MENU_Y)
            return 1;
    } 
    
    if(mouse.x >= MENU_X && mouse.x <= MENU_X + BUTTON_WIDTH) {
        if(mouse.y >= MENU_Y + BUTTON_GAP * 1 && mouse.y <= MENU_Y + BUTTON_GAP * 1 + BUTTON_HEIGHT)
            return 2;
    }

    if(mouse.x >= MENU_X && mouse.x <= MENU_X + BUTTON_WIDTH) {
        if(mouse.y >= MENU_Y + BUTTON_GAP * 2 && mouse.y <= MENU_Y + BUTTON_GAP * 2 + BUTTON_HEIGHT)
            return 3;
    }

    return -1;
}
