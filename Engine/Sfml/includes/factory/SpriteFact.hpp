/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** SpriteFact.hpp
*/

#ifndef __SHIPWRECK_SFML_SPRITEFACT_HPP__
#define __SHIPWRECK_SFML_SPRITEFACT_HPP__

#include "SW/Factory.hpp"
#include "components/Sprite.hpp"

namespace sfml
{

    class SpriteFact :
        public sw::AFactory<Sprite>
    {

        public:
            using sw::AFactory<Sprite>::AFactory;
            ~SpriteFact() = default;

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;

    }; // class SpriteFact

} // namespace sfml

#endif // __SHIPWRECK_SFML_SPRITEFACT_HPP__