#ifndef LOGS_HPP
#define LOGS_HPP

#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

#include "timeManager.hpp"
#include "compileSettings.hpp"

namespace adul {

class Logs {
protected:
    tManager::Timer timer;
public:
    std::string dir;

    Logs();

    Logs(const std::string& p_dir);

    void push(const std::string& message) const;

    void push(const char *message) const;
};

}

#endif