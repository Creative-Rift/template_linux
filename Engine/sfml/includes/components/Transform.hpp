/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** Transform.hpp
*/

#ifndef __SHIPWRECK_SFML_TRANSFORM_HPP__
#define __SHIPWRECK_SFML_TRANSFORM_HPP__

#include <SFML/Graphics/Transform.hpp>
#include <cmath>

#include "SW/Component.hpp"
#include "SW/utils/Matrix.hpp"
#include "SW/utils/Vector2.hpp"

namespace sfml
{

    class Transform :
        public sw::Component
    {

        private:
            sw::Vector2f m_position;
            sw::Vector2f m_scale;
            float m_rotation;

            mutable sw::Matrixf m_matrix;
            mutable sf::Transform m_sfTransform;
            mutable bool m_need_update;

            void needUpdate() {
                m_need_update = true;
            }
            void notNeedUpdate() {
                m_need_update = false;
            }

            ///////////////////////////////////////////////////////////////////
            ///
            /// Check if the Matrix need to be update.
            //
            bool checkUpdate() const;
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Update the matrix.
            ///
            /// @warning The const is just to can use it in get method,
            /// It's modify m_matrix variable.
            ///
            /// Thanks to this, we can reduce the calculations to what
            /// is strictly necessary.
            //
            void updateMatrix() const;
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Update the sfTransform.
            ///
            /// @warning The const is just to can use it in get method,
            /// It's modify m_sfTransform variable.
            ///
            /// Thanks to this, we can reduce the calculations to what
            /// is strictly necessary.
            //
            void updateSfTransform() const;
            //

        public:
            ///////////////////////////////////////////////////////////////////
            ///
            /// Initialize a Transform Component attached to the given Entity.
            ///
            /// @param engine The Engine data.
            /// @param entity The Entity to wich the Transform Component will
            /// be attached.
            ///
            Transform(sw::Entity& entityRef, const sw::Vector2f& position = {0, 0}, const sw::Vector2f& scale = {1, 1}, float rotation = 0);
            ///
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Set the position of a Transform Component.
            /// The default position of a Transform Component is (0, 0).
            ///
            /// @warning This function overwrites the actual position.
            /// @see move() to add to the current position.
            ///
            /// @param position New position.
            //
            void setPosition(const sw::Vector2f& position);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Set the position of a Transform Component.
            /// The default position of a Transform Component is (0, 0).
            ///
            /// @warning This function overwrites the actual position.
            /// @see move() to add to the current position.
            ///
            /// @param x X coordinate of the new position.
            /// @param y Y coordinate of the new position.
            //
            void setPosition(float x, float y);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Move a Transform Component
            ///
            /// @warning This function adds to the current position.
            /// @see setPosition to overwrite the actual position.
            ///
            /// @param offset Add to the actual position of
            /// the Transform Component.
            //
            void move(const sw::Vector2f& position);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Move a Transform Component.
            ///
            /// @warning This function adds to the current position.
            /// @see setPosition to overwrite the actual position.
            ///
            /// @param x X offset.
            /// @param y Y offset.
            //
            void move(float x, float y);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Get the position of a Transform Component.
            //
            const sw::Vector2f& getPosition() const;
            //

            ///////////////////////////////////////////////////////////////////
            ///
            /// Set the scalation of a Transform Component.
            /// The default scalation of a Transform Component is (1, 1).
            ///
            /// @warning This function overwrites the actual scalation.
            /// @see scale() to add to the current scalation.
            ///
            /// @param scale New scalation.
            //
            void setScale(const sw::Vector2f& scale);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Set the scalation of a Transform Component.
            /// The default scalation of a Transform Component is (1, 1).
            ///
            /// @warning This function overwrites the actual scalation.
            /// @see scale() to add to the current scalation.
            ///
            /// @param x New horizontal scale factor.
            /// @param y New vertical scale factor.
            //
            void setScale(float x, float y);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Scale the Transform Component.
            ///
            /// @warning This function multiplies the current scale of
            /// the Transform Component.
            /// @see setScale() to overwrite the actual scalation.
            ///
            /// @param scale Scale factor.
            //
            void scale(const sw::Vector2f& scale);
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Scale the Transform Component.
            ///
            /// @warning This function multiplies the current scale of
            /// the Transform Component.
            /// @see setScale() to overwrite the actual scalation.
            ///
            /// @param x Horizontal scale factor.
            /// @param y Vertical scale factor.
            //
            void scale(float x, float y);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Get the scalation of a Transform Component.
            //
            const sw::Vector2f& getScale() const;
            //

            ///////////////////////////////////////////////////////////////////
            ///
            /// Set the orientation of the Transform Component.
            /// The default rotation of a Transform Component is 0.
            ///
            /// @warning This function completely overwrites
            /// the previous rotation.
            /// @see rotate() to add an angle on the previous rotation.
            //
            void setRotation(float rotation);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Rotate the Transform Component.
            ///
            /// @warning This function adds to the current rotation of
            /// the Transform Component.
            /// @see setRotation() to overwrite the actual orientation.
            //
            void rotate(float angle);
            //
            ///////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////////////////////
            ///
            /// Get the orientation of the Transform Component in degree.
            //
            float getRotation() const;
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Get the orientation of the Transform Component in radiant.
            //
            float getRadianRotation() const;
            //

            ///////////////////////////////////////////////////////////////////
            ///
            /// Get the matrix of the Transform Component.
            //
            const sw::Matrixf& getMatrix() const;
            //

            ///////////////////////////////////////////////////////////////////
            ///
            /// Get the sfTransform of the Transform Component.
            //
            const sf::Transform& getTransform() const;
            //

            ///////////////////////////////////////////////////////////////////
            ///
            /// Return the position of the given point, transform by
            /// the Transform Component.
            ///
            /// @param point The point to transform.
            //
            const sw::Vector2f getTransformPoint(const sw::Vector2f& point) const;
            //
            ///////////////////////////////////////////////////////////////////
            ///
            /// Return the position of the given point, transform by
            /// the Transform Component.
            ///
            /// @param x X coordinate of the point to transform.
            /// @param y Y coordinate of the point to transform.
            //
            const sw::Vector2f getTransformPoint(float x, float y) const;
            //

    }; // class Transform

} // namespace sfml

#endif // __SHIPWRECK_SFML_TRANSFORM_HPP__