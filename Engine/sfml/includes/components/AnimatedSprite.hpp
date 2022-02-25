/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AnimatedSprite.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __ANIMATEDSPRITE_HPP__
#define __ANIMATEDSPRITE_HPP__

#include "Sprite.hpp"
#include "../concept.hpp"

namespace sfml
{
    class AnimatedSprite
        :   public Sprite
    {
        protected:
            bool m_isLoop;
            bool m_isAnim;

            float m_loopTime;
            float m_animTime;

            int m_rectMin;
            int m_rectPos;
            int m_rectOffset;
            int m_rectMax;

            sw::Chrono m_clock;

        public:
            AnimatedSprite(sw::Entity& entity, const std::string& rscName, const IntRect& rect,
                           int minPos = 0, int maxPos = 0, int offset = 0, float loopTime = -1, float animTime = -1);
            virtual ~AnimatedSprite() override = default;

            void setLoop(bool value);
            void setAnimated(bool value);
            void setLoopTime(float value);
            void setAnimationTime(float value);
            void setPosition(int value);
            void setOffset(int value);
            void setMaxPosition(int value);

            bool isLoop();
            bool isAnimated();
            float getLoopTime() const;
            float getAnimationTime() const;

            void Update();

            virtual std::string type() const override { return ("AnimatedSprite"); }

    }; // class AnimatedSprite

} // namespace sfml

#endif // __ANIMATEDSPRITE_HPP__