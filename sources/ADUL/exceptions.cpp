#include "../../include/ADUL/exceptions.hpp"

namespace adul::exceptions {

Message::Message(const char* p_msg) : msg(p_msg) { }

Message::Message(const std::string& p_msg) : msg(p_msg.c_str()) { }


const char* Message::what() const noexcept {
    return msg.c_str();
}

FailedXMLFile::FailedXMLFile(const std::string& p_msg) : msg("Failed working with XML file\nInfo:" + p_msg) {}

const char* FailedXMLFile::what() const noexcept {
    return msg.c_str();
}

FailedReadingXMLFile::FailedReadingXMLFile(const std::string& p_msg) : FailedXMLFile("Failed reading from XML file\nInfo: " + p_msg) {
    
}

FailedWritingXMLFile::FailedWritingXMLFile(const std::string& p_msg) : FailedXMLFile("Failed writing to XML file \nInfo:: " + p_msg) {
    
}

}