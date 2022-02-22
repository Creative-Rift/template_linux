/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** TransformFact.hpp
*/

#ifndef __SHIPWRECK_SFML_TRANSFORMFACT_HPP__
#define __SHIPWRECK_SFML_TRANSFORMFACT_HPP__

#include "SW/Factory.hpp"
#include "components/Transform.hpp"

namespace sfml
{

    class TransformFact :
        public sw::AFactory<Transform>
    {

        public:
            using sw::AFactory<Transform>::AFactory;
            ~TransformFact() override = default;

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;

    }; // class TransformFact

} // namespace sfml

#endif // __SHIPWRECK_SFML_TRANSFORMFACT_HPP__