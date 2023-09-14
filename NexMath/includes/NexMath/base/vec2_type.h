#ifndef __NEXMATH_BASE_VEC2_TYPE_H__
#define __NEXMATH_BASE_VEC2_TYPE_H__

#include "definisions.h"

namespace nex {
    template<typename Ty>
    struct Vec<2, Ty> {
        Ty x, y;

        Vec(): x(Ty{}), y(Ty{}) {}

        Vec(Ty x, Ty y): x(x), y(y) {}

        Vec(const Vec& other)
            : x(other.x), y(other.y) {}

        Ty magnitude() const;
        Ty squareMagnitude() const;
        Vec normalize() const;

        static Vec project(const Vec& vec1, const Vec& vec2);
        static Vec reject(const Vec& vec1, const Vec& vec2);

        Ty dot(const Vec& other) const;

        Vec& operator+=(const Vec& other);
        Vec& operator-=(const Vec& other);

        Vec& operator+=(Ty scalar);
        Vec& operator-=(Ty scalar);
    };

    // Operator "+"
    template<typename Ty>
    Vec<2, Ty> operator+(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2);

    template<typename Ty>
    Vec<2, Ty> operator+(const Vec<2, Ty>& vec, Ty scalar);

    template<typename Ty>
    Vec<2, Ty> operator+(Ty scalar, const Vec<2, Ty>& vec);

    // Operator "-"
    template<typename Ty>
    Vec<2, Ty> operator-(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2);

    template<typename Ty>
    Vec<2, Ty> operator-(const Vec<2, Ty>& vec, Ty scalar);

    template<typename Ty>
    Vec<2, Ty> operator-(Ty scalar, const Vec<2, Ty>& vec);

    // Operator "*"
    template<typename Ty>
    Vec<2, Ty> operator*(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2);

    template<typename Ty>
    Vec<2, Ty> operator*(const Vec<2, Ty>& vec, Ty scalar);

    template<typename Ty>
    Vec<2, Ty> operator*(Ty scalar, const Vec<2, Ty>& vec);

    // Operator "/"
    template<typename Ty>
    Vec<2, Ty> operator/(const Vec<2, Ty>& vec1, const Vec<2, Ty>& vec2);

    template<typename Ty>
    Vec<2, Ty> operator/(const Vec<2, Ty>& vec, Ty scalar);

    template<typename Ty>
    Vec<2, Ty> operator/(Ty scalar, const Vec<2, Ty>& vec);
}

#include "vec2_type.inl"

#endif // __NEXMATH_BASE_VEC2_TYPE_H__