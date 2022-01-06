#include "include/libGoldfish.h"
#include <iostream>
#include <string>

[[maybe_unused]] std::string
Goldfish::toMatch(const std::string &testName, const std::string &result, const std::string &expected) {
    std::string out;
    if (result != expected) {
        out = "Test failed!: " + testName + result + " != " + expected;
    } else {
        out = "Test passed!: " + testName + result + " = " + expected;
    }
    std::cout << out << std::endl;
    return out;
}

[[maybe_unused]] std::string
Goldfish::toNotMatch(const std::string &testName, const std::string &result, const std::string &expected) {
    std::string out;
    if (result == expected) {
        out = "Test failed!: " + testName + result + " = " + expected;
    } else {
        out = "Test passed!: " + testName + result + " != " + expected;
    }
    std::cout << out << std::endl;
    return out;
}

[[maybe_unused]] std::string
Goldfish::toContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    bool contain = false;
    std::string out;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == contains) {
            contain = true;
            break;
        }
    }
    if (!contain) {
        out = "Test failed!: The Array does not contain " + contains;
    } else {
        out = "Test passed!: The Array contains " + contains;
    }
    std::cout << out << std::endl;
    return out;
}

[[maybe_unused]] std::string
Goldfish::toNotContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    bool contain = true;
    std::string out;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == contains) {
            contain = false;
            break;
        }
    }
    if (!contain) {
        out = "Test passed!: The Array does not contain " + contains;
    } else {
        out = "Test failed!: The Array contains " + contains;
    }
    std::cout << out << std::endl;
    return out;
}
