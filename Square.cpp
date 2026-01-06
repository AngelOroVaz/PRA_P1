#include "Square.h"

Square::Square() : Rectangle("red", new Point2D[4]{Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for a square");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for a square");
    }
    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream& out, const Square& square) {
    out << "Cuadrado de color: " << square.get_color();
    out << ", vertices: ";
    for (int i = 0; i < N_VERTICES; i++) {
        out << "(" << square.get_vertex(i).get_x() << ", " << square.get_vertex(i).get_y() << ") ";
    }
    return out;
}
