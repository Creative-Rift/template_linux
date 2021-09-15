/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** moduleFunction.inl
*/

template <class ConcretModule>
requires std::is_base_of<sw::AModule, ConcretModule>::value
inline ConcretModule& sw::Engine::createModule(const std::string& moduleName)
{
    auto it = m_moduleMap.find(moduleName);

    if (it == m_moduleMap.end()) {
        it = m_moduleMap.emplace(moduleName, std::make_unique<ConcretModule>(moduleName)).first;
        if (m_activeModule.empty())
            m_activeModule = moduleName;
    }
    return (static_cast<ConcretModule&>(*it->second.get()));
}

template <class ConcretModule>
requires std::is_base_of<sw::AModule, ConcretModule>::value
inline ConcretModule& sw::Engine::getModule(const std::string& moduleName)
{
    auto it = m_moduleMap.find(moduleName);

    if (it == m_moduleMap.end())
        throw sw::Error("sw::Engine::getModule - Can't find Module <" + moduleName + ">", "4112");
    return (static_cast<ConcretModule&>(*it->second.get()));
}

inline sw::AModule& sw::Engine::getModule(const std::string& moduleName)
{
    auto it = m_moduleMap.find(moduleName);

    if (it == m_moduleMap.end())
        throw sw::Error("sw::Engine::getModule - Can't find Module <" + moduleName + ">", "4112");
    return (*it->second.get());
}

template<class ConcretModule>
requires std::is_base_of<sw::AModule, ConcretModule>::value
ConcretModule& sw::Engine::activeModule()
{
    auto it = m_moduleMap.find(m_activeModule);

    if (it == m_moduleMap.end())
        throw sw::Error("sw::Engine::activeModule - Can't find Module <" + m_activeModule + ">", "4112");
    return (static_cast<ConcretModule&>(*it->second.get()));
}

inline sw::AModule& sw::Engine::activeModule()
{
    auto it = m_moduleMap.find(m_activeModule);

    if (it == m_moduleMap.end())
        throw sw::Error("sw::Engine::activeModule - Can't find Module <" + m_activeModule + ">", "4112");
    return (*it->second.get());
}

inline void sw::Engine::deleteModule(const std::string& moduleName)
{
    m_moduleMap[moduleName]->terminate();
    m_moduleMap.erase(moduleName);
    m_activeModule.clear();
}

inline bool sw::Engine::hasModule(const std::string& moduleName)
{
    auto it = m_moduleMap.find(moduleName);

    if (it == m_moduleMap.end())
        return (false);
    return (true);
}