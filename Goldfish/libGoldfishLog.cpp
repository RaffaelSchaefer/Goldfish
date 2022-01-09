#include "Goldfish/libGoldfish.h"
#include <ctime>

[[maybe_unused]] Goldfish::Log::Log(const std::string &filename) {
    this->fileName = filename + ".md";
    this->startTime = std::time(nullptr);
    this->endTime = std::time(nullptr);
}

[[maybe_unused]] void Goldfish::Log::start() {
    this->log.open(this->fileName);
    this->startTime = std::time(nullptr);
    log << "# " << this->fileName << "\n\n## Start\n\nDate: " << std::asctime(std::localtime(&this->startTime)) << "\n"
        << "### Tests\n\n";
}

[[maybe_unused]] void Goldfish::Log::write(const Goldfish::Answer &input) {
    if (input.passed) {
        log << "✔ " << input.out << "\n\n";
    } else {
        log << "❌ " << input.out << "\n\n";
    }
}

[[maybe_unused]] void Goldfish::Log::write(const Goldfish::TestSuit &input) {
    log << input.answer.out << "\n\n";
}

[[maybe_unused]] void Goldfish::Log::write(const std::string &input) {
    log << input << "\n\n";
}

[[maybe_unused]] void Goldfish::Log::stop() {
    this->endTime = std::time(nullptr);
    log << "## End\n\nTest Duration: **" << endTime - startTime << " seconds**\n";
    log.close();
}

Goldfish::Log::~Log() = default;

