/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Texture.hpp
*/

#ifndef __SHIPWRECK_TEXTURE_HPP__
#define __SHIPWRECK_TEXTURE_HPP__

#include <SFML/Graphics/Texture.hpp>

#include "SW/Resources.hpp"

namespace sfml
{

    class Texture :
        public sw::ITexture
    {

        private:
            sf::Texture texture;

        public:
            Texture() = default;
            explicit Texture(sf::Texture& image);
            ~Texture() = default;

            sf::Texture& operator*();

    }; // class Texture

} // namespace sfml

#endif // __SHIPWRECK_TEXTURE_HPP__
