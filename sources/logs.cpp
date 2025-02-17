#include "../headers/logs.hpp"

namespace adul {

Logs::Logs() {
    dir = LOGSDIR;
    
#ifdef FILELOGS
    std::fstream(dir, std::ios::out);
#endif
}

Logs::Logs(const std::string& p_dir) : dir(p_dir) {
    
#ifdef FILELOGS
    std::fstream(dir, std::ios::out);
#endif
}

void Logs::push(const std::string& message) const {
#ifdef FILELOGS
    std::ofstream logs(dir, std::ios::app);

    logs << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
#endif

#ifdef CONSOLELOGS
    std::cout << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
#endif
}

void Logs::push(const char *message) const {
#ifdef FILELOGS
    std::ofstream logs(dir, std::ios::app);

    logs << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
#endif

#ifdef CONSOLELOGS
    std::cout << "[Time(ms): " << timer.getCurDur() / 1000 << "'" << timer.getCurDur() % 1000 << "]-> " << message << '\n';
#endif

}

}