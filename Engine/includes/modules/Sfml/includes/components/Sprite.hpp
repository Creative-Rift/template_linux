/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Sprite.hpp
*/

#ifndef __SHIPWRECK_SFML_SPRITE_HPP__
#define __SHIPWRECK_SFML_SPRITE_HPP__

#include <SFML/Graphics.hpp>

#include "SW/Components.hpp"

namespace sfml
{

    class Sprite :
        public sw::Component
    {

        private:
            sf::VertexArray m_vertexArray;
            sf::Texture m_texture;
            std::string m_textureName;
            sf::Color m_color;
            sf::FloatRect m_rect;
            bool m_invertedX;
            bool m_invertedY;

        public:
            //Sprite() = delete;
            //Sprite(Sprite const&) = delete;
            //Sprite(Sprite&&) = delete;
            //Sprite& operator=(Sprite const&) = delete;
            //Sprite& operator=(Sprite&&) = delete;
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            Sprite(sw::Entity& entityRef);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default destructor
            ////////////////////////////////////////////////////////////////////////////
            ~Sprite() = default;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Get the current texture associated with the sprite
            ///
            /// \return reference to the texture
            ////////////////////////////////////////////////////////////////////////////
            const sf::Texture& texture() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Get the vertex array (this array compose the displayed sprite)
            ///
            /// \return A copy of vertex array
            ////////////////////////////////////////////////////////////////////////////
            sf::VertexArray getVertexArray() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the displayed texture
            ///
            /// \param texture
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setTexture(std::string name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a rect displayed
            ///
            /// \param rect
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setTextureRect(sf::FloatRect rect);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a color (this color is multiplied with the texture)
            ///
            /// \param color
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setColor(const sf::Color &color);

            void invertX(bool invert);
            void invertY(bool invert);

            bool isInvertX() const;
            bool isInvertY() const;

            void updateInvert();

            friend void defineRect(Sprite& sp);

    }; // class Sprite

    void defineRect(Sprite& sp);

} // namespace sfml

#endif // __SHIPWRECK_SFML_SPRITE_HPP__