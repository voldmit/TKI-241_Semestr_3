#include "service.h"
Service::Service(int id, const std::string& name, double price)
	:id(id), name(name), price(price) {}

int Service::getId() const {
	return id;
}

std::string Service::getName() const {
	return name;
}

double Service::getPrice() const {
	return price;
}

void Service::setPrice(double price)
{
	this->price = price;
}