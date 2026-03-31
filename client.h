#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Person.h"

class Case;

class Client : public Person {
private:
    std::string contactInfo;
    std::vector<const Case*> cases;

public:
    Client(int id, const std::string& name, const std::string& contactInfo);

    std::string getContactInfo() const;
    void setContactInfo(const std::string& info);
    
    void addCase(const Case* caseObj);
    std::vector<const Case*> getCases() const;
    
    // Реализация виртуального метода
    std::string getInfo() const override;
};

#endif
