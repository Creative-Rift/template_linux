/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** factoryFunction.inl
*/

template<typename ConcretFactory>
requires std::is_base_of<sw::IFactory, ConcretFactory>::value
inline ConcretFactory& sw::AScene::createFactory(const std::string& factoryName)
{
    auto it = m_factoryMap.find(factoryName);

    if (it == m_factoryMap.end()) {
        it = m_factoryMap.emplace(factoryName, std::make_unique<ConcretFactory>(factoryName, *this)).first;
        m_factoryLayer.emplace_front(std::make_pair(0, factoryName));
    }
    return (static_cast<ConcretFactory&>(*it->second.get()));
}

template<typename ConcretFactory>
requires std::is_base_of<sw::IFactory, ConcretFactory>::value
inline ConcretFactory& sw::AScene::getFactory(const std::string& factoryName)
{
    auto it = m_factoryMap.find(factoryName);

    if (it == m_factoryMap.end())
        throw sw::Error("sw::Scene::getFactory - Scene <" + m_name + "> can't find Factory <" + factoryName + ">", "4314");
    return (static_cast<ConcretFactory&>(*it->second.get()));
}

inline bool sw::AScene::hasFactory(const std::string& factoryName)
{
    if (m_factoryMap.find(factoryName) == m_factoryMap.end())
        return (false);
    return (true);
}

inline void sw::AScene::deleteFactory(const std::string& factoryName)
{
    for (auto& [layer, name] : m_factoryLayer)
        if (name == factoryName) {
            m_factoryLayer.remove(std::pair<int, std::string>(layer, name));
            m_factoryMap.erase(factoryName);
            return;
        }
}

inline void sw::AScene::setLayer(const std::string& factoryName, int newLayer)
{
    if (m_factoryMap.find(factoryName) == m_factoryMap.end())
        throw sw::Error("sw::Scene::setLayer - Scene <" + m_name + "> can't find Factory <" + factoryName + ">", "4314");
    for (auto& [layer, name] : m_factoryLayer)
        if (name == factoryName)
            layer = newLayer;
    m_factoryLayer.needSort = true;
}


inline int sw::AScene::getLayer(std::string factoryName) const
{
    for (auto pair : m_factoryLayer)
        if (pair.second == factoryName) {
            return (pair.first);
        }
    throw sw::Error("sw::Scene::getLayer - Scene <" + m_name + "> can't find Factory <" + factoryName + ">", "4314");
}