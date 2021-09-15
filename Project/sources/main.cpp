/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** main.cpp
*/

#include "engine/Engine.hpp"

int main()
try
{
    sw::Engine::initialize();
    sw::Speech::flush();
    sw::Engine::update();
    sw::Speech::flush();
    sw::Engine::terminate();
    sw::Speech::flush();
    return (0);
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    sw::Speech::flush();
}
catch (const std::exception& e)
{
    sw::Speech::Error(e.what());
    sw::Speech::flush();
}