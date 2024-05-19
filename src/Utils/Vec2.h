#ifndef VEC2_H
#define VEC2_H

#include <raylib.h>
#include <iostream>
#include <math.h>

namespace Utils
{
    template<typename T>
    class Vec2
    {
    public:
        /**
         * @brief Constructs a new Vec2 object with a given type (default values are 0)
         */
        Vec2() : X(0), Y(0) {}
        /**
         * @brief Constructs a new Vec2 object with a given type and given values
         * 
         * @param x The x value
         * @param y The y value
         */
        Vec2(T x, T y) : X(x), Y(y) {}
        ~Vec2() = default;

        /**
         * @brief Returns the x value
         * 
         * @return T The x value
         */
        T GetX() const { return X; }
        /**
         * @brief Returns the y value
         * 
         * @return T The y value
         */
        T GetY() const { return Y; }
        /**
         * @brief Returns the angle of the vector
         * 
         * @return double The angle of the vector
         */
        double GetAngle() const { return atan2(Y, X) * RAD2DEG; }
        /**
         * @brief Returns the squared length of the vector
         * 
         * @return double The squared length of the vector
         */
        double GetLengthSquared() const { return X * X + Y * Y; }
        /**
         * @brief Returns the length of the vector
         * 
         * @return double The length of the vector
         */
        double GetLength() const { return sqrt(GetLengthSquared()); }
        /**
         * @brief Returns the normalized vector
         * 
         * @return Vec2 The normalized vector
         */
        Vec2 GetNormalized() const { return *this / GetLength(); }

        /**
         * @brief Sets the x value
         * 
         * @param x The new x value
         */
        void SetX(T x) { X = x; }
        /**
         * @brief Sets the y value
         * 
         * @param y The new y value
         */
        void SetY(T y) { Y = y; }

        /**
         * @brief Rotates the vector by a given angle
         * 
         * @param angle The angle to rotate the vector by
         * @return Vec2 The rotated vector
         */
        Vec2 Rotate(double angle) const
        {
            double a = GetAngle() + angle;
            double l = GetLength();
            return Vec2(cos(a * DEG2RAD) * l, sin(a * DEG2RAD) * l);
        }
        
        /**
         * @brief Returns the sum of two vectors
         * 
         * @param other The other vector
         * @return Vec2 The sum of the two vectors
         */
        Vec2 operator+(const Vec2& other) const { return Vec2(X + other.X, Y + other.Y); }
        /**
         * @brief Returns the difference of two vectors
         * 
         * @param other The other vector
         * @return Vec2 The difference of the two vectors
         */
        Vec2 operator-(const Vec2& other) const { return Vec2(X - other.X, Y - other.Y); }
        /**
         * @brief Returns the dot product of two vectors
         * 
         * @param other The other vector
         * @return T The dot product of the two vectors
         */
        T operator*(const Vec2& other) const { return X * other.X + Y * other.Y; }
        /**
         * @brief Returns the cross product of two vectors
         * 
         * @param other The other vector
         * @return T The cross product of the two vectors
         */
        T operator^(const Vec2& other) const { return X * other.Y - Y * other.X; }
        /**
         * @brief Returns the element-wise product of two vectors
         * 
         * @param other The other vector
         * @return Vec2 The product of the two vectors
         */
        Vec2 operator*(const T& other) const { return Vec2(X * other, Y * other); }
        /**
         * @brief Returns the element-wise division of two vectors
         * 
         * @param other The other vector
         * @return Vec2 The division of the two vectors
         */
        Vec2 operator/(const T& other) const { return Vec2(X / other, Y / other); }
        /**
         * @brief Returns the negation of the vector
         * 
         * @return Vec2 The negation of the vector
         */
        Vec2 operator-() const { return Vec2(-X, -Y); }

        /**
         * @brief Adds another vector to the current vector
         * 
         * @param other The other vector
         * @return Vec2& The current vector
         */
        Vec2& operator+=(const Vec2& other)
        {
            X += other.X;
            Y += other.Y;
            return *this;
        }
        /**
         * @brief Subtracts another vector from the current vector
         * 
         * @param other The other vector
         * @return Vec2& The current vector
         */
        Vec2& operator-=(const Vec2& other)
        {
            X -= other.X;
            Y -= other.Y;
            return *this;
        }
        /**
         * @brief Multiplies another vector with the current vector
         * 
         * @param other The other vector
         * @return Vec2& The current vector
         */
        Vec2& operator*=(const Vec2& other)
        {
            X *= other.X;
            Y *= other.Y;
            return *this;
        }
        /**
         * @brief Divides another vector with the current vector
         * 
         * @param other The other vector
         * @return Vec2& The current vector
         */
        Vec2& operator/=(const Vec2& other)
        {
            X /= other.X;
            Y /= other.Y;
            return *this;
        }
        /**
         * @brief Multiplies the vector with a scalar
         * 
         * @param other The scalar
         * @return Vec2& The current vector
         */
        Vec2& operator*=(const T& other)
        {
            X *= other;
            Y *= other;
            return *this;
        }
        /**
         * @brief Divides the vector with a scalar
         * 
         * @param other The scalar
         * @return Vec2& The current vector
         */
        Vec2& operator/=(const T& other)
        {
            X /= other;
            Y /= other;
            return *this;
        }
        operator Vector2() const { return Vector2{ (float)X, (float)Y }; }

    public:
        /**
         * @brief Creates a vector from an angle
         * 
         * @param angle The angle
         * @return Vec2 The vector from the angle
         */
        static Vec2 FromAngle(double angle) { return Vec2(cos(angle * DEG2RAD), sin(angle * DEG2RAD)); }
        /**
         * @brief Returns a zero vector
         * 
         * @return Vec2 The zero vector
         */
        static Vec2 Zero() { return Vec2(0, 0); }
        /**
         * @brief Returns a one vector
         * 
         * @return Vec2 The one vector
         */
        static Vec2 One() { return Vec2(1, 1); }
        /**
         * @brief Returns a unit vector pointing up
         * 
         * @return Vec2 The up vector
         */
        static Vec2 Up() { return Vec2(0, -1); }
        /**
         * @brief Returns a unit vector pointing down
         * 
         * @return Vec2 The down vector
         */
        static Vec2 Down() { return Vec2(0, 1); }
        /**
         * @brief Returns a unit vector pointing left
         * 
         * @return Vec2 The left vector
         */
        static Vec2 Left() { return Vec2(-1, 0); }
        /**
         * @brief Returns a unit vector pointing right
         * 
         * @return Vec2 The right vector
         */
        static Vec2 Right() { return Vec2(1, 0); }
    
    private:
        T X;
        T Y;
    };

    /**
     * @brief Inserts a vector into an output stream
     * 
     * @param os The output stream
     * @param vec The vector
     * @return std::ostream& The modified output stream
     */
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
    {
        os << "(" << vec.GetX() << ", " << vec.GetY() << ")";
        return os;
    }

    typedef Vec2<int> Vec2i;
    typedef Vec2<double> Vec2d;

    Vec2d Vector2ToVec2(const Vector2& vec);
}

#endif