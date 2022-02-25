/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Vector2.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

#include "SW/utils/Vector2.hpp"
#include "SFML/System/Vector2.hpp"

namespace sfml
{

    template <typename T>
    class Vector2
        :   public sw::Vector2<T>
    {

        public:
            Vector2() : sw::Vector2<T>{} {}
            Vector2(T X, T Y) : sw::Vector2<T>{X, Y} {}
            Vector2(const sf::Vector2<T>& vec) : sw::Vector2<T>{vec.x, vec.y} {}
            Vector2(const sw::Vector2<T>& vec) : sw::Vector2<T>{vec.x, vec.y} {}

            template <typename U>
            operator sf::Vector2<U>() const { return (sf::Vector2<U>{this->x, this->y}); }
            template <typename U>
            operator sw::Vector2<U>() const { return (sw::Vector2<U>{this->x, this->y}); }

    };

    /// Define the most common types
    typedef Vector2<int>          Vector2i;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<float>        Vector2f;

} // namespace sfml

#endif // __VECTOR2_HPP__