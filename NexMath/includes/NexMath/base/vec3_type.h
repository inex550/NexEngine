#ifndef __NEXMATH_BASE_VEC3_TYPE_H__
#define __NEXMATH_BASE_VEC3_TYPE_H__

#include "definisions.h"

namespace nex {
    template<typename Ty>
    struct Vec<3, Ty> {
        Ty x, y, z;

        Vec(): x(Ty{}), y(Ty{}), z(Ty{}) {}

        Vec(Ty x, Ty y, Ty z): x(x), y(y), z(z) {}

        Vec(Ty scalar)
            : x(scalar), y(scalar), z(scalar) {}

        Vec(Vec<3, Ty> vec)
            : x(vec.x), y(vec.y) {}

        Ty magnitude() const;
        Ty squareMagnitude() const;
        Vec normalize() const;

        Ty dot(const Vec& other) const;
        Vec cross(const Vec& other) const;

        static Vec project(const Vec& vec1, const Vec& vec2);
        static Vec project(const Vec& vec1, const Vec& vec2);

        Vec& operator+=(const Vec& other);
        Vec& operator-=(const Vec& other);

        Vec& operator+=(Ty scalar);
        Vec& operator-=(Ty scalar);
    };

    // Operator "+"
    template<typename Ty>
    Vec<3, Ty> operator+(Vec<3, Ty> vec1, Vec<3, Ty> vec2);

    template<typename Ty>
    Vec<3, Ty> operator+(Vec<3, Ty> vec, Ty scalar);

    template<typename Ty>
    Vec<3, Ty> operator+(Ty scalar, Vec<3, Ty> vec);

    // Operator "-"
    template<typename Ty>
    Vec<3, Ty> operator-(Vec<3, Ty> vec1, Vec<3, Ty> vec2);

    template<typename Ty>
    Vec<3, Ty> operator-(Vec<3, Ty> vec, Ty scalar);

    template<typename Ty>
    Vec<3, Ty> operator-(Ty scalar, Vec<3, Ty> vec);

    // Operator "*"
    template<typename Ty>
    Vec<3, Ty> operator*(Vec<3, Ty> vec1, Vec<3, Ty> vec2);

    template<typename Ty>
    Vec<3, Ty> operator*(Vec<3, Ty> vec, Ty scalar);

    template<typename Ty>
    Vec<3, Ty> operator*(Ty scalar, Vec<3, Ty> vec);

    // Operator "/"
    template<typename Ty>
    Vec<3, Ty> operator/(Vec<3, Ty> vec1, Vec<3, Ty> vec2);

    template<typename Ty>
    Vec<3, Ty> operator/(Vec<3, Ty> vec, Ty scalar);

    template<typename Ty>
    Vec<3, Ty> operator/(Ty scalar, Vec<3, Ty> vec);
}

#include "vec3_type.inl"

#endif // __NEXMATH_BASE_VEC3_TYPE_H__