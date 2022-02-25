/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * BoxColliderManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BOXCOLLIDERMANAGER_HPP__
#define __BOXCOLLIDERMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/BoxCollider.hpp"

namespace sfml
{

    class BoxColliderManager
        :   public sw::AManager<BoxCollider>
    {

        public:
            bool isDebuging;
            const std::string m_associatedTfmManager;

            BoxColliderManager(const std::string& name, sw::AScene& scene, const std::string& tfmManager = "");
            virtual ~BoxColliderManager() override = default;

            void onUpdate() override;

            virtual std::string type() const override { return ("BoxColliderManager"); }

    };

}

#endif // __BOXCOLLIDERMANAGER_HPP__