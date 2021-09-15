/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** MouseColliderFact.hpp
*/

#ifndef __SFML_MOUSECOLLIDERFACT_HPP__
#define __SFML_MOUSECOLLIDERFACT_HPP__

#include "SW/Factory.hpp"
#include "components/MouseCollider.hpp"

namespace sfml
{

    class MouseColliderFact :
        public sw::AFactory<MouseCollider>
    {

        public:
            using sw::AFactory<MouseCollider>::AFactory;
            ~MouseColliderFact() = default;

            void onLoad() override {};
            void onUpdate() override;
            void onUnload() override {};

    }; // class MouseColliderFact

} // namespace sfml

#endif // __SFML_MOUSECOLLIDERFACT_HPP__