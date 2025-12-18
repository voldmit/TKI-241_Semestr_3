#include "service.h"

Service::Service(const std::string& name, double price)
    : name_(name), price_(price) {
}

std::string Service::GetName() const { return name_; }
double Service::GetPrice() const { return price_; }