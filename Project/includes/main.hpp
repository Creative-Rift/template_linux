/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * main.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include "SW/Scene.hpp"
#include "SF/components/MouseCollider.hpp"
#include "SF/components/BoxCollider.hpp"
#include "SF/components/Sound.hpp"
#include "SF/maths/Rect.hpp"
#include "SF/maths/Vector2.hpp"

class MainScene
    :   public sw::AScene
{

    public:
        using sw::AScene::AScene;
        ~MainScene() = default;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;

        std::string type() const override { return ("MainScene"); }

};

class Button
    :   public sfml::MouseCollider
{

    public:
        Button(sw::Entity& entity, sfml::FloatRect rect)
            :   sw::Component{entity},
                sfml::MouseCollider{entity, rect}
        {}
        ~Button() override = default;

        void onPressed() override {
            m_entity.getComponent<sfml::Sound>("SoundManager").play();
            m_box.setOutlineColor(sfml::Color::Blue);
        }
        void onReleased() override {
            m_box.setOutlineColor(sfml::Color::Green);
        }
        void onHover() override {
            m_box.setOutlineColor(sfml::Color::Green);
        }
        void onNormal() override {
            m_box.setOutlineColor(sfml::Color::White);
        }

};

class Box
    :   public sfml::BoxCollider
{

    public:
        Box(sw::Entity& entity, sfml::FloatRect rect)
            :   sw::Component{entity},
                sfml::BoxCollider{entity, rect}
        {}
        ~Box() = default;

        void onCollision(const BoxCollider& collider) override {
            m_box.setFillColor(sfml::Color::Red);
        }
        void onExitCollision(const BoxCollider& collider) override {
            m_box.setFillColor(sfml::Color{0, 0, 0, 0});
        }

};

#endif // __MAIN_HPP__