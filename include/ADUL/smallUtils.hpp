#ifndef SMALLUTILS_HPP
#define SMALLUTILS_HPP

#include <string>
#include <sstream>
#include <stdexcept>

namespace adul {

  /**
   * @namespace adul::utils
   * @brief small utilities module
   * @details namespace module which includes different small functions or classes
   */
  namespace utils {
    /**
     * @brief converts std::string into other type
     * @details converts given std::string into thy T type using std::istringstream
     * @tparam T 
     * @brief type to which std::string will be converted 
     * @details type T must be supported by sdt::basic_stringstream operator>>
     */
    template<typename T> T convert_string(const std::string& str) {
      T result;
      std::istringstream iss(str);
      iss >> result;
      if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Conversion failed: '" + str + "' to type " + typeid(T).name());
      }
      return result;
    }

    template<> inline std::string convert_string<std::string>(const std::string& str) {
      return str;
    }
  }
}

#endif // !SMALLUTILS_HPP

