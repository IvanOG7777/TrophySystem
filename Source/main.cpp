//
// Created by elder on 11/10/2026.
//

#include <iostream>

#include "../Header/missile.h"


int main() {

    Missile missile;

    missile.set_mass(2.0f);
    missile.set_position(0.0f, 10.0f);
    missile.set_velocity(10.0f, 0.0f);
    float duration = 0.1f;


    std:: cout << "Before Integration" << std:: endl;
    std:: cout << "Mass: " << missile.mass << std:: endl;
    std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
    std:: cout << "Velocity: " << missile.velocity.x << ", " << missile.velocity.y << std:: endl;
    std:: cout << "Acceleration: " << missile.acceleration.x << ", " << missile.acceleration.y << std:: endl;
    std:: cout << std:: endl;

    for (int i = 0; i < 1; i++) {
        missile.integrate(duration);

        std:: cout << "Mass: " << missile.mass << std:: endl;
        std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
        std:: cout << "Velocity: " << missile.velocity.x << ", " << missile.velocity.y << std:: endl;
        std:: cout << "Acceleration: " << missile.acceleration.x << ", " << missile.acceleration.y << std:: endl;
        std:: cout << std:: endl;
    }


}