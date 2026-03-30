#include <vector>
#include <string>
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

public:
	void addService(const Service& service);
	void addClient(const Client& client);
	void addLawyer(const Lawyer& lawyer);
	void addCase(const Case& caseObj);

	void showServices() const;
	std::vector<Client> getClientsByService(const int serviceId) const;
	std::vector<Lawyer> getAvailableLawyersByService(const int serviceId) const;
	std::vector<const Case*> getClientCases(int clientId) const;
	std::vector<const Case*> getLawyerCases(int lawyerId) const;
	Case getCaseByNumber(const int caseNumber) const;
	
};

