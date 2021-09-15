/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** MouseCollider.inl
*/

inline void sfml::MouseCollider::onRightClick()
{
    if (!sw::Engine::activeScene().hasFactory("ScriptFact"))
        return;
    auto& scriptFact = sw::Engine::activeScene().getFactory<sw::ScriptFact>("ScriptFact");
    if (scriptFact.hasComponent(m_entity.name()))
        scriptFact[m_entity.name()].onRightClick();
}

inline void sfml::MouseCollider::onLeftClick()
{
    if (!sw::Engine::activeScene().hasFactory("ScriptFact"))
        return;
    auto& scriptFact = sw::Engine::activeScene().getFactory<sw::ScriptFact>("ScriptFact");
    if (scriptFact.hasComponent(m_entity.name()))
        scriptFact[m_entity.name()].onLeftClick();
}

inline void sfml::MouseCollider::onHover()
{
    if (!sw::Engine::activeScene().hasFactory("ScriptFact"))
        return;
    auto& scriptFact = sw::Engine::activeScene().getFactory<sw::ScriptFact>("ScriptFact");
    if (scriptFact.hasComponent(m_entity.name()))
        scriptFact[m_entity.name()].onHover();
}

inline void sfml::MouseCollider::notOnHover()
{
    if (!sw::Engine::activeScene().hasFactory("ScriptFact"))
        return;
    auto& scriptFact = sw::Engine::activeScene().getFactory<sw::ScriptFact>("ScriptFact");
    if (scriptFact.hasComponent(m_entity.name()))
        scriptFact[m_entity.name()].notOnHover();
}