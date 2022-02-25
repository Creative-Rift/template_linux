/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Resources.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_RESOURCES_HPP__
#define __RAYLIB_MODULE_RESOURCES_HPP__

#include <string>
#include <unordered_map>
#include <memory>

#include "SW/Scene.hpp"
#include "SW/errors/Error.hpp"
#include "Texture.hpp"
#include "Font.hpp"
#include "Music.hpp"
#include "Sound.hpp"

namespace sfml
{

    class Resources
        :   public sw::AResources
    {

        private:
            std::unordered_map<std::string, std::string> m_neededTextures;
            std::unordered_map<std::string, std::string> m_neededFonts;
            std::unordered_map<std::string, std::string> m_neededSounds;
            std::unordered_map<std::string, std::string> m_neededMusics;

            void loadTextures();
            void loadFonts();
            void loadSounds();
            void loadMusics();

        public:
            class TexturesMap
                :   private std::unordered_map<std::string, resources::Texture>
            {
                public:
                    using std::unordered_map<std::string, resources::Texture>::unordered_map;
                    using std::unordered_map<std::string, resources::Texture>::begin;
                    using std::unordered_map<std::string, resources::Texture>::end;

                    const resources::Texture& operator[](const std::string& textureName) const;
                    const resources::Texture& get(const std::string& textureName) const;

                friend Resources;
            };

            class FontsMap
                :   private std::unordered_map<std::string, resources::Font>
            {
                public:
                    using std::unordered_map<std::string, resources::Font>::unordered_map;
                    using std::unordered_map<std::string, resources::Font>::begin;
                    using std::unordered_map<std::string, resources::Font>::end;

                    const resources::Font& operator[](const std::string& fontName) const;
                    const resources::Font& get(const std::string& fontName) const;

                friend Resources;
            };

            class SoundsMap
                :   private std::unordered_map<std::string, resources::Sound>
            {
                public:
                    using std::unordered_map<std::string, resources::Sound>::unordered_map;
                    using std::unordered_map<std::string, resources::Sound>::begin;
                    using std::unordered_map<std::string, resources::Sound>::end;

                    const resources::Sound& operator[](const std::string& soundName) const;
                    const resources::Sound& get(const std::string& soundName) const;

                friend Resources;
            };

            class MusicsMap
                :   private std::unordered_map<std::string, resources::Music>
            {
                public:
                    using std::unordered_map<std::string, resources::Music>::unordered_map;
                    using std::unordered_map<std::string, resources::Music>::begin;
                    using std::unordered_map<std::string, resources::Music>::end;

                    const resources::Music& operator[](const std::string& musicName) const;
                    const resources::Music& get(const std::string& musicName) const;

                friend Resources;
            };

            TexturesMap textures;
            FontsMap fonts;
            SoundsMap sounds;
            MusicsMap musics;

            Resources();
            ~Resources() = default;

            void loadResources() override;
            void unloadResources() override;
            void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override;

            const resources::Texture& getTexture(const std::string& textureName) const;
            resources::Texture& getTexture(const std::string& textureName);
            const resources::Font& getFont(const std::string& fontName) const;
            resources::Font& getFont(const std::string& fontName);
            const resources::Sound& getSound(const std::string& soundName) const;
            resources::Sound& getSound(const std::string& soundName);
            const resources::Music& getMusic(const std::string& musicName) const;
            resources::Music& getMusic(const std::string& musicName);

    }; // class Resources

} // namespace sfml

#endif // __RAYLIB_MODULE_RESOURCES_HPP__