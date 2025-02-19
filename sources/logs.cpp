#include "../include/logs.hpp"

namespace adul {

Logs::Logs() {
    dir = "logs.txt";
    
    if(flagUseFileLogs) {
        std::fstream(dir, std::ios::out);
    }

}

Logs::Logs(char * p_dir) : dir(p_dir) {
    
    if(flagUseFileLogs) {
        std::fstream(dir, std::ios::out);
    }
}

void Logs::push(const std::string& message) const {
    if(flagUseFileLogs) {
        std::ofstream logs(dir, std::ios::app);

        logs << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
    }

    if(flagUseConsoleLogs) {
        std::cout << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
    }
}

void Logs::push(const char *message) const {
    if(flagUseFileLogs) {
        std::ofstream logs(dir, std::ios::app);

        logs << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
    }

    if(flagUseConsoleLogs) {
        std::cout << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
    }

}

}