//
// Created by elder on 11/10/2026.
//

#include <iostream>

#include "../Header/gl_utils.h"
#include "../Header/vec2.h"
#include "../Header/projectile.h"
#include "../Header/tank.h"
#include "../Header/trophy_system.h"

int main() {

    vec2 a(10.f, 20.0);
    vec2 b(10000.f, 20000.0);

    vec2 c = a + b;
    float dist = get_distance_squared(a, b);
    std:: cout << "Distance is: " << dist << std:: endl;

    std:: cout << c.x << ", " << c.y << std:: endl;

    Projectile projectile;

    projectile.set_position(0,0);
    projectile.set_velocity(2, 0);
    projectile.set_acceleration(2,0);
    projectile.set_target(a);
    std:: cout << projectile.get_status() << std:: endl;
    while (projectile.get_time_to_target() >= 0.16) {
        projectile.update_projectile(0.16f);
        std:: cout << "Projectile position: " << projectile.get_position().x << ", " << projectile.get_position().y << std:: endl;
        std:: cout << "TTT: " << projectile.get_time_to_target();
        std:: cout << std:: endl;
    }

    std:: cout << projectile.get_status() << std:: endl;
    return 0;
}