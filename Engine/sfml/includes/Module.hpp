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
#include "maths/Vector2.hpp"

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
            sf::Image m_logo;
            mutable sfml::Vector2u m_size;
            sf::RenderWindow m_rwindow;
            std::map<std::size_t, sf::RenderTexture> m_renderLayer;

        protected:
            bool m_isDebuging;

        public:
            Module();
            ~Module() = default;

            virtual void onInitialize() {};
            virtual void onUpdate() {};
            virtual void onTerminate() {};

            void setDebug(bool value) { m_isDebuging = value; }
            bool isDebuging() const { return (m_isDebuging); }
            void loadResourcesFile(const std::string& path) override;

            void CreateWindow(const std::string& title, unsigned width, unsigned height, WindowStyle style);
            void ClearWindow();
            void DisplayWindow();
            void CloseWindow();

            void draw(const Drawable& drawable, const std::string& tfmManager = "");
            void createRenderLayer(std::size_t first, std::size_t last = 0);

            bool setActive(bool active = true);
            bool isOpen() const;

            Vector2i getPosition() const;
            void setPosition(const Vector2i& position);
            Vector2u getSize() const;
            void setSize(const Vector2u& size);

            void setTitle(const std::string& title);
            void setIcon(const std::string& textureName);
            void setVisible(bool visible);
            void setVerticalSyncEnabled(bool enabled);
            void setMouseCursorVisible(bool visible);
            void setMouseCursorGrabbed(bool grabbed);
            void setFramerateLimit(unsigned int limit);
            void requestFocus();
            bool hasFocus() const;

            void initialize() override;
            bool isOk() override;
            void update() override;
            void terminate() override;
            std::unique_ptr<sw::AResources> createResourceInstance() override;

            sf::RenderWindow& _Window();
            void _Resized();

            std::string type() const override { return ("SfmlModule"); }

    }; // class Module

} // namespace sw

#endif // __SHIPWRECK_SFML_SYSTEM_HPP__