#pragma once
#include <string>

class Lawyer
{
public:
    Lawyer(const std::string& name, const std::string& specialization);

    std::string GetName() const;
    std::string GetSpecialization() const;
    bool IsFree() const;
    void SetBusy(bool busy);

private:
    std::string name_;
    std::string specialization_;
    bool busy_;
};

