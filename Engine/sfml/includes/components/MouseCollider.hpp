/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MouseCollider.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SFML_MODULE_MOUSECOLLIDER_HPP__
#define __SFML_MODULE_MOUSECOLLIDER_HPP__

#include <SFML/Graphics/RectangleShape.hpp>
#include <set>

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

#include "Drawable/Drawable.hpp"
#include "Transformable/Transformable.hpp"
#include "../Event.hpp"

namespace sfml
{

    class MouseCollider :
        public sfml::Drawable,
        public sfml::Transformable
    {

        public:
            enum State { None, Hover, Click };
            using Button = sfml::Event::Mouse::Button;

        protected:
            State m_state;
            sw::Chrono m_clock;
            sf::RectangleShape m_box;
            sw::Reference<Button> m_button;

        public:
            MouseCollider(sw::Entity& entity, sw::FloatRect boxValue);
            MouseCollider(sw::Entity& entity, const sw::Vector2f& pos, const sw::Vector2f& size);
            virtual ~MouseCollider() = default;

            State state() const { return (m_state); }
            State state(State value) { m_state = value; return (m_state); }
            void startClock() { m_clock.start(); }
            double clock() { return (m_clock.getElapsedTime()); }

            bool checkCollision(const sw::Vector2i& point, const std::string& tfmManager = "");

            void lookAt(Button button);
            void stopLookAt(Button button);
            bool lookingAt();
            bool lookingAt(Button button);
            Button button();

            virtual void onPressed() {};
            virtual void onReleased() {};
            virtual void onHover() {};
            virtual void onNormal() {};

            const sf::Drawable& operator&() const override;
            sf::Transformable& operator*() override;
            virtual std::string type() const override { return ("MouseCollider"); }

    }; // class MouseCollider

} // namespace sfml

#endif // __SFML_MODULE_MOUSECOLLIDER_HPP__