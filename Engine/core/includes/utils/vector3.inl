/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * vector2.inl
 *
 * Description:
 * Vector3 functions implementation
 */

#include <iostream>

template <typename T>
inline sw::Vector3<T>::Vector3()
    :   x{},
        y{},
        z{}
{}

template <typename T>
inline sw::Vector3<T>::Vector3(T X, T Y, T Z)
    :   x{X},
        y{Y},
        z{Z}
{}

template <typename T>
inline sw::Vector3<T> operator-(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z));
}

template <typename T>
inline sw::Vector3<T> operator-(const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(-right.x, -right.y, -right.z));
}

template <typename T>
inline sw::Vector3<T> operator+(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z));
}

template <typename T>
inline sw::Vector3<T> operator*(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x * right.x, left.y * right.y, left.z * right.z));
}

template <typename T>
inline sw::Vector3<T> operator*(const sw::Vector3<T>& left, T right)
{
    return (sw::Vector3<T>(left.x * right, left.y * right, left.z * right));
}

template <typename T>
inline sw::Vector3<T> operator/(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return (sw::Vector3<T>(left.x / right.x, left.y / right.y, left.z / right.z));
}

template <typename T>
inline sw::Vector3<T> operator/(const sw::Vector3<T>& left, T right)
{
    return (sw::Vector3<T>(left.x / right, left.y / right, left.z / right));
}

template <typename T>
inline sw::Vector3<T>& operator-=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator+=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator*=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator*=(sw::Vector3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator/=(sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return (left);
}

template <typename T>
inline sw::Vector3<T>& operator/=(sw::Vector3<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return (left);
}

template <typename T>
inline bool operator==(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z));
}

template <typename T>
inline bool operator!=(const sw::Vector3<T>& left, const sw::Vector3<T>& right)
{
    return ((left.x != right.x) || (left.y != right.y) || (left.z != right.z));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const sw::Vector3<T>& vector)
{
    os << "Vector<" << typeid(vector.x).name() << "> : [ x:" << vector.x << " , y:" << vector.y << " , z:" << vector.z << "  ]\n";
    return (os);
}