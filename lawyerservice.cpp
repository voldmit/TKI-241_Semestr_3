#include "lawyerservice.h"


CourtService::CourtService(const std::string& type, double price)
    : Service("Introduction in case", price), type_(type) {
}

std::string CourtService::GetInfo() const
{
    return GetName() + " (" + type_ + ") | Price: " +
        std::to_string(GetPrice());
}