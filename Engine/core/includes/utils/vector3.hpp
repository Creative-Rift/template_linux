/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * vector2.hpp
 *
 * Description:
 * Vector3 class
 * The Vector3 class allow you to make three dimensional vector with the type you want.
 */

#ifndef __SHIPWRECK_CORE_VECTOR3_HPP__
#define __SHIPWRECK_CORE_VECTOR3_HPP__

#include <ostream>

namespace sw
{
    template <typename T>
    class Vector3
    {

        public:
            /*////////////////////////////////////////////////////////////////*/
            /// @brief X Coordinate
            //
            T x;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Y Coordinate
            //
            T y;
            ///

            /*////////////////////////////////////////////////////////////////*/
            /// @brief Z Coordinate
            //
            T z;
            ///

            /*////////////////////////////////////////////////////////////////*/
            ///
            /// @brief Default constructor.
            ///
            /// Creates a Vector3(0, 0).
            //
            Vector3();
            ///

            /*////////////////////////////////////////////////////////////////*/
            ///
            /// @brief Construct the vector from the given coordinates.
            ///
            /// @param X X coordinate.
            /// @param Y Y coordinate.
            //
            Vector3(T x, T y, T z);
            ///

            /*////////////////////////////////////////////////////////////////*/
            ///
            /// @brief Default destructor.
            //
            ~Vector3() = default;
            ///

    }; // class Vector3

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator -
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise subtraction of both vectors
    //
    template <typename T>
    Vector3<T> operator -(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of unary operator -
    ///
    /// @param right Vector to negate
    ///
    /// @return Memberwise opposite of the vector
    //
    template <typename T>
    Vector3<T> operator -(const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator +
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise addition of both vectors
    //
    template <typename T>
    Vector3<T> operator +(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator *
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise multiplication of both vectors
    //
    template <typename T>
    Vector3<T> operator *(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator *
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise multiplication by right
    //
    template <typename T>
    Vector3<T> operator *(const sw::Vector3<T>& left, T right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Memberwise division of both vectors
    //
    template <typename T>
    Vector3<T> operator /(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    /// @relates Vector3
    /// @brief Overload of binary operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise division by right
    //
    template <typename T>
    Vector3<T> operator /(const sw::Vector3<T>& left, T right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator -=
    ///
    /// This operator performs a memberwise subtraction of both vectors,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Reference to left
    //
    template <typename T>
    Vector3<T>& operator -=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    /// @relates Vector3
    /// @brief Overload of binary operator +=
    ///
    /// This operator performs a memberwise addition of both vectors,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Reference to left
    //
    template <typename T>
    Vector3<T>& operator +=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator *=
    ///
    /// This operator performs a memberwise multiplication of both vectors,
    /// and assigns the result to left.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return Reference to left
    //
    template <typename T>
    Vector3<T>& operator *=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @return Reference to left
    //
    template <typename T>
    Vector3<T>& operator *=(sw::Vector3<T>& left, T right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise division of both vectors
    //
    template <typename T>
    Vector3<T>& operator /=(sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator /
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a scalar value)
    ///
    /// @return Memberwise division by right
    //
    template <typename T>
    Vector3<T>& operator /=(sw::Vector3<T>& left, T right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator ==
    ///
    /// This operator compares strict equality between two vectors.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return True if left is equal to right
    //
    template <typename T>
    bool operator ==(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /*////////////////////////////////////////////////////////////////////////*/
    ///
    /// @relates Vector3
    /// @brief Overload of binary operator !=
    ///
    /// This operator compares strict difference between two vectors.
    ///
    /// @param left  Left operand (a vector)
    /// @param right Right operand (a vector)
    ///
    /// @return True if left is not equal to right
    //
    template <typename T>
    bool operator !=(const sw::Vector3<T>& left, const sw::Vector3<T>& right);
    ///

    /// Define the most common types
    typedef Vector3<int>          Vector3i;
    typedef Vector3<unsigned int> Vector3u;
    typedef Vector3<float>        Vector3f;

    template <typename T>
    ::std::ostream& operator<<(::std::ostream& os, const Vector3<T>& vector);

    #include "vector3.inl"

} // namespace sw

#endif // __SHIPWRECK_CORE_VECTOR3_HPP__