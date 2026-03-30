#include "lawyer.h"
#include "case.h"

Lawyer::Lawyer(int id, const std::string& name, const Service& specialization)
    : id(id), name(name), specialization(specialization), isAvailable(true) {
}

int Lawyer::getId() const {
    return id;
}

std::string Lawyer::getName() const {
    return name;
}

Service Lawyer::getSpecialization() const {
    return specialization;
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
    }
}

std::vector<const Case*> Lawyer::getCases() const {
    return cases; 
}