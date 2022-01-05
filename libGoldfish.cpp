#include "include/libGoldfish.h"
#include <iostream>
#include <string>

[[maybe_unused]] void Goldfish::toEqualString(const std::string &testName, const std::string& result, const std::string& expected) {
    if (result != expected) {
        std::string out = "Test failed!: " + testName + result + " != " + expected;
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
    }
}

[[maybe_unused]] void Goldfish::toNotEqualString(const std::string &testName, const std::string& result, const std::string& expected) {
    if (result == expected) {
        std::string out = "Test failed!: " + testName + result + " = " + expected;
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
    }
}

[[maybe_unused]] float Goldfish::version() {
    std::cout << "Goldfish ><> Version 0.0.1\nMade with love by Raffael Elias Schaefer" << std::endl;
    return 0.01F;
}

