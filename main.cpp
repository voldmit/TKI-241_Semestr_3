#include "legalfirm.h"
#include <iostream>
#include <limits>

enum Options {
    EXIT,
    TASK1,
    TASK2,
    TASK3,
    TASK4,
    TASK5,
    TASK6,
    TASK7,
    TASK8
};

int main() {
    setlocale(LC_ALL, "Russian");

    LegalFirm firm;

    // Услуги
    Service civilLaw(1, "Гражданские дела", 5000.0);
    Service criminalLaw(2, "Уголовные дела", 10000.0);
    Service familyLaw(3, "Семейные дела", 7000.0);
    
    firm.addService(civilLaw);
    firm.addService(criminalLaw);
    firm.addService(familyLaw);
    
    // Проверка уникальности - этот ID уже существует
    Service duplicateLaw(1, "Дубликат", 1000.0);
    firm.addService(duplicateLaw); // Выведет сообщение об ошибке

    // Клиенты
    Client client1(101, "Иванов Иван", "ivan@mail.ru");
    Client client2(102, "Сидоров Максим", "maks@mail.ru");
    Client client3(103, "Антонов Василий", "vasya@mail.ru");
    Client client4(104, "Спиридонов Виталий", "vitalik@mail.ru");
    
    firm.addClient(client1);
    firm.addClient(client2);
    firm.addClient(client3);
    firm.addClient(client4);
    
    // Проверка уникальности
    Client duplicateClient(101, "Дубликат", "dup@mail.ru");
    firm.addClient(duplicateClient); // Выведет сообщение об ошибке

    // Адвокаты
    Lawyer lawyer1(201, "Петров Александр", civilLaw);
    Lawyer lawyer2(202, "Ивашин Глеб", criminalLaw);
    Lawyer lawyer3(203, "Николаев Роман", criminalLaw);
    Lawyer lawyer4(204, "Смирнов Сергей", civilLaw);
    
    firm.addLawyer(lawyer1);
    firm.addLawyer(lawyer2);
    firm.addLawyer(lawyer3);
    firm.addLawyer(lawyer4);

    // Дела
    Case case1(1001, "Дело о разводе", &lawyer1, &client1);
    Case case2(1002, "Дело о разделе имущества", &lawyer1, &client2);
    Case case3(1003, "Кража", &lawyer2, &client3);
    Case case4(1004, "Нападение", &lawyer2, &client4);
    
    firm.addCase(case1);
    firm.addCase(case2);
    firm.addCase(case3);
    firm.addCase(case4);
    
    // Проверка уникальности дела
    Case duplicateCase(1001, "Дубликат", &lawyer1, &client1);
    firm.addCase(duplicateCase); // Выведет сообщение об ошибке

    Options choice;
    do {
        std::cout << "\n========================================\n";
        std::cout << "Выберите действие:\n";
        std::cout << "1. Показать список услуг\n";
        std::cout << "2. Показать всех клиентов\n";
        std::cout << "3. Показать всех адвокатов\n";
        std::cout << "4. Клиенты по услуге\n";
        std::cout << "5. Свободные адвокаты по услуге\n";
        std::cout << "6. Получить содержание дела по номеру\n";
        std::cout << "7. Показать все дела клиента\n";
        std::cout << "8. Показать все дела адвоката\n";
        std::cout << "0. Выйти\n";
        std::cout << "Ваш выбор: ";
        
        int input;
        std::cin >> input;
        choice = static_cast<Options>(input);
        
        switch (choice) {
            case TASK1: {
                firm.showServices();
                break;
            }
            case TASK2: {
                firm.showAllClients();
                break;
            }
            case TASK3: {
                firm.showAllLawyers();
                break;
            }
            case TASK4: {
                std::cout << "Введите ID услуги: ";
                int serviceId;
                std::cin >> serviceId;
                
                auto clients = firm.getClientsByService(serviceId);
                if (clients.empty()) {
                    std::cout << "Клиентов по этой услуге нет.\n";
                } else {
                    std::cout << "Список клиентов:\n";
                    for (const auto& client : clients) {
                        std::cout << client->getInfo() << "\n";
                    }
                }
                break;
            }
            case TASK5: {
                std::cout << "Введите ID услуги: ";
                int serviceId;
                std::cin >> serviceId;
                
                auto lawyers = firm.getAvailableLawyersByService(serviceId);
                if (lawyers.empty()) {
                    std::cout << "Свободных адвокатов по этой услуге нет.\n";
                } else {
                    std::cout << "Список свободных адвокатов:\n";
                    for (const auto& lawyer : lawyers) {
                        std::cout << lawyer->getInfo() << "\n";
                    }
                }
                break;
            }
            case TASK6: {
                std::cout << "Введите номер дела: ";
                int caseNumber;
                std::cin >> caseNumber;
                
                try {
                    Case caseInfo = firm.getCaseByNumber(caseNumber);
                    std::cout << "Номер дела: " << caseInfo.getCaseNumber() << "\n"
                              << "Содержание: " << caseInfo.getContent() << "\n"
                              << "Адвокат: " << caseInfo.getLawyer()->getName() << "\n"
                              << "Клиент: " << caseInfo.getClient()->getName() << "\n";
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка: " << e.what() << "\n";
                }
                break;
            }
            case TASK7: {
                std::cout << "Введите ID клиента: ";
                int clientId;
                std::cin >> clientId;
                
                auto clientCases = firm.getClientCases(clientId);
                if (clientCases.empty()) {
                    std::cout << "У клиента с ID " << clientId << " нет дел.\n";
                } else {
                    std::cout << "Дела клиента с ID " << clientId << ":\n";
                    for (const auto& casePtr : clientCases) {
                        if (casePtr) {
                            std::cout << "  - Номер: " << casePtr->getCaseNumber() 
                                     << ", Содержание: " << casePtr->getContent() << "\n";
                        }
                    }
                }
                break;
            }
            case TASK8: {
                std::cout << "Введите ID адвоката: ";
                int lawyerId;
                std::cin >> lawyerId;
                
                auto lawyerCases = firm.getLawyerCases(lawyerId);
                if (lawyerCases.empty()) {
                    std::cout << "У адвоката с ID " << lawyerId << " нет дел.\n";
                } else {
                    std::cout << "Дела адвоката с ID " << lawyerId << ":\n";
                    for (const auto& casePtr : lawyerCases) {
                        if (casePtr) {
                            std::cout << "  - Номер: " << casePtr->getCaseNumber() 
                                     << ", Содержание: " << casePtr->getContent() << "\n";
                        }
                    }
                }
                break;
            }
            case EXIT: {
                std::cout << "Выход из программы.\n";
                break;
            }
            default: {
                std::cout << "Неверный выбор! Попробуйте снова.\n";
                break;
            }
        }
    } while (choice != EXIT);

    return 0;
}
