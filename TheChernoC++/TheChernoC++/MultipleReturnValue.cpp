#include <iostream>
#include <utility>  // for std::pair
#include <tuple>    // for std::tuple
#include <vector>   // for std::vector

// Example 1: Using std::pair
std::pair<int, double> getPairValues() {
    return std::make_pair(42, 3.14);
}

// Example 2: Using std::tuple
std::tuple<int, double, std::string> getTupleValues() {
    return std::make_tuple(42, 3.14, "Hello");
}

// Example 3: Using Output Parameters (pass by reference)
void getOutputValues(int& a, double& b) {
    a = 42;
    b = 3.14;
}

// Example 4: Using a struct
struct Result {
    int a;
    double b;
};

Result getStructValues() {
    Result result;
    result.a = 42;
    result.b = 3.14;
    return result;
}

// Example 5: Using std::vector for same type values
std::vector<int> getVectorValues() {
    return { 1, 2, 3, 4, 5 };
}

// Example 6: Using a Lambda Function
auto getLambdaValues() {
    return [](int x, double y) {
        return std::make_pair(x, y);
        };
}

//int main() {
//    // Example 1: std::pair
//    auto pairResult = getPairValues();
//    std::cout << "Pair values: " << pairResult.first << ", " << pairResult.second << "\n";
//
//    // Example 2: std::tuple
//    auto tupleResult = getTupleValues();
//    std::cout << "Tuple values: " << std::get<0>(tupleResult) << ", "
//        << std::get<1>(tupleResult) << ", "
//        << std::get<2>(tupleResult) << "\n";
//
//    // Example 3: Output Parameters
//    int x;
//    double y;
//    getOutputValues(x, y);
//    std::cout << "Output parameters: " << x << ", " << y << "\n";
//
//    // Example 4: Struct
//    Result structResult = getStructValues();
//    std::cout << "Struct values: " << structResult.a << ", " << structResult.b << "\n";
//
//    // Example 5: std::vector
//    std::vector<int> vectorResult = getVectorValues();
//    std::cout << "Vector values: ";
//    for (int value : vectorResult) {
//        std::cout << value << " ";
//    }
//    std::cout << "\n";
//
//    // Example 6: Lambda Function
//    auto lambda = getLambdaValues();
//    auto lambdaResult = lambda(42, 3.14);
//    std::cout << "Lambda values: " << lambdaResult.first << ", " << lambdaResult.second << "\n";
//
//    return 0;
//}
