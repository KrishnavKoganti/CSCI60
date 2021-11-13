
#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <ostream>
#include <iostream>
template <class T>
class node
{
public:
    node(const T& initdata = T(), //Calls the default constructor for the template type
        node* initlink = nullptr)
    {
        data_ = initdata;
        link_ = initlink;
    }
    T data() const
    {
        return data_;
    }
    T& data()
    {
        return data_;
    }
    node* link()
    {
        return link_;
    }
    const node* link() const
    {
        return link_;
    }
    void setdata(const T& newdata)
    {
        data_ = newdata;
    }
    void setlink(node* newlink)
    {
        link_ = newlink;
    }

private:
    T data_;
    node* link_;
};

// linked list toolkit functions

template <class T>
std::size_t list_size(const node<T>* head)
{
    std::size_t count = 0;
    for(const node<T>* p = head; p != nullptr; p = p->link())
    {
        count++;
    }
    return count;
}

template <class T>
void list_head_insert(node<T>*& head, //call by reference node<T> pointer - so if you change head in the function, you change the head that was passed in
    node<T>*& tail,
    const T& value)
{
    head = new node<T>(value, head); //creates a new node with the value and the head
    if(tail == nullptr)
    { //if the tail is null, then the new node is the tail
        tail = head;
    }
}

template <class T>
void list_tail_insert(node<T>*& head, node<T>*& tail, const T& value)
{
    node<T>* newnode = new node<T>(value, nullptr);
    if(head == nullptr) {
        head = newnode;
    }
    else {

        if(tail != nullptr) {
            tail->setlink(newnode);
        }
    }
    tail = newnode;

}
template <class T>
std::ostream& operator<<(std::ostream& os, const node<T>* head)
{
    for(const node<T>* p = head; p != nullptr; p = p->link()) {
        if(p != nullptr) {
            os << head->data();
        }
        os << p->data() << ", ";

    }

    return os;


}

template <class T>
node<T>* list_search(const node<T>* head, const T& value)
{

    for(const node<T>* p = head; p != nullptr; p = p->link()) {
        if(p->data() == value) {
            return p;
        }
    }
    return nullptr;
}

template <class T>
void list_copy(const node<T>* orig_head, const node<T>* orig_tail, node<T>*& new_head, node<T>*& new_tail)
{
    //Can functions we've already written
    //help?
    //new_head=orig_head;Doesn't make a copy
    //new_tail=orig_tail;Shares original list

    new_head = new node<T>(orig_head->data(), nullptr);
    new_tail = new node<T>(orig_tail->data(), nullptr);
    new_head->setlink(new_tail);
    for(const node<T>* p = orig_head; p != nullptr; p = p->link()) {
        if(p->link() != nullptr) {
            list_tail_insert(new_head, new_tail, p->data());

        }
    }
    list_tail_insert(new_head, new_tail, orig_tail->data());
}

template <class T>e
void list_remove(node<T>* previous, node<T>*& tail)
{
    if(previous->link() == nullptr) {

        delete previous;
        tail = nullptr;


    }
    else {

        previous->setlink(previous->link()->link());
        delete previous->link();
    }

}


template <class T>
void list_head_remove(node<T>*& head, node<T>*& tail)
{

    if(head == nullptr) {
        return;
    }
    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        node<T>* temp = head;
        head = head->link();
        delete temp;
    }
}

//Remember, we already have head insert and tail insert
template <class T>
void list_insert(node<T>* previous, const T& value)
{
    node<T> *newnode = new node<T>(value,previous->link());
    previous -> setlink(newnode);
}


#endif // NODE_H
