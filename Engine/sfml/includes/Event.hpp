/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Input.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <SFML/Window/Event.hpp>
#include <set>

#include "maths/Vector2.hpp"

namespace sfml
{

    class Event
    {

        public:
            using Keyboard = sf::Keyboard;
            using Mouse = sf::Mouse;
            using Joystick = sf::Joystick;

        private:
            static sf::Event m_event;
            static std::set<Keyboard::Key> m_keyPressed;
            static std::set<Mouse::Button> m_buttonPressed;
            static std::set<Keyboard::Key> m_keyReleased;
            static std::set<Mouse::Button> m_buttonReleased;

        public:
            Event() = delete;
            Event(Event&&) = delete;
            Event(const Event&) = delete;
            ~Event() = default;

            // Detect if a mouse button is being pressed
            static bool GetKeyDown(Keyboard::Key key);

            // Detect if a mouse button has been pressed once
            static bool GetKeyPressed(Keyboard::Key key);

            // Detect if a mouse button is NOT being pressed
            static bool GetKeyUp(Keyboard::Key key);

            // Detect if a mouse button has been released once
            static bool GetKeyReleased(Keyboard::Key key);

            static bool IsMouseButtonPressed(Mouse::Button key);
            static bool IsMouseButtonDown(Mouse::Button key);
            static bool IsMouseButtonReleased(Mouse::Button key);
            static bool IsMouseButtonUp(Mouse::Button key);

            // static float GetGamepadAxis(int padNbr, int axisNbr);
            // static std::string GetGamePadName(int padNbr);
            // static bool IsGamePadButtonDown(int padNbr, int key);
            // static bool IsGamePadButtonPressed(int padNbr, int key);
            // static bool IsGamePadButtonReleased(int padNbr, int key);
            // static bool IsGamePadButtonUp(int padNbr, int key);


            // static int GetMouseX();
            // static int GetMouseY();

            static void checkEvent();
            static sfml::Vector2i GetMousePosition();

    }; // class Input

} // namespace sfml

#endif // __EVENT_HPP__