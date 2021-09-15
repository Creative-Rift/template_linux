/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Scene.hpp
*/

#ifndef __SHIPWRECK_ASCENE_HPP__
#define __SHIPWRECK_ASCENE_HPP__

#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>
#include <forward_list>
#include <type_traits>

#include "entity/IEntity.hpp"
#include "factory/IFactory.hpp"

#include "error/Error.hpp"
#include "utils/Speech.hpp"

#include "resources/AResources.hpp"
#include "json_parser/jsnp.hpp"

namespace sw
{

    class Entity;

    class AScene
    {

        protected:
            class FactoryMap :
                private std::unordered_map<std::string, std::unique_ptr<IFactory>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IFactory>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IFactory>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IFactory>>::operator[];

                friend AScene;

            } m_factoryMap;

            class EntityMap :
                private std::unordered_map<std::string, std::unique_ptr<IEntity>>
            {
                public:
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::begin;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::end;
                    using std::unordered_map<std::string, std::unique_ptr<IEntity>>::operator[];

                friend AScene;

            } m_entityMap;

            class FactoryLayer :
                private std::forward_list<std::pair<int, std::string>>
            {
                private:
                    bool needSort;

                public:
                    using std::forward_list<std::pair<int, std::string>>::begin;
                    using std::forward_list<std::pair<int, std::string>>::end;

                friend AScene;

            } m_factoryLayer;

            std::vector<std::string> m_deleteEntity;
            bool m_isLoad;
            std::unique_ptr<AResources> m_resources;

            virtual void onLoad() = 0;
            virtual void onUpdate() = 0;
            virtual void onUnload() = 0;

        public:
            const std::string m_name;

            AScene() = delete;
            AScene(AScene&&) = delete;
            AScene(const AScene&) = delete;
            AScene(const std::string& sceneName);
            ~AScene();

            void load();
            void update();
            void unload();

            Entity& createEntity(const std::string& entityName);
            Entity& getEntity(const std::string& entityName);
            bool hasEntity(const std::string& entityName);
            void deleteEntity(const std::string& entityName);
            void deleteRequestedEntity();

            template <typename ConcretFactory>
                requires std::is_base_of<IFactory, ConcretFactory>::value
                ConcretFactory& createFactory(const std::string& factoryName);

            template <typename ConcretFactory>
                requires std::is_base_of<IFactory, ConcretFactory>::value
                ConcretFactory& getFactory(const std::string& factoryName);

            bool hasFactory(const std::string& factoryName);
            void deleteFactory(const std::string& factoryName);
            void setLayer(const std::string& factoryName, int layer);
            int getLayer(const std::string factoryName) const;

            std::unique_ptr<AResources>& resources();

            friend void LoadResourcesFile(const std::string& path);
            friend void AddResourcesOnScene(jsnp::Token& it);

            bool operator==(const sw::AScene& right) const {
                return (m_name == right.m_name);
            }

    }; // class Scene

    #include "Scene.inl"
    #include "entityFunction.inl"
    #include "factoryFunction.inl"

} // namespace sw

//inline auto operator<=>(const std::pair<int, std::string>& left, const std::pair<int, std::string>& right)
//{
//    return (left.first <=> right.first);
//}

#endif // __SHIPWRECK_ASCENE_HPP__