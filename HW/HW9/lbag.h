#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include <string>
#include "node.h"

template <class T>
class LBag
{
public:
  // pre: none
  // post: creates an empty LBag
  LBag();

  // pre: none
  // post: creates an LBag that is a copy of given LBag
  LBag(const LBag &);

  // Returns all memory to the runtime environment and sets head and tail to nullptr
  ~LBag();

  // pre: none
  // post:  change this bag to be a copy of the parameter bag
  void operator=(const LBag &b);

  // pre: none
  // post:  returns the number of nodes in the linked list
  std::size_t size() const;

  // pre: none
  // post:  returns the number of times the parameter value appears in the bag
  std::size_t count(const T &value) const;

  // pre: none
  // Post:  the parameter value is inserted at the head of the bag
  void insert(const T &value);

  // pre: none
  // post:  our bag includes all of its elements, followed by all of the parameter bag's elements
  void operator+=(const LBag &b); // homework

  // pre: none
  // post:  removes the first instance of the parameter value in the bag, if there is one.
  bool erase_one(const T &value); // homework

  // pre: none
  // post:  removes all instances of the parameter value in the bag.
  std::size_t erase(const T &value); // homework



  template <typename T2>
  friend std::ostream &operator<<(std::ostream &out, const LBag<T2> &b);
  // friend functions can use private members

private:
  node<T> *head, *tail;
};

template <class T>
LBag<T> operator+(const LBag<T> &a, const LBag<T> &b);
// template <class T>//This is a template function because it operates on
// a template class object, but it is NOT a member function of a template class
// std::ostream& operator <<(std::ostream& out, const LBag<T> &);

// pre: none
// post: creates an empty LBag
template <class T>
LBag<T>::LBag()
{
  head = nullptr;
  tail = nullptr;
}

// pre: none
// post: creates an LBag that is a copy of given LBag
template <class T>
LBag<T>::LBag(const LBag &b)
{
  list_copy(b.head, b.tail, head, tail);
}
// ways to call the copy constructor
// Lbag<int> lb(lb1);
// Lbag<int> lb = lb1;

// Returns all memory to the runtime environment and
// sets head and tail to nullptr
template <class T>
LBag<T>::~LBag()
{
  list_clear(head, tail);
}

// pre: none
// post:  change this bag to be a copy of the parameter bag
template <class T>
void LBag<T>::operator=(const LBag &b)
{
  list_clear(head, tail);
  list_copy(b.head, b.tail, head, tail);
}
// pre: none
// post:  returns the number of nodes in the linked list
template <class T>
std::size_t LBag<T>::size() const
{
  return list_size(head);
}

// pre: none
// post:  returns the number of times the parameter value appears in the bag
template <class T>
std::size_t LBag<T>::count(const T &value) const
{
  node<T> *temp = head;
  std::size_t count = 0;
  while (temp != nullptr)
  {
    if (value == temp->data()) // each value is equal to the value, increment counter
      count++;
    temp = temp->link();
  }
  return count;
}
/*Alternative
    template <class T>
    std::size_t LBag<T>::count(const T & value) const{
      node<T>* temp=list_search(head, value);
      std::size_t count = 0;
      while(temp!=nullptr){
        ++count;
        temp = list_search(temp->link(), value);
      }
      return count;
    }
    */
// pre: none
// Post:  the parameter value is inserted at the head of the bag
template <class T>
void LBag<T>::insert(const T &value)
{
  list_head_insert(head, tail, value);
}

template <class T>
std::ostream &operator<<(std::ostream &out,
                         const LBag<T> &b)
{
  out << b.head;
  return out;
}

//Homework

// pre: none
// post:  our bag includes all of its elements, followed by all of the parameter bag's elements
template <class T>
void LBag<T>::operator+=(const LBag &b){
  for(node<T>* temp = b.head; temp!=nullptr; temp=temp->link()){
    list_tail_insert(head, tail, temp->data());
  }


}

template <class T>
LBag<T> operator+(const LBag<T> &a, const LBag<T> &b){
 //overload using +=
  LBag<T> c;
  c+=a;
  c+=b;
  return c;
}

// pre: none
// post:  removes the first instance of the parameter value in the bag, if there is one.
template <class T>
bool LBag<T>::erase_one(const T &value){
 
  for(node<T>* temp = head; temp!=nullptr; temp=temp->link()){//iterate through the list
    if(temp->data()==value){//if the value is found 
   
      if(temp==head){//if the value is at the head
        head=head->link();//move the head to the next node
        delete temp;
        return true;
      }else{
        node<T>* temp2=head;
        while(temp2->link()!=temp){
          temp2=temp2->link();
        }
        temp2->setlink(temp->link());
        delete temp;
        return true;
      }
   
   }
  }
  return false;
}

// pre: none
// post:  removes all instances of the parameter value in the bag.
template <class T>
std::size_t LBag<T>::erase(const T &value){
  //remove all instances of the value
  std::size_t count=0;
  while(erase_one(value)){
    count++;
  }
  return count;
}
  



//linked list toolkit functions

template <class T>
void list_clear(node<T> * & head, node<T> * &tail){
  //Deletes all memory for the LL, and resets head and tail to nullptr
  node<T> *temp;
  while(head!=nullptr){
    temp = head;
    head = head->link();
    delete temp;
  }
  tail = nullptr;
}





#endif // LBAG_H
