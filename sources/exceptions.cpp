#include "../include/exceptions.hpp"

namespace adul::exceptions {

Message::Message() {
    msg = "!Error occurred! No info provided!\n";
}

Message::Message(const char* p_msg) : msg(p_msg) { }

Message::Message(const std::string& p_msg) : msg(p_msg.c_str()) { }

const char* Message::what() const noexcept {
    return msg;
}

FailedXMLFile::FailedXMLFile(const char* p_path) : path(p_path) {}

FailedXMLFile::FailedXMLFile(const std::string& p_path) : path(p_path) {}

const char* FailedXMLFile::what() const noexcept {
    std::string res = "Failed working with XML file at path: " + path;
    return res.data();
}

const char* FailedReadingXMLFile::what() const noexcept {
    std::string res = "Failed reading from XML file at path: " + path;
    return res.data();
}

const char* FailedWritingXMLFile::what() const noexcept {
    std::string res = "Failed writing to XML file at path: " + path;
    return res.data();
}

}