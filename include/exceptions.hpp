
#ifndef ADUL_EXCEPTIONS_HPP
#define ADUL_EXCEPTIONS_HPP

#include <exception>

namespace adul::exceptions {
    class Message;
}

class adul::exceptions::Message : std::exception {
protected:
    const char* msg;
public:
    Message();
    Message(const Message&) = default;
    Message(const char*);
    virtual const char* what() const noexcept override;
};

#endif
