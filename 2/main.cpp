/*
#include <C:\Users\fedor\Desktop\mipt\4 semester\informatics\03.02.2024\задачи\2\header.h>
#include <shared_ptr.cpp>
//*/
#include "h2.h"
#include "shared_ptr.cpp"

class Test {
    public:
    int t;
    Test(): t(0) {}
    int print() {std::cout << t << std::endl;}
};

int main()
{
    int a = 10;
    int b = 20;
    //int cout;
    std::cout << "ctors and bool():" << std::endl;
    shared_ptr<int> shptr1(&a);     ///ctor from regular ptr
    shared_ptr<int> shptr2(shptr1); ///copy ctor
    //cout = shptr1.use_count();
    //std::cout << cout << std::endl;
    shared_ptr<int> shptr3(std::move(shptr1)); ///move ctor

    if (shptr1) { ///bool()
        std::cout << "1 " << std::endl;
    } else {
        std::cout << "2 " << std::endl;
    }

    std::cout << "* overloading: " <<  *shptr2 << ' ' << *shptr3 << ' ' << std::endl; ///* overloading
    std::cout << "use_count: " << shptr1.use_count() << ' ' << shptr2.use_count() << ' ' << shptr3.use_count() << ' ' << std::endl; ///use_count



    Test test;
    test.t = 30;
    std::unique_ptr<Test> u_ptr (&test);

    shared_ptr<Test> shptr4(u_ptr); ///ctor form unique ptr
    shared_ptr<Test> shptr5;        ///default ctor
    std::cout << "move= " << std::endl;
    shptr5 = std::move(shptr4);     ///move=
    std::cout << "-> overloading:" << std::endl;
    shptr5->print();                ///-> overloading


    ///reset()
    shptr3.reset();         ///to a nullptr
    if (!shptr3) {std::cout << "reset works" << std::endl;}
    shptr2.reset(&b);       ///reset with a raw ptr
    //std::cout << shptr2.use_count() << std::endl;
    shptr1.reset(shptr2);   ///reset with a shrd ptr
    std::cout << "use_count: " << shptr1.use_count() << ' ' << shptr2.use_count() << ' ' << shptr3.use_count() << ' ' << std::endl; ///use_count

    shptr3 = shared_ptr<int> (&a);  ///move=
    shptr2 = shptr3;                ///copy=

    shptr1.swap(shptr2);            ///swap
    std::cout << "use_count: " << shptr1.use_count() << ' ' << shptr2.use_count() << ' ' << shptr3.use_count() << ' ' << std::endl;
    std::cout << "* overloading: " <<  *shptr1 << ' ' << *shptr2 << ' ' << *shptr3 << ' ' << std::endl;
    //shptr2.reset(shptr4);
    //cout = shptr2.use_count();
    //std::cout << cout << std::endl;

    return 0;
}
