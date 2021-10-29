#ifndef DYNAMICBAG_H
#define DYNAMICBAG_H

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>

template<typename T>
class DynamicBag
{
public:
        typedef std::size_t size_type;
        typedef T* iterator;
    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty DynamicBag
    DynamicBag();

    // copy constructor  (NEW! Before we used the built-in one)
    // pre: none
    // post: creates a new DynamicBag which is a copy of the given one
    DynamicBag(const DynamicBag &b);
    // pre: size tells us how many ints are in arr
    DynamicBag(int arr[], std::size_t size);
    // pre: none    (NEW!  Our first destructor)
    // post: destroys this DynamicBag; needed because we are using
    //       dynamically allocated memory
    ~DynamicBag();

    // CONSTANT MEMBERS
    // pre: none
    // post: returns the number of elements in this DynamicBag
    std::size_t size() const {return used_;}

    // pre: none
    // post: returns the number of times entry appears in this DynamicBag
    std::size_t count(int entry) const;

    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    int operator [](std::size_t pos) const;

    // MUTATING MEMBERS

    // pre: none
    // post: adds a copy of target to this DynamicBag
    void insert(int target);

    void insertAt(int item, size_t index);
    // pre: none
    // post: adds to this DynamicBag a copy of each element of b
    void operator += (const DynamicBag & b);

    // pre: none
    // post: if target appears in this DynamicBag, remove one copy and
    //       return true; else return false

    bool erase_one(int target);

    // pre: none
    // post: removes every copy of target in this DynamicBag and
    //       returns the number of elements removed
    std::size_t erase(int target);

    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
    void operator =(const DynamicBag &b);

    iterator begin() {return data_;}//returns the first element in the bag
    iterator end() {return data_ + used_;}//returns the last element in the bag
   



private:
    int *data_;
    std::size_t capacity_;
    std::size_t used_;

    // INVARIANTS:
    //   data_ points a dynamically allocated array of size capacity_
    //   data_[0], data_[1], ..., data_[used_-1] store the elements
    //   of this DynamicBag
    //   we don't care about data_[used_], ..., data_[capacity_]


};

// pre: none
// post: returns the sum of a and b

DynamicBag operator +(const DynamicBag & a, const DynamicBag & b);
std::ostream& operator<<(std::ostream&  out, const DynamicBag& b);


#endif // DYNAMICBAG_H
