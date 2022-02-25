/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Music.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __MUSIC_HPP__
#define __MUSIC_HPP__

#include <SFML/Audio/Music.hpp>

#include "SW/Component.hpp"
#include "SW/utils/Reference.hpp"
#include "../resources/Music.hpp"
#include "../utils/Span.hpp"
#include "../utils/TimePoint.hpp"

namespace sfml
{

    class Music
        :   public sw::Component
    {

        public:
            enum Status {
                Stopped,
                Paused,
                Playing
            };

            using TimeSpan = Span<time::Point>;

            Music(sw::Entity& entity, const std::string& musicName = "");
            ~Music() = default;

            void play();
            void pause();
            void stop();
            time::Point getDuration() const;
            TimeSpan getLoopPoints() const;
            void setLoopPoints(TimeSpan timePoints);
            unsigned int getChannelCount() const;
            unsigned int getSampleRate() const;
            Status getStatus() const;

            void setPlayingOffset(time::Point timeOffset);
            time::Point getPlayingOffset() const;

            void setLoop(bool loop);
            bool getLoop() const;

        private:
            sw::Reference<sf::Music> m_music;

    }; // class Music

} // namespace sfml

#endif // __MUSIC_HPP__