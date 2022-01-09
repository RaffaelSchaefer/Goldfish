#include <utility>

#include "Goldfish/libGoldfish.h"

[[maybe_unused]] Goldfish::TestSuit::TestSuit(std::string name) {
    this->name = std::move(name);
    this->answer = {"", false};
    this->startTime = std::time(nullptr);
    this->endTime = std::time(nullptr);
}

Goldfish::TestSuit::~TestSuit() = default;

