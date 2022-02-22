/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Module.inl
*/

inline sfml::Module::Module(const std::string& name)
    :   sw::AModule(name)
{}

inline bool sfml::Module::GetKeyDown(sf::Keyboard::Key key)
{
    return (sf::Keyboard::isKeyPressed(key));
}

inline void sfml::Module::draw(const sf::Vertex* vertices, std::size_t vertexCount,
                      sf::PrimitiveType type, const sf::RenderStates& states)
{
    m_rwindow.draw(vertices, vertexCount, type, states);
}

inline void sfml::Module::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
    m_rwindow.draw(drawable, states);
}

inline void sfml::Module::draw(const sf::VertexBuffer& vertexBuffer, const sf::RenderStates& states)
{
    m_rwindow.draw(vertexBuffer, states);
}