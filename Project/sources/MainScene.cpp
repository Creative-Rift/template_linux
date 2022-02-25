/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MainScene.cpp
 *
 * Description:
 * [Change]
 */

#include "SF/managers/MouseColliderManager.hpp"
#include "SF/managers/DrawableManager.hpp"
#include "SF/managers/TransformManager.hpp"
#include "SF/managers/MusicManager.hpp"
#include "SF/managers/SoundManager.hpp"
#include "SF/managers/BoxColliderManager.hpp"
#include "SF/components/RectangleShape.hpp"
#include "SF/components/CircleShape.hpp"
#include "SF/components/Sprite.hpp"
#include "SF/components/AnimatedSprite.hpp"
#include "SF/Event.hpp"

#include "main.hpp"

void MainScene::onLoad()
{
    createEntity("Entity");
    createEntity("Box1");
    createEntity("Box2");
    createEntity("Spr");

    auto& tmanager = createManager<sfml::TransformManager>("TransformManager");
    auto& manager = createManager<sfml::MouseColliderManager>("MouseColliderManager");
    auto& dmanager = createManager<sfml::DrawableManager>("DrawableManager", "TransformManager");
    auto& musicManager = createManager<sfml::MusicManager>("MusicManager");
    auto& soundManager = createManager<sfml::SoundManager>("SoundManager");
    auto& boxManager = createManager<sfml::BoxColliderManager>("BoxColliderManager", "TransformManager");

    manager.createComponent<Button>("Entity", sfml::FloatRect{100, 100, 100, 100})
           .lookAt(sfml::MouseCollider::Button::Left);
    manager.isDebuging = true;

    auto& rect = dmanager.createComponent<sfml::RectangleShape>("Entity", sfml::Vector2f{100, 100});
    rect.setFillColor(sfml::Color::Magenta);
    rect.setOutlineColor(sfml::Color::Red);
    rect.setOrigin(sfml::Vector2f{50, 50});
    rect.setScale(sfml::Vector2f{2, 2});

    tmanager.createComponent("Entity", sfml::Vector2f{200, 200}).setRotation(45);
    tmanager.createComponent("Box1", sfml::Vector2f{0, 0});

    musicManager.createComponent<sfml::Music>("Entity", "Battle");
    soundManager.createComponent<sfml::Sound>("Entity", "Play");

    boxManager.isDebuging = true;
    boxManager.createComponent<Box>("Box1", sfml::FloatRect{0, 0, 100, 100});
    boxManager.createComponent<Box>("Box2", sfml::FloatRect{0, 0, 100, 100});
    boxManager.setLayer("Box1", 2);

    setLayer("BoxColliderManager", 2);

    dmanager.createComponent<sfml::Sprite>("Spr", "Planet").setPosition(400, 400);
}

void MainScene::onUpdate()
{
    auto mpos = sfml::Event::GetMousePosition();
    auto& cpt = getManager<sfml::TransformManager>("TransformManager").getComponent("Box1");

    cpt.setPosition(mpos);
}

void MainScene::onUnload()
{

}