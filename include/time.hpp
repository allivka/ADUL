
#ifndef ADUL_TIMEMANAGER_HPP

#define ADUL_TIMEMANAGER_HPP

#include <chrono>
#include <vector>

#include "exceptions.hpp"
namespace adul {


namespace time {
    namespace chrono {
        using namespace std::chrono;
    }

    class Clock;
    
    class DurationsClock;
}

class time::Clock {

//This class is just a simple wrapper for std::chrono::steady_clock STL interface
    
protected:
    chrono::steady_clock::time_point startPoint;
    bool flagReady = false;
public:
    
    void start();
    
    void stop();
    
    bool isReady() const;
    
    chrono::steady_clock::duration timeElapsed() const;
};
    
class time::DurationsClock {
    
    //This class represent the sequence of durations and interface of working with them. It uses std::chrono::steady_clock STL interface
    
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