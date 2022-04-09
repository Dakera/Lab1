#include "persons.h"

my_stack<char>* readPersons(std::istream& stream)
{
    // Сохранили состояние исключений потока
    std::ios_base::iostate s = stream.exceptions();

    // Установили состояние таким образом, что при достижении
    // конца файла будет сгенерировано исключение
    stream.exceptions(std::ios_base::eofbit);

    //std::string* str = new std::string[100];
    char* str = new char[100];
    my_stack<char>* m = new my_stack<char>[100];
    for (int i=0; i<100; i++) {
        try {
            stream >> str[i];
        }
        catch (const std::ios_base::failure&) {
            // дошли до конца файла
            break;
        }
        m[i].push(str[i]); // с типом string не работает
    }
    stream.exceptions(s);
    return m;
}



