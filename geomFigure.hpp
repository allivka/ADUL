
#ifndef GEOMFIGURE_HPP
#define GEOMFIGURE_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "object.hpp"
#include "geomPoint.hpp"
#include "tinyxml2.hpp"
class GeomFigure : public sf::Drawable, public Object {

public:
    std::vector<GeomPoint> points;

    GeomFigure();
    
    GeomFigure(const GeomFigure& obj) = default;

    GeomPoint& at(const size_t& idx);
    
    const GeomPoint& at(const size_t& idx) const;

    GeomPoint& operator[](const size_t& idx);
    
    const GeomPoint& operator[](const size_t& idx) const;
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void saveToXMLElement(xml::XMLElement* const pElement, xml::XMLDocument* const xmlDoc) const;

    void loadFromXMLElement(const xml::XMLElement* const pElement);
};

#endif