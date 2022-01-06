#include "include/libGoldfish.h"
#include <ctime>
#include <iomanip>

Goldfish::Log::Log(std::string filename) {
    if(filename == "") {
        this->fileName = "log.md";
    } else {
        this->fileName = filename+".md";
    }
}

[[maybe_unused]] void Goldfish::Log::start() {
    this->log.open(this->fileName);
}

[[maybe_unused]] void Goldfish::Log::write(const std::string& input) {
    log << input << "\n\n";
}

[[maybe_unused]] void Goldfish::Log::stop() {
    log.close();
}

Goldfish::Log::~Log() = default;

