//
// Created by elder on 11/10/2026.
//

#include <iostream>

#include "../Header/missile.h"


int main() {

    Missile missile;

    missile.set_mass(2.0f);
    missile.set_position(0.0f, 10.0f);
    missile.set_velocity(8.0f, 0.0f);
    float duration = 0.5f;


    std:: cout << "Before Integration" << std:: endl;
    std:: cout << std:: endl;
    std:: cout << "Mass: " << missile.mass << std:: endl;
    std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
    std:: cout << "Velocity: " << missile.velocity.y << ", " << missile.velocity.y << std:: endl;
    std:: cout << "Acceleration: " << missile.acceleration.y << ", " << missile.acceleration.y << std:: endl;

    missile.integrate(duration);
    std:: cout << std:: endl;

    std:: cout << "After Integration" << std:: endl;
    std:: cout << std:: endl;
    std:: cout << "Mass: " << missile.mass << std:: endl;
    std:: cout << "Position: " << missile.position.x << ", " << missile.position.y << std:: endl;
    std:: cout << "Velocity: " << missile.velocity.y << ", " << missile.velocity.y << std:: endl;
    std:: cout << "Acceleration: " << missile.acceleration.y << ", " << missile.acceleration.y << std:: endl;


}