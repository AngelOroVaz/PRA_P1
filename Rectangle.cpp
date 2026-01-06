#include "Rectangle.h"

Rectangle::Rectangle() : Shape("red"), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1.0, 0.5);
    vs[1] = Point2D(1.0, 0.5);
    vs[2] = Point2D(1.0, -0.5);
    vs[3] = Point2D(-1.0, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no conforman un rectángulo válido");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no conforman un rectángulo válido");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectángulo de color: " << r.get_color() << ", vértices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << "(" << r.vs[i].get_x() << ", " << r.vs[i].get_y() << ")";
        if (i < Rectangle::N_VERTICES - 1) {
            out << ", ";
        }
    }
    return out;
}

bool Rectangle::check(Point2D* vertices) {
    double d1 = vertices[0].distance(vertices[1]);
    double d2 = vertices[1].distance(vertices[2]);
    double d3 = vertices[2].distance(vertices[3]);
    double d4 = vertices[3].distance(vertices[0]);
    return (d1 == d3 && d2 == d4);
}
