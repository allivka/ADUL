
#ifndef ADUL_EXCEPTIONS_HPP
#define ADUL_EXCEPTIONS_HPP

#include <exception>
#include <string>

/**
 * @namespace adul::exceptions
 * @brief exceptions module
 * 
 */
namespace adul::exceptions {
    class Message;
    
    class FailedXMLFile;
    class FailedReadingXMLFile;
    class FailedWritingXMLFile;
}

/**
 * @class adul::exceptions::Message
 * @brief modified std::exception class \n
 * The only difference is that you define message by yourself when create an object
 * 
 */
class adul::exceptions::Message : public std::exception {
protected:
    std::string msg = "!Error occurred! No info provided!\n";
    
public:
    Message() = default;
    Message(const std::string&);
    Message(const char*);
    virtual const char* what() const noexcept override;
};

/**
 * @class adul::exceptions::FailedXMLFile
 * @brief represents failure with working with XML file
 * 
 */
class adul::exceptions::FailedXMLFile : public std::exception {
protected:
    std::string msg = "Failed working with XML file";
public:
    FailedXMLFile() = default;
    FailedXMLFile(const std::string& p_msg);
    virtual const char* what() const noexcept override;
};


/**
 * @class adul::exceptions::FailedReadingXMLFile
 * @brief represents failure with reading from XML file
 * 
 */
class adul::exceptions::FailedReadingXMLFile : public FailedXMLFile {
public:
    FailedReadingXMLFile(const std::string& p_path);
    FailedReadingXMLFile(const FailedReadingXMLFile&) = default;
    FailedReadingXMLFile(FailedReadingXMLFile&&) = default;
};


/**
 * @class adul::exceptions::FailedWritingXMLFile
 * @brief represents failure with writing to XML file
 * 
 */
class adul::exceptions::FailedWritingXMLFile : public FailedXMLFile {
public:
    FailedWritingXMLFile(const std::string& p_path);
    FailedWritingXMLFile(const FailedWritingXMLFile&) = default;
    FailedWritingXMLFile(FailedWritingXMLFile&&) = default;
};


#endif
