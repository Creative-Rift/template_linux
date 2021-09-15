/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Module.cpp
*/

#include "SW/Engine.hpp"
#include "Sfml/includes/Module.hpp"
#include "scenes/Main.hpp"

std::string sfml::Module::transformFactName = "TransformFact";
std::string sfml::Module::scriptFactName = "ScriptFact";
std::string sfml::Module::mouseColliderFactName = "MouseColliderFact";
std::string sfml::Module::spriteFactName = "SpriteFact";

void sfml::Module::onInitialize()
{
    m_debugMode = true;
    m_rwindow.create({1920, 1080, 32}, "Window");
    m_clock = sf::Clock();

    m_rwindow.setFramerateLimit(60);
    sw::Engine::createScene<Main>("main");
}

void sfml::Module::onUpdate()
{}

void sfml::Module::onTerminate()
{
    sw::Engine::deleteScene("main");
}