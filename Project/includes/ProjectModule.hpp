/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ProjectModule.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __PROJECTMODULE_HPP__
#define __PROJECTMODULE_HPP__

#include "SF/Module.hpp"

class ProjectModule
    :   public sfml::Module
{

    public:
        using sfml::Module::Module;
        ~ProjectModule() override = default;

        void onInitialize() override;
        void onUpdate() override;
        void onTerminate() override;

};

#endif // __PROJECTMODULE_HPP__