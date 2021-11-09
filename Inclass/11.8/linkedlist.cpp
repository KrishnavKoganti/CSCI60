
using namespace std;

node* head = nullptr;
node* tail = nullptr

//add a node with value 5

head = new node(5,nullptr);
tail = head;

//add a node with value 6 after 5
node* temp = new node(6,nullptr);
(*tail).set_link(temp);
tail = temp;

//without temp
(*tail).set_link(new node(6,nullptr));
tail = (*tail).link();

//add a node with value 1 before 5
temp = new node(1,head);
head = temp;
//without temp
head = new node(1,head);


//insert a node with value 7 after 6
temp = new node(7,nullptr);
(*tail).set_link(temp);
tail = temp;

//loop over the linkedlist and print the values
node* temp = head;  
while(temp != nullptr)
{
    cout << (*temp).data() << endl;
    temp = (*temp).link();
}
