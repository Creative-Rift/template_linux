/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Audio.hpp
*/

#ifndef __SHIPWRECK_SFML_AUDIO_HPP__
#define __SHIPWRECK_SFML_AUDIO_HPP__

#include <map>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "SW/Components.hpp"

namespace sfml
{

    class Audio :
        public sw::Component
    {

        public:
            std::map<std::string, sf::SoundBuffer> m_songs;
            sf::Sound m_listener;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            Audio(sw::Entity& entityRef);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Play the audio you want with the specified name
            ///
            /// \param name
            ////////////////////////////////////////////////////////////////////////////
            void play(std::string name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Add audio on your component with specified name
            ///
            /// \param sound
            /// \param name
            /// \return the component
            Audio& addSound(sf::SoundBuffer sound, std::string name);

    }; // class Audio

} // namespace sfml

#endif // __SHIPWRECK_SFML_AUDIO_HPP__