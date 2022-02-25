/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** Transformable.cpp
*/

inline void sfml::Transformable::setPosition(float x, float y)
{
    operator*().setPosition(x, y);
}

inline void sfml::Transformable::setPosition(const sfml::Vector2f& position)
{
    operator*().setPosition(position);
}

inline void sfml::Transformable::setRotation(float angle)
{
    operator*().setRotation(angle);
}

inline void sfml::Transformable::setScale(float factorX, float factorY)
{
    operator*().setScale(factorX, factorY);
}

inline void sfml::Transformable::setScale(const sfml::Vector2f& factors)
{
    operator*().setScale(factors);
}

inline void sfml::Transformable::setOrigin(float x, float y)
{
    operator*().setOrigin(x, y);
}

inline void sfml::Transformable::setOrigin(const sfml::Vector2f& origin)
{
    operator*().setOrigin(origin);
}

inline sfml::Vector2f sfml::Transformable::getPosition()
{
    return (operator*().getPosition());
}

inline float sfml::Transformable::getRotation()
{
    return (operator*().getRotation());
}

inline sfml::Vector2f sfml::Transformable::getScale()
{
    return (operator*().getScale());
}

inline sfml::Vector2f sfml::Transformable::getOrigin()
{
    return (operator*().getOrigin());
}

inline void sfml::Transformable::move(float offsetX, float offsetY)
{
    operator*().move(offsetX, offsetY);
}

inline void sfml::Transformable::move(const sfml::Vector2f& offset)
{
    operator*().move(offset.x, offset.y);
}

inline void sfml::Transformable::rotate(float angle)
{
    operator*().rotate(angle);
}

inline void sfml::Transformable::scale(float factorX, float factorY)
{
    operator*().scale(factorX, factorY);
}

inline void sfml::Transformable::scale(const sfml::Vector2f& factor)
{
    operator*().scale(factor.x, factor.y);
}

inline const sf::Transform& sfml::Transformable::getTransform()
{
    return (operator*().getTransform());
}

inline const sf::Transform& sfml::Transformable::getInverseTransform()
{
    return (operator*().getInverseTransform());
}