/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** sceneFunction.inl
*/

template <class ConcretScene>
requires std::is_base_of<sw::AScene, ConcretScene>::value
inline ConcretScene& sw::Engine::createScene(const std::string& sceneName)
{
    auto it = m_sceneMap.find(sceneName);

    if (it == m_sceneMap.end()) {
        it = m_sceneMap.emplace(sceneName, std::make_unique<ConcretScene>(sceneName)).first;
        if (m_activeScene.empty())
            m_activeScene = sceneName;
    }
    return (static_cast<ConcretScene&>(*it->second.get()));
}

template <class ConcretScene>
requires std::is_base_of<sw::AScene, ConcretScene>::value
inline ConcretScene& sw::Engine::getScene(const std::string& sceneName)
{
    auto it = m_sceneMap.find(sceneName);

    if (it == m_sceneMap.end())
        throw sw::Error("sw::Engine::getScene - Can't find Scene <" + sceneName + ">", "4113");
    return (static_cast<ConcretScene&>(*it->second.get()));
}

inline sw::AScene& sw::Engine::getScene(const std::string& sceneName)
{
    auto it = m_sceneMap.find(sceneName);

    if (it == m_sceneMap.end())
        throw sw::Error("sw::Engine::getScene - Can't find Scene <" + sceneName + ">", "4113");
    return (*it->second.get());
}

template<class ConcretScene>
requires std::is_base_of<sw::AScene, ConcretScene>::value
ConcretScene& sw::Engine::activeScene()
{
    auto it = m_sceneMap.find(m_activeScene);

    if (it == m_sceneMap.end())
        throw sw::Error("sw::Engine::activeScene - Can't find active Scene <" + m_activeScene + ">", "4113");
    return (static_cast<ConcretScene&>(*it->second.get()));
}

inline sw::AScene& sw::Engine::activeScene()
{
    auto it = m_sceneMap.find(m_activeScene);

    if (it == m_sceneMap.end())
        throw sw::Error("sw::Engine::activeScene - Can't find active Scene <" + m_activeScene + ">", "4113");
    return (*it->second.get());
}

inline void sw::Engine::deleteScene(const std::string& sceneName)
{
    auto it = m_sceneMap.find(sceneName);

    if (it == m_sceneMap.end())
        throw sw::Error("sw::Engine::activeScene - Can't find Scene <" + sceneName + ">", "4113");
    m_sceneMap.erase(sceneName);
    if (m_activeScene == sceneName)
        m_activeScene.clear();
}

inline bool sw::Engine::hasScene(const std::string& sceneName)
{
    auto it = m_sceneMap.find(sceneName);

    if (it == m_sceneMap.end())
        return (false);
    return (true);
}

inline void sw::Engine::setActiveScene(const std::string& name)
{
    auto it = m_sceneMap.find(name);

    if (it == m_sceneMap.end())
        throw sw::Error("ERROR: sw::Engine::setActiveScene - Can't find Scene <" + name + ">", 0);
    deleteScene(m_activeScene);
    m_activeScene = name;
    activeScene().load();
}