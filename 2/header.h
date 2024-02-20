#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <memory>
//using namespace std;
template <typename T>
class Control {
    public:
    int ref_count;
    //Control() = delete;
    //Control(T* obj);
    //bool check();
    //~Control();
    Control(): ref_count(1) {}
};
/*
template <typename T>
bool Control<T>::check() {
    if (ref_count > 0) {
        return true;
    } else {
        return false;
    }
}
/*
template <typename T>
Control::~Control() {

}
//*/
/*
template <typename T>
Control<T>::Control(T* obj0) {
    obj = obj0;
    ref_count = 1;
}
//*/


template <typename T>
class shared_ptr {
    public:
    Control<T>* ctrl;
    T* ptr;

    ///ctors
    shared_ptr();                                       ///default ctor
    shared_ptr(shared_ptr<T>& other);                   ///from other shared pointer
    shared_ptr(T* ptr0);                                ///from regular pointer
    shared_ptr(std::unique_ptr<T>& unq);                 ///from unique pointer
    shared_ptr(shared_ptr<T>&& other);                  ///move ctor

    shared_ptr<T>& operator=(shared_ptr<T>& other);     ///copy=
    shared_ptr<T>& operator=(shared_ptr<T>&& other);    ///move=

    void reset ();
    void reset (T* ptr);
    void reset (shared_ptr<T>& other);

    T* get() {return ptr;}

    void swap(shared_ptr<T>& other);

    int use_count();

    operator bool();
    T& operator* ();
    //A& operator-> (A a);
    T* operator-> ();
};

#endif // HEADER_H_INCLUDED
