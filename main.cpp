#include "../lawfirm3/legalfirm.h"

#include <iostream>

enum Options {
	EXIT,
	TASK1,
	TASK2,
	TASK3,
	TASK4,
	TASK5,
	TASK6
	
};

int main()
{
	
	setlocale(LC_ALL, "Russian");

	// Услуги
	LegalFirm firm;
	Service civilLaw(1, "Гражданские дела" , 5000.0);
	Service criminalLaw(2, "Уголовные дела", 10000.0);
	firm.addService(civilLaw);
	firm.addService(criminalLaw);
	// Клиенты
	Client client1(101, "Иванов Вася", "ivan@mail.ru");
	Client client2(102, "Сидоров Максим", "maks@mail.ru");
	Client client3(103, "Антонов Василий", "vasya@mail.ru");
	Client client4(104, "Спиридонов Виталий", "vitalik@mail.ru");
	firm.addClient(client1);
	firm.addClient(client2);
	firm.addClient(client3);
	firm.addClient(client4);
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

	// Задания 

	Options choice;
	do
	{
		std::cout << "Введите желаемую услугу:\n1.Показание списка услуг\n2.Клиенты по услуге\n3.Cвободные адвокаты по услуге\n4.Получить содержание дела по номеру\n5.Показать все дела клиента\n6.Показать все дела адвоката\n0.Выйти" << std::endl;
		int input;
		std::cin >> input;
		choice = static_cast<Options>(input);
		switch (choice) 
		{
		case TASK1: {
			firm.showServices();
			
		}
		case TASK2:
		{
			std::cout << "Введите id услуги по какому запросу нужно вывести клиентов \n";
			int number1;
			std::cin >> number1;
			std::cout << "Список клиентов \n";
			auto civilClients = firm.getClientsByService(number1);
			for (const auto& client : civilClients)
			{
				std::cout << "ID: " << client.getId() << ", Имя: " << client.getName() << ", Контакты: " << client.getContactInfo() << "\n";
			}
			
		}
		case TASK3:

		{
			int number2;
			std::cout << "Введите id услуги: \n";
			std::cin >> number2;

			std::cout << "Список свободных адвокатов по услуге " << number2 << ":\n";
			auto availableLawyers = firm.getAvailableLawyersByService(number2);

			if (availableLawyers.empty()) {
				std::cout << "Свободных адвокатов по этой услуге нет.\n";
			}
			else {
				for (const auto& lawyer : availableLawyers) {
					std::cout << "ID: " << lawyer.getId()
						<< ", Имя: " << lawyer.getName()
						<< "\n";
				}
			}
			
		}
		case TASK4:
		{
			int number3;
			std::cout << "Введите номер дела \n";
			std::cin >> number3;

			try {
				Case caseInfo = firm.getCaseByNumber(number3);
				std::cout << "Номер дела: " << caseInfo.getCaseNumber() << "\n" << "Содержание: " << caseInfo.getContent() << "\n" << "Адвокат: "
					<< caseInfo.getLawyer()->getName() << "\n" << "Клиент: " << caseInfo.getClient()->getName() << "\n";
			}
			catch (const std::exception& e)
			{
				std::cerr << "Ошибка: " << e.what() << "\n";
			}
			
		}
		case TASK5:
		{
			std::cout << "Введите ID клиента: \n";
			int clientId;
			std::cin >> clientId;

			auto clientCases = firm.getClientCases(clientId);
			if (clientCases.empty())
			{
				std::cout << "У клиента с ID " << clientId << " нет дел.\n";
			}
			else
			{
				std::cout << "Дела клиента с ID " << clientId << ":\n";
				for (const auto& casePtr : clientCases)
				{
					if (casePtr)
					{
						std::cout << " - Номер: " << casePtr->getCaseNumber() << ", Содержание: " << casePtr->getContent() << "\n";
					}
				}
			}
			
		}
		case TASK6: {
			std::cout << "Введите ID адвоката: \n";
			int lawyerId;
			std::cin >> lawyerId;

			auto lawyerCases = firm.getLawyerCases(lawyerId);
			if (lawyerCases.empty())
			{
				std::cout << " У адвоката с ID " << lawyerId << " нет дел.\n";
			}
			else
			{
				std::cout << "Дела адвоката с ID " << lawyerId << ":\n";
				for (const auto& casePtr : lawyerCases)
				{
					if (casePtr)
					{
						std::cout << "  - Номер: " << casePtr->getCaseNumber() << ", Содержание: " << casePtr->getContent() << "\n";
					}
				}
			}
			
		}
		case EXIT: { std::cout << "Выход из программы.\n"; break; }
		default: { std::cout << "Неверный выбор! Попробуйте снова.\n"; break; }
		}
	} while (choice != EXIT);

	/*int b = 6;
	while(b != 0)
	{
		std::cout << "Введите желаемую услугу:\n1.Показание списка услуг\n2.Клиенты по услуге\n3.Cвободные адвокаты по услуге\n4.Получить содержание дела по номеру\n5.Показать все дела клиента\n6.Показать все дела адвоката\n0.Выйти" << std::endl;
		std::cin >> b;
		//1 . Показание списка услуг
		if (b == 1)
		{
			firm.showServices();
		}
		// 2. Клиенты по услуге 
		if (b == 2)
		{
			std::cout << "Введите id услуги по какому запросу нужно вывести клиентов \n";
			int number;
			std::cin >> number;
			std::cout << "Список клиентов \n";
			auto civilClients = firm.getClientsByService(number);
			for (const auto& client : civilClients)
			{
				std::cout << "ID: " << client.getId() << ", Имя: " << client.getName() << ", Контакты: " << client.getContactInfo() << "\n";
			}
		}
		// 3 Cвободные адвокаты
		if (b == 3) {
			int number;
			std::cout << "Введите id услуги: \n";
			std::cin >> number;

			std::cout << "Список свободных адвокатов по услуге " << number << ":\n";
			auto availableLawyers = firm.getAvailableLawyersByService(number);

			if (availableLawyers.empty()) {
				std::cout << "Свободных адвокатов по этой услуге нет.\n";
			}
			else {
				for (const auto& lawyer : availableLawyers) {
					std::cout << "ID: " << lawyer.getId()
						<< ", Имя: " << lawyer.getName()
						<< "\n";
				}
			}
		}		// Получить содержание дела по номеру
		if (b == 4)
		{
			int number;
			std::cout << "Введите номер дела \n";
			std::cin >> number;

			try {
				Case caseInfo = firm.getCaseByNumber(number);
				std::cout << "Номер дела: " << caseInfo.getCaseNumber() << "\n" << "Содержание: " << caseInfo.getContent() << "\n" << "Адвокат: "
					<< caseInfo.getLawyer()->getName() << "\n" << "Клиент: " << caseInfo.getClient()->getName() << "\n";
			}
			catch (const std::exception& e)
			{
				std::cerr << "Ошибка: " << e.what() << "\n";
			}
		}
		if (b == 5)
		{
			std::cout << "Введите ID клиента: \n";
			int clientId;
			std::cin >> clientId;
			
			auto clientCases = firm.getClientCases(clientId);
			if (clientCases.empty())
			{
				std::cout << "У клиента с ID " << clientId << " нет дел.\n";
			}
			else
			{
				std::cout << "Дела клиента с ID " << clientId << ":\n";
				for (const auto& casePtr : clientCases)
				{
					if (casePtr)
					{
						std::cout << " - Номер: " << casePtr->getCaseNumber() << ", Содержание: " << casePtr->getContent() << "\n";
					}
				}
			}
		}
		if (b == 6)
		{
			std::cout << "Введите ID адвоката: \n";
			int lawyerId;
			std::cin >> lawyerId;

			auto lawyerCases = firm.getLawyerCases(lawyerId);
			if (lawyerCases.empty())
			{
				std::cout << " У адвоката с ID " << lawyerId << " нет дел.\n";
			}
			else
			{
				std::cout << "Дела адвоката с ID " << lawyerId << ":\n";
				for (const auto& casePtr : lawyerCases)
				{
					if (casePtr)
					{
						std::cout << "  - Номер: " << casePtr->getCaseNumber() << ", Содержание: " << casePtr->getContent() << "\n";
					}
				}
			}
		}
	}
	*/
	return 0;
}
