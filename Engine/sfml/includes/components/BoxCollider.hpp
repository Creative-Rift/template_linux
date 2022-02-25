/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * BoxCollider.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __BOXCOLLIDER_HPP__
#define __BOXCOLLIDER_HPP__

#include "Drawable/Drawable.hpp"
#include "Transformable/Transformable.hpp"

#include "../maths/Rect.hpp"

namespace sfml
{

    class BoxCollider
        :   public sfml::Drawable,
            public sfml::Transformable
    {

        protected:
            sf::RectangleShape m_box;
            std::unordered_map<std::string, std::reference_wrapper<BoxCollider>> m_collidingObjects;

        public:
            BoxCollider(sw::Entity& entity, sfml::FloatRect boxValue);
            BoxCollider(sw::Entity& entity, const sfml::Vector2f& pos, const sfml::Vector2f& size);
            virtual ~BoxCollider() = default;

            bool isColliding() const;
            bool checkCollision(const BoxCollider& other, const std::string& tfmManager = "");

            bool isCollidingWith(const std::string& entity);
            void addCollidingObject(BoxCollider& collider);
            void removeCollidingObject(const std::string& entity);
            void clearCollidingObject();

            virtual void onCollision(const BoxCollider& collider) {};
            virtual void onExitCollision(const BoxCollider& collider) {};

            const sf::Drawable& operator&() const override;
            sf::Transformable& operator*() override;
            virtual std::string type() const override { return ("BoxCollider"); }


    }; // class BoxCollider

} // namespace sfml

#endif // __BOXCOLLIDER_HPP__