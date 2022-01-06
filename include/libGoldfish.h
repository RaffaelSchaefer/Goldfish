#pragma once
#ifndef GOLDFISH_LIBGOLDFISH_H
#define GOLDFISH_LIBGOLDFISH_H

#include <string>
#include <iostream>

class [[maybe_unused]] Goldfish {
private:
protected:
public:
    template<typename type>
    [[maybe_unused]] static void toEqual(const std::string &, type, type);

    [[maybe_unused]] static void toMatch(const std::string &, const std::string &, const std::string &);

    template<typename type>
    [[maybe_unused]] static void toNotEqual(const std::string &, type, type);

    [[maybe_unused]] static void toNotMatch(const std::string &, const std::string &, const std::string &);

    template<typename type>
    [[maybe_unused]] static void toBe(const std::string &, type *, type *);

    template<typename type>
    [[maybe_unused]] static void toNotBe(const std::string &, type *, type *);

    template<typename type>
    [[maybe_unused]] static void toBeNull(const std::string &, type *);

    template<typename type>
    [[maybe_unused]] static void toBeNull(const std::string &, type);

    template<typename type>
    [[maybe_unused]] static void toBeGreaterThen(const std::string &, type, type);

    template<typename type>
    [[maybe_unused]] static void toBeGreaterEqualThen(const std::string &, type, type);

    template<typename type>
    [[maybe_unused]] static void toBeLessThen(const std::string &, type, type);

    template<typename type>
    [[maybe_unused]] static void toBeLessEqualThen(const std::string &, type, type);

    template<typename type>
    [[maybe_unused]] static void toContain(const std::string &, type *, type, int);

    template<typename type>
    [[maybe_unused]] static void toNotContain(const std::string &, type *, type, int);

    [[maybe_unused]] static void toContainString(const std::string &, std::string *, const std::string&, int);

    [[maybe_unused]] static void toNotContainString(const std::string &, std::string *, const std::string&, int);

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

template<typename type>
[[maybe_unused]] void Goldfish::toBeNull(const std::string &testName, type *result) {
    if (result != nullptr) {
        throw std::invalid_argument("Test failed!: The result is not null");
    } else {
        std::cout << "Test passed!: The result is null";
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toBeNull(const std::string &testName, type result) {
    if (*result != nullptr) {
        throw std::invalid_argument("Test failed!: The result is not null");
    } else {
        std::cout << "Test passed!: The result is null";
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toBeGreaterThen(const std::string &testName, type result, type expected) {
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
[[maybe_unused]] void Goldfish::toBeGreaterEqualThen(const std::string &testName, type result, type expected) {
    if (result < expected) {
        std::string out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " >= " << expected << std::endl;
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toBeLessThen(const std::string &testName, type result, type expected) {
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
[[maybe_unused]] void Goldfish::toBeLessEqualThen(const std::string &testName, type result, type expected) {
    if (result > expected) {
        std::string out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
        throw std::invalid_argument(out);
    } else {
        std::cout << "Test passed!: " << testName << result << " <= " << expected << std::endl;
    }
}

template<typename type>
[[maybe_unused]] void Goldfish::toContain(const std::string &testName, type *array, type contains, int size) {
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
[[maybe_unused]] void Goldfish::toNotContain(const std::string &testName, type *array, type contains, int size) {
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

#endif //GOLDFISH_LIBGOLDFISH_H