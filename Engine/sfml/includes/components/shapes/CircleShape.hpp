/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * CircleShape.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __CIRCLESHAPE_HPP__
#define __CIRCLESHAPE_HPP__

#include <SFML/Graphics/CircleShape.hpp>

#include "../../concept.hpp"
#include "../Drawable/Drawable.hpp"
#include "../Transformable/Transformable.hpp"
#include "../../maths/Rect.hpp"
#include "../../maths/Vector2.hpp"

namespace sfml
{

    class CircleShape
        :   public Drawable,
            public Transformable
    {

        private:
            sf::CircleShape m_shape;
            std::string m_txtName;

        public:
            explicit CircleShape(sw::Entity& entity, float radius = 10, std::size_t pointCount = 30);
            ~CircleShape() = default;

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

            void setRadius(float radius);
            float getRadius() const;
            void setPointCount(std::size_t count);
            std::size_t getPointCount() const;
            sfml::Vector2f getPoint(std::size_t index) const;

            const sf::Drawable& operator&() const override;
            sf::Transformable& operator*() override;
            std::string type() const override { return ("CircleShape"); }

    }; // class CircleShape

} // namespace sfml

#endif // __CIRCLESHAPE_HPP__