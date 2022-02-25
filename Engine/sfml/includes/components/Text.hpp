/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Text.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __TEXT_HPP__
#define __TEXT_HPP__

#include <SFML/Graphics/Text.hpp>

#include "../concept.hpp"
#include "Drawable/Drawable.hpp"
#include "Transformable/Transformable.hpp"

namespace sfml
{

    class Text
        :   public Drawable,
            public Transformable
    {

        private:
            sf::Text m_text;
            std::string m_fontName;

        public:
            enum Style
            {
                Regular       = 0,
                Bold          = 1 << 0,
                Italic        = 1 << 1,
                Underlined    = 1 << 2,
                StrikeThrough = 1 << 3
            };

            Text(sw::Entity& entity);
            Text(sw::Entity& entity, const std::string& string, const std::string& font, unsigned int characterSize = 30);
            ~Text() = default;

            void setString(const std::string& string);
            void setFont(const std::string& font);
            void setCharacterSize(unsigned int size);
            void setLineSpacing(float spacingFactor);
            void setLetterSpacing(float spacingFactor);
            void setStyle(Style style);
            void setFillColor(Color color);
            void setOutlineColor(Color color);
            void setOutlineThickness(float thickness);

            const std::string& getString() const;
            const std::string& getFont() const;
            unsigned int getCharacterSize() const;
            float getLetterSpacing() const;
            float getLineSpacing() const;
            Style getStyle() const;
            const Color& getFillColor() const;
            const Color& getOutlineColor() const;
            float getOutlineThickness() const;
            sw::Vector2f findCharacterPos(std::size_t index) const;

            const sf::Drawable& operator&() const override;
            sf::Transformable& operator*() override;
            std::string type() const override { return ("Text"); }

    }; // class Text

} // namespace sfml

#endif // __TEXT_HPP__