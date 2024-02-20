#include "h2.h"


template <typename T>
shared_ptr<T>::shared_ptr(): ctrl(nullptr), ptr(nullptr) {}

template <typename T>
shared_ptr<T>::shared_ptr(T* ptr0): ctrl(nullptr), ptr(nullptr) {
    ptr = ptr0;
    if ((ptr)) {
        ctrl = new Control<T>();
        //std::cout << ctrl->ref_count << std::endl;
    } else {
        //std::cout << "not created" << std::endl;
    }
}

template <typename T>
shared_ptr<T>::shared_ptr (std::unique_ptr<T>& unq): ctrl(nullptr), ptr(nullptr) {
    ptr = unq.release();
    if ((ptr)) {
        ctrl = new Control<T>();
    }
}

template <typename T>
shared_ptr<T>::shared_ptr(shared_ptr<T>& other): ctrl(nullptr), ptr(nullptr) {
    ptr = other.ptr;
    ctrl = other.ctrl;
    if (ctrl) {
        ctrl->ref_count++;
        //std::cout << "+1" << std::endl;
    }

    //prt = A.ptr;
}

template <typename T>
shared_ptr<T>::shared_ptr(shared_ptr<T>&& other): ctrl(nullptr), ptr(nullptr) {
    ctrl = other.ctrl;
    ptr = other.ptr;
    other.ctrl = nullptr;
    other.ptr = nullptr;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>& other) {
    (*this).reset();
    (*this).ctrl = other.ctrl;
    (*this).ptr = other.ptr;
    if (other.ctrl) {
        other.ctrl->ref_count++;
    }
    /*
    if (ctrl) {
        std::cout << "+1" << std::endl;
    }
    //*/
    return *this;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>&& other) {
    (*this).reset();
    (*this).ctrl = other.ctrl;
    (*this).ptr = other.ptr;
    other.ctrl = nullptr;
    other.ptr = nullptr;
    return *this;
}



template <typename T>
void shared_ptr<T>::reset() {
    ptr = nullptr;
    if (ctrl) {
        ctrl->ref_count--;
        if (ctrl->ref_count == 0) {
            delete ctrl;
        }
        ctrl = nullptr;
    }
}

template <typename T>
void shared_ptr<T>::reset(T* ptr0) {
    (*this).reset();
    (*this) = shared_ptr<T>(ptr0);
}

template <typename T>
void shared_ptr<T>::reset(shared_ptr<T>& other) {
    (*this).reset();
    *this = other;
}



template <typename T>
void shared_ptr<T>::swap(shared_ptr<T>& other) {
    auto current = this;
    std::swap((*current).ptr, other.ptr);
    std::swap((*current).ctrl, other.ctrl);
    //std::swap((*this).ptr, (*current).ptr);
    //std::swap((*this).ptr, (*current).ptr);
}

template <typename T>
int shared_ptr<T>::use_count() {
    //std::cout << ctrl->ref_count << std::endl;
    if (ctrl) {
        return ctrl->ref_count;
    } else {
        //std::cout << "not present" << std::endl;
        return 0;
    }
}

template <typename T>
shared_ptr<T>::operator bool() {
    if ((*this).ptr == nullptr) {
        return false;
    } else {
        return true;
    }
}

template <typename T>
T& shared_ptr<T>::operator*() {
    return *ptr;
}

template <typename T>
T* shared_ptr<T>::operator-> () {
    return ptr;
}

