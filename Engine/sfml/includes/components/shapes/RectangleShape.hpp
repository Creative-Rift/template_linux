/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * RectangleShape.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __RECTANGLESHAPE_HPP__
#define __RECTANGLESHAPE_HPP__

#include <SFML/Graphics/RectangleShape.hpp>

#include "SW/utils/Rect.hpp"

#include "../../concept.hpp"
#include "../Drawable/Drawable.hpp"
#include "../Transformable/Transformable.hpp"
#include "../../maths/Vector2.hpp"
#include "../../maths/Rect.hpp"

namespace sfml
{

    class RectangleShape
        :   public Drawable,
            public Transformable
    {

        private:
            sf::RectangleShape m_shape;
            std::string m_txtName;

        public:
            explicit RectangleShape(sw::Entity& entity, const sfml::Vector2f& size = sfml::Vector2f(10, 10));
            ~RectangleShape() = default;

            void setTexture(const std::string& textureName, bool resetRect = false);
            void setTextureRect(const sfml::IntRect& rect);
            void setFillColor(const Color& color);
            void setOutlineColor(const Color& color);
            void setOutlineThickness(float thickness);

            std::string getTextureName() const;
            const sfml::IntRect& getTextureRect() const;
            const Color& getFillColor() const;
            const Color& getOutlineColor() const;
            float getOutlineThickness() const;

            void setSize(const sfml::Vector2f& size);
            const sfml::Vector2f& getSize() const;
            std::size_t getPointCount() const;
            sfml::Vector2f getPoint(std::size_t index) const;

            const sf::Drawable& operator&() const override;
            sf::Transformable& operator*() override;
            std::string type() const override { return ("RectangleShape"); }

    }; // class RectangleShape

} // namespace sfml

#endif // __RECTANGLESHAPE_HPP__