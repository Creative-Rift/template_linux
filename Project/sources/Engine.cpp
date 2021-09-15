/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.cpp
*/

#include "Sfml/includes/Module.hpp"
#include "SW/Engine.hpp"

///////////////////////////////////////////////////////////////////////////////
///
///     Initialize your Module here
//
void sw::Engine::onInitialize()
{
    sw::Engine::createModule<sfml::Module>("Sfml");
}

///////////////////////////////////////////////////////////////////////////////
///
///     Update your Module here
//
void sw::Engine::onUpdate()
{}

///////////////////////////////////////////////////////////////////////////////
///
///     Terminate your Module here
//
void sw::Engine::onTerminate()
{}
