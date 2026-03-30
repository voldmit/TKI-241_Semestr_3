#pragma once
#include <string>
#include <vector>

class Case; 

class Client {
private:
    int id;
    std::string name;
    std::string contactInfo;
    std::vector<const Case*> cases;

public:
    Client(int id, const std::string& name, const std::string& contactInfo);

    int getId() const;
    std::string getName() const;
    std::string getContactInfo() const;

    void addCase(const Case* caseObj);
    std::vector<const Case*> getCases() const;
};
