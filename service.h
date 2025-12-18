#pragma once
#include <string>

class Service
{
public:
    Service(const std::string& name, double price);
    virtual ~Service() = default;

    std::string GetName() const;
    double GetPrice() const;

    virtual std::string GetInfo() const = 0;

private:
    std::string name_;
    double price_;
};
