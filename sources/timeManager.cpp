#include "../include/timeManager.hpp"

namespace adul {

size_t tManager::millis() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

void tManager::delay(const size_t& time) {
    size_t start = millis();
    while(millis() - start <= time);
}

tManager::Timer::Timer() {
    startPoint = millis();
}

size_t tManager::Timer::stop() {

    size_t temp = millis() - startPoint;

    durations.clear();
    startPoint = 0;

    return temp;
}

void tManager::Timer::start() {

    durations.clear();
    startPoint = millis();

}

size_t tManager::Timer::restart() {
    size_t temp = millis() - startPoint;

    for(size_t i = 0; i < durations.size(); i++) {
        temp += durations[i];
    }

    durations.clear();
    startPoint = millis();

    return temp;
}

size_t tManager::Timer::pause() {
    size_t temp = millis() - startPoint;

    durations.push_back(temp);
    startPoint = 0;

    return temp;
}

void tManager::Timer::resume() {
    startPoint = millis();

}

size_t tManager::Timer::getCurDur() const {
    return millis() - startPoint;
}

size_t tManager::Timer::getTotalDur() const {
    size_t temp = 0;

    for(size_t i = 0; i < durations.size(); i++) {
        temp += durations[i];
    }

    return temp;
}

const std::vector<size_t>& tManager::Timer::getDurations() const {
    return durations;
}

}
