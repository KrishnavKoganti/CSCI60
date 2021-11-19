#include <iostream>
#include "node.h"

using namespace std;



size_t list_index(node *head_ptr, int target){
  size_t count = 0;
  for(node *p = head_ptr; p!=nullptr; p=p->link()){
    if(p->data() == target){
      return count;
    }
    count++;
  }
  return -1;
}

node* list_at(node * head_ptr, std::size_t n){
  size_t count = 0;
  node *temp;
  for(node *p = head_ptr; p!=nullptr && count < n; p=p->link()){
    temp = p;
    count++;
  }
  return temp;
}
void list_clear(node * & head_ptr, node * & tail_ptr){
  node *p = head_ptr;
  while(p!=nullptr){
    head_ptr = head_ptr->link();
    delete p;
    p = head_ptr;
  }
  tail_ptr = nullptr;
}

void list_reverse(node *&head_ptr, node *&tail_ptr)
{
  node *p = head_ptr;
  node *q = nullptr;
  node *r = nullptr;
  while (p != nullptr)
  {
    r = q;
    q = p;
    p = p->link();
    q->set_link(r);
  }
  head_ptr = q;
  tail_ptr = head_ptr;

  while (tail_ptr->link() != nullptr)
  {
    tail_ptr = tail_ptr->link();
  }

  //without using temp


}

void list_reverse_ec(node *&head_ptr, node *&tail_ptr){
  

}

int main() {
      node *head = new node(4, nullptr);
      node *tail(head);
      node *temp;
      temp = new node(1, nullptr);
      tail->set_link(temp);
      tail = temp;
      head = new node(1, head);
      head = new node(3, head);
      temp = new node(5, nullptr);
      tail->set_link(temp);
      tail = temp;
      for (const node *p = head; p != nullptr; p = p->link())
        cout << p->data() << " ";
      cout << endl;

      list_reverse(head, tail);
      for (const node *p = head; p != nullptr; p = p->link())
        cout << p->data() << " ";
      cout << endl;
      list_clear(head,tail);
        for (const node *p = head; p != nullptr; p = p->link())
        cout << p->data() << " ";
      cout << endl;
      return 0;
    }