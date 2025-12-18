#pragma once
#include <string>
#include "lawyer.h"
#include "client.h"
#include "service.h"

class Case
{
public:
    Case(int number,
        const std::string& description,
        Lawyer* lawyer,
        Client* client,
        Service* service);

    int GetNumber() const;
    std::string GetDescription() const;
    Service* GetService() const;
    Client* GetClient() const;

private:
    int number_;
    std::string description_;
    Lawyer* lawyer_;
    Client* client_;
    Service* service_;
};

