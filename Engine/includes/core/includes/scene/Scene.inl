/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Scene.inl
*/

inline sw::AScene::~AScene()
{}

inline void sw::AScene::load()
try
{
    if (m_isLoad) {
        sw::Speech::Warning("Scene <" + m_name + "> is already load !", "3320");
        return;
    }
    sw::Speech::Info("Loading Scene <" + m_name + "> ...", "1320");

    m_resources->loadResources();
    onLoad();
    m_factoryLayer.sort();
    for (auto& [_, factoryName] : m_factoryLayer)
        m_factoryMap[factoryName]->load();
    m_isLoad = true;

    sw::Speech::Info("Scene <" + m_name + "> was successfully load !", "1320");
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Scene <" + m_name + "> can not be loaded.", "4340");
}

inline void sw::AScene::update()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning("Scene <" + m_name + "> can not be update because it was not load !", "3330");
        return;
    }
    sw::Speech::Info("Updating Scene <" + m_name + "> ...", "1330");

    if (m_factoryLayer.needSort)
        m_factoryLayer.sort();
    onUpdate();
    for (auto& [_, factoryName] : m_factoryLayer) {
        try {
            m_factoryMap[factoryName]->update();
        }
        catch (sw::Error& error) {
            sw::Speech::Error(error.getMessage(), error.getCode());
        }
    }

    sw::Speech::Info("Scene <" + m_name + "> was successfully updated !", "1330");
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Scene <" + m_name + "> can not be updated.", "4340");
}

inline void sw::AScene::unload()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning("Scene <" + m_name + "> is already unload !", "3340");
        return;
    }
    sw::Speech::Info("Unloading Scene <" + m_name + "> ...", "1340");

    onUnload();
    m_resources->unloadResources();
    for (auto& [_, fact] : m_factoryMap)
        fact->unload();
    m_factoryMap.clear();
    m_entityMap.clear();
    m_factoryLayer.clear();
    m_deleteEntity.clear();
    m_isLoad = false;

    sw::Speech::Info("Scene <" + m_name + "> was successfully unload !", "2340");
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error("Scene <" + m_name + "> can not be unloaded.", "4340");
}

inline std::unique_ptr<AResources>& sw::AScene::resources()
{
    return (m_resources);
}