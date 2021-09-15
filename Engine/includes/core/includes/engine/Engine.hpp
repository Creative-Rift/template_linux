/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.hpp
*/

#ifndef __SHIPWRECK_ENGINE_HPP__
#define __SHIPWRECK_ENGINE_HPP__

#include <unordered_map>
#include <string>
#include <type_traits>

#include "scene/AScene.hpp"
#include "module/AModule.hpp"

namespace sw
{

    class Engine
    {

        private:
            static std::unordered_map<std::string, std::unique_ptr<AScene>> m_sceneMap;
            static std::string m_activeScene;
            static std::unordered_map<std::string, std::unique_ptr<AModule>> m_moduleMap;
            static std::string m_activeModule;
            static bool m_isLoad;

            static void onInitialize();
            static void onUpdate();
            static void onTerminate();

        public:
            Engine() = delete;
            Engine(Engine&&) = delete;
            Engine(const Engine&) = delete;
            ~Engine() = default;

            static void initialize();
            static void update();
            static void terminate();

            template <class ConcretScene>
                requires std::is_base_of<AScene, ConcretScene>::value
                static ConcretScene& createScene(const std::string& sceneName);

            template <class ConcretScene>
                requires std::is_base_of<AScene, ConcretScene>::value
                static ConcretScene& getScene(const std::string& sceneName);

            static AScene& getScene(const std::string& sceneName);

            template <class ConcretScene>
                requires std::is_base_of<AScene, ConcretScene>::value
                static ConcretScene& activeScene();

            static AScene& activeScene();
            static void deleteScene(const std::string& sceneName);
            static bool hasScene(const std::string& sceneName);
            static void setActiveScene(const std::string& name);

            template <class ConcretModule>
                requires std::is_base_of<AModule, ConcretModule>::value
                static ConcretModule& createModule(const std::string& moduleName);

            template <class ConcretModule>
                requires std::is_base_of<AModule, ConcretModule>::value
                static ConcretModule& getModule(const std::string& moduleName);

            static AModule& getModule(const std::string& moduleName);

            template <class ConcretModule>
                requires std::is_base_of<AModule, ConcretModule>::value
                static ConcretModule& activeModule();

            static AModule& activeModule();
            static void deleteModule(const std::string& moduleName);
            static bool hasModule(const std::string& sceneName);

    }; // class Engine

    #include "moduleFunction.inl"
    #include "sceneFunction.inl"

} // namespace sw

#endif // __SHIPWRECK_ENGINE_HPP__