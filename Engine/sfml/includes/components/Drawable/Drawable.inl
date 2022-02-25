/*
** EPITECH PROJECT, 2021
** Epitech Years 3
** File description:
** Drawable.inl
*/

inline sfml::Drawable::Drawable(sw::Entity& entity)
    :   sw::Component{entity},
        m_layer{0}
{}

inline void sfml::Drawable::setLayer(std::size_t value)
{
    m_layer = value;
}

inline std::size_t sfml::Drawable::getLayer() const
{
    return (m_layer);
}