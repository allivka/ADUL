#include "../include/logger.hpp"

namespace adul {



Logger::Logger() {
    
}

void Logger::addStream(const std::basic_ostream<char>& p_stream) {
    streams.emplace_back(p_stream);
}

void Logger::clearStreams() {
    streams.clear();
}

void Logger::start() {
    timer.start();
    isActive = 1;
}

void Logger::stop() {
    timer.stop();
    isActive = 0;
}

bool Logger::isActivated() const {
    return isActive;
}

void Logger::push(const std::string& message) const {
    if(!isActive) return;
    
    for(uint64_t i = 0; i < streams.size(); i++) {
        if(streams[i].get().good()) continue;
        streams[i].get() << "[Time(s'ms): " << (timer.getCurDur() / 1000) << "'" << (timer.getCurDur() % 1000) << "]-> " << message << '\n';
    }
}

void Logger::push(const char *message) const {
    if(!isActive) return;
    
    for(uint64_t i = 0; i < streams.size(); i++) {
        if(streams[i].get().good()) continue;
        streams[i].get() << "[Time(s'ms): " << (timer.getCurDur() / 1000) << "'" << (timer.getCurDur() % 1000) << "]-> " 
        << message << '\n';
    }
}

void Logger::push(const std::exception& err) const {

    if(!isActive) return;
        
    for(uint64_t i = 0; i < streams.size(); i++) {
        if(streams[i].get().good()) continue;
        streams[i].get() << "[Time(s'ms): " << (timer.getCurDur() / 1000) << "'" << (timer.getCurDur() % 1000) << "]-> " 
        << err.what() << '\n';
    }
}