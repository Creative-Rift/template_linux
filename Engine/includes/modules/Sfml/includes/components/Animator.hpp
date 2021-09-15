/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Animator.hpp
*/

#ifndef __SHIPWRECK_SFML_ANIMATOR_HPP__
#define __SHIPWRECK_SFML_ANIMATOR_HPP__

#include "SW/Components.hpp"
#include "Sprite.hpp"

namespace sfml
{

    class Animator :
        public sw::Component
    {

        private:
        public:
            sf::Vector2u m_rect;
            sf::Rect<float> m_displayRect;
            float m_lastFrame;
            int m_endFrame;
            float m_loopDelay;
            bool m_isPlaying;
            bool m_loop;
            float m_framePerSecond;

            Sprite& m_spr;


            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the type of the animation
            ////////////////////////////////////////////////////////////////////////////
            enum Anim_type {
                ANIM_SPRITE,
                ANIM_LINE
            } m_animType;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            Animator(sw::Entity& entity);
            Animator() = delete;
            Animator(Animator const&) = delete;
            Animator(Animator&&) = delete;
            Animator& operator=(Animator const&) = delete;
            Animator& operator=(Animator&&) = delete;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Play your animation
            ////////////////////////////////////////////////////////////////////////////
            void play();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Set pause on your animation
            ////////////////////////////////////////////////////////////////////////////
            void pause();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Reset your animation (set on first frame)
            ////////////////////////////////////////////////////////////////////////////
            void reset();

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Return a bool if the animation is playing
            ///
            /// \return bool
            ////////////////////////////////////////////////////////////////////////////
            [[nodiscard]] bool isPlaying() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Set your animation in loop or not
            ///
            /// \param loop
            /// \param delay delay between two animation
            /// \return reference to your sprite animator
            ////////////////////////////////////////////////////////////////////////////
            Animator& setLoop(bool loop, float delay = 0);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief If you have one animation per line on your texture, you can define
            ///        the line you want here and the number of the frame (if you have
            ///        les frame than the length of your texture)
            ///
            /// \param engine
            /// \param line
            /// \param end number of frame in your animation
            /// \return reference to your sprite animator
            ////////////////////////////////////////////////////////////////////////////
            Animator& setLine(int line, int end = -1);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the displayed rect on your texture
            ///
            /// \param engine
            /// \param rect
            /// \return reference to your sprite animator
            ////////////////////////////////////////////////////////////////////////////
            Animator& setRect(sf::Vector2u rect);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the speed (number of frame per second) of your animation
            ///
            /// \param fps
            /// \return reference to your sprite
            ////////////////////////////////////////////////////////////////////////////
            Animator& setFPS(float fps);

            friend void animSprite(Animator &animator, float &current_time);
            friend void animLine(Animator &animator, float &current_time);

    }; // class Animator

    void animLine(Animator &animator, float &current_time);
    void animSprite(Animator &animator, float &current_time);

} // namespace sfml

#endif // __SHIPWRECK_SFML_ANIMATOR_HPP__