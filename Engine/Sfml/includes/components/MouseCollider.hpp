/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** MouseCollider.hpp
*/

#ifndef __SFML_MOUSECOLLIDER_HPP__
#define __SFML_MOUSECOLLIDER_HPP__

#include "SW/Components.hpp"
#include "SW/Factory.hpp"

namespace sfml
{

    class MouseCollider :
        public sw::Component
    {

        public:
            sf::FloatRect box;

            enum State
            {
                NONE,
                HOVER,
                LCLICK,
                RCLICK
            } state;

            MouseCollider(sw::Entity& entity, sf::FloatRect boxValue)
                : sw::Component(entity), box(boxValue), state(State::NONE)
            {}
            ~MouseCollider() = default;

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user use right click on them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onRightClick();

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user use left click on them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onLeftClick();

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user move the mouse on them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onHover();

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user move the mouse outside of them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void notOnHover();

    }; // class MouseCollider

    #include "MouseCollider.inl"

} // namespace sfml

#endif // __SFML_MOUSECOLLIDER_HPP__