#pragma once
#ifndef GOLDFISH_LIBGOLDFISH_H
#define GOLDFISH_LIBGOLDFISH_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

//Classes
namespace Goldfish {
    class Answer {
    private:
    protected:
    public:
        std::string out;
        bool passed;

        Answer();

        ~Answer();
    };

    class Log {
    private:
        std::string fileName;
        std::ofstream log;
        std::time_t startTime;
        std::time_t endTime;
    protected:
    public:
        explicit Log(const std::string &);

        ~Log();

        [[maybe_unused]] void start();

        [[maybe_unused]] void write(const std::string &);

        [[maybe_unused]] void write(const Answer &);

        [[maybe_unused]] void stop();
    };
}

//Functions
namespace Goldfish {
    //String functions

    [[maybe_unused]] Answer toMatch(const std::string &, const std::string &, const std::string &);

    [[maybe_unused]] Answer toNotMatch(const std::string &, const std::string &, const std::string &);

    [[maybe_unused]] Answer toContainString(const std::string &, std::string *, const std::string &, int);

    [[maybe_unused]] Answer toNotContainString(const std::string &, std::string *, const std::string &, int);

    //Boolean functions

    [[maybe_unused]] Answer toBeTrue(const std::string &, bool);

    [[maybe_unused]]Answer toBeFalse(const std::string &, bool);

    //Util functions

    [[maybe_unused]] std::string version();

    //Templates functions

    template<typename type>
    [[maybe_unused]] std::string toEqual(const std::string &testName, type result, type expected) {
        std::string out;
        if (result != expected) {
            out = "Test failed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
        } else {
            out = "Test passed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toNotEqual(const std::string &testName, type result, type expected) {
        std::string out;
        if (result == expected) {
            out = "Test failed!: " + testName + std::to_string(result) + " == " + std::to_string(expected);
        } else {
            out = "Test passed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBe(const std::string &testName, type *result, type *expected) {
        std::string out;
        if (result != expected) {
            if (*result == *expected) {
                out = "Test failed!: " + testName + "The result is a duplicate of the expected value";
            } else {
                out = "Test failed!: " + testName + "The result is not the same a the expected value";
            }
        } else {
            out = "Test passed!: " + testName + "The result is the same a the expected value";
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toNotBe(const std::string &testName, type *result, type *expected) {
        std::string out;
        if (result != expected) {
            if (*result == *expected) {
                out = "Test failed!: " + testName + "The result is a duplicate of the expected value";
            } else {
                out = "Test failed!: " + testName + "The result is not the same a the expected value";
            }
        } else {
            out = "Test passed!: " + testName + "The result is not the same a the expected value";
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeNull(const std::string &testName, type *result) {
        std::string out;
        if (result != nullptr) {
            out = "Test failed!: The result is not null";
        } else {
            out = "Test passed!: The result is null";
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeNull(const std::string &testName, type result) {
        std::string out;
        if (result != nullptr) {
            out = "Test failed!: The result is not null";
        } else {
            out = "Test passed!: The result is null";
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeGreaterThen(const std::string &testName, type result, type expected) {
        std::string out;
        if (result <= expected) {
            if (result == expected) {
                out = "Test failed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
            } else {
                out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
            }
        } else {
            out = "Test passed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeGreaterEqualThen(const std::string &testName, type result, type expected) {
        std::string out;
        if (result < expected) {
            out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
        } else {
            out = "Test passed!: " + testName + std::to_string(result) + " >= " + std::to_string(expected);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeLessThen(const std::string &testName, type result, type expected) {
        std::string out;
        if (result >= expected) {
            if (result == expected) {
                out = "Test failed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
            } else {
                out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
            }
        } else {
            out = "Test passed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeLessEqualThen(const std::string &testName, type result, type expected) {
        std::string out;
        if (result > expected) {
            out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
        } else {
            out = "Test passed!: " + testName + std::to_string(result) + " <= " + std::to_string(expected);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toContain(const std::string &testName, type *array, type contains, int size) {
        std::string out;
        bool contain = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] == contains) {
                contain = true;
                break;
            }
        }
        if (!contain) {
            out = "Test failed!: The Array does not contain " + std::to_string(contains);
        } else {
            out = "Test passed!: The Array contains " + std::to_string(contains);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toNotContain(const std::string &testName, type *array, type contains, int size) {
        std::string out;
        bool contain = true;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] == contains) {
                contain = false;
                break;
            }
        }
        if (contain) {
            out = "Test failed!: The Array does not contain " + std::to_string(contains);
        } else {
            out = "Test passed!: The Array contains " + std::to_string(contains);
        }
        std::cout << out << std::endl;
        return out;
    }

    template<typename type>
    [[maybe_unused]] std::string toBeInRange(const std::string &testName, type result, type expected, type accuracy) {
        std::string out;
        bool inRange = false;
        type lowerBorder = expected - accuracy;
        type upperBorder = expected + accuracy;
        if (lowerBorder <= result) {
            if (upperBorder >= result) {
                inRange = true;
            }
        }
        if (!inRange) {
            out = "Test failed!: " + testName + "Result is not in range";
        } else {
            out = "Test passed!: " + testName + "Result is in range";
        }
        std::cout << out << std::endl;
        return out;
    }
}

#endif //GOLDFISH_LIBGOLDFISH_H