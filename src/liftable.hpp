#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

namespace fl {

template <typename E>
struct Liftable
{
    template <typename T>
    auto operator()(T const& left, T const& right) const
    {
        E const& expression = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
        return expression.impl(left, right);
    }

    template <typename T>
    auto operator()(T const& left, std::vector<T> const& right) const
    {
        E const& expression = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
        std::vector<decltype(expression(T{}, T{}))> result(right.size());
        std::transform(right.cbegin(), right.cend(), result.begin(), [left, expression](T const& r){ return expression(left, r); });
        return result;
    }

    template <typename T>
    auto operator()(std::vector<T> const& left, T const& right) const
    {
        E const& expression = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
        std::vector<decltype(expression(T{}, T{}))> result(left.size());
        std::transform(left.cbegin(), left.cend(), result.begin(), [right, expression](T const& l){ return expression(l, right); });
        return result;
    }

    template <typename T>
    auto operator()(std::vector<T> const& left, std::vector<T> const& right) const
    {
        assert(left.size() <= right.size());

        E const& expression = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
        std::vector<decltype(expression(T{}, T{}))> result(left.size());

        std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), expression);
        // I have no idea why, but expression.impl cannot be passed here ...........^
        // so instead it's relying on the scalar-valued overload Liftable<E>::operator()(T, T) defined above ¯\_(ツ)_/¯

        return result;
    }

    // TODO: provide more overloads for unary and binary functions
    //               vector  -> vector
    //      (scalar, vector) -> vector
    //      (vector, scalar) -> vector
};

}
