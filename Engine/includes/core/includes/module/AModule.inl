/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AModule.inl
*/

inline sw::AModule::AModule(const std::string& name)
    :   m_name(name),
        m_isLoad(false)
{}

inline std::string sw::AModule::name() const
{
    return (m_name);
}
