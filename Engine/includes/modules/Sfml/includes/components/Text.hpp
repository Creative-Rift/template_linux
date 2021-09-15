/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Text.hpp
*/

#ifndef __SHIPWRECK_SFML_TEXT_HPP__
#define __SHIPWRECK_SFML_TEXT_HPP__

#include <SFML/Graphics/Font.hpp>

#include "SW/Components.hpp"

namespace sw
{
}

namespace sfml
{

    class Text :
        public sw::Component
    {

        public:

            enum Style {
                Regular = 0,
                Bold = 1 << 0,
                Italic = 1 << 1,
                Underlined = 1 << 2,
                StrikeThrough = 1 << 3
            } m_style;

            std::string m_text;
            unsigned int m_size;
            sf::Font m_font;
            sf::Color m_color;
            float m_lineSpacing;

            Text() = delete;
            Text(Text const&) = delete;
            Text(Text&&) = delete;
            Text& operator=(Text const&) = delete;
            Text& operator=(Text&&) = delete;
            Text(sw::Entity& entityRef);

            void setLayer(int layer);
            int getLayer() const;

    }; // class Text

} // namespace sfml

#endif // __SHIPWRECK_SFML_TEXT_HPP__