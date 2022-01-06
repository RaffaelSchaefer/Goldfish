#include "include/libGoldfish.h"
#include <iostream>
#include <string>

[[maybe_unused]] void
Goldfish::toMatch(const std::string &testName, const std::string &result, const std::string &expected) {
    if (result != expected) {
        std::string out = "Test failed!: " + testName + result + " != " + expected;
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
    }
}

[[maybe_unused]] void
Goldfish::toNotMatch(const std::string &testName, const std::string &result, const std::string &expected) {
    if (result == expected) {
        std::string out = "Test failed!: " + testName + result + " = " + expected;
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
    }
}

[[maybe_unused]] void
Goldfish::toContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    bool contain = false;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == contains) {
            contain = true;
            break;
        }
    }
    if (!contain) {
        std::string out = "Test failed!: The Array does not contain " + contains;
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: The Array contains " << contains << std::endl;
    }
}

[[maybe_unused]] void
Goldfish::toNotContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    bool contain = true;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == contains) {
            contain = false;
            break;
        }
    }
    if (contain) {
        std::string out = "Test failed!: The Array does not contain " + contains;
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: The Array contains " << contains << std::endl;
    }
}

[[maybe_unused]] float Goldfish::version() {
    std::cout << "Goldfish ><> Version 0.0.1\nMade with love by Raffael Elias Schaefer" << std::endl;
    return 0.01F;
}

