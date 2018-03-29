//====================================================
//  smart_ptr.cpp                                   //
//  Class: Advance C++                              //
//  Professor: Solomon L. Russell                   //
//  Homework#: Spec 1                               //
//  OS Used: MacOS(Xcode)/Windows(Visual Studio)    //
//  Last successful run: 3/28/18                    //
//  Created by Kirby James Fernandez on 3/24/18.    //
//  Copyright © 2018 oc. All rights reserved.       //
//====================================================

#include <iostream>
#include <stdexcept>
#include <exception>
#include <cassert>
#include <string>
#include <cstddef>

using namespace std;

class null_ptr_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Unexpected Exception";
    }
};

template <typename T>
class smart_ptr
{
private:
    // pointer to the referred object
    T* ptr_;
    // pointer to a reference count
    int* ref_;
public:
    // Create a smart_ptr that is initialized to NULL. The reference count
    // should be zero.
    smart_ptr() : ptr_(nullptr), ref_(new int(0))
    {
    
    }
    
    // Create a smart_ptr that is initialized to raw_ptr. The reference count
    // should be one.
    explicit smart_ptr(T* raw_ptr) : ptr_(raw_ptr), ref_(new int(1))
    {

    }

    // Copy construct a pointer from rhs. The reference count should be
    // incremented by one.
    smart_ptr(const smart_ptr<T>& rhs)
    {
        ptr_ = rhs.ptr_;
        ref_ = rhs.ref_;
        (*ref_)++;
    }

    // Move construct a pointer from rhs.
    smart_ptr(smart_ptr&& rhs)
    {
        ptr_ = rhs.ptr_;
        ref_ = rhs.ref_;
        rhs.ptr_ = nullptr;
        rhs.ref_ = nullptr;
    }

    // This assignment should make a shallow copy of the right-hand side's
    // pointer data. The reference count should be incremented as appropriate.
    smart_ptr<T>& operator=(const smart_ptr<T>& rhs)
    {
        if (*ref_ == 1)
        {
            delete ptr_;
            delete ref_;
        }
        else
        {
            (*ref_)--;
        }
        
        ptr_ = rhs.ptr_;
        ref_ = rhs.ref_;
        return *this;
    }

    // This move assignment should steal the right-hand side's pointer data.
    smart_ptr& operator=(smart_ptr&& rhs);
    
    // If the smart_ptr is either NULL or has a reference count of one, this
    // function will do nothing and return false. Otherwise, the referred to
    // object's reference count will be decreased and a new deep copy of the
    // object will be created. This new copy will be the object that this
    // smart_ptr points and its reference count will be one.
    bool clone()
    {
        if (smart_ptr() == nullptr || smart_ptr().ref_count() == 1)
        {
            // return nothing if the condition has a reference count of 1 and
            // smart_ptr is nullptr
            return false;
        }
        else
        {
            --ref_count();
            // deep copy of the object will be created
            
        }
    }

    // Returns the reference count of the pointed to data.
    int ref_count() const
    {
        assert(ref_);
        return *ref_;
    }

    // The dereference operator shall return a reference to the referred object.
    // Throws null_ptr_exception on invalid access.
    T& operator*()
    {
        return const_cast<T&>(static_cast<const smart_ptr<T>&>(*this).operator*());
        /* Read more about this exception handling
           In the homework instruction it should throw a null_ptr_exception on invalid access
        throw std::null_ptr
         */
    }

    // The arrow operator shall return the pointer ptr_. Throws null_ptr_exception
    // on invalid access.
    T* operator->()
    {
        if (ptr_)
        {
            return ptr_;
//            throw std::null_ptr_exception();
        }
    }
    
    // deallocate all dynamic memory
    ~smart_ptr()
    {
        if (!--*ref_)
        {
            // delete all dynamically allocated memory on
            // the pointed referred object and referred count
            delete ptr_;
            delete ref_;
        }
    }
};


int main()
{
        /* TEST CODE
        int* p { new int { 42 } };
        smart_ptr<int> sp1 { p };
    
        cout << "Ref count is " << sp1.ref_count() << endl;    // Ref Count is 1
        {
            smart_ptr<int> sp2 { sp1 };
            cout << "Ref count is " << sp1.ref_count() << endl;    // Ref Count is 2
            cout << "Ref count is " << sp2.ref_count() << endl;    // Ref Count is 2
        }
        cout << "Ref count is " << sp1.ref_count() << endl;    // Ref Count is 1
    
        smart_ptr<int> sp3;
    
        cout << "Ref count is " << sp3.ref_count() << endl;    // Ref Count is 0
    
        sp3 = sp1;
    
        cout << "Ref count is " << sp1.ref_count() << endl;    // Ref Count is 2
        cout << "Ref count is " << sp3.ref_count() << endl;    // Ref Count is 2
    
        smart_ptr<int> sp4 = std::move(sp1);
    
        cout << *sp4 << " " << *sp3 << endl;        // prints 42 42
        cout << *sp1 << endl;                       // throws null_ptr_exception
         */
    
    cin.get();
    return 0;
}


