#include "include/libGoldfish.h"

[[maybe_unused]] std::string Goldfish::toBeTrue(const std::string &testName, bool result) {
    std::string out;
    if(!result) {
        out = "Test failed!: "+testName+"The result is false";
    } else {
        out = "Test passed!: "+testName+"The result is true";
    }
    std::cout << out << std::endl;
    return out;
}

[[maybe_unused]] std::string Goldfish::toBeFalse(const std::string &testName, bool result) {
    std::string out;
    if(!result) {
        out = "Test failed!: "+testName+"The result is true";
    } else {
        out = "Test passed!: "+testName+"The result is false";
    }
    std::cout << out << std::endl;
    return out;
}