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
     * @details if "flagActive" is false doesn't do anything \n
     * if  "flagReady" is true runs properly, otherwise throws an adul::exceptions::message \n 
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
    template<typename T> void push(const T& message) const {
        if(!flagActive) return;
        if(!flagReady) throw exceptions::Message("!Error! Logger is not ready!\n");
        
        for(size_t i = 0; i < streams.size(); i++) {
            if(!streams[i].get().good()) continue;
            adul::time::chrono::steady_clock::duration elapsed = clock.timeElapsed();
            streams[i].get() << "[Time: "<< 
            std::chrono::duration_cast<std::chrono::hours>(elapsed).count() << "h " << 
            std::chrono::duration_cast<std::chrono::minutes>(elapsed).count() % 60 << "m " << 
            std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() % 60 << "s " << 
            std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() % 1000 << "ms]-> " 
            << message << '\n';
        }
    }
};

}

}

#endif
