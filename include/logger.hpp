#ifndef ADUL_LOGS_HPP
#define ADUL_LOGS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <functional>

#include "time.hpp"
#include "exceptions.hpp"
namespace adul {

class Logger {

//This "Logger" class basically prints the messages to all the streams in "streams" vector if the object is "activated"
    
protected:
    time::Clock clock;
    std::vector<std::reference_wrapper<std::ostream>> streams;
    bool isActive = false;
public:
    
    Logger();

    void addStream(std::basic_ostream<char>& p_stream);
    
    void clearStreams();
    
    void start();
    
    void stop();
    
    bool isActivated() const;
    
    void push(const char *message) const;
    
    void push(const std::exception& err) const;
};

};

#endif