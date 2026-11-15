//
// Created by elder on 11/10/2026.
//

#include <cassert>
#include <iostream>
#include <algorithm>
#include "../Header/world_variables.h"
#include "../Header/missile.h"
#include "../Header/vec2.h"

Missile::Missile() {
    damage = 0.0f;
    time_to_target = 0.0f;
    mass = 0.0f;
    collision_radius = 0.25f;
    status = FLYING;
    collision_type = NONE;
    target_location = {};
    position = {};
    velocity = {};
    acceleration = {};
}

vec2 Missile::quadratic_drag_force(vec2 &relative_air_velocity) {
    auto relative_force_magnitude = get_magnitude(relative_air_velocity);

    return (-0.5f * air_density * drag_constant * cross_section_area * relative_force_magnitude) * relative_air_velocity;
}

// only change velocity and positions
void Missile::integrate(float duration) {
    assert(duration > 0.0f);
    assert(mass > 0.0f);
    if (status != FLYING) {
        std:: cout << "Missile isn't flying" << std::endl;
        return;
    }

    auto new_velocity = velocity + (acceleration * duration);
    auto new_position = position + (new_velocity * duration);

    velocity = new_velocity;
    position = new_position;
}

// let this function handle total acceleration since we are calculating many forces here then finally updating acceleration
void Missile::follow_target() {
    assert(mass > 0.0f);
    vec2 directional_vector = get_directional_vector(target_location, position);

    vec2 relative_velocity = velocity - wind_velocity;

    vec2 force_tracking = tracking_strength_constant * directional_vector;
    vec2 force_drag = quadratic_drag_force(relative_velocity);
    vec2 force_gravity = gravity_acceleration * mass;

    vec2 total_force = force_tracking + force_drag + force_gravity;

    vec2 total_acceleration = total_force / mass;

    acceleration = total_acceleration;
}

void Missile::update_projectile(float duration) {
    if (status != FLYING) return;
    check_collision();
    if (status != FLYING) return;

    follow_target();
    integrate(duration);

    check_collision();
}

vec2 Missile::get_directional_vector(const vec2 &target, const vec2 &current_pos) {
    return target - current_pos;
}

float Missile::get_magnitude(const vec2 &vector) {

    float x = vector.x * vector.x;
    float y = vector.y * vector.y;

    return sqrtf(x + y);
}

vec2 Missile::get_normal(const vec2 &target, const vec2 &current_pos) {
    vec2 directional_vector = get_directional_vector(target, current_pos);
    float mag = get_magnitude(directional_vector);
    assert(mag > 0.0f);

    return directional_vector / mag;
}

void Missile::check_collision() {
    // for now check for ground, then check on tanks position
    if (position.y <= 0.001) {
        status = IMPACTED;
        collision_type = GROUND;
        position.y = 0.0f;
        return;
    }

    float target_radius = 0.5f;
    auto combined_radius_sum = target_radius + collision_radius;
    auto combined_radius_squared = combined_radius_sum * combined_radius_sum;

    auto distance_squared = get_distance_squared(target_location, position);

    if (distance_squared <= combined_radius_squared) {
        status = IMPACTED;
        collision_type = TARGET;
    }
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
