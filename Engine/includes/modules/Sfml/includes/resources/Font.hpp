/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Font.hpp
*/

#ifndef __SHIPWRECK_FONT_HPP__
#define __SHIPWRECK_FONT_HPP__

#include <SFML/Graphics/Font.hpp>

#include "SW/Resources.hpp"

namespace sfml
{

    class Font :
        public sw::IFont
    {

        private:
            sf::Font font;

        public:
            Font() = default;
            explicit Font(sf::Font& police);
            ~Font() = default;

            sf::Font operator*() const;

    }; // class Font

} // namespace sfml

#endif // __SHIPWRECK_FONT_HPP__
