#include <iostream>


class Something
{
public:
    Something() {
        std::cout << "*** Вызван конструктор по умолчанию у Something" << std::endl;
    }

    ~Something() {
        std::cout << "*** Вызван деструктор у Something" << std::endl;
    }
    
};

class Other: public Something
{
public:
    Other() {
        std::cout << "*** Вызван конструктор по умолчанию у Other" << std::endl;
    }

    ~Other() {
        std::cout << "*** Вызван деструктор у Other" << std::endl;
    }
    
};


int main()
{

    std::cout << "Создаём s1..." << std::endl;
    Other s1;


    std::cout << "Конец программы." << std::endl;
    return 0;
}

