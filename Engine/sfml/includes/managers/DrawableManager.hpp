/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * DrawableManager.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __DRAWABLEMANAGER_HPP__
#define __DRAWABLEMANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Drawable/Drawable.hpp"

namespace sfml
{

    class DrawableManager
        :   public sw::AManager<Drawable>
    {

        public:
            const std::string m_associatedTfmManager;

            DrawableManager(const std::string& name, sw::AScene& scene, const std::string& tfmManager = "");
            virtual ~DrawableManager() override = default;

            void onUpdate() override;

            virtual std::string type() const override { return ("DrawableManager"); }

    };

}

#endif // __DRAWABLEMANAGER_HPP__