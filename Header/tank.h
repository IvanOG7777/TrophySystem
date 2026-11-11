//
// Created by elder on 11/10/2026.
//

#ifndef TROPHYSYSTEM_TANK_H
#define TROPHYSYSTEM_TANK_H

#include  "../Header/vec2.h"

class Tank {
private:
    bool is_hit;
    float mass;
    float inverse_mass;
    float health;
    vec2 position;
    vec2 velocity;
    vec2 acceleration;

public:

    void integrate(float duration);

    void set_mass(float passed_mass);

    void set_position(float passed_x, float passed_y);
    void set_position(const vec2 &passed_position);
    vec2 get_position();

    void set_velocity(float passed_x, float passed_y);
    void set_velocity(const vec2 &passed_velocity);
    vec2 get_velocity();

    void set_acceleration(float passed_x, float passed_y);
    void set_acceleration(const vec2 &passed_acceleration);
    vec2 get_acceleration();
};

#endif //TROPHYSYSTEM_TANK_H