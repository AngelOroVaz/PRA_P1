#ifdef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {

protected:
	std::string color;

public:
	Shape(const std::string color = "red");

	Shape::Shape(std::string c){
		if (c != "red" && c != "green" && c != "blue"){
			throw std::invalid_argument("El color no es valido");
		}
		color = c;
	}
	std::string get_color() const{
		return color;
	}
