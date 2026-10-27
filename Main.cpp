#include <raylib.h>
#include <cmath>
#include <string>

class BodyMass {
public:
    float x_pos, y_pos, stat_fric, dyna_fric, restitution;

    BodyMass(float x_pos, float y_pos, float stat_fric, float dyna_fric, float restitution) {
        this->x_pos = x_pos;
        this->y_pos = y_pos;
        this->stat_fric = stat_fric;
        this->dyna_fric = dyna_fric;
        this->restitution = restitution;
    }
};

class Ball : public BodyMass {
public:

    float speed_x, speed_y, radius, mass;
    Color color;
    static constexpr float accel = 9.81f;
    static constexpr float pixelsPerMeter = 50;
    bool isColiiding = false; 

    Ball(float x_pos, float y_pos, float speed_x, float speed_y, float radius, float mass, float stat_fric, float dyna_fric, float restitution, Color color) 
        : BodyMass(x_pos, y_pos, stat_fric, dyna_fric, restitution) {
        this->speed_x = speed_x;
        this->speed_y = speed_y;
        this->radius = radius;
        this->mass = mass;
        this->color = color;
    }

    void update(float dt) {
        if (x_pos == 0) {

        }
        speed_y += accel * dt;
        x_pos += speed_x * dt;
        y_pos += speed_y * dt;

        
    }

    void draw() {
        DrawCircle((int)(x_pos * pixelsPerMeter), (int)(y_pos * pixelsPerMeter), radius, color);
    }
};

class Object : public BodyMass {
public:
    float width, height;


    Object(float x_pos, float y_pos, float width, float height, float stat_fric, float dyna_fric, float restitution) 
        : BodyMass(x_pos, y_pos, stat_fric, dyna_fric, restitution) {
        this->width = width;
        this->height = height;
    }

    void draw() {
        DrawRectangle((int)(x_pos * 50), (int)(y_pos * 50), (int)(width * 50), (int)(height * 50), BLUE);
    }

};

int main() {
    InitWindow(1200, 800, "Physics model");
    SetTargetFPS(60);

   
    Ball ball(1, -1, 2, 4, 20, 1, 0.5f, 0.2f, 0.3f, WHITE);
    Object platform(2, 10, 10, 0.2, 0.5, 0.2, 0.4);
    

    while (!WindowShouldClose()) {
        ball.update(GetFrameTime());
       
        BeginDrawing();

        ClearBackground(BLACK);
        ball.draw();
        platform.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}