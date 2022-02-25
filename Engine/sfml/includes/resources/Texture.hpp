/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Maxime P.
 * File name:
 * Texture.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SFML_MODULE_TEXTURE_HPP__
#define __SFML_MODULE_TEXTURE_HPP__

#include "SW/Resources.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace sfml::resources
{

    class Texture
        :   public sw::ITexture
    {

        private:
            sf::Texture m_texture;

        public:
            explicit Texture(const std::string& filePath);
            ~Texture() noexcept override = default;

            const sf::Texture& operator*() const;

    }; // class Front

} // namespace sfml::resources

#endif //__SFML_MODULE_TEXTURE_HPP__
