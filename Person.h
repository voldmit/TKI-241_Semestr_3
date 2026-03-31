#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    int id;
    std::string name;

public:
    Person(int id, const std::string& name) : id(id), name(name) {}
    virtual ~Person() = default;

    virtual int getId() const { return id; }
    virtual std::string getName() const { return name; }
    virtual void setName(const std::string& newName) { name = newName; }
    
    // Чисто виртуальный метод
    virtual std::string getInfo() const = 0;
};

#endif
