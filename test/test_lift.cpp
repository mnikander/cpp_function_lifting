#include <gtest/gtest.h>

#include <cmath>
#include <functional>
#include <vector>
#include "../src/functional.hpp"

namespace {

TEST(scalar, negate)
{
    const int a = 5;
    const int r = fl::Negate{}(a);

    EXPECT_EQ(r, -5);
}

TEST(vector, negate)
{
    const std::vector<int> v = {-1, 0, 1};
    const std::vector<int> r = fl::Negate{}(v);

    ASSERT_EQ(r.size(), v.size());
    EXPECT_EQ(r[0], 1);
    EXPECT_EQ(r[1], 0);
    EXPECT_EQ(r[2], -1);
}

TEST(scalar_scalar, add)
{
    const int a = 2;
    const int b = 3;
    const int r = fl::Add{}(a, b);

    EXPECT_EQ(r, 5);
}

TEST(scalar_scalar, less)
{
    const int a = 2;
    const int b = 3;
    const int r = fl::Less{}(a, b);

    EXPECT_EQ(r, true);
}

TEST(scalar_scalar, greater)
{
    const int a = 2;
    const int b = 3;
    const int r = fl::Greater{}(a, b);

    EXPECT_EQ(r, false);
}

TEST(scalar_scalar, or)
{
    const bool a = true;
    const bool b = false;
    const bool r = fl::LogicalOr{}(a, b);

    EXPECT_EQ(r, true);
}

TEST(scalar_vector, add)
{
    const int i = 10;
    const std::vector<int> v{0, 1, 2};
    const std::vector<int> r = fl::Add{}(i, v);

    ASSERT_EQ(r.size(), v.size());
    EXPECT_EQ(r[0], 10);
    EXPECT_EQ(r[1], 11);
    EXPECT_EQ(r[2], 12);
}

TEST(scalar_vector, or)
{
    const bool i = false;
    const std::vector<bool> v{false, true};
    const std::vector<bool> r = fl::LogicalOr{}(i, v);

    ASSERT_EQ(r.size(), v.size());
    EXPECT_EQ(r[0], false);
    EXPECT_EQ(r[1], true);
}

TEST(vector_scalar, add)
{
    const int i = 10;
    const std::vector<int> v{0, 1, 2};
    const std::vector<int> r = fl::Add{}(v, i);

    ASSERT_EQ(r.size(), v.size());
    EXPECT_EQ(r[0], 10);
    EXPECT_EQ(r[1], 11);
    EXPECT_EQ(r[2], 12);
}

TEST(vector_scalar, or)
{
    const bool i = false;
    const std::vector<bool> v{false, true};
    const std::vector<bool> r = fl::LogicalOr{}(v, i);

    ASSERT_EQ(r.size(), v.size());
    EXPECT_EQ(r[0], false);
    EXPECT_EQ(r[1], true);
}

TEST(vector_vector, empty)
{
    const std::vector<int> a{};
    const std::vector<int> b{};
    const std::vector<int> r = fl::Add{}(a, b);

    ASSERT_EQ(r.size(), 0);
}

TEST(vector_vector, one)
{
    const std::vector<int> a{1};
    const std::vector<int> b{1};
    const std::vector<int> r = fl::Add{}(a, b);

    ASSERT_EQ(r.size(), 1);
    EXPECT_EQ(r[0], 2);
}

TEST(vector_vector, two)
{
    const std::vector<int> a{1, 2};
    const std::vector<int> b{1, 2};
    const std::vector<int> r = fl::Add{}(a, b);

    ASSERT_EQ(r.size(), 2);
    EXPECT_EQ(r[0], 2);
    EXPECT_EQ(r[1], 4);
}

TEST(vector_vector, logical_or)
{
    const std::vector<bool> a{true, false, false, true};
    const std::vector<bool> b{true, false, true, false};
    const std::vector<bool> r = fl::LogicalOr{}(a, b);

    ASSERT_EQ(r.size(), 4);
    EXPECT_EQ(r[0], true);
    EXPECT_EQ(r[1], false);
    EXPECT_EQ(r[2], true);
    EXPECT_EQ(r[3], true);
}

}
