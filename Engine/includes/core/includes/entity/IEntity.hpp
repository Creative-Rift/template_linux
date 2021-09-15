/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IEntity.hpp
*/

#ifndef __SHIPWRECK_IENTITY_HPP__
#define __SHIPWRECK_IENTITY_HPP__

namespace sw
{

    class AScene;

    class IEntity
    {

        public:
            virtual ~IEntity() = default;

            virtual std::string name() = 0;
            virtual AScene& scene() = 0;
            virtual bool isActive() const = 0;
            virtual void setActive(bool value) = 0;
            virtual void addChild(const std::string& entityName) = 0;

    }; // class Entity

} // namespace sw

#endif // __SHIPWRECK_IENTITY_HPP__