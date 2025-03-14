#include "../include/ADUL/logger.hpp"

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

template<typename T> void Logger::push(T message) const {
    if(!flagActive) return;
    if(!flagReady) throw exceptions::Message("!Error! Logger is not ready!\n");
    
    for(uint64_t i = 0; i < streams.size(); i++) {
        if(!streams[i].get().good()) continue;
        streams[i].get() << "[Time: " << std::chrono::duration_cast<std::chrono::seconds>(clock.timeElapsed()).count() << "s " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(clock.timeElapsed()).count() % 1000 << "ms]-> " 
        << message << '\n';
    }
}

void Logger::push(const std::exception& msg) const {
    Logger::push(msg.what());
}

}