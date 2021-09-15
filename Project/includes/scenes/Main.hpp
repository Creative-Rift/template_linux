/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.h
** Description: [CHANGE]
*/

#ifndef MAIN_HPP
#define MAIN_HPP

#include "SW/Scene.hpp"

class Main :
        public sw::AScene
{

    public:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;

};

#endif //MAIN_HPP
