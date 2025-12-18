#include <iostream>
#include <vector>
#include <memory>


#include "..\lawfirmlib\firm.h"
#include "..\lawfirmlib\CONSULTATION.h"
#include "..\lawfirmlib\lawyerservice.h"

int main()
{
    std::vector<std::shared_ptr<Service>> services;

    services.push_back(std::make_shared<Consultation>(2000));
    services.push_back(std::make_shared<CourtService>("Civil", 50000));
    services.push_back(std::make_shared<CourtService>("Criminal", 120000));

    for (const auto& s : services)
        std::cout << s->GetInfo() << std::endl;

    return 0;
}