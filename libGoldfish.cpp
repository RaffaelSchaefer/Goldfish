#include "libGoldfish.h"
#include <iostream>
#include <string>

void Goldfish::equal(const std::string &testName, auto result, auto expected) {
    if (result != expected) {
        std::cout << "Test failed!: " << testName << result << " != " << expected << std::endl;
        throw std::invalid_argument("result does not align with expectation");
    } else {
        std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
    }
}

void Goldfish::notEqual(const std::string &testName, auto result, auto expected) {
    if (result == expected) {
        std::cout << "Test failed!: " << testName << result << " == " << expected << std::endl;
        throw std::invalid_argument("result does not align with expectation");
    } else {
        std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
    }
}