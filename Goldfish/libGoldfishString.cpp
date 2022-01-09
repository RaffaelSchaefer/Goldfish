#include "Goldfish/libGoldfish.h"
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
    Goldfish::Answer answer;
    answer.passed = false;
    for (int i = 0; i < size; ++i) {
        if (array[i] == contains) {
            answer.passed = true;
            break;
        }
    }
    if (!answer.passed) {
        answer.out = "Test failed!: The Array does not contain " + contains;
    } else {
        answer.out = "Test passed!: The Array contains " + contains;
    }
    std::cout << answer.out << std::endl;
    return answer;
}

[[maybe_unused]] Goldfish::Answer
Goldfish::toNotContainString(const std::string &testName, std::string *array, const std::string &contains, int size) {
    Goldfish::Answer answer;
    answer.passed = false;
    for (int i = 0; i < size; ++i) {
        if (array[i] == contains) {
            answer.passed = true;
            break;
        }
    }
    if (!answer.passed) {
        answer.out = "Test passed!: The Array does not contain " + contains;
        answer.passed = true;
    } else {
        answer.out = "Test failed!: The Array contains " + contains;
        answer.passed = false;
    }
    std::cout << answer.out << std::endl;
    return answer;
}
