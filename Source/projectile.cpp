//
// Created by elder on 11/10/2026.
//

#include <cassert>
#include <cmath>
#include <algorithm>
#include "../Header/projectile.h"

#include <ctime>

#include "../Header/vec2.h"

Projectile::Projectile() {
    damage = 0.0f;
    speed = 0.0f;
    time_to_target = 10.0f; // 10 units of x time
    status = IDLE;
    target_location = {};
    position = {};
    velocity = {};
    acceleration = {};
}

void Projectile::integrate(float duration) {

    assert(duration > 0.0f);

    if (Projectile::status != FLYING) return;

    velocity = velocity + acceleration * duration;

    position = position + velocity * duration;
}

vec2 Projectile::get_directional_vector() {
    return target_location - position;
}

void Projectile::follow_target() {
    // make sure projectile is in the correct status
    if (status != FLYING) return;

    float distance_squared = get_distance_squared(target_location, position);

    float distance = std::sqrtf(distance_squared);

    speed = distance / time_to_target;

    vec2 normal = get_normal();

    normal *= speed; // calculate new velocity

    velocity = normal;
}

bool Projectile::check_collision() {
    float distance_squared = get_distance_squared(target_location, position);
    return distance_squared <= 0.001 * 0.001;
}

void Projectile::update_projectile(float duration) {
    assert(duration > 0.0f);

    if (status != FLYING) return;

    if (check_collision() == true) {
        status = IMPACTED;
        position = target_location;
        time_to_target = 0.0f;
        return;
    }

    if (time_to_target <= 0.0f) {
        status = EXPIRED;
        return;
    }

    // use min of either real time step or time_to_target as the step
    float step = std::min(duration, time_to_target);

    follow_target();
    integrate(step);

    time_to_target -= step;

    if (check_collision()) {
        status = IMPACTED;
        position = target_location;
        time_to_target = 0.0f;
        return;
    }

    if (time_to_target <= 0.0f) {
        status = EXPIRED;
    }
}


float Projectile::get_magnitude() {
    vec2 dir_vec = get_directional_vector();

    float x = dir_vec.x * dir_vec.x;
    float y = dir_vec.y * dir_vec.y;

    return sqrtf(x +y);
}

vec2 Projectile::get_normal() {
    vec2 directional_vector = get_directional_vector();
    float mag = get_magnitude();
    assert(mag > 0.0f);

    return directional_vector / mag;
}





// Setters and Getters
void Projectile::set_damage(float passed_damage) {
    damage = passed_damage;
}

void Projectile::set_position(const float passed_x, const float passed_y) {
    position.x = passed_x;
    position.y = passed_y;
}
void Projectile::set_position(const vec2 &passed_position) {
    position = passed_position;
}
vec2 Projectile::get_position() {
    return position;
}

void Projectile::set_velocity(const float passed_x, const float passed_y) {
    velocity.x = passed_x;
    velocity.y = passed_y;
}
void Projectile::set_velocity(const vec2 &passed_velocity) {
    velocity = passed_velocity;
}
vec2 Projectile::get_velocity() {
    return velocity;
}

void Projectile::set_acceleration(float passed_x, float passed_y) {
    acceleration.x = passed_x;
    acceleration.y = passed_y;
}
void Projectile::set_acceleration(const vec2 &passed_acceleration) {
    acceleration = passed_acceleration;
}
vec2 Projectile::get_acceleration() {
    return acceleration;
}
