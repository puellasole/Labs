#pragma once

#include "Shape.hpp"

namespace sh {

    class Rectangle : public sh::Shape {
    public:
        Rectangle(double x, double y, const std::string& colour, double a,
            double b) : Shape(x, y, colour) {
            if ((a > 0) && (b >= 0)) {
                this->a = a;
                this->b = b;
            }
        };

        double calculateArea() override;

    private:
        double a, b;


    };

}
