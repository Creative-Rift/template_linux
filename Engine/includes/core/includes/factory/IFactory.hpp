/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IFactory.hpp
*/

#ifndef __SHIPWRECK_IFACTORY_HPP__
#define __SHIPWRECK_IFACTORY_HPP__

#include <string>

namespace sw
{

    class AScene;

    class IFactory
    {

        public:
            virtual ~IFactory() = default;

            virtual AScene& scene() const = 0;
            virtual std::string name() const = 0;
            virtual bool isActive() const = 0;
            virtual bool hasComponent(const std::string& entityName) const = 0;

            virtual void setActive(bool value) = 0;
            virtual void load() = 0;
            virtual void update() = 0;
            virtual void unload() = 0;

    }; // class IFactory

} // namespace sw

#endif // __SHIPWRECK_IFACTORY_HPP__