#include "../include/menu.h";

#define ENTITIES       4
#define MENU_X         64
#define MENU_Y         64
#define BUTTON_WIDTH   100
#define BUTTON_HEIGHT  32
#define BUTTON_GAP     50
#define FONT_SIZE      14
#define TRI_BUTTON_GAP 8
#define TRI_HEIGHT     32

Color buttonColors[ENTITIES] = {{130, 130, 130, 255}, {130, 130, 130, 255}, {130, 130, 130, 255}, {130, 130, 130, 255}};
Color rightButtonColors[ENTITIES] = {{0, 228, 48, 255}, {0, 228, 48, 255}, {0, 228, 48, 255}, {0, 228, 48, 255}};
Color leftButtonColors[ENTITIES]  = {{0, 228, 48, 255}, {0, 228, 48, 255}, {0, 228, 48, 255}, {0, 228, 48, 255}};

const char buttonMessages[ENTITIES][20] = {"Random color", "Speed", "Acceleration", "Destroy"};
const char colorButtonMessages[25][20]  = {
    "LIGHTGRAY", "GRAY",  "DARKGRAY",  "YELLOW",  "GOLD",  "ORANGE",   "PINK",    "RED",    "MAROON",
    "GREEN",     "LIME",  "DARKGREEN", "SKYBLUE", "BLUE",  "DARKBLUE", "PURPLE",  "VIOLET", "DARKPURPLE",
    "BEIGE",     "BROWN", "DARKBROWN", "WHITE",   "BLACK", "BLANK",    "RAYWHITE"};

extern int color_position;
extern Vector2 velocity_magnitude;

void update_menu()
{
    int rectCollision      = check_button_collision();
    int incrementCollision = check_increment_button_collision();
    int decrementCollision = check_decrement_button_collision();
    // if(CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);
    if (rectCollision != -1)
    {
        buttonColors[rectCollision].a = 127;
    }
    else if (incrementCollision != -1)
    {
        rightButtonColors[incrementCollision].a = 127;
    }
    else if (decrementCollision != -1)
    {
        leftButtonColors[decrementCollision].a = 127;
    }
    else
    {
        int i;
        for (i = 0; i < ENTITIES; ++i)
        {
            buttonColors[i].a      = 255;
            leftButtonColors[i].a  = 255;
            rightButtonColors[i].a = 255;
        }
    }
}

void draw_menu()
{
    int i;
    for (i = 0; i < ENTITIES; ++i)
    {
        DrawRectangle(MENU_X, MENU_Y + i * BUTTON_GAP, BUTTON_WIDTH, BUTTON_HEIGHT, buttonColors[i]);
        DrawText(buttonMessages[i], MENU_X + BUTTON_WIDTH / 2 - MeasureText(buttonMessages[i], FONT_SIZE) / 2,
                 MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT / 2 - FONT_SIZE / 2, FONT_SIZE, RED);

        if (i == 0)
        {
            if (color_position != 0)
            {
                DrawText(colorButtonMessages[color_position],
                         MENU_X + BUTTON_WIDTH / 2 - MeasureText(colorButtonMessages[color_position], FONT_SIZE) / 2,
                         MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT / 2 - FONT_SIZE / 2 + FONT_SIZE, FONT_SIZE / 2, RED);
            }
        }

        DrawTriangle((Vector2){MENU_X - TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP},
                     (Vector2){MENU_X - TRI_HEIGHT, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT / 2}, // CENTER
                     (Vector2){MENU_X - TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT}, leftButtonColors[i]);

        DrawTriangle(
            (Vector2){MENU_X + BUTTON_WIDTH + TRI_HEIGHT, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT / 2}, // CENTER
            (Vector2){MENU_X + BUTTON_WIDTH + TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP},
            (Vector2){MENU_X + BUTTON_WIDTH + TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT},
            rightButtonColors[i]);
    }
}

int check_button_collision()
{
    Vector2 mouse = GetMousePosition();
    int i;
    for (i = 0; i < ENTITIES; ++i)
    {
        if (CheckCollisionPointRec(mouse, (Rectangle){MENU_X, MENU_Y + i * BUTTON_GAP, BUTTON_WIDTH, BUTTON_HEIGHT}))
        {
            return i;
        }
    }
    return -1;
}

int check_increment_button_collision()
{
    Vector2 mouse = GetMousePosition();
    int i;
    for (i = 0; i < ENTITIES; ++i)
    {
        if (CheckCollisionPointTriangle(
                mouse,
                (Vector2){MENU_X + BUTTON_WIDTH + TRI_HEIGHT, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT / 2}, // CENTER
                (Vector2){MENU_X + BUTTON_WIDTH + TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP},
                (Vector2){MENU_X + BUTTON_WIDTH + TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT}))
        {
            return i;
        }
    }
    return -1;
}

int check_decrement_button_collision()
{
    Vector2 mouse = GetMousePosition();
    int i;
    for (i = 0; i < ENTITIES; ++i)
    {
        if (CheckCollisionPointTriangle(
                mouse, (Vector2){MENU_X - TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP},
                (Vector2){MENU_X - TRI_HEIGHT, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT / 2}, // CENTER
                (Vector2){MENU_X - TRI_BUTTON_GAP, MENU_Y + i * BUTTON_GAP + BUTTON_HEIGHT}))
        {
            return i;
        }
    }
    return -1;
}

int collision_exists()
{
    return check_decrement_button_collision() != -1 || check_increment_button_collision() != -1 ||
           check_button_collision() != -1;
}