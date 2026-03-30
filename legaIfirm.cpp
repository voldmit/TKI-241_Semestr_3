#include "legalfirm.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// Проверка уникальности ID
bool LegalFirm::isServiceIdUnique(int id) const {
    return std::find_if(services.begin(), services.end(),
        [id](const Service& s) { return s.getId() == id; }) == services.end();
}

bool LegalFirm::isClientIdUnique(int id) const {
    return std::find_if(clients.begin(), clients.end(),
        [id](const Client& c) { return c.getId() == id; }) == clients.end();
}

bool LegalFirm::isLawyerIdUnique(int id) const {
    return std::find_if(lawyers.begin(), lawyers.end(),
        [id](const Lawyer& l) { return l.getId() == id; }) == lawyers.end();
}

bool LegalFirm::isCaseNumberUnique(int caseNumber) const {
    return std::find_if(cases.begin(), cases.end(),
        [caseNumber](const Case& c) { return c.getCaseNumber() == caseNumber; }) == cases.end();
}

// Методы добавления с проверкой
bool LegalFirm::addService(const Service& service) {
    if (!isServiceIdUnique(service.getId())) {
        std::cerr << "Ошибка: Услуга с ID " << service.getId() << " уже существует!\n";
        return false;
    }
    services.push_back(service);
    return true;
}

bool LegalFirm::addClient(const Client& client) {
    if (!isClientIdUnique(client.getId())) {
        std::cerr << "Ошибка: Клиент с ID " << client.getId() << " уже существует!\n";
        return false;
    }
    clients.push_back(client);
    return true;
}

bool LegalFirm::addLawyer(const Lawyer& lawyer) {
    if (!isLawyerIdUnique(lawyer.getId())) {
        std::cerr << "Ошибка: Адвокат с ID " << lawyer.getId() << " уже существует!\n";
        return false;
    }
    lawyers.push_back(lawyer);
    return true;
}

bool LegalFirm::addCase(const Case& caseObj) {
    if (!isCaseNumberUnique(caseObj.getCaseNumber())) {
        std::cerr << "Ошибка: Дело с номером " << caseObj.getCaseNumber() << " уже существует!\n";
        return false;
    }
    
    cases.push_back(caseObj);

    // Добавление дела клиенту
    const Client* clientPtr = caseObj.getClient();
    if (clientPtr) {
        for (auto& client : clients) {
            if (client.getId() == clientPtr->getId()) {
                client.addCase(&cases.back());
                break;
            }
        }
    }

    // Добавление дела адвокату
    const Lawyer* lawyerPtr = caseObj.getLawyer();
    if (lawyerPtr) {
        for (auto& lawyer : lawyers) {
            if (lawyer.getId() == lawyerPtr->getId()) {
                lawyer.addCase(&cases.back());
                break;
            }
        }
    }
    
    return true;
}

// Поиск по ID
const Client* LegalFirm::findClientById(int id) const {
    auto it = std::find_if(clients.begin(), clients.end(),
        [id](const Client& c) { return c.getId() == id; });
    return (it != clients.end()) ? &(*it) : nullptr;
}

const Lawyer* LegalFirm::findLawyerById(int id) const {
    auto it = std::find_if(lawyers.begin(), lawyers.end(),
        [id](const Lawyer& l) { return l.getId() == id; });
    return (it != lawyers.end()) ? &(*it) : nullptr;
}

const Service* LegalFirm::findServiceById(int id) const {
    auto it = std::find_if(services.begin(), services.end(),
        [id](const Service& s) { return s.getId() == id; });
    return (it != services.end()) ? &(*it) : nullptr;
}

const Case* LegalFirm::findCaseByNumber(int caseNumber) const {
    auto it = std::find_if(cases.begin(), cases.end(),
        [caseNumber](const Case& c) { return c.getCaseNumber() == caseNumber; });
    return (it != cases.end()) ? &(*it) : nullptr;
}

void LegalFirm::showServices() const {
    std::cout << "Список предоставляемых услуг:\n";
    for (const auto& service : services) {
        std::cout << "ID: " << service.getId()
            << ", Услуга: " << service.getName()
            << ", Цена: " << service.getPrice() << " руб.\n";
    }
}

void LegalFirm::showAllClients() const {
    std::cout << "Список клиентов:\n";
    for (const auto& client : clients) {
        std::cout << client.getInfo() << "\n";
    }
}

void LegalFirm::showAllLawyers() const {
    std::cout << "Список адвокатов:\n";
    for (const auto& lawyer : lawyers) {
        std::cout << lawyer.getInfo() << "\n";
    }
}

std::vector<const Client*> LegalFirm::getClientsByService(int serviceId) const {
    std::vector<const Client*> result;
    
    for (const auto& caseObj : cases) {
        const Lawyer* lawyer = caseObj.getLawyer();
        if (lawyer && lawyer->getSpecialization().getId() == serviceId) {
            const Client* client = caseObj.getClient();
            if (client && std::find(result.begin(), result.end(), client) == result.end()) {
                result.push_back(client);
            }
        }
    }
    return result;
}

std::vector<const Lawyer*> LegalFirm::getAvailableLawyersByService(int serviceId) const {
    std::vector<const Lawyer*> result;

    for (const auto& lawyer : lawyers) {
        if (lawyer.getSpecialization().getId() == serviceId && lawyer.getAvailability()) {
            result.push_back(&lawyer);
        }
    }
    return result;
}

std::vector<const Case*> LegalFirm::getClientCases(int clientId) const {
    const Client* client = findClientById(clientId);
    return client ? client->getCases() : std::vector<const Case*>{};
}

std::vector<const Case*> LegalFirm::getLawyerCases(int lawyerId) const {
    const Lawyer* lawyer = findLawyerById(lawyerId);
    return lawyer ? lawyer->getCases() : std::vector<const Case*>{};
}

Case LegalFirm::getCaseByNumber(int caseNumber) const {
    const Case* casePtr = findCaseByNumber(caseNumber);
    if (!casePtr) {
        throw std::runtime_error("Дело с номером " + std::to_string(caseNumber) + " не найдено");
    }
    return *casePtr;
}
