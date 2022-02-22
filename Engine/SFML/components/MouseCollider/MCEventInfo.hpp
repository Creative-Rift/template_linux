/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MCEventInfo.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __MCEVENTINFO_HPP__
#define __MCEVENTINFO_HPP__

#include "SW/Event.hpp"
#include "SW/utils/Vector.hpp"

namespace sfml
{

    class MCEventInfo
        :   public sw::IEventInfo
    {

        public:
            sw::Vector2i mousePosition;

            MCEventInfo(const sw::Vector2i& mpos)
                :   mousePosition{mpos} {}
            ~MCEventInfo() = default;

    };

}

#endif // __MCEVENTINFO_HPP__