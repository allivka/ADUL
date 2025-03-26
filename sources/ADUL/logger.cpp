#include "../../include/ADUL/logger.hpp"

namespace adul::logs {


Logger::Logger() { }

void Logger::addStream(std::basic_ostream<char>& p_stream) {
    streams.emplace_back(p_stream);
}

void Logger::clearStreams() {
    streams.clear();
}

void Logger::start() {
    clock.start();
    flagReady = true;
}

void Logger::stop() {
    clock.stop();
    flagReady = false;
}

bool Logger::isReady() const {
    return flagReady;
}

void Logger::activate() {
    flagActive = true;
}

void Logger::deactivate() {
    flagActive = false;
}

bool Logger::isActive() const {
    return flagActive;
}

}