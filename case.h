
#ifndef CASE_H
#define CASE_H
#include <string>

class Client;
class Lawyer;

class Case {
private:
    int caseNumber;
    std::string content;
    const Lawyer* lawyer;
    const Client* client;

public:
    Case(int caseNumber, const std::string& content, const Lawyer* lawyer, const Client* client);

    int getCaseNumber() const;
    std::string getContent() const;
    const Lawyer* getLawyer() const;
    const Client* getClient() const;
};
#endif