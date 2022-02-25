/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MouseColliderManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __MOUSECOLLIDERMANAGER_HPP__
#define __MOUSECOLLIDERMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/MouseCollider.hpp"

namespace sfml
{

    class MouseColliderManager
        :   public sw::AManager<MouseCollider>
    {

        public:
            float autoRelease;
            bool isDebuging;
            const std::string m_associatedTfmManager;

            MouseColliderManager(const std::string& name, sw::AScene& scene, const std::string& tfmManager = "");
            ~MouseColliderManager() override = default;

            void onUpdate() override;

            virtual std::string type() const override { return ("MouseColliderManager"); }

    };

}

#endif // __MOUSECOLLIDERMANAGER_HPP__