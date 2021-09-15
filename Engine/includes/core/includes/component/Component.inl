/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Component.inl
*/

inline sw::Component::Component(sw::Entity& entityRef)
    :   m_isActive(true),
        m_entity(entityRef)
{}

inline std::ostream& operator<<(std::ostream& os, const sw::Component& obj)
{
    os << obj.entity().name();
    return (os);
}

inline void sw::Component::setActive(bool value)
{
    m_isActive = value;
}

inline bool sw::Component::isActive() const
{
    return (m_isActive);
}

inline sw::Entity& sw::Component::entity() const
{
    return (m_entity);
}