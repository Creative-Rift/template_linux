/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * SoundManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SOUNDMANAGER_HPP__
#define __SOUNDMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Sound.hpp"

namespace sfml
{

    class SoundManager
        :   public sw::AManager<Sound>
    {

        public:
            using sw::AManager<Sound>::AManager;
            virtual ~SoundManager() override = default;

            void onUpdate() override {}

            virtual std::string type() const override { return ("SoundManager"); }

    };

}

#endif // __SOUNDMANAGER_HPP__