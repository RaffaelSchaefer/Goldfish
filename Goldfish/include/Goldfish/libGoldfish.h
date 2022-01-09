#pragma once
#ifndef GOLDFISH_LIBGOLDFISH_H
#define GOLDFISH_LIBGOLDFISH_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

//Structs
namespace Goldfish {
    struct Answer {
        std::string out;
        [[maybe_unused]] bool passed;
    };
}

//Classes
namespace Goldfish {

    class [[maybe_unused]] TestSuit {
    private:
    protected:
    public:
        std::string name;
        Answer answer;
        std::time_t startTime;
        std::time_t endTime;

        [[maybe_unused]] explicit TestSuit(std::string);

        [[maybe_unused]] void start();

        [[maybe_unused]] void write(const std::string &);

        [[maybe_unused]] void write(const Answer &);

        [[maybe_unused]] void stop();

        ~TestSuit();
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
    [[maybe_unused]] Answer toEqual(const std::string &testName, type result, type expected) {
        Answer answer;
        if (result != expected) {
            answer.out = "Test failed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
            answer.passed = false;
        } else {
            answer.out = "Test passed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toNotEqual(const std::string &testName, type result, type expected) {
        Answer answer;
        if (result == expected) {
            answer.out = "Test failed!: " + testName + std::to_string(result) + " == " + std::to_string(expected);
            answer.passed = false;
        } else {
            answer.out = "Test passed!: " + testName + std::to_string(result) + " != " + std::to_string(expected);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBe(const std::string &testName, type *result, type *expected) {
        Answer answer;
        if (result != expected) {
            if (*result == *expected) {
                answer.out = "Test failed!: " + testName + "The result is a duplicate of the expected value";
                answer.passed = false;
            } else {
                answer.out = "Test failed!: " + testName + "The result is not the same a the expected value";
                answer.passed = false;
            }
        } else {
            answer.out = "Test passed!: " + testName + "The result is the same a the expected value";
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toNotBe(const std::string &testName, type *result, type *expected) {
        Answer answer;
        if (result != expected) {
            if (*result == *expected) {
                answer.out = "Test failed!: " + testName + "The result is a duplicate of the expected value";
                answer.passed = false;
            } else {
                answer.out = "Test failed!: " + testName + "The result is not the same a the expected value";
                answer.passed = false;
            }
        } else {
            answer.out = "Test passed!: " + testName + "The result is not the same a the expected value";
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeNull(const std::string &testName, type *result) {
        Answer answer;
        if (result != nullptr) {
            answer.out = "Test failed!: The result is not null";
            answer.passed = false;
        } else {
            answer.out = "Test passed!: The result is null";
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeNull(const std::string &testName, type result) {
        Answer answer;
        if (result != nullptr) {
            answer.out = "Test failed!: The result is not null";
            answer.passed = false;
        } else {
            answer.out = "Test passed!: The result is null";
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeGreaterThen(const std::string &testName, type result, type expected) {
        Answer answer;
        if (result <= expected) {
            if (result == expected) {
                answer.out = "Test failed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
                answer.passed = false;
            } else {
                answer.out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
                answer.passed = false;
            }
        } else {
            answer.out = "Test passed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeGreaterEqualThen(const std::string &testName, type result, type expected) {
        Answer answer;
        if (result < expected) {
            answer.out = "Test failed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
            answer.passed = false;
        } else {
            answer.out = "Test passed!: " + testName + std::to_string(result) + " >= " + std::to_string(expected);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeLessThen(const std::string &testName, type result, type expected) {
        Answer answer;
        if (result >= expected) {
            if (result == expected) {
                answer.out = "Test failed!: " + testName + std::to_string(result) + " = " + std::to_string(expected);
                answer.passed = false;
            } else {
                answer.out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
                answer.passed = false;
            }
        } else {
            answer.out = "Test passed!: " + testName + std::to_string(result) + " < " + std::to_string(expected);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeLessEqualThen(const std::string &testName, type result, type expected) {
        Answer answer;
        if (result > expected) {
            answer.out = "Test failed!: " + testName + std::to_string(result) + " > " + std::to_string(expected);
            answer.passed = false;
        } else {
            answer.out = "Test passed!: " + testName + std::to_string(result) + " <= " + std::to_string(expected);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toContain(const std::string &testName, type *array, type contains, int size) {
        Answer answer;
        bool contain = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] == contains) {
                contain = true;
                break;
            }
        }
        if (!contain) {
            answer.out = "Test failed!: The Array does not contain " + std::to_string(contains);
            answer.passed = false;
        } else {
            answer.out = "Test passed!: The Array contains " + std::to_string(contains);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toNotContain(const std::string &testName, type *array, type contains, int size) {
        Answer answer;
        bool contain = true;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] == contains) {
                contain = false;
                break;
            }
        }
        if (contain) {
            answer.out = "Test failed!: The Array does not contain " + std::to_string(contains);
            answer.passed = false;
        } else {
            answer.out = "Test passed!: The Array contains " + std::to_string(contains);
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeInRange(const std::string &testName, type result, type expected, type accuracy) {
        Answer answer;
        bool inRange = false;
        type lowerBorder = expected - accuracy;
        type upperBorder = expected + accuracy;
        if (lowerBorder <= result) {
            if (upperBorder >= result) {
                inRange = true;
            }
        }
        if (!inRange) {
            answer.out = "Test failed!: " + testName + "Result is not in range";
            answer.passed = false;
        } else {
            answer.out = "Test passed!: " + testName + "Result is in range";
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }

    template<typename type>
    [[maybe_unused]] Answer toBeNotInRange(const std::string &testName, type result, type expected, type accuracy) {
        Answer answer;
        bool inRange = false;
        type lowerBorder = expected - accuracy;
        type upperBorder = expected + accuracy;
        if (lowerBorder <= result) {
            if (upperBorder >= result) {
                inRange = true;
            }
        }
        if (inRange) {
            answer.out = "Test failed!: " + testName + "Result is in range";
            answer.passed = false;
        } else {
            answer.out = "Test passed!: " + testName + "Result is not in range";
            answer.passed = true;
        }
        std::cout << answer.out << std::endl;
        return answer;
    }
}

#endif //GOLDFISH_LIBGOLDFISH_H