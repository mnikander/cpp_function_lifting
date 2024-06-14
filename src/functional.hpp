#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

namespace fl {

template <typename E>
struct Liftable 
{
    template <typename T>
    T operator()(T const& left, T const& right) const
    {
        const auto expression = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
        return expression.impl(left, right);
    }

    template <typename T>
    auto operator()(std::vector<T> const& left, std::vector<T> const& right) const
        -> std::vector<T>
        // -> std::vector<decltype((*static_cast<const E*>(this))(T{}, T{}))>
    {
        assert(left.size() <= right.size());
        
        const auto expression = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
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

struct Add : Liftable<Add> { template <typename T> T impl(T lhs, T rhs) const { return lhs + rhs; } };

}
