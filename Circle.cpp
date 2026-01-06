#include "Circle.h"
#include <cmath>
#include <stdexcept>
#include "Circle.h"

Circle::Circle() : Shape("red"), center(Point2D(0, 0)), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Círculo de color: " << c.get_color() << ", centro en (" 
        << c.get_center().get_x() << ", " << c.get_center().get_y() 
        << "), radio: " << c.get_radius();
    return out;
}

