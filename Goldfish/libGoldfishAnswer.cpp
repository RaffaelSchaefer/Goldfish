#include "include/libGoldfish.h"

Goldfish::Answer::Answer() {
    this->out = "";
    this->passed = false;
    this->time = std::time(nullptr);
}

Goldfish::Answer::~Answer() = default;
