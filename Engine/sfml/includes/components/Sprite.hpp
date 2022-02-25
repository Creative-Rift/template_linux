/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** Sprite.hpp
*/

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "Drawable/Drawable.hpp"
#include "Transformable/Transformable.hpp"
#include "../maths/Rect.hpp"
#include "../concept.hpp"

namespace sfml
{

    class Sprite
        :   public Drawable,
            public Transformable
    {

        protected:
            sf::Sprite m_sprite;

        public:
            Sprite(sw::Entity& entity);
            Sprite(sw::Entity& entity, const std::string& textureName);
            Sprite(sw::Entity& entity, const std::string& textureName, const IntRect& rectangle);
            ~Sprite() override = default;

            void setTexture(const std::string& rscName, bool resetRect = false);
            void setTexture(const std::string& rscName, const IntRect& rect);
            void setTextureRect(const IntRect& rect);
            void setColor(const Color& color);

            IntRect getTextureRect() const;
            Color getColor() const;

            const sf::Drawable& operator&() const override;
            sf::Transformable& operator*() override { return (m_sprite); }
            virtual std::string type() const override { return ("Sprite"); }

    }; // class Sprite

} // namespace sfml

#endif // __SPRITE_H__