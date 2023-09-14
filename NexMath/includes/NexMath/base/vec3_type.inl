#include "vec3_type.h"

#include <cmath>

namespace nex {
    template<typename Ty>
    Ty Vec<3, Ty>::magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    template<typename Ty>
    Ty Vec<3, Ty>::squareMagnitude() const {
        return x * x + y * y + z * z;
    }

    template<typename Ty>
    Vec<3, Ty> Vec<3, Ty>::normalize() const {
        return *this / magnitude();
    }

    template<typename Ty>
    Ty Vec<3, Ty>::dot(const Vec<3, Ty>& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    template<typename Ty>
    Vec<3, Ty> Vec<3, Ty>::cross(const Vec<3, Ty>& other) const {
        return Vec<3, Ty>(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        )
    }

    template<typename Ty>
    Vec<3, Ty>& Vec<3, Ty>::operator+=(const Vec<3, Ty>& vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }

    template<typename Ty>
    Vec<3, Ty>& Vec<3, Ty>::operator-=(const Vec<3, Ty>& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    template<typename Ty>
    Vec<3, Ty>& Vec<3, Ty>::operator+=(Ty scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
        return *this;
    }

    template<typename Ty>
    Vec<3, Ty>& Vec<3, Ty>::operator-=(Ty scalar) {
        x -= scalar;
        y -= scalar;
        z -= scalar;
        return *this;
    }

    // Operator "+"
    template<typename Ty>
    Vec<3, Ty> operator+(Vec<3, Ty> vec1, Vec<3, Ty> vec2) {
        return Vec<3, Ty>(
            vec1.x + vec2.x,
            vec1.y + vec2.y,
            vec1.z + vec2.z
        );
    }

    template<typename Ty>
    Vec<3, Ty> operator+(Vec<3, Ty> vec, Ty scalar) {
        return Vec<3, Ty>(
            vec.x + scalar,
            vec.y + scalar,
            vec.z + scalar
        )
    }

    template<typename Ty>
    Vec<3, Ty> operator+(Ty scalar, Vec<3, Ty> vec) {
        return Vec<3, Ty>(
            vec.x + scalar,
            vec.y + scalar,
            vec.z + scalar
        )
    }

    // Operator "-"
    template<typename Ty>
    Vec<3, Ty> operator-(Vec<3, Ty> vec1, Vec<3, Ty> vec2) {
        return Vec<3, Ty>(
            vec1.x - vec2.x,
            vec1.y - vec2.y,
            vec1.z - vec2.z
        );
    }

    template<typename Ty>
    Vec<3, Ty> operator-(Vec<3, Ty> vec, Ty scalar) {
        return Vec<3, Ty>(
            vec.x - scalar,
            vec.y - scalar,
            vec.z - scalar
        )
    }

    template<typename Ty>
    Vec<3, Ty> operator-(Ty scalar, Vec<3, Ty> vec) {
        return Vec<3, Ty>(
            vec.x - scalar,
            vec.y - scalar,
            vec.z - scalar
        )
    }

    // Operator "*"
    template<typename Ty>
    Vec<3, Ty> operator*(Vec<3, Ty> vec1, Vec<3, Ty> vec2) {
        return Vec<3, Ty>(
            vec1.x * vec2.x,
            vec1.y * vec2.y,
            vec1.z * vec2.z
        );
    }

    template<typename Ty>
    Vec<3, Ty> operator*(Vec<3, Ty> vec, Ty scalar) {
        return Vec<3, Ty>(
            vec.x * scalar,
            vec.y * scalar,
            vec.z * scalar
        )
    }

    template<typename Ty>
    Vec<3, Ty> operator*(Ty scalar, Vec<3, Ty> vec) {
        return Vec<3, Ty>(
            vec.x * scalar,
            vec.y * scalar,
            vec.z * scalar
        )
    }

    // Operator "/"
    template<typename Ty>
    Vec<3, Ty> operator/(Vec<3, Ty> vec1, Vec<3, Ty> vec2) {
        return Vec<3, Ty>(
            vec1.x / vec2.x,
            vec1.y / vec2.y,
            vec1.z / vec2.z
        );
    }

    template<typename Ty>
    Vec<3, Ty> operator/(Vec<3, Ty> vec, Ty scalar) {
        return Vec<3, Ty>(
            vec.x / scalar,
            vec.y / scalar,
            vec.z / scalar
        )
    }

    template<typename Ty>
    Vec<3, Ty> operator/(Ty scalar, Vec<3, Ty> vec) {
        return Vec<3, Ty>(
            vec.x / scalar,
            vec.y / scalar,
            vec.z / scalar
        )
    }
}
