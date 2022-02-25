/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * TimePoint.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __TIMEPOINT_HPP__
#define __TIMEPOINT_HPP__

#include <chrono>
#include <SFML/System/Time.hpp>

namespace sfml::time
{

    using microseconds = std::chrono::microseconds;
    using milliseconds = std::chrono::milliseconds;
    using seconds = std::chrono::seconds;

    class Point
    {

        public:
            Point(microseconds value = microseconds(0))
                :   m_microseconds{value}
            {}

            Point(sf::Time time)
                :   m_microseconds{time.asMicroseconds()}
            {}

            double asSeconds() const
            {
                return (std::chrono::duration_cast<seconds>(m_microseconds).count());
            }

            double asMilliseconds() const
            {
                return (std::chrono::duration_cast<milliseconds>(m_microseconds).count());
            }

            double asMicroseconds() const
            {
                return (m_microseconds).count();
            }

            operator sf::Time() const { return (sf::microseconds(m_microseconds.count())); }

        private:
            microseconds m_microseconds;

    };

}

constexpr sfml::time::seconds operator ""s(unsigned long long s)
{
    return sfml::time::seconds(s);
}

constexpr sfml::time::milliseconds operator ""ms(unsigned long long ms)
{
    return sfml::time::milliseconds(ms);
}

constexpr sfml::time::microseconds operator ""us(unsigned long long us)
{
    return sfml::time::microseconds(us);
}

#endif // __TIMEPOINT_HPP__