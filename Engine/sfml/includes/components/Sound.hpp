/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Sound.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <SFML/Audio/Sound.hpp>

#include "SW/Component.hpp"

#include "../concept.hpp"
#include "../resources/Sound.hpp"
#include "../utils/TimePoint.hpp"
#include "../maths/Vector3.hpp"

namespace sfml
{

    class Sound
        :   public sw::Component
    {

        public:
            enum Status {
                Stopped,
                Paused,
                Playing
            };

            Sound(sw::Entity& entity, const std::string& soundName = "");
            ~Sound() = default;

            void setPitch(float pitch);
            void setVolume(float volume);
            void setPosition(float x, float y, float z);
            void setPosition(const sfml::Vector3f& position);
            void setRelativeToListener(bool relative);
            void setMinDistance(float distance);
            void setAttenuation(float attenuation);

            float getPitch() const;
            float getVolume() const;
            sfml::Vector3f getPosition() const;
            bool isRelativeToListener() const;
            float getMinDistance() const;
            float getAttenuation() const;

            void play();
            void pause();
            void stop();
            void setBuffer(const std::string& soundName);
            void setLoop(bool loop);
            void setPlayingOffset(time::Point timeOffset);
            const std::string& getSoundName() const;
            bool getLoop() const;
            time::Point getPlayingOffset() const;
            Status getStatus() const;

        private:
            sf::Sound m_sound;
            std::string m_soundName;
            Status m_status;

    }; // class Sound

} // namespace sfml

#endif // __SOUND_HPP__