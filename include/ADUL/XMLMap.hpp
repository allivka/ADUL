
#ifndef XMLMAP_HPP

#define XMLMAP_HPP

#include "../extern/tinyxml2.hpp"
#include "exceptions.hpp"
#include "smallUtils.hpp"

#include <unordered_map>

namespace adul { namespace atm {
  
/**
 * @brief this class is wrapper for STL container std::unordered_map
 * @details this class is wrapper for std::unordered_map and provides some functions to save and read data from XML files and XML elements \n 
 * these functions use tinyxml2 library api and are supposed to be used along with it \n 
 * all the map elements are placed in the XML element each with name "mapElement" and key and value of map element are stored as attributes of this XML element
 * if these functions fail they throw exceptions of adul::exceptions module
 */
template <typename keyT, typename valueT> class XMLMap {
public:
  std::unordered_map<keyT, valueT> map;

  void savePropsToXMLElement(adul::xml::XMLElement *const pElement, adul::xml::XMLDocument *const xmlDoc) const {
    adul::xml::XMLElement *pSubEl = nullptr;

    for (auto cur = map.begin(); cur != map.end(); cur++) {
      pSubEl = xmlDoc->NewElement("mapElement");

      pSubEl->SetAttribute("key", cur->first);
      pSubEl->SetAttribute("value", cur->second);

      pElement->InsertEndChild(pSubEl);
    }
  }

  void loadPropsFromXMLElement(const adul::xml::XMLElement *const pElement) {

    const adul::xml::XMLElement *pSubEl =
        pElement->FirstChildElement("mapElement");

    while (pSubEl != nullptr) {
      map[adul::utils::convert_string<keyT>(std::string(pSubEl->Attribute("key")))] =
      adul::utils::convert_string<valueT>(std::string(pSubEl->Attribute("value")));
      pSubEl = pSubEl->NextSiblingElement("mapElement");
    }
  }

  void savePropsToXMLFile(const char *dir) {

    try {

      adul::xml::XMLDocument document;
      adul::xml::XMLElement *pRoot = document.NewElement("root");

      savePropsToXMLElement(pRoot, &document);
      document.InsertFirstChild(pRoot);

      if (document.SaveFile(dir) != adul::xml::XMLError::XML_SUCCESS)
        throw adul::exceptions::FailedWritingXMLFile(dir);

    } catch (const char *error) {
      throw adul::exceptions::FailedWritingXMLFile(error);
    } catch (const adul::exceptions::FailedWritingXMLFile &error) {
      throw;
    }
  }

  void loadPropsFromXMLFile(const char *dir) {

    try {

      adul::xml::XMLDocument document;

      if (document.LoadFile(dir) != adul::xml::XMLError::XML_SUCCESS)
        throw adul::exceptions::FailedReadingXMLFile(dir);

      adul::xml::XMLElement *pRoot = document.FirstChildElement("root");

      loadPropsFromXMLElement(pRoot);

    } catch (const char *error) {
      throw adul::exceptions::FailedReadingXMLFile(error);
    } catch (const adul::exceptions::FailedReadingXMLFile &error) {
      throw;
    }
  }
};

}} // namespace adul
#endif
