/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Maxime P.
 * File name:
 * Music.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SFML_MODULE_MUSIC_HPP__
#define __SFML_MODULE_MUSIC_HPP__

#include "SW/Resources.hpp"
#include "SFML/Audio/Music.hpp"

namespace sfml::resources
{

    class Music
        :   public sw::IMusic
    {

        private:
            sf::Music m_music;

        public:
            explicit Music(const std::string& filePath);
            ~Music() noexcept override = default;

            const sf::Music& operator*() const;
            sf::Music& operator*();

    }; // class Front

} // namespace sfml::resources

#endif //__SFML_MODULE_MUSIC_HPP__
