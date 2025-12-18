#include "CONSULTATION.h"

Consultation::Consultation(double price)
    : Service("Consultation", price) {
}

std::string Consultation::GetInfo() const
{
    return GetName() + " Price : " + std::to_string(GetPrice());
}