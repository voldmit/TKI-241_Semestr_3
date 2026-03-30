#ifndef SERVICE_H
#define SERVICE_H
#include <string>

class Service {
private:
    int id;
    std::string name;
    double price;
public:
    Service(const int id, const std::string& name, const double price);

    int getId() const;
    std::string getName() const;
    double getPrice() const;

    void setPrice(const double price);
};
#endif