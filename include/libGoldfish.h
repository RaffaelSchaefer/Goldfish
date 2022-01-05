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
    [[maybe_unused]] static void toEqual(const std::string &, type, type);

    [[maybe_unused]] static void toEqualString(const std::string &, const std::string &, const std::string &);

    template<typename type>
    [[maybe_unused]] static void toNotEqual(const std::string &, type, type);

    [[maybe_unused]] static void toNotEqualString(const std::string &, const std::string &, const std::string &);

    template<typename type>
    [[maybe_unused]] static void toBe(const std::string &, type *, type *);

    template<typename type>
    [[maybe_unused]] static void toNotBe(const std::string &, type *, type *);

    [[maybe_unused]] static float version();
};

template<typename type>
[[maybe_unused]] void Goldfish::toEqual(const std::string &testName, type result, type expected) {
    if (result != expected) {
        std::string out = "Test failed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toNotEqual(const std::string &testName, type result, type expected) {
    if (result == expected) {
        std::string out = "Test failed!: " + testName + std::to_string(result) + " == " + std::to_string(expected);
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toBe(const std::string &testName, type *result, type *expected) {
    if (result != expected) {
        if (*result == *expected) {
            throw std::invalid_argument("Test failed!: The result is a duplicate of the expected value");
        } else {
            throw std::invalid_argument("Test failed!: The result is not the same a the expected value");
        }
    } else {
        std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toNotBe(const std::string &testName, type *result, type *expected) {
    if (result != expected) {
        if (*result == *expected) {
            throw std::invalid_argument("Test failed!: The result is a duplicate of the expected value");
        } else {
            throw std::invalid_argument("Test failed!: The result is not the same a the expected value");
        }
    } else {
        std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
    }
}

#endif //GOLDFISH_LIBGOLDFISH_H