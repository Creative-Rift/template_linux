/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Rect.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __RECT_HPP__
#define __RECT_HPP__

#include "SW/utils/Rect.hpp"
#include "SFML/Graphics/Rect.hpp"

namespace sfml
{

    template <typename T>
    class Rect
        :   public sw::Rect<T>
    {

        public:
            Rect() : sw::Rect<T>{} {}
            Rect(T Left, T Top, T With, T Height) : sw::Rect<T>{Left, Top, With, Height} {}
            Rect(sf::Rect<T> rect) : sw::Rect<T>{rect.left, rect.top, rect.width, rect.height} {}

            template <typename U>
            operator sf::Rect<U>() const { return (sf::Rect<U>{this->left, this->top, this->width, this->height}); }
            template <typename U>
            operator sw::Rect<U>() const { return (sw::Rect<U>{this->left, this->top, this->width, this->height}); }

    };

    /// Define the most common types
    typedef Rect<int>          IntRect;
    typedef Rect<unsigned int> UIntRect;
    typedef Rect<float>        FloatRect;

} // namespace sfml

#endif // __RECT_HPP__