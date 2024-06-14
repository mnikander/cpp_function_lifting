#include <gtest/gtest.h>

#include <cmath>
#include <functional>
#include <vector>
#include "../src/functional.hpp"

namespace {

TEST(scalar_scalar, one)
{
    const int a = 2;
    const int b = 3;

    const int r = fl::Add{}(a, b);

    EXPECT_EQ(r, 5);
}

TEST(vector_vector, empty)
{
    const std::vector<int> a{};
    const std::vector<int> b{};

    const std::vector<int> r = fl::Add{}(a, b);

    EXPECT_EQ(r.size(), 0);
}

TEST(vector_vector, one)
{
    const std::vector<int> a{1};
    const std::vector<int> b{1};

    const std::vector<int> r = fl::Add{}(a, b);

    EXPECT_EQ(r.size(), 1);
    EXPECT_EQ(r[0], 2);
}

TEST(vector_vector, two)
{
    const std::vector<int> a{1, 2};
    const std::vector<int> b{1, 2};

    const std::vector<int> r = fl::Add{}(a, b);

    EXPECT_EQ(r.size(), 2);
    EXPECT_EQ(r[0], 2);
    EXPECT_EQ(r[1], 4);
}

}
