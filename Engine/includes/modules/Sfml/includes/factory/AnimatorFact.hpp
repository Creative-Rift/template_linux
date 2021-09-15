/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AnimatorFact.hpp
*/

#ifndef __SHIPWRECK_SFML_ANIMATORFACT_HPP__
#define __SHIPWRECK_SFML_ANIMATORFACT_HPP__

#include "SW/Factory.hpp"
#include "components/Animator.hpp"

namespace sfml
{

    class AnimatorFact :
        public sw::AFactory<Animator>
    {

        public:
            using sw::AFactory<Animator>::AFactory;
            ~AnimatorFact() = default;

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;

    }; // class AnimatorFact

} // namespace sfml

#endif // __SHIPWRECK_SFML_ANIMATORFACT_HPP__