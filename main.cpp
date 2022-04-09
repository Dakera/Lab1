#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>

#include "exception.h"
#include "persons.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    PersonKeeper& instance = PersonKeeper::Instance();
    my_stack<string> m(100);
    string str;
    fstream stream;
    stream.open("test.txt", ios_base::in);
    //m.push(instance.readPersons(stream));
    instance.readPersons(stream);
    m.push(str);
    m.print_s();
    stream.close();
    return a.exec();
}

/*
    my_stack<char> test(5); // размер 5
    char ch = '3', cc = '2', hh = '1';
    test.push(ch);
    test.push(cc);
    test.push(hh);
    test.print_s();

    cout << endl << "Size of stack: " << test.getStackSize() << endl;

    cout << endl << "Now pop(): ";
    cout << test.pop() << endl << endl;
    test.print_s();

    cout << endl << "Now pop(): ";
    cout << test.pop() << endl << endl;
    test.print_s();
    cout << endl << "Now pop(): ";
    cout << test.pop() << endl << endl;
    test.print_s();
    cout << endl << "Now pop(): ";
    cout << test.pop() << endl << endl; // Обработка исключения
    */
