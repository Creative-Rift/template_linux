/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.cpp
** Description: [CHANGE]
*/

#include "scenes/Main.hpp"
#include "Module.hpp"
#include "factories.hpp"

void Main::onLoad()
{
    auto& tfmFact = createFactory<sfml::TransformFact>(sfml::Module::transformFactName);
    auto& txtFact = createFactory<sfml::TextFact>("TextFact");

    createEntity("Text");

    auto& transform = tfmFact.createComponent("Text");
    auto& cmpt = txtFact.createComponent("Text");
    cmpt.m_text = "Hello World";
    cmpt.m_color = sf::Color::Red;
    cmpt.m_size = 100;
    transform.setPosition(600, 400);
}

void Main::onUpdate()
{}

void Main::onUnload()
{}
