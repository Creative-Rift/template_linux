/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MusicManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __MUSICMANAGER_HPP__
#define __MUSICMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Music.hpp"

namespace sfml
{

    class MusicManager
        :   public sw::AManager<Music>
    {

        public:
            using sw::AManager<Music>::AManager;
            virtual ~MusicManager() override = default;

            void onUpdate() override {}

            virtual std::string type() const override { return ("MusicManager"); }

    };

}

#endif // __MUSICMANAGER_HPP__