#ifndef VEC2_H
#define VEC2_H

#ifndef CPORTA
    #include <raylib.h>
#else
    #define PI 3.14159265358979323846f
    #define DEG2RAD (PI/180.0f)
    #define RAD2DEG (180.0f/PI)
#endif
#include <iostream>
#include <math.h>

namespace Utils
{
    template<typename T>
    class Vec2
    {
    public:
        Vec2() : X(0), Y(0) {}
        Vec2(T x, T y) : X(x), Y(y) {}
        ~Vec2() = default;

        T GetX() const { return X; }
        T GetY() const { return Y; }
        double GetAngle() const { return atan2(Y, X) * RAD2DEG; }
        double GetLengthSquared() const { return X * X + Y * Y; }
        double GetLength() const { return sqrt(GetLengthSquared()); }
        Vec2 GetNormalized() const { return *this / GetLength(); }

        void SetX(T x) { X = x; }
        void SetY(T y) { Y = y; }

        Vec2 Rotate(double angle) const
        {
            double a = GetAngle() + angle;
            double l = GetLength();
            return Vec2(cos(a * DEG2RAD) * l, sin(a * DEG2RAD) * l);
        }
        
        Vec2 operator+(const Vec2& other) const { return Vec2(X + other.X, Y + other.Y); }
        Vec2 operator-(const Vec2& other) const { return Vec2(X - other.X, Y - other.Y); }
        T operator*(const Vec2& other) const { return X * other.X + Y * other.Y; }
        T operator^(const Vec2& other) const { return X * other.Y - Y * other.X; }
        Vec2 operator*(const T& other) const { return Vec2(X * other, Y * other); }
        Vec2 operator/(const T& other) const { return Vec2(X / other, Y / other); }
        Vec2 operator-() const { return Vec2(-X, -Y); }

        Vec2& operator+=(const Vec2& other)
        {
            X += other.X;
            Y += other.Y;
            return *this;
        }
        Vec2& operator-=(const Vec2& other)
        {
            X -= other.X;
            Y -= other.Y;
            return *this;
        }
        Vec2& operator*=(const Vec2& other)
        {
            X *= other.X;
            Y *= other.Y;
            return *this;
        }
        Vec2& operator/=(const Vec2& other)
        {
            X /= other.X;
            Y /= other.Y;
            return *this;
        }
        Vec2& operator*=(const T& other)
        {
            X *= other;
            Y *= other;
            return *this;
        }
        Vec2& operator/=(const T& other)
        {
            X /= other;
            Y /= other;
            return *this;
        }
        #ifndef CPORTA
            operator Vector2() const { return Vector2{ (float)X, (float)Y }; }
        #endif

    public:
        static Vec2 FromAngle(double angle) { return Vec2(cos(angle * DEG2RAD), sin(angle * DEG2RAD)); }
        static Vec2 Zero() { return Vec2(0, 0); }
        static Vec2 One() { return Vec2(1, 1); }
        static Vec2 Up() { return Vec2(0, -1); }
        static Vec2 Down() { return Vec2(0, 1); }
        static Vec2 Left() { return Vec2(-1, 0); }
        static Vec2 Right() { return Vec2(1, 0); }
    
    private:
        T X;
        T Y;
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
    {
        os << "(" << vec.GetX() << ", " << vec.GetY() << ")";
        return os;
    }

    typedef Vec2<int> Vec2i;
    typedef Vec2<double> Vec2d;

#ifndef CPORTA
    Vec2d Vector2ToVec2(const Vector2& vec);
#endif
}

#endif