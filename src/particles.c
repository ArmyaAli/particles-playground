#include "../include/particles.h"

int color_position = 0;

int defaults[4] = {0, 0, 0, 0};

Vector2 velocity_magnitude     = {1.0f, 1.0f};
Vector2 acceleration_magnitude = {0.0f, 1.0f};

void create_particles(PARTICLE_BUFFER* buffer)
{
    const Color colors[25] = {LIGHTGRAY, GRAY,  DARKGRAY,  YELLOW,  GOLD,  ORANGE,   PINK,    RED,    MAROON,
                              GREEN,     LIME,  DARKGREEN, SKYBLUE, BLUE,  DARKBLUE, PURPLE,  VIOLET, DARKPURPLE,
                              BEIGE,     BROWN, DARKBROWN, WHITE,   BLACK, BLANK,    RAYWHITE};
    const int colorsLen    = 3;
    const int offset       = 32;
    Vector2 velocity       = {1.0f, 0.0f};
    Vector2 acceleration   = {0.0f, 0.2f};
    const Vector2 mouse    = GetMousePosition();
    time_t t;
    srand((unsigned)time(&t));

    int i;
    for (i = 0; i < SIZE / 2; ++i)
    {
        Particle p = {
            {mouse.x - offset * cos(float_rand(PI / 2, 2 * PI / 3)), mouse.y - offset * sin(float_rand(PI, 2 * PI))},
            velocity,
            acceleration,
            rand() % 1000 + 500,
            colors[rand() % 25]};
        add_particle(buffer, &p);
    }

    for (i = SIZE / 2; i < SIZE; ++i)
    {
        Particle p = {
            {mouse.x - offset * cos(float_rand(PI / 2, 2 * PI / 3)), mouse.y - offset * sin(float_rand(PI, 2 * PI))},
            {velocity.x * -1, velocity.y},
            acceleration,
            rand() % 1000 + 500,
            colors[rand() % 25]};
        add_particle(buffer, &p);
    }
}

void update_particles(PARTICLE_BUFFER* buffer)
{
    Particle* pArray = buffer->particles;

    Color colors[25] = {LIGHTGRAY, GRAY,  DARKGRAY,  YELLOW,  GOLD,  ORANGE,   PINK,    RED,    MAROON,
                        GREEN,     LIME,  DARKGREEN, SKYBLUE, BLUE,  DARKBLUE, PURPLE,  VIOLET, DARKPURPLE,
                        BEIGE,     BROWN, DARKBROWN, WHITE,   BLACK, BLANK,    RAYWHITE};

    change_color_on_button_click();
    change_velocity_on_button_click();
    change_acceleration_on_button_click();

    int i;
    for (i = 0; i < buffer->size; ++i)
    {
        // these should happen every frame
        lifetime_stuff(pArray, i);
        update_physics(pArray, i);
        check_bounds(pArray, i);

        if (color_position != 0)
            pArray[i].color = colors[color_position - 1];

        if (defaults[0] == 1)
        {
            pArray[i].color = colors[rand() % 25];
        }

        destroy_all(pArray, i);
    }
    remove_finished_particles(buffer);
    reset_defaults();
}

void lifetime_stuff(Particle* pArray, int i)
{
    if (pArray[i].lifeTime > 0)
        pArray[i].lifeTime--;
}

void update_physics(Particle* pArray, int i)
{
    pArray[i].pos.x += pArray[i].vel.x * velocity_magnitude.x;
    pArray[i].pos.y += pArray[i].vel.y * velocity_magnitude.y;

    pArray[i].vel.x += pArray[i].acceleration.x * acceleration_magnitude.x;
    pArray[i].vel.y += pArray[i].acceleration.y * acceleration_magnitude.y;
}

void check_bounds(Particle* pArray, int i)
{
    const Vector2 bounds = {800, 400};

    if (pArray[i].pos.x >= bounds.x || pArray[i].pos.x <= 0)
    {
        pArray[i].vel.x *= -1;
    }

    if (pArray[i].pos.y >= bounds.y || pArray[i].pos.y <= 0)
    {
        pArray[i].vel.y *= -1;
    }
}

void change_velocity_on_button_click()
{
    if (IsMouseButtonPressed(0))
    {
        if (check_increment_button_collision() == 1)
        {
            if (velocity_magnitude.x < 50.0f)
            {
                velocity_magnitude.x += 0.5f;
            }
        }

        if (check_decrement_button_collision() == 1)
        {
            if (velocity_magnitude.x > 0)
            {
                velocity_magnitude.x -= 0.5f;
            }
        }

        if (check_button_collision() == 1)
        {
            defaults[1] == 1;
            velocity_magnitude = (Vector2){1.0f, 1.0f};
        }
    }
}


void change_acceleration_on_button_click()
{
    if (IsMouseButtonPressed(0))
    {
        if (check_increment_button_collision() == 2)
        {
            if (acceleration_magnitude.y < 50.0f)
            {
                acceleration_magnitude.y += 0.2f;
            }
        }

        if (check_decrement_button_collision() == 2)
        {
            if (acceleration_magnitude.y > 0)
            {
                acceleration_magnitude.y -= 0.5f;
            }
        }

        if (check_button_collision() == 2)
        {
            defaults[2] == 1;
            acceleration_magnitude = (Vector2){0.0f, 1.0f};
        }
    }
}

void change_color_on_button_click()
{

    if (IsMouseButtonPressed(0))
    {
        if (check_increment_button_collision() == 0)
        {
            if (color_position < 25)
            {
                ++color_position;
            }
        }

        if (check_decrement_button_collision() == 0)
        {
            if (color_position > 0)
            {
                --color_position;
            }
        }

        if (check_button_collision() == 0)
        {
            color_position = 0;
            defaults[0]    = 1;
        }
    }
}

void destroy_all(Particle* pArray, int index)
{
    if (IsMouseButtonPressed(0))
    {
        if (check_button_collision() == 3)
        {   
            pArray[index].lifeTime = 0;
        }
    }
}

void reset_defaults()
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        defaults[i] = 0;
    }
}

void draw_particles(PARTICLE_BUFFER* buffer)
{
    Particle* pArray = buffer->particles;
    int i;
    for (i = 0; i < buffer->size; ++i)
    {
        DrawCircle(pArray[i].pos.x, pArray[i].pos.y, RADIUS, pArray[i].color);
    }
}

void destroy_particles(PARTICLE_BUFFER* buffer)
{
    destroy_particle_buffer(buffer);
}