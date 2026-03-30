#ifndef LEGALFIRM_H
#define LEGALFIRM_H

#include <vector>
#include <string>
#include <memory>
#include "service.h"
#include "client.h"
#include "lawyer.h"
#include "case.h"

class LegalFirm {
private:
    std::vector<Service> services;
    std::vector<Client> clients;
    std::vector<Lawyer> lawyers;
    std::vector<Case> cases;

    // Вспомогательные методы для проверки уникальности
    bool isServiceIdUnique(int id) const;
    bool isClientIdUnique(int id) const;
    bool isLawyerIdUnique(int id) const;
    bool isCaseNumberUnique(int caseNumber) const;

public:
    // Методы добавления с проверкой уникальности
    bool addService(const Service& service);
    bool addClient(const Client& client);
    bool addLawyer(const Lawyer& lawyer);
    bool addCase(const Case& caseObj);

    // Поиск по ID
    const Client* findClientById(int id) const;
    const Lawyer* findLawyerById(int id) const;
    const Service* findServiceById(int id) const;
    const Case* findCaseByNumber(int caseNumber) const;

    void showServices() const;
    void showAllClients() const;
    void showAllLawyers() const;
    
    std::vector<const Client*> getClientsByService(int serviceId) const;
    std::vector<const Lawyer*> getAvailableLawyersByService(int serviceId) const;
    std::vector<const Case*> getClientCases(int clientId) const;
    std::vector<const Case*> getLawyerCases(int lawyerId) const;
    Case getCaseByNumber(int caseNumber) const;
};

#endif
