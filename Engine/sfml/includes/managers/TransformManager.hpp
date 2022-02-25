/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * TransformManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __TRANSFORMMANAGER_HPP__
#define __TRANSFORMMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Transform.hpp"

namespace sfml
{

    class TransformManager
        :   public sw::AManager<Transform>
    {

        public:
            using sw::AManager<Transform>::AManager;
            virtual ~TransformManager() override = default;

            void onUpdate() override {}

            virtual std::string type() const override { return ("TransformManager"); }

    };

}

#endif // __TRANSFORMMANAGER_HPP__