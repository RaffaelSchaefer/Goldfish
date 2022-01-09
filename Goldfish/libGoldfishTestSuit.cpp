#include "Goldfish/libGoldfish.h"

[[maybe_unused]] Goldfish::TestSuit::TestSuit(std::string name) {
    this->name = std::move(name);
    this->answer = {"", false};
    this->startTime = std::time(nullptr);
    this->endTime = std::time(nullptr);
    failedCounter = 0;
    passedCounter = 0;
    duration = 0;
}

Goldfish::TestSuit::~TestSuit() = default;

[[maybe_unused]] int Goldfish::TestSuit::getPassed() const {
    return this->passedCounter;
}

[[maybe_unused]] int Goldfish::TestSuit::getFailed() const {
    return this->failedCounter;
}

[[maybe_unused]] std::time_t Goldfish::TestSuit::getDuration() const {
    return duration;
}

[[maybe_unused]] void Goldfish::TestSuit::start() {
    this->startTime = std::time(nullptr);
    answer.out = "#### " + this->name + "\n\n";
}

[[maybe_unused]] void Goldfish::TestSuit::write(const Goldfish::Answer &input) {
    this->answer.out += input.out + "\n\n";
    if (!input.passed) {
        failedCounter++;
    } else {
        passedCounter++;
    }
}

[[maybe_unused]] void Goldfish::TestSuit::write(const std::string &input) {
    this->answer.out += input + "\n\n";
}

[[maybe_unused]] void Goldfish::TestSuit::stop() {
    this->endTime = std::time(nullptr);
    duration = endTime - startTime;
    answer.out +=
            "##### Results\n\n**Passed Tests**: " + std::to_string(this->passedCounter) + "\n\n**Failed Tests**: " +
            std::to_string(this->failedCounter) + "\n\n**Success rate**: " +
            std::to_string(((float) passedCounter / ((float) failedCounter + (float) passedCounter)) * 100.0F) + "%" +
            "\n\n" + "**Duration**: " + std::to_string(duration) + " seconds.";
}