/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Script.inl
*/

inline sw::Script::Script(sw::Script&& sc)
    : sw::Component(sc.entity())
{}

inline sw::Script::Script(sw::Script const& sc)
    : sw::Component(sc.entity())
{}

inline sw::Script::Script(sw::Entity& entityRef)
    : sw::Component(entityRef)
{}
