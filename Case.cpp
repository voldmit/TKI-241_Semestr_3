#include "Case.h"

Case::Case(int number,
    const std::string& description,
    Lawyer* lawyer,
    Client* client,
    Service* service)
    : number_(number),
    description_(description),
    lawyer_(lawyer),
    client_(client),
    service_(service)
{
    lawyer_->SetBusy(true);
}

int Case::GetNumber() const 
{ 
    return number_; 
}
std::string Case::GetDescription() const 
{ 
    return description_; 
}
Service* Case::GetService() const 
{ 
    return service_; 
}
Client* Case::GetClient() const 
{ 
    return client_; 
}