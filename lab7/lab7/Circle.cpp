#include "Circle.hpp"

namespace sh {


    double Circle::calculateArea() {
        area = PI * radius;
        return area;
    }

    double Circle::getRadius() const {
        return radius;
    }

}