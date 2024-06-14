#include <gtest/gtest.h>

#include <cmath>
#include <functional>
#include <vector>
#include "../src/functional.hpp"

namespace {

TEST(plus, empty)
{
    const std::vector<int> a{};
    const std::vector<int> b{};

    const std::vector<int> r = fl::Add{}(a, b);

    EXPECT_EQ(r.size(), 0);
}

TEST(plus, zero)
{
    const std::vector<int> a{0};
    const std::vector<int> b{0};

    const std::vector<int> r = fl::Add{}(a, b);

    EXPECT_EQ(r.size(), 1);
    EXPECT_EQ(r[0], 0);
}

TEST(plus, zero_one)
{
    const std::vector<int> a{0, 1};
    const std::vector<int> b{0, 1};

    const std::vector<int> r = fl::Add{}(a, b);

    EXPECT_EQ(r.size(), 2);
    EXPECT_EQ(r[0], 0);
    EXPECT_EQ(r[1], 2);
}

}
