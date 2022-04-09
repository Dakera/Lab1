#include <fstream>
#include "persons.h"

my_stack<std::string> PersonKeeper::readPersons(std::istream& stream)
{
    // Сохранили состояние исключений потока
    std::ios_base::iostate s = stream.exceptions();

    // Установили состояние таким образом, что при достижении
    // конца файла будет сгенерировано исключение
    stream.exceptions(std::ios_base::eofbit);

    std::string* str = new std::string[100];
    //my_stack<std::string>* m = new my_stack<std::string>[100];
    my_stack<std::string> m(100);
    for (int i=0; i<100; i++) {
        try {
            stream >> str[i];
            m.push(str[i]);
        }
        catch (const std::ios_base::failure&) {
            // дошли до конца файла
            break;
        }
    }
    stream.exceptions(s);
    return m;
}


void PersonKeeper::writePersons(my_stack<std::string> stack){
    std::ofstream ofs;
    //std::ios_base::iostate s = ofs.exceptions();
    ofs.exceptions(std::ios_base::eofbit);
    for (int i = 0; i < 100; i++){
        ofs << stack.pop();
    }
}

void PersonKeeper::showmystream(std::istream& stream){
    std::string* str = new std::string[100];
    std::cout << "outmystream's happening: " << "\n";
    for (int i = 0; i < 100; i++){
        stream >> str[i];
        std::cout << str[i];
    }

}
