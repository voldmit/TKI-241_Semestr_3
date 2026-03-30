#ifndef LAWYER_H
#define LAWYER_H

#include <string>
#include <vector>
#include "Person.h"
#include "service.h"

class Case;

class Lawyer : public Person {
private:
    Service specialization;
    bool isAvailable;
    std::vector<const Case*> cases;

public:
    Lawyer(int id, const std::string& name, const Service& specialization);

    Service getSpecialization() const;
    void setSpecialization(const Service& spec);
    
    bool getAvailability() const;
    void setAvailability(bool available);
    
    void addCase(const Case* caseObj);
    std::vector<const Case*> getCases() const;
    
    // Реализация виртуального метода
    std::string getInfo() const override;
};

#endif
