/*
Задача №5
«Поиск ошибок»

Найти все ошибки в приведенном коде. Предложить варианты исправления.
*/


#include <iostream>
#include <memory>
#include <vector>

class Foo {
private:
    std::vector<int> m_i; //int* -> std::vector && i -> m_i

public:
    Foo(int j) {
        std::cout << "parent's constructor" << std::endl;

        for (int i =0; i < j; i++) { // <- i = new int[j]
            m_i.push_back(i);
        }
    }
    virtual ~Foo() { // добавлен virtual
        std::cout << "parent's destructor" << std::endl;
        // удалено "delete i"
    }

    void getI() { // вывод m_i
        for (auto i : m_i) {
            std::cout << m_i[i] << std::endl;
        }
    }

};

class Bar: public Foo { //добавлен public
private:
    std::vector<char> m_k; //char* -> std::vector<char> && i -> m_k

public:
    Bar(int j) : Foo(j) { // добавлено : Foo(j)
        std::cout << "child's constructor" << std::endl;
         m_k.push_back((char)j); // <- i = new char[j]
    }
    virtual ~Bar() { //добавлен virtual
        std::cout << "child's destructor" << std::endl;
        //удалено "delete i"
    }

};


int main() { // void -> main

    std::unique_ptr<Foo> f = std::make_unique<Foo>(5); // <- Foo* f=new Foo(100);
    std::unique_ptr<Foo> b = std::make_unique<Bar>(7); // <- Foo* b=new Bar(200);

    //добавлен вывод
    f->getI();
    std::cout << "-------------" << std::endl;
    b->getI();

    std::cout << "==============" << std::endl;

    *f = *b;

    f->getI();
    std::cout << "-------------" << std::endl;
    b->getI();

    return 0; // добавлено
}

