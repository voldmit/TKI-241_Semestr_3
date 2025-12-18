#include "firm.h"

void LawOffice::AddLawyer(Lawyer* lawyer)
{
    lawyers_.push_back(lawyer);
}

void LawOffice::AddCase(Case* legalCase)
{
    cases_.push_back(legalCase);
}

std::vector<Service*> LawOffice::GetServices() const
{
    std::vector<Service*> result;
    for (auto c : cases_)
        result.push_back(c->GetService());
    return result;
}

std::vector<Client*> LawOffice::GetClientsByService(const std::string& serviceName) const
{
    std::vector<Client*> result;
    for (auto c : cases_)
        if (c->GetService()->GetName() == serviceName)
            result.push_back(c->GetClient());
    return result;
}

std::vector<Lawyer*> LawOffice::GetFreeLawyers(const std::string& specialization) const
{
    std::vector<Lawyer*> result;
    for (auto l : lawyers_)
        if (l->IsFree() && l->GetSpecialization() == specialization)
            result.push_back(l);
    return result;
}

std::string LawOffice::GetCaseDescription(int caseNumber) const
{
    for (auto c : cases_)
        if (c->GetNumber() == caseNumber)
            return c->GetDescription();
    return "No Case Found";
}