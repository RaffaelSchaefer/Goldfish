#pragma once
#ifndef GOLDFISH_LIBGOLDFISH_H
#define GOLDFISH_LIBGOLDFISH_H

#include <string>
#include <iostream>

class Goldfish {
private:
protected:
public:
    template<typename type>
    static void equal(const std::string &, type, type);

    template<typename type>
    static void notEqual(const std::string &, type, type);

    static float version();
};

template<typename type>
void Goldfish::equal(const std::string &testName, type result, type expected) {
    if (result != expected) {
        std::string out = "Test failed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
    }
}

template<typename type>
void Goldfish::notEqual(const std::string &testName, type result, type expected) {
    if (result == expected) {
        std::string out = "Test failed!: " + testName + std::to_string(result) + " == " + std::to_string(expected);
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
    }
}

#endif //GOLDFISH_LIBGOLDFISH_H