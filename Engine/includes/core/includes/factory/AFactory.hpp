/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AFactory.hpp
*/

#ifndef __SHIPWRECK_AFACTORY_HPP__
#define __SHIPWRECK_AFACTORY_HPP__

#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>
#include <memory>
#include <type_traits>

#include "IFactory.hpp"
#include "engine/Engine.hpp"
#include "scene/AScene.hpp"
#include "error/Error.hpp"
#include "component/IComponent.hpp"

namespace sw
{

    template <typename ConcretComponent>
    requires std::is_base_of<IComponent, ConcretComponent>::value
    class AFactory :
        public IFactory
    {

        protected:
            class Components :
                private std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::operator[];

                friend AFactory;

            } m_componentMap;

            class ComponentLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AFactory;

            } m_componentLayer;

            AScene& m_scene;
            bool m_isActive;
            const std::string m_name;

            bool m_isLoad;

            virtual void onLoad() = 0;
            virtual void onUpdate() = 0;
            virtual void onUnload() = 0;

        public:
            AFactory(const std::string& factoryName, AScene& sceneRef);
            ~AFactory();

            AScene& scene() const override;
            std::string name() const override;
            bool isActive() const override;
            bool hasComponent(const std::string& entityName) const override;

            void setActive(bool value) override;
            void load() override;
            void update() override;
            void unload() override;

            template <typename... Args>
            ConcretComponent& createComponent(const std::string& entityName, Args... values);

            void deleteComponent(const std::string& entityName);
            void setLayer(const std::string& entityName, int layer);
            [[nodiscard]] int getLayer(const std::string& entityName) const;

            template <typename RealComponent, typename... Args>
                requires std::is_base_of<IComponent, RealComponent>::value
                ConcretComponent& addScript(const std::string& entity, Args... values);

            std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator begin();
            std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator end();
            ConcretComponent& operator[](const std::string& entityName);

        template <typename T>
            requires std::is_base_of<IComponent, T>::value
            friend std::ostream& operator<<(std::ostream& os, AFactory<T>& sys);

    }; // class AFactory

    #include "AFactory.inl"

} // namespace sw

#endif // __SHIPWRECK_AFACTORY_HPP__