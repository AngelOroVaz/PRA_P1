#include "Drawing.h"
#include <iostream>

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0;
    for (int i = 0; i < shapes->size(); ++i) {
        if (Circle* circle = dynamic_cast<Circle*>(shapes->get(i))) {
            total_area += circle->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        if (Square* square = dynamic_cast<Square*>(shapes->get(i))) {
            square->translate(incX, incY);
        }
    }
}
