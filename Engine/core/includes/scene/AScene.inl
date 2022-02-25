/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * AScene.inl
 *
 * Description:
 * Implementation of Scene functions
 */

inline sw::AResources& sw::AScene::resources()
{
    if (m_resources == nullptr)
        throw sw::Error(std::string(FUNCTION) + " - Resource of Scene <" + m_name + "> has not be created.", "4317");
    return (*m_resources);
}

template <sw::ConcreteResource Resources>
inline Resources& sw::AScene::resources()
{
    if (m_resources == nullptr)
        throw sw::Error(std::string(FUNCTION) + " - Resource of Scene <" + m_name + "> has not be created.", "4317");
    return (static_cast<Resources&>(*m_resources));
}

inline sw::EventManager& sw::AScene::eventManager()
{ return (m_eventManager); }

inline std::string sw::AScene::name() const
{ return (m_name); }

inline bool sw::AScene::isLoad() const
{ return (m_isLoad); }

inline std::string sw::AScene::type() const
{ return ("AScene"); }

inline std::ostream& operator<<(std::ostream& os, const sw::AScene& scene)
{
    os  << "Scene '" << scene.name() << "'\n"
        << "\tType : '" << scene.type() << "'\n"
        << "\tIs Load : " << std::boolalpha << scene.isLoad() << "\n"
        << "\tEntities count : " << scene.entitiesCount() << "\n"
        << "\tManagers count : " << scene.managersCount() << "\n";
    return (os);
}