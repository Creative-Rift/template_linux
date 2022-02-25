/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * main.cpp
 *
 * Description:
 * [Change]
 */

#include "SW/Engine.hpp"
#include "SF/Module.hpp"
#include "scenes/Main.hpp"

int main()
try
{
    sw::Speech::setDisplayed(true);
    sw::Speech::stack = true;

    sw::Engine::createModule<sfml::Module>();
    sw::Engine::createScene<MainScene>("MainScene");

    sw::Engine::initialize();
    sw::Engine::activeScene().load();
    sw::Speech::flush();
    while (sw::Engine::getModule().isOk()) {
        sw::Engine::update();
        sw::Speech::flush();
    }
    sw::Engine::terminate();
    sw::Speech::flush();
    return (0);
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    sw::Speech::flush();
}
// catch (std::exception& error)
// {
//     sw::Speech::Error("An unknow error occured ^^'");
//     sw::Speech::Error(error.what());
//     sw::Speech::flush();
// }