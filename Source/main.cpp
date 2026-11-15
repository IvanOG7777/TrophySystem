//
// Created by elder on 11/10/2026.
//

#include <iostream>

#include "../Header/missile.h"


int main() {

    Missile missile;

    missile.set_mass(2.0f);
    missile.set_position(0.0f, 10.0f);
    missile.set_velocity(8.0f, 4.0f);
    float duration = 0.5f;
    vec2 target(8.0f, 10.0f);
    missile.set_target(target);


    std:: cout << "Before Integration" << std:: endl;
    std:: cout << "Mass: " << missile.mass << std:: endl;
    std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
    std:: cout << "Velocity: " << missile.velocity.x << ", " << missile.velocity.y << std:: endl;
    std:: cout << "Acceleration: " << missile.acceleration.x << ", " << missile.acceleration.y << std:: endl;
    std:: cout << "Status: " << missile.status << std:: endl;
    std:: cout << std:: endl;

    for (int i = 0; i < 100; i++) {
        if (missile.status != FLYING) break;
        missile.update_projectile(duration);

        std:: cout << "Mass: " << missile.mass << std:: endl;
        std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
        std:: cout << "Velocity: " << missile.velocity.x << ", " << missile.velocity.y << std:: endl;
        std:: cout << "Acceleration: " << missile.acceleration.x << ", " << missile.acceleration.y << std:: endl;
        std:: cout << "Status: " << missile.status << std:: endl;
        std:: cout << std:: endl;
    }

    std:: cout << "Mass: " << missile.mass << std:: endl;
    std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
    std:: cout << "Velocity: " << missile.velocity.x << ", " << missile.velocity.y << std:: endl;
    std:: cout << "Acceleration: " << missile.acceleration.x << ", " << missile.acceleration.y << std:: endl;
    std:: cout << "Status: " << missile.status << std:: endl;
    std:: cout << std:: endl;


}