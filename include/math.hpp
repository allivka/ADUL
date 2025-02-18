#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>
#include <optional>
#include <SFML/Graphics.hpp>

namespace adul {

namespace Math {

    long double getVectorLength(const sf::Vector2<long double>& vec);

    long double getSegmentLength(const sf::Vector2<long double>& p1, const sf::Vector2<long double>& p2);

    std::optional<sf::Vector2<long double>> linesCross(const sf::Vector2<long double>& p1, const sf::Vector2<long double>& p2, 
    const sf::Vector2<long double>& p3, const sf::Vector2<long double>& p4, const long double& prec);

    std::optional<sf::Vector2<long double>> segmentsCross(const sf::Vector2<long double>& p1, const sf::Vector2<long double>& p2, 
    const sf::Vector2<long double>& p3, const sf::Vector2<long double>& p4, const long double& prec);
    
    sf::Vector2<long double> countCathetusesFromHypotenuseAndAlphaAngle(const long double& angleDegrees, const long double& hypLen);
    
    sf::Vector2<long double> getCoordsOfSegmentEndWithStartAtZeroFromLengthAndXAxisAngle(const long double& angleDegrees, const long double& segmentLen);

};

}

#endif
