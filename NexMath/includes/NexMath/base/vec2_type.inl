#include "vec2_type.h"

#include <cmath>

namespace nex {
    template<typename Ty>
    Ty Vec<2, Ty>::magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    template<typename Ty>
    Ty Vec<2, Ty>::squareMagnitude() const {
        return x * x + y * y;
    }

    template<typename Ty>
    Vec<2, Ty> Vec<2, Ty>::normalize() const {
        return *this / magnitude();
    }

    template<typename Ty>
    Ty Vec<2, Ty>::dot(const Vec<2, Ty>& other) const {
        return x * other.x + y * other.y;
    }

    template<typename Ty>
    Vec<2, Ty> Vec<2, Ty>::project(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2) {
        return (vec1.dot(vec2) / vec2.squareMagnitude()) * vec2;
    }

    template<typename Ty>
    Vec<2, Ty> Vec<2, Ty>::reject(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2) {
        return vec1 - (vec1.dot(vec2) / vec2.squareMagnitude()) * vec2;
    }

    template<typename Ty>
    Vec<2, Ty>& Vec<2, Ty>::operator+=(const Vec<2, Ty>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    template<typename Ty>
    Vec<2, Ty>& Vec<2, Ty>::operator-=(const Vec<2, Ty>& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    template<typename Ty>
    Vec<2, Ty>& Vec<2, Ty>::operator+=(Ty scalar) {
        x += scalar;
        y += scalar;
        return *this;
    }

    template<typename Ty>
    Vec<2, Ty>& Vec<2, Ty>::operator-=(Ty scalar) {
        x -= scalar;
        y -= scalar;
        return *this;
    }

    // Operator "+"
    template<typename Ty>
    Vec<2, Ty> operator+(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2) {
        return Vec<2, Ty>(
            vec1.x + vec2.x,
            vec1.y + vec2.y
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator+(const Vec<2, Ty>& vec, Ty scalar) {
        return Vec<2, Ty>(
            vec.x + scalar,
            vec.y + scalar
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator+(Ty scalar, const Vec<2, Ty>& vec) {
        return Vec<2, Ty>(
            vec.x + scalar,
            vec.y + scalar
        );
    }

    // Operator "-"
    template<typename Ty>
    Vec<2, Ty> operator-(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2) {
        return Vec<2, Ty>(
            vec1.x - vec2.x,
            vec1.y - vec2.y
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator-(const Vec<2, Ty>& vec, Ty scalar) {
        return Vec<2, Ty>(
            vec.x - scalar,
            vec.y - scalar
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator-(Ty scalar, const Vec<2, Ty>& vec) {
        return Vec<2, Ty>(
            vec.x - scalar,
            vec.y - scalar
        );
    }

    // Operator "*"
    template<typename Ty>
    Vec<2, Ty> operator*(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2) {
        return Vec<2, Ty>(
            vec1.x * vec2.x,
            vec1.y * vec2.y
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator*(const Vec<2, Ty>& vec, Ty scalar) {
        return Vec<2, Ty>(
            vec.x * scalar,
            vec.y * scalar
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator*(Ty scalar, const Vec<2, Ty>& vec) {
        return Vec<2, Ty>(
            vec.x * scalar,
            vec.y * scalar
        );
    }

    // Operator "/"
    template<typename Ty>
    Vec<2, Ty> operator/(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2) {
        return Vec<2, Ty>(
            vec1.x / vec2.x,
            vec1.y / vec2.y
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator/(const Vec<2, Ty>& vec, Ty scalar) {
        return Vec<2, Ty>(
            vec.x / scalar,
            vec.y / scalar
        );
    }

    template<typename Ty>
    Vec<2, Ty> operator/(Ty scalar, const Vec<2, Ty>& vec) {
        return Vec<2, Ty>(
            vec.x / scalar,
            vec.y / scalar
        );
    }
}