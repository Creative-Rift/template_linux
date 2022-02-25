/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Vector3.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __VECTOR3_HPP__
#define __VECTOR3_HPP__

#include "SFML/System/Vector3.hpp"
#include "SW/utils/Vector3.hpp"

namespace sfml
{

    template <typename T>
    class Vector3
        :   public ::sw::Vector3<T>
    {

        public:
            Vector3() : sw::Vector3<T>{} {}
            Vector3(T X, T Y, T Z) : sw::Vector3<T>{X, Y, Z} {}
            Vector3(const sf::Vector3<T>& vec) : sw::Vector3<T>{vec.x, vec.y, vec.z} {}
            Vector3(const sw::Vector3<T>& vec) : sw::Vector3<T>{vec.x, vec.y, vec.z} {}

            template <typename U>
            operator sf::Vector3<U>() const { return (sf::Vector3<U>{this->x, this->y, this->z}); }
            template <typename U>
            operator sw::Vector3<U>() const { return (sw::Vector3<U>{this->x, this->y, this->z}); }

    };

    /// Define the most common types
    typedef Vector3<int>          Vector3i;
    typedef Vector3<unsigned int> Vector3u;
    typedef Vector3<float>        Vector3f;

} // namespace sfml

#endif // __VECTOR3_HPP__