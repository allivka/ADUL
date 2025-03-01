#include "../include/ADUL/time.hpp"

namespace adul::time {
    
    void Clock::start() {
        startPoint = chrono::steady_clock::now();
        flagReady = true;
    }

    chrono::steady_clock::duration Clock::timeElapsed() const {
        if(flagReady) return chrono::steady_clock::now() - startPoint;
        else throw exceptions::Message("Error! Clock is not ready!\n");
    }
    
    void Clock::stop() {
        flagReady = false;
    }

    bool Clock::isReady() const {
        return flagReady;
    }
    
    
    void DurationsClock::startNewDuration() {
        startPoint = chrono::steady_clock::now();
        flagReady = true;
    }
    
    chrono::steady_clock::duration DurationsClock::getCurrentDuration() const {
        if(flagReady) return currentDuration + (chrono::steady_clock::now() - startPoint);
        else throw exceptions::Message("!Error! Clock is not ready!\n");
    }
    
    void DurationsClock::pauseCurrentDuration() {
        currentDuration += (chrono::steady_clock::now() - startPoint);
        flagReady = false;
    }
    
    void DurationsClock::continueCurrentDuration() {
        startPoint = chrono::steady_clock::now();
        flagReady = true;
    }
    
    void DurationsClock::stopCurrentDuration() {
        currentDuration = chrono::steady_clock::duration();
        flagReady = false;
    }
    
    void DurationsClock::saveCurrentDuration() {
        currentDuration += (chrono::steady_clock::now() - startPoint);
        durations.emplace_back(currentDuration);
    }
    
    void DurationsClock::clearSavedDurations() {
        durations.clear();
    }
    
    const std::vector<chrono::steady_clock::duration>& DurationsClock::getSavedDurations() const {
        return durations;
    }
    
};
