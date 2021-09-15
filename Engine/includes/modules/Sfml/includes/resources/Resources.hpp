/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Resources.hpp
*/

#ifndef __SHIPWRECK_RESOURCES_HPP__
#define __SHIPWRECK_RESOURCES_HPP__

#include <string>
#include <unordered_map>
#include <memory>

#include "SW/Resources.hpp"
#include "error/Error.hpp"
#include "resources/resourcesList.hpp"
#include "json_parser/jsnp.hpp"

namespace sfml
{

    class Resources : public sw::AResources
    {

        private:
            std::unordered_map<std::string, std::string> m_neededTextures;
            std::unordered_map<std::string, std::string> m_neededSounds;
            std::unordered_map<std::string, std::string> m_neededFonts;

            void loadTextures();
            void loadSounds();
            void loadFonts();
            void AddResourcesOnScene(jsnp::Token& it);

        public:
            class TexturesMap :
                private std::unordered_map<std::string, std::shared_ptr<sfml::Texture>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<sfml::Texture>>::operator[];
                    friend Resources;

            } textures;

            class SoundsMap :
                private std::unordered_map<std::string, std::shared_ptr<sfml::Sound>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<sfml::Sound>>::operator[];
                    friend Resources;

            } sounds;

            class FontsMap :
            private std::unordered_map<std::string, std::shared_ptr<sfml::Font>>
            {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<sfml::Font>>::operator[];
                    friend Resources;

            } fonts;

            Resources() = default;
            ~Resources();

            void loadResources();
            void unloadResources();

            void loadResourcesFile(const std::string& path);
    }; // class Resources

} // namespace sw

#endif // __SHIPWRECK_RESOURCES_HPP__