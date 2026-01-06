#include "Shape.h"
#include <stdexcept>

Shape::Shape() : color("red") {}
Shape::Shape(std::string color) {
	if (color != "red" && color != "green" && color != "blue"){
		throw std::invalid_argument("Color no valido, Solo 'red', 'green', 'blue' son aceptados.");
	}
	this->color = color;
}
std::string Shape::get_color() const {
	return color;
}
void Shape::set_color(std::string c) {
	if (c != "red" && c != "green" && c != "blue") {
		throw std::invalid_argument("Color no valido. Solo 'red', 'green', 'blue' son aceptados.");
	}
	color = c;
}
double Shape::area() const {
	throw std::logic_error("Metodo no implementado en clase base Shape.");
}
double Shape::perimeter() const {
	throw std::logic_error("Metodo no implementado en clase base Shape.");
}

void Shape::translate(double incX, double incY) {
	throw std::logic_error("Metodo no implementado en clase base Shape.");
}

void Shape::print(){
	throw std::logic_error("Metodo no implementado en clase base Shape.");
}
