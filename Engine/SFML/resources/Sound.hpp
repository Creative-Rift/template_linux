/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Maxime P.
 * File name:
 * Sound.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SFML_MODULE_SOUND_HPP__
#define __SFML_MODULE_SOUND_HPP__

#include "SW/Resources.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

namespace sfml
{

    class Sound
        :   public sw::ISound
    {

        private:
            sf::SoundBuffer m_soundBuffer;

        public:
            explicit Sound(const std::string& filePath);
            ~Sound() noexcept override = default;

            const sf::SoundBuffer& operator*() const;

    }; // class Front

} // namespace sfml

#endif //__SFML_MODULE_SOUND_HPP__
