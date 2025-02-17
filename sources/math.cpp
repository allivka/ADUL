#include "../headers/math.hpp"
namespace adul {

long double Math::getVectorLength(const sf::Vector2<long double>& vec) {
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

long double Math::getSegmentLength(const sf::Vector2<long double>& p1, const sf::Vector2<long double>& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

std::optional<sf::Vector2<long double>> Math::linesCross(const sf::Vector2<long double>& p1, const sf::Vector2<long double>& p2, const sf::Vector2<long double>& p3, 
const sf::Vector2<long double>& p4, const long double& prec) {

    const long double A1 = p2.y - p1.y;
    const long double B1 = p1.x - p2.x;
    const long double C1 = p1.y * p2.x - p1.x * p2.y;

    const long double A2 = p4.y - p3.y;
    const long double B2 = p3.x - p4.x;
    const long double C2 = p3.y * p4.x - p3.x * p4.y;

    const long double oprAB = A1 * B2 - A2 * B1;

    std::optional<sf::Vector2<long double>> resP;

    if(oprAB < prec) return resP;

    const long double oprX = -(C1 * B2 - C2 * B1);
    const long double oprY = -(A1 * C2 - A2 * C1);

    resP->x = oprX / oprAB;
    resP->y = oprY / oprAB;

    return resP;
}

 std::optional<sf::Vector2<long double>> Math::segmentsCross(const sf::Vector2<long double>& p1, const sf::Vector2<long double>& p2, const sf::Vector2<long double>& p3, 
 const sf::Vector2<long double>& p4, const long double& prec) {

    std::optional<sf::Vector2<long double>> resP;

    resP = linesCross(p1, p2, p3, p4, prec);

    if(!resP) {
        resP.reset();
        return resP;
    }

    if(std::abs(getSegmentLength(p1, p2) - (getSegmentLength(p1, *resP) + getSegmentLength(p2, *resP))) < prec) resP.reset();

    if(std::abs(getSegmentLength(p3, p4) - (getSegmentLength(p3, *resP) + getSegmentLength(p4, *resP))) < prec) resP.reset();

    return resP;
}

sf::Vector2<long double> Math::countCathetusesFromHypotenuseAndAlphaAngle(const long double& angleDegrees, const long double& hypLen) {
    long double angle = angleDegrees * M_PI / 180.0;
    long double x = hypLen * cos(angle);
    long double y = hypLen * sin(angle);
    
    return sf::Vector2<long double>(x, y);
};

sf::Vector2<long double> Math::getCoordsOfSegmentEndWithStartAtZeroFromLengthAndXAxisAngle(const long double& angleDegrees, const long double& segmentLen) {
    long double angle = fmod(fmod(angleDegrees, 360) + 360, 360);
    long double adjustedAngle = fmod(angle, 90);
    sf::Vector2<long double> coords = countCathetusesFromHypotenuseAndAlphaAngle(adjustedAngle, segmentLen);
    
    if(0 <= angle && angle < 90) {
        return coords;
    } else if (90 <= angle && angle < 180) {
        std::swap(coords.x, coords.y);
        coords.x *= -1;
    } else if (180 <= angle && angle < 270) {
        coords.x *= -1;
        coords.y *= -1;
    } else {
        std::swap(coords.x, coords.y);
        coords.y *= -1;
    }
    
    return coords;
}

}