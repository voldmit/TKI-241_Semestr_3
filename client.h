#pragma once
#include <string>

class Client
{
public:
    Client(const std::string& name);
    std::string GetName() const;

private:
    std::string name_;
};
