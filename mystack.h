#ifndef MYSTACK_H
#define MYSTACK_H

/*
 https://ru.stackoverflow.com/questions/937440/Не-работает-обьявление-шаблона-класса-в-заголовочном-файле-с-определением-методо

 Нельзя выносить реализацию шаблонного класса в отдельный cpp файл
 */

#include <iostream>
#include <string>
#include "exception.h"

//using namespace std;

template <typename T>
class my_stack //: public QObject
{
    //Q_OBJECT; // Не знаю почему, но с этим всё ломается
private:
    T* stack_p; // указатель на стек
    int top; // номер текущего элемента стека
    const int SIZE_S; // размер стека
public:
    my_stack(int maxsize = 10) : SIZE_S(maxsize) { // конструктор
        stack_p = new T[SIZE_S];
        top = 0;
    };
    ~my_stack(){ // деструктор
        delete [] stack_p;
    };
    void push(T &); // поместить элемент на вершину стека
    void print_s(); // вывод стека
    T pop(); // удаление элемента из вершины
    int getStackSize(); // получение размера стека
};


template <typename T>
void my_stack<T>::push(T &value)
{
    try {
        if (top >= SIZE_S)
            throw exc::EStackException("Stack overflow!");
        stack_p[top++] = value; // помещаем элемент в стек, нужен top++
    }
    catch (const exc::EStackException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

template <typename T>
void my_stack<T>::print_s()
{
    for (int i = top - 1; i >= 0; i--)
        std::cout << " | " << stack_p[i] << std::endl;
}

template <typename T>
T my_stack<T>::pop()
{
    try {
        if (top <= 0) // номер текущего элемента должен быть больше 0
            throw exc::EStackEmpty("Stack is empty!");
        T s;
        s = stack_p[top - 1]; // запоминаем удаляемый эл-т для ретерна
        stack_p[--top] = 0; // удаляем сам этот элемент
        return s;
    }
    catch (const exc::EStackException& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
}

template <typename T>
int my_stack<T>::getStackSize()
{
    return SIZE_S;
}


#endif // MYSTACK_H
