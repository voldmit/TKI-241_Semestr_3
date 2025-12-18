#include "lawyer.h"

Lawyer::Lawyer(const std::string& name, const std::string& specialization)
    : name_(name), specialization_(specialization), busy_(false) 
{}

std::string Lawyer::GetName() const
{
    return name_;
}
std::string Lawyer::GetSpecialization() const 
{ 
    return specialization_; 
}
bool Lawyer::IsFree() const 
{ 
    return !busy_; 
}
void Lawyer::SetBusy(bool busy) 
{ 
    busy_ = busy; 
}