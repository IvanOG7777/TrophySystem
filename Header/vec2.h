//
// Created by elder on 11/10/2026.
//

#ifndef TROPHYSYSTEM_VEC2_H
#define TROPHYSYSTEM_VEC2_H

struct vec2 {
    float x;
    float y;

    vec2() {
        x = 0.0f;
        y = 0.0f;
    }

    vec2(float passed_x, float passed_y) {
        x = passed_x;
        y = passed_y;
    }
};

inline vec2 operator+(vec2 &a, vec2 &b) {
    return {a.x + b.x, a.y + b.y};
}

inline void operator+=(vec2 &a, vec2 &b) {
    a.x += b.x;
    a.y += b.y;
}

inline vec2 operator+=(vec2 &a, float val) {
    a.x += val;
    a.y += val;
}

inline vec2 operator-(vec2 &a, vec2 &b) {
    return {a.x - b.x, a.y - b.y};
}

inline vec2 operator*(vec2 &a, vec2 &b) {
    return {a.x * b.x, a.y * b.y};
}

inline vec2 operator*(vec2 &a, float val) {
    return {a.x * val, a.y * val};
}

inline void operator*=(vec2 &a, float val) {
    a.x *= val;
    a.y *= val;
}

inline vec2 operator/(vec2 &a, float val) {
    return {a.x / val, a.y / val};
}

inline float distance (vec2 &a, vec2 &b) {
    float x = a.x - b.x;
    float y = a.y - b.y;

    float x_squared = x * x;
    float y_squared = y * y;

    return x_squared + y_squared;
}

#endif //TROPHYSYSTEM_VEC2_H