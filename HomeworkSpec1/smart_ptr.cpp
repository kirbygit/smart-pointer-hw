#include <iostream>
using namespace std;

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

    }

    // Move construct a pointer from rhs.
    smart_ptr(smart_ptr&& rhs);

    // This assignment should make a shallow copy of the right-hand side's
    // pointer data. The reference count should be incremented as appropriate.
    smart_ptr& operator=(const smart_ptr& rhs);

    // This move assignment should steal the right-hand side's pointer data.
    smart_ptr& operator=(smart_ptr&& rhs);
    
    // If the smart_ptr is either NULL or has a reference count of one, this
    // function will do nothing and return false. Otherwise, the referred to
    // object's reference count will be decreased and a new deep copy of the
    // object will be created. This new copy will be the object that this
    // smart_ptr points and its reference count will be one.
    bool clone();

    // Returns the reference count of the pointed to data.
    int ref_count() const;

    // The dereference operator shall return a reference to the referred object.
    // Throws null_ptr_exception on invalid access.
    T& operator*();

    // The arrow operator shall return the pointer ptr_. Throws null_ptr_exception
    // on invalid access.
    T* operator->();
    
    // deallocate all dynamic memory
    ~smart_ptr();
};


int main()
{
    cout << "TEST" << endl;
    
    cin.get();
    return 0;
}


