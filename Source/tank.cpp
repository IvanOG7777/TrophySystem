//
// Created by elder on 11/10/2026.
//

#include <cassert>
#include "../Header/tank.h"

void Tank::integrate(float duration) {
    if (inverse_mass <= 0.0f) return;

    assert(duration > 0.0f);

    vec2 resulting_acceleration = acceleration * inverse_mass;

    vec2 scaled_acceleration = resulting_acceleration * duration;

    velocity += scaled_acceleration;

    vec2 scaled_velocity = velocity * duration;

    position += scaled_velocity;

    velocity *= duration;
}

void Tank:: set_mass(float passed_mass) {
    mass = passed_mass;
    inverse_mass = 1/passed_mass;
}

void Tank::set_position(const float passed_x, const float passed_y) {
    position.x = passed_x;
    position.y = passed_y;
}
void Tank::set_position(const vec2 &passed_position) {
    position = passed_position;
}
vec2 Tank::get_position() {
    return position;
}


void Tank::set_velocity(const float passed_x, const float passed_y) {
    velocity.x = passed_x;
    velocity.y = passed_y;
}
void Tank::set_velocity(const vec2 &passed_velocity) {
    velocity = passed_velocity;
}
vec2 Tank::get_velocity() {
    return velocity;
}

void Tank::set_acceleration(float passed_x, float passed_y) {
    acceleration.x = passed_x;
    acceleration.y = passed_y;
}
void Tank::set_acceleration(const vec2 &passed_acceleration) {
    acceleration = passed_acceleration;
}
vec2 Tank::get_acceleration() {
    return acceleration;
}