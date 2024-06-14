# Function lifting

Allow binary functions operating on two elements, to be applied to two sequences of elements, without having to explicitly call transform and without having to implement extra overloads for each function.

## Getting started

1. Install dependencies
```bash
sudo apt get install libgtest-dev cmake g++
```

2. Clone the repo

3. Build and run:
```bash
cd cpp_function_lifting
mkdir out
cd out
cmake ..
cd ..
cmake --build out/ # out-of-source build
./out/unit_tests
```

You can find plenty of usage examples in the unit tests, but here are a few...

## Examples for unary functions

```cpp
    // unary function
    // Negate: scalar -> scalar
    const int a = 2;
    const int r = fl::Negate{}(a); // -2
```

'Negate' can be lifted automatically:

```cpp
    // Negate: vector -> vector
    const std::vector<int> a = {-1, 0, 1};
    const std::vector<int> r = fl::Negate{}(a); // [1, 0, -1]
```

## Examples for binary functions

```cpp
    // binary function
    // Add: (scalar, scalar) -> scalar
    const int a = 2;
    const int b = 3;
    const int r = fl::Add{}(a, b); // 5
```

'Add' can be lifted automatically:

```cpp
    // Add: (scalar, vector) -> vector
    const int a              = 10;
    const std::vector<int> b = {1, 2};
    const std::vector<int> r = fl::Add{}(a, b); // [11, 12]
```

```cpp
    // Add: (scalar, vector) -> vector
    const std::vector<int> a = {1, 2};
    const int b              = 10;
    const std::vector<int> r = fl::Add{}(a, b); // [11, 12]
```

```cpp
    // Add: (vector, vector) -> vector
    const std::vector<int> a = {10, 20};
    const std::vector<int> b = {1, 2};
    const std::vector<int> r = fl::Add{}(a, b); // [11, 22]
```
