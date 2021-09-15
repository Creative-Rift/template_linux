/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Module.hpp
*/

#ifndef __SHIPWRECK_SFML_SYSTEM_HPP__
#define __SHIPWRECK_SFML_SYSTEM_HPP__

#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "SW/Module.hpp"
#include "resources/resourcesList.hpp"
#include "resources/Resources.hpp"

namespace sfml
{

    class Module :
        public sw::AModule
    {

        private:
            sf::RenderWindow m_rwindow;
            sf::Event m_event;
            sf::Clock m_clock;
            sf::Vector2f m_mousePos;
            bool m_debugMode;

            void onInitialize() override;
            void onUpdate() override;
            void onTerminate() override;

        public:
            static std::string transformFactName;
            static std::string scriptFactName;
            static std::string mouseColliderFactName;
            static std::string spriteFactName;

            Module(const std::string& name);
            ~Module() = default;

            void initialize() override;
            bool isOk() override;
            void update() override;
            void terminate() override;
            bool isDebuging() override { return (m_debugMode); };
            sf::Clock clock() { return (m_clock); }

            void CloseWindow();
            void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
            void draw(const sf::Vertex* vertices, std::size_t vertexCount,
                      sf::PrimitiveType type, const sf::RenderStates& states = sf::RenderStates::Default);
            void draw(const sf::VertexBuffer& vertexBuffer, const sf::RenderStates& states = sf::RenderStates::Default);

            void checkEvent();
            void updateMousePosition();
            void checkMouseRightClick();
            void checkMouseLeftClick();
            void checkMouseHover();

            static bool GetKeyDown(sf::Keyboard::Key key);

            static std::shared_ptr<sfml::Texture> getTexture(const std::string& textureName);
            static std::shared_ptr<sfml::Sound> getSound(const std::string& soundName);
            static std::shared_ptr<sfml::Font> getFont(const std::string& fontName);
            std::unique_ptr<sw::AResources> createResourceInstance() override;
    }; // class Module

    #include "Module.inl"

} // namespace sw

#endif // __SHIPWRECK_SFML_SYSTEM_HPP__