/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Sound.hpp
*/

#ifndef __SHIPWRECK_SOUND_HPP__
#define __SHIPWRECK_SOUND_HPP__

#include <SFML/Audio/SoundBuffer.hpp>

#include "SW/Resources.hpp"

namespace sfml
{

    class Sound :
        public sw::ISound
    {

        private:
            sf::SoundBuffer sound;

        public:
            Sound() = default;
            explicit Sound(sf::SoundBuffer& buffer);
            ~Sound() = default;

            sf::SoundBuffer operator*();

    }; // class Sound

} // namespace sfml

#endif // __SHIPWRECK_SOUND_HPP__
