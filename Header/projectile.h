//
// Created by elder on 11/10/2026.
//

#ifndef TROPHYSYSTEM_PROJECTILE_H
#define TROPHYSYSTEM_PROJECTILE_H

#include  "../Header/vec2.h"

enum Status {
    IDLE,
    FLYING,
    IMPACTED,
    EXPIRED,
};

class Projectile {
private:
    float damage;
    float speed;
    float time_to_target;
    Status status;
    vec2 target_location;
    vec2 position;
    vec2 velocity;
    vec2 acceleration;

public:
    Projectile();
    // ~Projectile();

    void integrate(float duration);
    void follow_target(float duration);
    bool check_collision();
    void update_projectile(float duration);

    vec2 get_directional_vector();
    float get_magnitude();
    vec2 get_normal();
    void set_damage(float passed_damage);

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

#endif //TROPHYSYSTEM_PROJECTILE_H