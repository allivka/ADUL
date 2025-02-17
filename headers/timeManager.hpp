
#ifndef TIMEMANAGER_HPP

#define TIMEMANAGER_HPP

#include <chrono>
#include <vector>

namespace adul {

namespace chrono {
    using namespace std::chrono;
}

namespace tManager {
    size_t millis();
    
    void delay(const size_t& time);

    class Timer;
}

class tManager::Timer {
    protected:
        size_t startPoint;
        std::vector<size_t> durations;
    public:

        Timer();

        size_t stop();

        void start();

        size_t restart();

        size_t pause();

        void resume();

        size_t getCurDur() const;

        size_t getTotalDur() const;

        const std::vector<size_t>& getDurations() const;
    };
    
}

#endif