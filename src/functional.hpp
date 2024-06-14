#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // greatest_common_divisor, least_common_multiple
#include <vector>
#include "liftable.hpp"

namespace fl {

// Logical operators
struct LogicalNot : Liftable<LogicalNot>     { template <typename T> T impl(T t) const { return !t; } };
struct LogicalAnd : Liftable<LogicalAnd>     { template <typename T> T impl(T lhs, T rhs) const { return lhs && rhs; } };
struct LogicalOr  : Liftable<LogicalOr>      { template <typename T> T impl(T lhs, T rhs) const { return lhs || rhs; } };

// unary ops
struct Identity : Liftable<Identity>         { template <typename T> T impl(T t) const { return t; } };
struct Negate   : Liftable<Negate>           { template <typename T> T impl(T t) const { return -t; } };
// TODO: abs, sqrt, crt, log, log_2, log_10, exp, exp_2, exp_10 ...

// binary ops
struct Add          : Liftable<Add>          { template <typename T> T impl(T lhs, T rhs) const { return lhs + rhs; } };
struct Subtract     : Liftable<Subtract>     { template <typename T> T impl(T lhs, T rhs) const { return lhs - rhs; } };
struct Multiply     : Liftable<Multiply>     { template <typename T> T impl(T lhs, T rhs) const { return lhs * rhs; } };
struct Divide       : Liftable<Divide>       { template <typename T> T impl(T lhs, T rhs) const { return lhs / rhs; } };
struct Modulo       : Liftable<Modulo>       { template <typename T> T impl(T lhs, T rhs) const { return lhs % rhs; } };
struct Power        : Liftable<Power>        { template <typename T> T impl(T base, T exp) const { return std::pow(base, exp); } };
struct Minimum      : Liftable<Minimum>      { template <typename T> T impl(T lhs, T rhs) const { return std::min(lhs, rhs); } };
struct Maximum      : Liftable<Maximum>      { template <typename T> T impl(T lhs, T rhs) const { return std::max(lhs, rhs); } };
struct Equal        : Liftable<Equal>        { template <typename T> bool impl(T lhs, T rhs) const { return lhs == rhs; } };
struct NotEqual     : Liftable<NotEqual>     { template <typename T> bool impl(T lhs, T rhs) const { return lhs != rhs; } };
struct Less         : Liftable<Less>         { template <typename T> bool impl(T lhs, T rhs) const { return lhs < rhs; } };
struct LessEqual    : Liftable<LessEqual>    { template <typename T> bool impl(T lhs, T rhs) const { return lhs <= rhs; } };
struct Greater      : Liftable<Greater>      { template <typename T> bool impl(T lhs, T rhs) const { return lhs > rhs; } };
struct GreaterEqual : Liftable<GreaterEqual> { template <typename T> bool impl(T lhs, T rhs) const { return lhs >= rhs; } };

struct LeastCommonMultiple : Liftable<LeastCommonMultiple> // note that AND is a specialization of LCM for booleans
{
    template <typename T> T impl(T lhs, T rhs) const { return std::lcm(lhs,rhs); }
                       bool impl(bool lhs, bool rhs) const { return lhs && rhs; }
};

struct GreatestCommonDivisor : Liftable<GreatestCommonDivisor> // note that OR is a specialization of GCD for booleans
{
    template <typename T> T impl(T lhs, T rhs) const { return std::gcd(lhs,rhs); }
                       bool impl(bool lhs, bool rhs) const { return lhs || rhs; }
};

}
