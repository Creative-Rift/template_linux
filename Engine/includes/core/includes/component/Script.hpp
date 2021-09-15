/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Script.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCRIPT
#define SHIPWRECK_ENGINE_SCRIPT

#include "Component.hpp"

namespace sw
{

    class Script :
        public Component
    {

        public:
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param entityRef
            ////////////////////////////////////////////////////////////////////////////
            Script(Entity& entityRef);
            Script(Script const& sc);
            Script(Script&& sc);
            Script() = delete;
            virtual ~Script() = default;
            Script& operator=(Script const&) = delete;
            Script& operator=(Script&&) = delete;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Override this function to update your entity and their
            ///        component
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void update() {}

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Override this function set up your entity when the project start
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void start() {}

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Override this function to update your entity and their
            ///        component when he enter on collision
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onCollision() {}

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Overwrite this function to update your entity and their
            ///        component when he enter on trigger
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onTrigger() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user use right click on them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onRightClick() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user use left click on them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onLeftClick() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user move the mouse on them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void onHover() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user move the mouse outside of them
            ///
            ////////////////////////////////////////////////////////////////////////////
            virtual void notOnHover() {}

    }; // class Script

    #include "Script.inl"

} // namespace sfml

#endif //SHIPWRECK_ENGINE_SCRIPT