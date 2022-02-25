/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * ProjectModule.cpp
 *
 * Description:
 * [Change]
 */

#include "SW/Engine.hpp"
#include "ProjectModule.hpp"
#include "main.hpp"

void ProjectModule::onInitialize()
{
    sw::Engine::createScene<MainScene>("MainScene");

    CreateWindow("Project", 800, 600, sfml::WindowStyle::Default);
    setFramerateLimit(60);
    setIcon("assets/textures/Planet.png");

    loadResourcesFile("assets/textures.json");
    loadResourcesFile("assets/sounds.json");
    loadResourcesFile("assets/fonts.json");
    loadResourcesFile("assets/musics.json");
}

void ProjectModule::onUpdate()
{
}

void ProjectModule::onTerminate()
{
}