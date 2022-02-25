/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Span.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

namespace sfml
{

    template <typename T>
    class Span
    {
        public:
            Span()
                :   offset{},
                    length{}
            {}

            Span(T off, T len)
                :   offset(off),
                    length(len)
            {}

            T offset;
            T length;

    }; // class Span

} // namespace sfml

#endif // __SPAN_HPP__