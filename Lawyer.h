#ifndef LAWYER_H
#define LAWYER_H
#pragma once
#include <string>
#include <vector>
#include "service.h"

class Case; 

class Lawyer {
private:
    int id;
    std::string name;
    Service specialization;
    bool isAvailable;
    std::vector<const Case*> cases; 

public:
    Lawyer(int id, const std::string& name, const Service& specialization);

    int getId() const;
    std::string getName() const;
    Service getSpecialization() const;
    bool getAvailability() const;

    void setAvailability(bool available);
    void addCase(const Case* caseObj);
    std::vector<const Case*> getCases() const;
};
#endif