/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** Drawable.hpp
*/

#ifndef __DRAWABLE_HPP__
#define __DRAWABLE_HPP__

#include "SW/Component.hpp"
#include "SFML/Graphics.hpp"

namespace sfml
{

    class Drawable
        :   virtual public sw::Component
    {

        protected:
            std::size_t m_layer;

        public:
            Drawable(sw::Entity& entity);
            virtual ~Drawable() override = default;

            void setLayer(std::size_t value);
            std::size_t getLayer() const;
            virtual const sf::Drawable& operator&() const = 0;
            virtual std::string type() const override { return ("Drawable"); }

    }; // class Drawable

    #include "Drawable.inl"

} // namespace sfml

#endif // __DRAWABLE_HPP__