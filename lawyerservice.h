#pragma once
#include "service.h"
#include <string>

class CourtService : public Service
{
public:
    CourtService(const std::string& type, double price);
    std::string GetInfo() const override;

private:
    std::string type_;
};
