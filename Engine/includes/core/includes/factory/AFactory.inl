/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AFactory.inl
*/

template<typename ConcretComponent>
inline sw::AFactory<ConcretComponent>::AFactory(const std::string& factoryName, AScene& sceneRef)
    :   m_componentMap{},
        m_componentLayer{},
        m_scene{sceneRef},
        m_isActive{true},
        m_name{factoryName},
        m_isLoad{false}
{
    m_componentLayer.needSort = true;
}

template<typename ConcretComponent>
inline sw::AFactory<ConcretComponent>::~AFactory()
{
    m_componentMap.clear();
    m_componentLayer.clear();
}

template <typename ConcretComponent>
template <typename... Args>
inline ConcretComponent& sw::AFactory<ConcretComponent>::createComponent(const std::string& entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AFactory::createComponent - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end()) {
        it = m_componentMap.try_emplace(entityName, std::make_unique<ConcretComponent>(m_scene.getEntity(entityName), values...)).first;
        m_componentLayer.emplace_front(std::make_pair(0, entityName));
    }
    return (*it->second);
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::deleteComponent(const std::string& entityName)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AFactory::deleteComponent - Entity <" + entityName + "> not found", "4415");
    m_componentMap.erase(entityName);
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::load()
try
{
    if (m_isLoad) {
        sw::Speech::Warning("Factory <" + m_name + "> it was already loaded !", "3420");
        return;
    }

    onLoad();
    if (m_componentLayer.needSort)
        m_componentLayer.sort();
    m_isLoad = true;
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Factory <" + m_name + "> can not be loaded.", "4420");
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::update()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning("Factory <" + m_name + "> can not be update because it was not loaded.", "3430");
        return;
    }

    if (m_componentLayer.needSort)
        m_componentLayer.sort();
    onUpdate();
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Factory <" + m_name + "> can not be updated.", "4430");
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::unload()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning("Factory <" + m_name + "> was alredy unloaded !", "3440");
        return;
    }

    onUnload();
    m_isLoad = false;
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Factory <" + m_name + "> can not be unloaded.", "4440");
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::setLayer(const std::string& entityName, int newLayer)
{
    for (auto& [layer, name] : m_componentLayer)
        if (name == entityName) {
            layer = newLayer;
            break;
        }
    m_componentLayer.needSort = true;
}

template<typename ConcretComponent>
inline int sw::AFactory<ConcretComponent>::getLayer(const std::string& entityName) const
{
    for (auto& [layer, name] : m_componentLayer)
        if (name == entityName)
            return (layer);
    throw sw::Error("sw::AFactory::getLayer - Entity <" + entityName + "> not found", "4415");
}

template <typename T>
requires std::is_base_of<sw::IComponent, T>::value
inline std::ostream& operator<<(std::ostream& os, sw::AFactory<T>& sys)
{
    std::cout << "Display AFactory" << std::endl;
    for (auto& [entityName, obj] : sys.m_componentMap)
        std::cout << "  " << entityName << std::endl;
    std::cout << "<------------>" << std::endl << std::endl;
    return (os);
}

template<typename ConcretComponent>
template<typename RealComponent, typename... Args>
requires std::is_base_of<sw::IComponent, RealComponent>::value
inline ConcretComponent& sw::AFactory<ConcretComponent>::addScript(const std::string &entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AFactory::addScript - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end())
        it = m_componentMap.try_emplace(entityName, std::make_unique<RealComponent>(m_scene.getEntity(entityName), values...)).first;
    return (*it->second);
}

template<typename ConcretComponent>
inline ConcretComponent& sw::AFactory<ConcretComponent>::operator[](const std::string& entityName)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AFactory::operator[] - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end())
        throw sw::Error("sw::AFactory::operator[] - Component for <" + entityName + "> not found", "4416");
    return (*it->second);
}

template <typename ConcretComponent>
inline std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator sw::AFactory<ConcretComponent>::begin()
{
    return (m_componentMap.begin());
}

template <typename ConcretComponent>
inline std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator sw::AFactory<ConcretComponent>::end()
{
    return (m_componentMap.end());
}

template <typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::setActive(bool value)
{
    m_isActive = value;
}

template<typename ConcretComponent>
sw::AScene& sw::AFactory<ConcretComponent>::scene() const
{ return (m_scene); }

template<typename ConcretComponent>
std::string sw::AFactory<ConcretComponent>::name() const
{ return (m_name); }

template <typename ConcretComponent>
inline bool sw::AFactory<ConcretComponent>::isActive() const
{ return (m_isActive); }


template<typename ConcretComponent>
bool sw::AFactory<ConcretComponent>::hasComponent(const std::string& entityName) const
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("sw::AFactory::operator[] - Entity <" + entityName + "> not found", "4415");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end())
        return (false);
    return (true);
}