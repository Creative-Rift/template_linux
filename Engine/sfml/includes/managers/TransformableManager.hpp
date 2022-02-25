/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * TransformableManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __TRANSFORMABLEMANAGER_HPP__
#define __TRANSFORMABLEMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Transformable/Transformable.hpp"

namespace sfml
{

    class TransformableManager
        :   public sw::AManager<Transformable>
    {

        public:
            const std::string m_associatedTfmManager;

            TransformableManager(const std::string& name, sw::AScene& scene, const std::string& tfmManager = "");
            virtual ~TransformableManager() override = default;

            void onUpdate() override {};

            virtual std::string type() const override { return ("TransformableManager"); }

    };

}

#endif // __TRANSFORMABLEMANAGER_HPP__