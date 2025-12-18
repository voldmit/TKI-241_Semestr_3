#pragma once
#include <vector>
#include <string>
#include "lawyer.h"
#include "Case.h"
#include "Service.h"   
#include "Client.h"

class LawOffice
{
public:
    void AddLawyer(Lawyer* lawyer);
    void AddCase(Case* legalCase);

    std::vector<Service*> GetServices() const;
    std::vector<Client*> GetClientsByService(const std::string& serviceName) const;
    std::vector<Lawyer*> GetFreeLawyers(const std::string& specialization) const;
    std::string GetCaseDescription(int caseNumber) const;

private:
    std::vector<Lawyer*> lawyers_;
    std::vector<Case*> cases_;
};