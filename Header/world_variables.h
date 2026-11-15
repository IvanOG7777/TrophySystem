//
// Created by elder on 11/13/2026.
//

#ifndef TROPHYSYSTEM_WORLD_VARIABLES_H
#define TROPHYSYSTEM_WORLD_VARIABLES_H

#include "vec2.h"

const vec2 gravity_acceleration = {0.0, -10.0f};
const vec2 wind_velocity = {5.0f, 0.0f}; // considered as force
constexpr float air_density = 1.25f; // approx sea level air density
constexpr float drag_constant = 0.8f;
constexpr float tracking_strength_constant = 12.0f;
constexpr float cross_section_area = 0.4;

#endif //TROPHYSYSTEM_WORLD_VARIABLES_H