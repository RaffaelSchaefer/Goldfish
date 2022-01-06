#pragma once
#ifndef GOLDFISH_LIBGOLDFISH_H
#define GOLDFISH_LIBGOLDFISH_H

#include <string>
#include <iostream>

namespace Goldfish{
    [[maybe_unused]] static void toMatch(const std::string &, const std::string &, const std::string &);

    [[maybe_unused]] static void toNotMatch(const std::string &, const std::string &, const std::string &);

    [[maybe_unused]] static void toContainString(const std::string &, std::string *, const std::string&, int);

    [[maybe_unused]] static void toNotContainString(const std::string &, std::string *, const std::string&, int);

    [[maybe_unused]] static float version();

    template<typename type>
    [[maybe_unused]] void toEqual(const std::string &testName, type result, type expected) {
        if (result != expected) {
            std::string out = "Test failed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
            throw std::invalid_argument(out);
        } else {
            std::cout << "Test passed!: " << testName << result << " = " << expected << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toNotEqual(const std::string &testName, type result, type expected) {
        if (result == expected) {
            std::string out = "Test failed!: " + testName + std::to_string(result) + " == " + std::to_string(expected);
            throw std::invalid_argument(out);
        } else {
            std::cout << "Test passed!: " << testName << result << " != " << expected << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toBe(const std::string &testName, type *result, type *expected) {
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
    [[maybe_unused]] void toNotBe(const std::string &testName, type *result, type *expected) {
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

    template<typename type>
    [[maybe_unused]] void toBeNull(const std::string &testName, type *result) {
        if (result != nullptr) {
            throw std::invalid_argument("Test failed!: The result is not null");
        } else {
            std::cout << "Test passed!: The result is null";
        }
    }

    template<typename type>
    [[maybe_unused]] void toBeNull(const std::string &testName, type result) {
        if (*result != nullptr) {
            throw std::invalid_argument("Test failed!: The result is not null");
        } else {
            std::cout << "Test passed!: The result is null";
        }
    }

    template<typename type>
    [[maybe_unused]] void toBeGreaterThen(const std::string &testName, type result, type expected) {
        if (result <= expected) {
            if (result == expected) {
                std::string out = "Test failed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
                throw std::invalid_argument(out);
            } else {
                std::string out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
                throw std::invalid_argument(out);
            }
        } else {
            std::cout << "Test passed!: " << testName << result << " > " << expected << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toBeGreaterEqualThen(const std::string &testName, type result, type expected) {
        if (result < expected) {
            std::string out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
            throw std::invalid_argument(out);
        } else {
            std::cout << "Test passed!: " << testName << result << " >= " << expected << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toBeLessThen(const std::string &testName, type result, type expected) {
        if (result >= expected) {
            if (result == expected) {
                std::string out = "Test failed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
                throw std::invalid_argument(out);
            } else {
                std::string out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
                throw std::invalid_argument(out);
            }
        } else {
            std::cout << "Test passed!: " << testName << result << " < " << expected << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toBeLessEqualThen(const std::string &testName, type result, type expected) {
        if (result > expected) {
            std::string out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
            throw std::invalid_argument(out);
        } else {
            std::cout << "Test passed!: " << testName << result << " <= " << expected << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toContain(const std::string &testName, type *array, type contains, int size) {
        bool contain = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] == contains) {
                contain = true;
                break;
            }
        }
        if (!contain) {
            std::string out = "Test failed!: The Array does not contain "+std::to_string(contains);
            throw std::invalid_argument(out);
        } else {
            std::cout << "Test passed!: The Array contains " << contains << std::endl;
        }
    }

    template<typename type>
    [[maybe_unused]] void toNotContain(const std::string &testName, type *array, type contains, int size) {
        bool contain = true;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] == contains) {
                contain = false;
                break;
            }
        }
        if (contain) {
            std::string out = "Test failed!: The Array does not contain "+std::to_string(contains);
            throw std::invalid_argument(out);
        } else {
            std::cout << "Test passed!: The Array contains " << contains << std::endl;
        }
    }
}

#endif //GOLDFISH_LIBGOLDFISH_H