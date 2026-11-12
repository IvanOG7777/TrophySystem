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
    vec2 b(10.f, 20.0);

    vec2 c = a + b;
    float dist = get_distance_squared(a, b);
    std:: cout << "Distance is: " << dist << std:: endl;

    std:: cout << c.x << ", " << c.y << std:: endl;

    Projectile projectile;

    projectile.set_position(c);
    projectile.set_velocity(2, 0);
    projectile.set_acceleration(2,0);

    projectile.integrate(1.2f);
    std:: cout << "Projectile position: " << projectile.get_position().x << ", " << projectile.get_position().y << std:: endl;
    return 0;
}