#include "../include/exceptions.hpp"

namespace adul::exceptions {
    Message::Message() {
        msg = "!Error occurred! No info provided!\n";
    }
    
    Message::Message(const char* p_msg) : msg(p_msg) { }
    
    const char* Message::what() const noexcept {
        return msg;
    }
}