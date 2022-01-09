#include "Goldfish/libGoldfish.h"

[[maybe_unused]] Goldfish::Answer Goldfish::toBeTrue(const std::string &testName, bool result) {
    Goldfish::Answer answer;
    if(!result) {
        answer.out = "Test failed!: "+testName+"The result is false";
        answer.passed = false;
    } else {
        answer.out = "Test passed!: "+testName+"The result is true";
        answer.passed = true;
    }
    std::cout << answer.out << std::endl;
    return answer;
}

[[maybe_unused]] Goldfish::Answer Goldfish::toBeFalse(const std::string &testName, bool result) {
    Goldfish::Answer answer;
    if(!result) {
        answer.out = "Test failed!: "+testName+"The result is true";
        answer.passed = false;
    } else {
        answer.out = "Test passed!: "+testName+"The result is false";
        answer.passed = true;
    }
    std::cout << answer.out << std::endl;
    return answer;
}