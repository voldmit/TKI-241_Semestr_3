#include "client.h"
#include "case.h"
#include <sstream>

Client::Client(int id, const std::string& name, const std::string& contactInfo)
    : Person(id, name), contactInfo(contactInfo) {
}

std::string Client::getContactInfo() const {
    return contactInfo;
}

void Client::setContactInfo(const std::string& info) {
    contactInfo = info;
}

void Client::addCase(const Case* caseObj) {
    if (caseObj) {
        cases.push_back(caseObj);
    }
}

std::vector<const Case*> Client::getCases() const {
    return cases;
}

std::string Client::getInfo() const {
    std::ostringstream oss;
    oss << "Клиент ID: " << id << ", Имя: " << name 
        << ", Контакты: " << contactInfo;
    return oss.str();
}
