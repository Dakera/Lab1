#include <QCoreApplication>
#include <iostream>

using namespace std;

class my_stack : public QObject
{
    Q_OBJECT;
    my_stack *stack_p; // указатель на стек
private:
    int top; // текущий элемент стека
    const int size_s = 10;
public:
    my_stack() { // конструктор
        stack_p = new my_stack[size_s];
        top = 0;
    };
    ~my_stack(){ // деструктор
        delete [] stack_p;
    };
    void print_s(); // вывод стека
    void push(my_stack &); // поместить элемент на вершину стека
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    my_stack test;
    test.print_s();
    return a.exec();
}

void my_stack::print_s()
{
    for (int i = top - 1; i >= 0; i--)
        cout << " | " << &stack_p[i] << endl;
}
