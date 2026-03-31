#include "case.h"
#include "client.h"
#include "lawyer.h"
Case::Case(int caseNumber, const std::string& content, const Lawyer* lawyer, const Client* client) : caseNumber(caseNumber), content(content), lawyer(lawyer), client(client) {}

int Case::getCaseNumber() const {
	return caseNumber;
}

std::string Case::getContent() const
{
	return content;
}
const Lawyer* Case::getLawyer() const {
	return lawyer;
}
const Client* Case::getClient() const {
	return client;
}
