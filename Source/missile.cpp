//
// Created by elder on 11/10/2026.
//

#include <cassert>
#include <cmath>
#include <algorithm>
#include <ctime>
#include "../Header/world_variables.h"
#include "../Header/missile.h"
#include "../Header/vec2.h"

Missile::Missile() {
    damage = 0.0f;
    time_to_target = 0.0f;
    mass = 0.0f;
    status = FLYING;
    target_location = {};
    position = {};
    velocity = {};
    acceleration = {};
}

void Missile::integrate(float duration) {
    assert(duration > 0.0f);
    assert(mass > 0.0f);

    auto drag_acceleration = -drag_constant * (velocity - wind_velocity);

    acceleration = (drag_acceleration + gravity_acceleration) / mass;

    auto new_velocity = velocity + (acceleration * duration);
    auto new_position = position * (new_velocity * duration);

    velocity = new_velocity;
    position = new_position;
}

vec2 Missile::get_directional_vector() {
    return target_location - position;
}

float Missile::get_magnitude() {
    vec2 dir_vec = get_directional_vector();

    float x = dir_vec.x * dir_vec.x;
    float y = dir_vec.y * dir_vec.y;

    return sqrtf(x +y);
}

vec2 Missile::get_normal() {
    vec2 directional_vector = get_directional_vector();
    float mag = get_magnitude();
    assert(mag > 0.0f);

    return directional_vector / mag;
}





// Setters and Getters
void Missile::set_damage(float passed_damage) {
    damage = passed_damage;
}

void Missile::set_position(const float passed_x, const float passed_y) {
    position.x = passed_x;
    position.y = passed_y;
}
void Missile::set_position(const vec2 &passed_position) {
    position = passed_position;
}
vec2 Missile::get_position() {
    return position;
}

void Missile::set_velocity(const float passed_x, const float passed_y) {
    velocity.x = passed_x;
    velocity.y = passed_y;
}
void Missile::set_velocity(const vec2 &passed_velocity) {
    velocity = passed_velocity;
}
vec2 Missile::get_velocity() {
    return velocity;
}

void Missile::set_acceleration(float passed_x, float passed_y) {
    acceleration.x = passed_x;
    acceleration.y = passed_y;
}
void Missile::set_acceleration(const vec2 &passed_acceleration) {
    acceleration = passed_acceleration;
}
vec2 Missile::get_acceleration() {
    return acceleration;
}

void Missile::set_target(vec2 &passed_target) {
    target_location = passed_target;
}

vec2 Missile::get_target() {
    return target_location;
}

float Missile::get_time_to_target() {
    return time_to_target;
}

Status Missile::get_status() {
    return status;
}

void Missile::set_mass(const float passed_mass) {
    mass = passed_mass;
}
