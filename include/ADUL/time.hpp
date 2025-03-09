
#ifndef ADUL_TIMEMANAGER_HPP

#define ADUL_TIMEMANAGER_HPP

#include <chrono>
#include <vector>

#include "exceptions.hpp"

/**
 * @namespace adul
 * @brief project api's namespace
 * 
 */
namespace adul {

/**
 * @namespace adul::time
 * @brief time module
 * @details contains classes and functions for working with time
 * 
 */
namespace time {
    namespace chrono {
        using namespace std::chrono;
    }

    class Clock;
    
    class DurationsClock;
}

/**
 * @class time::Clock;
 * @brief wrapper for part of std::chrono::steady_clock STL interface
 * Must be started before usage
 */

class time::Clock {
    
protected:
    chrono::steady_clock::time_point startPoint;
    bool flagReady = false;
public:
    
    void start();
    
    void stop();
    
    bool isReady() const;
    
    chrono::steady_clock::duration timeElapsed() const;
};

/**
 * @class time::DurationsClock
 * @brief This class represent the sequence of durations and interface of working with them.
 * @details It uses std::chrono::steady_clock STL interface
 * Must be started before usage
 */

class time::DurationsClock {
    
protected:
    std::vector<chrono::steady_clock::duration> durations;
    
    chrono::steady_clock::time_point startPoint;
    
    chrono::steady_clock::duration currentDuration;
    
    bool flagReady = false;
    
public:
    void startNewDuration();
    
    chrono::steady_clock::duration getCurrentDuration() const;
    
    void pauseCurrentDuration();
    
    void continueCurrentDuration();
    
    void stopCurrentDuration();
    
    void saveCurrentDuration();
    
    void clearSavedDurations();
    
    const std::vector<chrono::steady_clock::duration>& getSavedDurations() const;
};

};

#endif