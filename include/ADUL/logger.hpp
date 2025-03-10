#ifndef ADUL_LOGS_HPP
#define ADUL_LOGS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <functional>

#include "time.hpp"
#include "exceptions.hpp"

namespace adul {

/**
 * @namespace adul::logs
 * @brief logging system module
 * 
 */
namespace logs {
/**
 * @class adul::Logger
 * @brief This is "Logger" class 
 * @details It basically prints the messages to all the streams in "streams" vector if the object is "isReady" and "isActive" \n
 * isReady represents the state if the logger is initialized \n
 * isActive represents the state if logger should work right now. \n 
 * isActive = false prevents logger::push method from working and doesn't throw any exceptions \n
 * Both isActive and isReady are false by default and must be modified via methods activate and start correspondingly \n
 */
class Logger {
    
protected:
    time::Clock clock;
    std::vector<std::reference_wrapper<std::ostream>> streams;
    bool flagReady = false;
    bool flagActive = true;
public:
    
    Logger();

    void addStream(std::basic_ostream<char>& p_stream);
    
    void clearStreams();
    
    void start();
    
    void stop();
    
    bool isReady() const;
    
    void activate();
    
    void deActivate();
    
    bool isActive() const;
    
    void push(const char *message) const;
    
    void push(const std::exception& err) const;
};

}

}

#endif