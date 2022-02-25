/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Maxime P.
 * File name:
 * Font.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SFML_MODULE_FONT_HPP__
#define __SFML_MODULE_FONT_HPP__

#include "SW/Resources.hpp"
#include "SFML/Graphics/Font.hpp"

namespace sfml::resources
{

    class Font
        :   public sw::IFont
    {

        private:
            sf::Font m_font;

        public:
            explicit Font(const std::string& filePath);
            ~Font() noexcept override = default;

            const sf::Font& operator*() const;

    }; // class Front

} // namespace sfml::resources

#endif //__SFML_MODULE_FONT_HPP__
