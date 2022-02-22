/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** Transformable.hpp
*/

#ifndef __SHIPWRECK_SFML_TRANSFORMABLE_HPP__
#define __SHIPWRECK_SFML_TRANSFORMABLE_HPP__

#include <SFML/Graphics/Transformable.hpp>

#include "SW/Component.hpp"

#include "SW/utils/Vector.hpp"

namespace sfml
{

    class Transformable
        :   virtual public sw::Component
    {

        public:
            using sw::Component::Component;
            virtual ~Transformable() override = default;

            void setPosition(float x, float y);
            void setPosition(const sw::Vector2f& position);
            void setRotation(float angle);
            void setScale(float factorX, float factorY);
            void setScale(const sw::Vector2f& factors);
            void setOrigin(float x, float y);
            void setOrigin(const sw::Vector2f& origin);

            sw::Vector2f getPosition();
            float getRotation();
            sw::Vector2f getScale();
            sw::Vector2f getOrigin();

            void move(float offsetX, float offsetY);
            void move(const sw::Vector2f& offset);
            void rotate(float angle);
            void scale(float factorX, float factorY);
            void scale(const sw::Vector2f& factor);
            const sf::Transform& getTransform();
            const sf::Transform& getInverseTransform();

            virtual sf::Transformable& operator*() = 0;
            virtual std::string type() const override { return ("Transformable"); }
    };

    #include "Transformable.inl"

}

#endif // __SHIPWRECK_SFML_TRANSFORMABLE_HPP__