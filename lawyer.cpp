#include "lawyer.h"
#include "case.h"
#include <sstream>

Lawyer::Lawyer(int id, const std::string& name, const Service& specialization)
    : Person(id, name), specialization(specialization), isAvailable(true) {
}

Service Lawyer::getSpecialization() const {
    return specialization;
}

void Lawyer::setSpecialization(const Service& spec) {
    specialization = spec;
}

bool Lawyer::getAvailability() const {
    return isAvailable;
}

void Lawyer::setAvailability(bool available) {
    isAvailable = available;
}

void Lawyer::addCase(const Case* caseObj) {
    if (caseObj) {
        cases.push_back(caseObj);
        isAvailable = false;
    }
}

std::vector<const Case*> Lawyer::getCases() const {
    return cases;
}

std::string Lawyer::getInfo() const {
    std::ostringstream oss;
    oss << "Адвокат ID: " << id << ", Имя: " << name 
        << ", Специализация: " << specialization.getName()
        << ", Доступен: " << (isAvailable ? "Да" : "Нет");
    return oss.str();
}
