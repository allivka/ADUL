#include "../include/logger.hpp"

namespace adul {


Logger::Logger() { }

void Logger::addStream(std::basic_ostream<char>& p_stream) {
    streams.emplace_back(p_stream);
}

void Logger::clearStreams() {
    streams.clear();
}

void Logger::start() {
    clock.start();
    isActive = 1;
}

void Logger::stop() {
    clock.stop();
    isActive = 0;
}

bool Logger::isActivated() const {
    return isActive;
}

void Logger::push(const char *message) const {
    if(!isActive) throw exceptions::Message("!Error! Logger is not activated!\n");
    
    for(uint64_t i = 0; i < streams.size(); i++) {
        if(streams[i].get().good()) continue;
        streams[i].get() << "[Time(s'ms): " << std::chrono::duration_cast<std::chrono::seconds>(clock.timeElapsed()).count() << "'" << 
        std::chrono::duration_cast<std::chrono::milliseconds>(clock.timeElapsed()).count() << "]-> " 
        << message << '\n';
    }
}

void Logger::push(const std::exception& msg) const {
    Logger::push(msg.what());
}

}