
#ifndef ADUL_EXCEPTIONS_HPP
#define ADUL_EXCEPTIONS_HPP

#include <exception>
#include <string>

namespace adul::exceptions {
    class Message;
    
    class FailedXMLFile;
    class FailedReadingXMLFile;
    class FailedWritingXMLFile;
}


class adul::exceptions::Message : std::exception {
protected:
    const char* msg;
public:
    Message();
    Message(const Message&) = default;
    Message(const std::string&);
    Message(const char*);
    virtual const char* what() const noexcept override;
};

    
class adul::exceptions::FailedXMLFile : std::exception {
protected:
    std::string path;
public:
    FailedXMLFile() = default;
    FailedXMLFile(const char* p_path);
    FailedXMLFile(const std::string& p_path);
    FailedXMLFile(const FailedXMLFile&) = default;
    virtual const char* what() const noexcept override;
};


class adul::exceptions::FailedReadingXMLFile : protected FailedXMLFile {
public:
    using FailedXMLFile::FailedXMLFile;
    virtual const char* what() const noexcept override;
};


class adul::exceptions::FailedWritingXMLFile : FailedXMLFile {
public:
    using FailedXMLFile::FailedXMLFile;
    virtual const char* what() const noexcept override;
};


#endif
