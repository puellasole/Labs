#include <iostream>
#include <memory>

enum class Color
{
    BLUE,
    GREEN,
    YELLOW
};

class Figure
{
protected:
    Color m_color;
    double m_x_coord, m_y_coord;
    double m_angles;

public:
    Figure(Color color, double x_coord, double y_coord, double angles) : m_color(color), m_x_coord(x_coord), m_y_coord(y_coord), m_angles(angles) { }
    virtual ~Figure() {}
    virtual double Area() = 0;
};

class Triangle : public Figure
{
private:
    double m_side_A, m_side_B, m_side_C;

public:
    Triangle(Color color, double x_coord, double y_coord, double side_A, double side_B, double side_C) : Figure(color, x_coord, y_coord, 3), m_side_A(side_A), m_side_B(side_B), m_side_C(side_C) { }

    double Area() override
    {
        double p = (m_side_A + m_side_B + m_side_C) / 2;
        return sqrt(p * (p - m_side_A) * (p - m_side_B) * (p - m_side_C));
    }

    ~Triangle() override {}
};

class Rectangle : public Figure
{
private:
    double m_height, m_width;

public:
    Rectangle(Color color, double x_coord, double y_coord, double height, double width) : Figure(color, x_coord, y_coord, 4), m_height(height), m_width(width) { }

    double Area() override
    {
        return m_height * m_width;
    }

    ~Rectangle() override {}
};

class Circle : public Figure
{
private:
    double m_radius;

public:
    Circle(Color color, double x_coord, double y_coord, double radius) : Figure(color, x_coord, y_coord, 0), m_radius(radius) { }

    double Area() override
    {
        return acos(-1) * m_radius * m_radius;
    }

    ~Circle() override {}
};

int main()
{
    std::unique_ptr<Figure> t = std::make_unique<Triangle>(Color::BLUE, 6, 7, 6, 5, 7);
    std::unique_ptr<Figure> r = std::make_unique<Rectangle>(Color::GREEN, 3, 5, 1, 9);
    std::unique_ptr<Figure> c = std::make_unique<Circle>(Color::YELLOW, 1, 2, 3);

    std::cout << t->Area() << ", ";
    std::cout << r->Area() << ", ";
    std::cout << c->Area();

    return 0;
}
