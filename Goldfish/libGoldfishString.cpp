#include "include/libGoldfish.h"
#include <iostream>
#include <string>

[[maybe_unused]] Goldfish::Answer
Goldfish::toMatch(const std::string &testName, const std::string &result, const std::string &expected) {
    Goldfish::Answer answer;
    if (result != expected) {
        answer.out = "Test failed!: " + testName + result + " != " + expected;
        answer.passed = false;
    } else {
        answer.out = "Test passed!: " + testName + result + " = " + expected;
        answer.passed = true;
    }
    std::cout << answer.out << std::endl;
    return answer;
}

[[maybe_unused]] Goldfish::Answer
Goldfish::toNotMatch(const std::string &testName, const std::string &result, const std::string &expected) {
    Goldfish::Answer answer;
    if (result == expected) {
        answer.out = "Test failed!: " + testName + result + " = " + expected;
        answer.passed = false;
    } else {
        answer.out = "Test passed!: " + testName + result + " != " + expected;
        answer.passed = true;
    }
    std::cout << answer.out << std::endl;
    return answer;
}

[[maybe_unused]] Goldfish::Answer
Goldfish::toContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    bool contain = false;
    Goldfish::Answer answer;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == contains) {
            contain = true;
            break;
        }
    }
    if (!contain) {
        answer.out = "Test failed!: The Array does not contain " + contains;
        answer.passed = false;
    } else {
        answer.out = "Test passed!: The Array contains " + contains;
        answer.passed = true;
    }
    std::cout << answer.out << std::endl;
    return answer;
}

[[maybe_unused]] Goldfish::Answer
Goldfish::toNotContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    bool contain = true;
    Goldfish::Answer answer;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == contains) {
            contain = false;
            break;
        }
    }
    if (!contain) {
        answer.out = "Test passed!: The Array does not contain " + contains;
        answer.passed = true;
    } else {
        answer.out = "Test failed!: The Array contains " + contains;
        answer.passed = false;
    }
    std::cout << answer.out << std::endl;
    return answer;
}
