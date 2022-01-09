#include <utility>

#include "Goldfish/libGoldfish.h"

[[maybe_unused]] Goldfish::TestSuit::TestSuit(std::string name) {
    this->name = std::move(name);
    this->answer = {"", false};
    this->startTime = std::time(nullptr);
    this->endTime = std::time(nullptr);
}

Goldfish::TestSuit::~TestSuit() = default;

void Goldfish::TestSuit::start() {
    this->startTime = std::time(nullptr);
}

[[maybe_unused]] void Goldfish::TestSuit::write(const Goldfish::Answer &input) {
    this->answer.out += input.out + "\n\n";
}

[[maybe_unused]] void Goldfish::TestSuit::write(const std::string &input) {
    this->answer.out += input + "\n\n";
}

void Goldfish::TestSuit::stop() {
    this->endTime = std::time(nullptr);
}