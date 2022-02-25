/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Module.hpp
*/

#ifndef __SHIPWRECK_SFML_SYSTEM_HPP__
#define __SHIPWRECK_SFML_SYSTEM_HPP__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

#include "SW/Module.hpp"
#include "concept.hpp"
#include "resources/Resources.hpp"

namespace sfml
{

    enum WindowStyle {
        None       = 0,
        Titlebar   = 1 << 0,
        Resize     = 1 << 1,
        Close      = 1 << 2,
        Fullscreen = 1 << 3,
        Default = Titlebar | Resize | Close
    };

    class Module :
        public sw::AModule
    {

        private:
            const std::string m_titleScreen;
            const WindowStyle m_wstyle;

            sf::VideoMode m_vmode;
            sf::RenderWindow m_rwindow;
            std::map<std::size_t, sf::RenderTexture> m_renderLayer;
            bool m_isDebuging;

        public:
            Module(const std::string& title = "Sfml", unsigned width = 800, unsigned height = 600, WindowStyle style = WindowStyle::Default);
            ~Module() = default;

            void initialize() override;
            bool isOk() override;
            void update() override;
            void terminate() override;

            void setDebug(bool value) { m_isDebuging = value; }
            bool isDebuging() const { return (m_isDebuging); }

            void CreateWindow(const std::string& title, unsigned width, unsigned height, WindowStyle style);
            void ClearWindow();
            void DisplayWindow();
            void CloseWindow();
            sf::RenderWindow& Window();

            void draw(const sfml::Drawable& drawable, const std::string& tfmManager = "");

            void loadResourcesFile(const std::string& path) override;
            std::unique_ptr<sw::AResources> createResourceInstance() override;
            void createRenderLayer(std::size_t first, std::size_t last = 0);

            std::string type() const override { return ("SfmlModule"); }

    }; // class Module

} // namespace sw

#endif // __SHIPWRECK_SFML_SYSTEM_HPP__