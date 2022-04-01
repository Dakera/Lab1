#include <QCoreApplication>
#include <iostream>

using namespace std;

template <typename T>
class my_stack //: public QObject
{
    //Q_OBJECT; // Не знаю почему, но с этим всё ломается
private:
    T *stack_p; // указатель на стек
    int top; // номер текущего элемента стека
    const int size_s = 10;
public:
    my_stack() { // конструктор
        stack_p = new T[size_s];
        top = 0;
    };
    ~my_stack(){ // деструктор
        delete [] stack_p;
    };
    void push(T &); // поместить элемент на вершину стека
    void print_s(); // вывод стека
    T pop(); // удаление элемента из вершины
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    my_stack<char> test;
    char ch = '2';
    test.push(ch);
    test.print_s();
    return a.exec();
}


template <typename T>
void my_stack<T>::push(T &value)
{
    if (top < size_s) // Пока так
        stack_p[top++] = value; // помещаем элемент в стек (начинается с 1)
    else
        cout << "Stack is full";
}
template <typename T>
void my_stack<T>::print_s()
{
    for (int i = top - 1; i >= 0; i--)
        cout << " | " << stack_p[i] << endl;
}
template <typename T>
T my_stack<T>::pop()
{
    int s;
    if (top > 0) {// номер текущего элемента должен быть больше 0
        s = stack_p[top];
        stack_p[top] = 0;
        top--;
    }
    else
        cout << "top < 0";
    return s;
}
