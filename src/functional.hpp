#pragma once

#include <algorithm>
#include <cmath>
#include <vector>
#include "liftable.hpp"

namespace fl {

struct Add : Liftable<Add> { template <typename T> T impl(T lhs, T rhs) const { return lhs + rhs; } };

}
