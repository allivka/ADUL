
#ifndef ADUL_XMLMAP_HPP
#define ADUL_XMLMAP_HPP

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

  void saveMapToXMLElement(adul::xml::XMLElement *const pElement, adul::xml::XMLDocument *const xmlDoc) const {
    adul::xml::XMLElement *pSubEl = nullptr;

    for (auto cur = map.begin(); cur != map.end(); cur++) {
      pSubEl = xmlDoc->NewElement("mapElement");

      pSubEl->SetAttribute("key", 
        adul::utils::convert_string<std::string>(cur->first).c_str());
      pSubEl->SetAttribute("value", 
        adul::utils::convert_string<std::string>(cur->second).c_str());

      pElement->InsertEndChild(pSubEl);
    }
  }

  void loadMapFromXMLElement(const adul::xml::XMLElement *const pElement) {
    const adul::xml::XMLElement *pSubEl =
        pElement->FirstChildElement("mapElement");

    while (pSubEl != nullptr) {
      const char* keyAttr = pSubEl->Attribute("key");
      const char* valueAttr = pSubEl->Attribute("value");
      if (!keyAttr || !valueAttr) {
        throw adul::exceptions::Message("Missing key/value attribute in XML");
      }

      map[adul::utils::convert_string<keyT>(keyAttr)] =
          adul::utils::convert_string<valueT>(valueAttr);
      pSubEl = pSubEl->NextSiblingElement("mapElement");
    }
  }

  void saveMapToXMLFile(const char *dir) {
    adul::xml::XMLDocument document;
    adul::xml::XMLElement *pRoot = document.NewElement("root");

    saveMapToXMLElement(pRoot, &document);
    document.InsertFirstChild(pRoot);

    if (document.SaveFile(dir) != adul::xml::XMLError::XML_SUCCESS)
      throw adul::exceptions::FailedWritingXMLFile(dir);
  }

  void loadMapFromXMLFile(const char *dir) {
    adul::xml::XMLDocument document;

    if (document.LoadFile(dir) != adul::xml::XMLError::XML_SUCCESS)
      throw adul::exceptions::FailedReadingXMLFile(dir);

    adul::xml::XMLElement *pRoot = document.FirstChildElement("root");
    if (!pRoot) throw adul::exceptions::FailedReadingXMLFile("Missing root element");

    loadMapFromXMLElement(pRoot);
  }
};

}} // namespace adul
#endif
