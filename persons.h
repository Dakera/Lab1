#ifndef PERSONS_H
#define PERSONS_H

#include "mystack.h"

class Person
{
private:
    long key;
    std::string last_name;
    std::string first_name;
public:
    Person();
    Person(const Person&);
    const std::string& getLastName() const { return last_name; };
    const std::string& getFirstName() const { return first_name; };
    void setLastName(const std::string&);
    void setFirstame(const std::string&);
};

class PersonKeeper{
public:

    static PersonKeeper& Instance(){
        static PersonKeeper p;
        return p;
    };

    my_stack<std::string> readPersons(std::istream& stream);
    void writePersons(my_stack<std::string> stack);
    void showmystream(std::istream& stream);

private:
    PersonKeeper(){}; // запрещаем конструктор
    ~PersonKeeper(){}; // деструктор
    PersonKeeper(PersonKeeper const&); // копирование
    PersonKeeper& operator= (PersonKeeper const&); // и перегрузку оператора
    // в соответствии с шаблоном Singleton
protected:

};


#endif // PERSONS_H
