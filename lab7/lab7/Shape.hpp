#pragma once

#include <string>
#include <utility>
#include <iostream>
#include <cmath>
#include <utility>

namespace sh {

    class Shape {
    public:
        Shape(double x, double y, std::string colour) : x(x), y(y), colour(std::move(colour)) {};

        virtual ~Shape() = default;

        virtual double calculateArea() = 0;

        void printArea() const {
            if (area != -1)
                std::cout << area << std::endl;
        };

        static constexpr double PI = 3.14;
        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        double getArea() const {
            return area;
        }

        const std::string& getColour() const {
            return colour;
        }

    protected:
        double y;
        double x;
        double area = -1;
        std::string colour;

    };

}
