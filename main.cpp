#include <QCoreApplication>
#include <iostream>

using namespace std;

class my_stack //: public QObject
{
    //Q_OBJECT; // Не знаю почему, но с этим всё ломается
private:
    char *stack_p; // указатель на стек
    int top; // номер текущего элемента стека
    const int size_s = 10;
public:
    my_stack() { // конструктор
        stack_p = new char[size_s];
        top = 0;
    };
    ~my_stack(){ // деструктор
        delete [] stack_p;
    };
    void push(char &); // поместить элемент на вершину стека
    void print_s(); // вывод стека
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    my_stack test;
    char ch = '2';
    test.push(ch);
    test.print_s();
    return a.exec();
}

void my_stack::push(char &value)
{
    if (top < size_s) // Пока так
        stack_p[top++] = value; // помещаем элемент в стек
    else
        cout << "Stack is full";
}

void my_stack::print_s()
{
    for (int i = top - 1; i >= 0; i--)
        cout << " | " << stack_p[i] << endl;
}
