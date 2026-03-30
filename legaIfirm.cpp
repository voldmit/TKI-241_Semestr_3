#include "legalfirm.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

void LegalFirm::addService(const Service& service) {
    services.push_back(service);
}

void LegalFirm::addClient(const Client& client) {
    clients.push_back(client);
}

void LegalFirm::addLawyer(const Lawyer& lawyer) {
    lawyers.push_back(lawyer);
}

void LegalFirm::addCase(const Case& caseObj) {
    cases.push_back(caseObj);

    // Добавление дела клиенту
    const Client* clientPtr = caseObj.getClient();
    if (clientPtr) {
        for (auto& client : clients) {
            if (client.getId() == clientPtr->getId()) {
                client.addCase(&caseObj);
                break;
            }
        }
    }

    // Добавление дела адвокату
    const Lawyer* lawyerPtr = caseObj.getLawyer();
    if (lawyerPtr) {
        for (auto& lawyer : lawyers) {
            if (lawyer.getId() == lawyerPtr->getId()) {
                lawyer.addCase(&caseObj);
                lawyer.setAvailability(false);
                break;
            }
        }
    }
}

void LegalFirm::showServices() const {
    std::cout << "Список предоставляемых услуг:\n";
    for (const auto& service : services) {
        std::cout << "ID: " << service.getId()
            << ", Услуга: " << service.getName()
            << ", Цена: " << service.getPrice() << " руб.\n";
    }
}

std::vector<Client> LegalFirm::getClientsByService(int serviceId) const {
    std::vector<Client> result;
    for (const auto& caseObj : cases) {
        const Lawyer* lawyer = caseObj.getLawyer();
        if (lawyer && lawyer->getSpecialization().getId() == serviceId) {
            const Client* client = caseObj.getClient();
            if (client && std::find_if(result.begin(), result.end(),
                [client](const Client& c) { return c.getId() == client->getId(); }) == result.end()) {
                result.push_back(*client);
            }
        }
    }
    return result;
}

std::vector<const Case*> LegalFirm::getClientCases(int clientId) const {
    for (const auto& client : clients) {
        if (client.getId() == clientId) {
            return client.getCases();
        }
    }
    return {};
}

std::vector<const Case*> LegalFirm::getLawyerCases(int lawyerId) const {
    for (const auto& lawyer : lawyers) {
        if (lawyer.getId() == lawyerId) {
            return lawyer.getCases();
        }
    }
    return {};
}

std::vector<Lawyer> LegalFirm::getAvailableLawyersByService(int serviceId) const {
    std::vector<Lawyer> result;

    for (const auto& lawyer : lawyers) {
        // Проверяем специализацию
        if (lawyer.getSpecialization().getId() == serviceId) {
            // Проверяем доступность
            if (lawyer.getAvailability()) {
                result.push_back(lawyer);
            }
        }
    }

    return result;
}
Case LegalFirm::getCaseByNumber(int caseNumber) const {
    for (const auto& caseObj : cases) {
        if (caseObj.getCaseNumber() == caseNumber) {
            return caseObj;
        }
    }
    throw std::runtime_error("Дело с номером " + std::to_string(caseNumber) + " не найдено");
}