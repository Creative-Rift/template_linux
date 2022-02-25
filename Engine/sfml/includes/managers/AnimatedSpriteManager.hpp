/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AnimatedSpriteManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __ANIMATEDSPRITEMANAGER_HPP__
#define __ANIMATEDSPRITEMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/AnimatedSprite.hpp"

namespace sfml
{

    class AnimatedSpriteManager
        :   public sw::AManager<AnimatedSprite>
    {

        public:
            const std::string m_associatedTfmManager;

            AnimatedSpriteManager(const std::string& name, sw::AScene& scene, const std::string& tfmManager = "");
            ~AnimatedSpriteManager() override = default;

            void onUpdate() override;

            virtual std::string type() const override { return ("AnimatedSpriteManager"); }

    }; // class AnimatedSpriteManager

} // namespace sfml


#endif // __ANIMATEDSPRITEMANAGER_HPP__