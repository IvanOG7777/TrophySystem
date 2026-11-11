//
// Created by elder on 11/10/2026.
//

#include <iostream>
#include "../Header/vec2.h"

int main() {

    vec2 a(10.f, 20.0);
    vec2 b(10.f, 20.0);

    vec2 c = a + b;
    float dist = distance(a, b);
    std:: cout << "Distace is: " << dist << std:: endl;

    std:: cout << c.x << ", " << c.y << std:: endl;
    return 0;
}