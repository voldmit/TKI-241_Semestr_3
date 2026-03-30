#include "client.h"
#include "case.h"

Client::Client(int id, const std::string& name, const std::string& contactInfo)
    : id(id), name(name), contactInfo(contactInfo) {
}

int Client::getId() const {
    return id;
}

std::string Client::getName() const {
    return name;
}

std::string Client::getContactInfo() const {
    return contactInfo;
}

void Client::addCase(const Case* caseObj) {
    if (caseObj) { 
        cases.push_back(caseObj); 
    }
}

std::vector<const Case*> Client::getCases() const {
    return cases; 
}