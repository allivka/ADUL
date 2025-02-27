#ifndef LOGS_HPP
#define LOGS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <functional>

#include "timeManager.hpp"

namespace adul {

class Logger {

//This "Logger" class basically prints the messages to all the streams in "streams" vector if the object is "activated"
    
protected:
    tManager::Timer timer;
    std::vector<std::reference_wrapper<std::ostream>> streams;
    bool isActive = false;
public:
    
    Logger();

    void addStream(const std::basic_ostream<char>& p_stream);
    
    void clearStreams();
    
    void start();
    
    void stop();
    
    bool isActivated() const;
    
    void push(const std::string& message) const;

    void push(const char *message) const;
    
    void push(const std::exception& err) const;
};

}

#endif