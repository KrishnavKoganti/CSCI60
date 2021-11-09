#include <iostream>
// #include "node.h"
using namespace std;

void insert(node* n,int value){
    node* temp = new node;
    temp->data = value;
    temp->next = n;
    n = temp;
}

int main(){

    node * head, * tail;

    node n = node(5, nullptr);
    head = &n;
    tail = &n;


    node n2 = node(10, nullptr);
    //add a mode with value 5
    node n2 = node(5, nullptr);
    tail->set_link(&n2)
    tail = &n2;
    //add a node with value 6 after 5   
    node n3 = node(6, nullptr);
    tail->set_link(n3);
    tail = &n3;
    // We don't do it this way! WE dont't create node variables,
    //we just acccess everything through the headpointer.
    // we dont work with node objects, we work with pointers to nodes


    return 0; 
}