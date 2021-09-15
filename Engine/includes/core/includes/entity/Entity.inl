/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Entity.inl
*/

inline sw::Entity::Entity(const std::string& entityName, AScene& sceneRef)
    :   m_isActive(true),
        m_name(entityName),
        m_scene(sceneRef)
{}

inline sw::Entity::Entity(const std::string& entityName, AScene& sceneRef, bool isActive)
    :   m_isActive(isActive),
        m_name(entityName),
        m_scene(sceneRef)
{}

inline std::string sw::Entity::name()
{ return (m_name); }

inline sw::AScene& sw::Entity::scene()
{ return (m_scene); }

inline bool sw::Entity::isActive() const
{ return (m_isActive); }

inline void sw::Entity::setActive(bool value)
{
    m_isActive = value;
}

inline void sw::Entity::addChild(const std::string& entityName)
{
    auto& entity = m_scene.getEntity(entityName);

    entity.m_parent = *this;
    m_childrenMap.insert({entity.m_name, entity});
}

template<typename ConcretComponent, typename... Args>
requires std::is_base_of<sw::IComponent, ConcretComponent>::value
inline ConcretComponent& sw::Entity::createComponent(const std::string& factoryName, Args... values)
{
    return (m_scene.getFactory<sw::AFactory<ConcretComponent>>(factoryName).createComponent(m_name, values...));
}

template <typename ConcretComponent>
requires std::is_base_of<sw::IComponent, ConcretComponent>::value
inline ConcretComponent& sw::Entity::getComponent(const std::string& factoryName)
{
    try {
        return (m_scene.getFactory<sw::AFactory<ConcretComponent>>(factoryName)[m_name]);
    }
    catch (sw::Error& err) {
        throw sw::Error("sw::Entity::getComponent - Component for <" + m_name + "> not found in <" + factoryName + ">", "4416");
    }
}