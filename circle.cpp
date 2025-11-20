void Circle::print() const{
	std::cout << "Circle(color="<< center.y
		  << "), radius=" <<radius << ")\n";
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
	/*out << "Circle(Color=" << c.color
	 << ", center=(" << c.center.x << ", "<< c.center.y
	 << "), radius =" << c.radius <<")";*/
	c.print();
	return out;
}
