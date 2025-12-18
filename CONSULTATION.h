#pragma once
#include "service.h"

class Consultation : public Service
{
public:
    Consultation(double price);
    std::string GetInfo() const override;
};