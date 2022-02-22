/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** TextFact.hpp
*/

#ifndef __SHIPWRECK_SFML_TEXTFACT_HPP__
#define __SHIPWRECK_SFML_TEXTFACT_HPP__

#include "SW/Factory.hpp"
#include "components/Text.hpp"

namespace sfml
{

    class TextFact :
        public sw::AFactory<Text>
    {

        public:
            using sw::AFactory<Text>::AFactory;
            ~TextFact() override = default;

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;

    }; // class TextFact

} // namespace sfml

#endif // __SHIPWRECK_SFML_TEXTFACT_HPP__