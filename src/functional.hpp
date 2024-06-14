#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

namespace fl {

template <typename E>
struct Liftable 
{
    template <typename T>
    auto operator()(std::vector<T> const& left, std::vector<T> const& right) const
        -> std::vector<T>
        // -> std::vector<decltype((*static_cast<const E*>(this))(T{}, T{}))>
    {
        assert(left.size() <= right.size());
        
        const auto binary_function = *(static_cast<const E*>(this)); // downcasting to the exact type of function via CRTP
        std::vector<decltype(binary_function(T{}, T{}))> result(left.size());
        std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), binary_function);
        return result;
    }

    // TODO: provide more overloads for unary and binary functions
    //               vector  -> vector
    //      (scalar, vector) -> vector
    //      (vector, scalar) -> vector
};

struct Add : Liftable<Add>
{
    using Liftable<Add>::operator();
    template <typename T> T operator()(T lhs, T rhs) const { return lhs + rhs; }
};

}
