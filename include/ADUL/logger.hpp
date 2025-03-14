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
 * @class adul::logs::Logger
 * @brief This is "Logger" class 
 * @details It basically prints the messages to all the streams in "streams" vector if the object is "flagReady" and "flagActive" \n
 * isReady represents the state if the logger is initialized \n
 * isActive represents the state if logger should work right now. \n 
 * isActive = false prevents logger::push method from working and doesn't throw any exceptions \n
 * Both "flagActive" and "flagReady" are false by default and must be modified via methods activate and start correspondingly \n
 */
class Logger {
    
protected:
    time::Clock clock;
    std::vector<std::reference_wrapper<std::ostream>> streams;
    bool flagReady = false;
    bool flagActive = false;
public:
    
    Logger();

    void addStream(std::basic_ostream<char>& p_stream);
    
    void clearStreams();
    
    /**
     * @brief initializes the logger
     * @details sets the "flagReady" to true and starts clock since initialization
     * 
     */
    void start();
    
    /**
     * @brief stops the logger
     * @details sets "flagReady" to false and stops the timer;
     * 
     */
    void stop();
    
    bool isReady() const;
    
    /**
     * @brief activates the timer
     * @details sets the "flagActive" to true
     * 
     */
    void activate();
    
    /**
     * @brief deactivates the timer
     * @details sets the "flagActive" to false
     * 
     */
    void deactivate();
    
    bool isActive() const;
    
    /**
     * @brief pushes message to all the logger streams
     * @details if object "flagActive" doesn't do anything \n
     * if object is "flagReady" runs properly, otherwise throws an adul::exceptions::message \n 
     * before every message it prints the time since last usage of start() method in milliseconds
     * 
     * @param message is message to be pushed in all the streams
     * 
     * @see adul#exceptions#Message "Message exception class"
     * @see start "start() method"
     * @see stop "stop() method"
     * @see activate "activate() method"
     * @see deactivate "deactivate() method"
     */
    template<typename T >void push(T message) const;
    
    /**
     * @brief pushes message of exception to all the logger streams
     * @details acts similarly to @ref push "push method" but extracts message from exception class object
     * 
     * @param message is std::exception class or inherited from it, which must implement what() method, which is needed to extract message from the class
     */
    void push(const std::exception& message) const;
};

}

}

#endif