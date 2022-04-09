#include <QCoreApplication>
#include <iostream>
#include <string>

#include "exception.h"
#include "mystack.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
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
    return a.exec();
}

