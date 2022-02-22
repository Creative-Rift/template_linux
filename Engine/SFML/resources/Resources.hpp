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
                :   private std::unordered_map<std::string, Texture>
            {
                public:
                    using std::unordered_map<std::string, Texture>::begin;
                    using std::unordered_map<std::string, Texture>::end;

                    const Texture& operator[](const std::string& textureName) const;
                    const Texture& get(const std::string& textureName) const;

                friend Resources;
            };

            class FontsMap
                :   private std::unordered_map<std::string, Font>
            {
                public:
                    using std::unordered_map<std::string, Font>::begin;
                    using std::unordered_map<std::string, Font>::end;

                    const Font& operator[](const std::string& textureName) const;
                    const Font& get(const std::string& textureName) const;

                friend Resources;
            };

            class SoundsMap
                :   private std::unordered_map<std::string, Sound>
            {
                public:
                    using std::unordered_map<std::string, Sound>::begin;
                    using std::unordered_map<std::string, Sound>::end;

                    const Sound& operator[](const std::string& textureName) const;
                    const Sound& get(const std::string& textureName) const;

                friend Resources;
            };

            class MusicsMap
                :   private std::unordered_map<std::string, Music>
            {
                public:
                    using std::unordered_map<std::string, Music>::begin;
                    using std::unordered_map<std::string, Music>::end;

                    const Music& operator[](const std::string& textureName) const;
                    const Music& get(const std::string& textureName) const;

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
            //void loadResourcesFile(const std::string& path) override;
            void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override;

            const Texture& getTexture(const std::string& textureName) const;
            const Font& getFont(const std::string& fontName) const;
            const Sound& getSound(const std::string& soundName) const;
            const Music& getMusic(const std::string& musicName) const;

    }; // class Resources

} // namespace sfml

#endif // __RAYLIB_MODULE_RESOURCES_HPP__