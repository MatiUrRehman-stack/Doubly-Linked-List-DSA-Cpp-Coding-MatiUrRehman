#include <iostream>
#include "DNode.hpp"
using namespace std;

class DList{
private:
   Node *head;
   Node *tail;
public:
//==========Constructer & Destructer
   DList(){head = tail = nullptr;}
   ~DList(){Node *curr = head;while(curr != nullptr){Node *Next = curr->get_next();delete curr;curr = Next;}head = tail = nullptr;}

//======Push and POP from front (head)
   void push_front(int val){Node *newNode = new Node(val);if(head == nullptr){head = tail = newNode;return;}else{newNode->set_next(head);head->set_prev(newNode);head = newNode;}}

   void pop_front(){if(head == nullptr){cout<<"List is Empty"<<endl;return;}Node *temp = head;head = head->get_next();if(head != nullptr){head->set_prev(nullptr);temp->set_next(nullptr);}else{tail = nullptr;};delete temp;}


//=========Push and POP from back (tail)
   void push_back(int val){Node *newNode = new Node (val);if (head == nullptr){head = tail = newNode;return;}else{newNode->set_prev(tail);tail->set_next(newNode);tail = newNode;}}

   void pop_back(){if(head == nullptr){cout<<"List is Empty"<<endl;return;}Node *temp = tail;tail = tail->get_prev();if(tail != nullptr){temp->set_prev(nullptr);tail->set_next(nullptr);}else{head = nullptr;}delete temp;}

//========Palindrome check in DLIST
   bool is_palindrome(){if(head == nullptr){cout<<"List is empty"<<endl;return false;}else if(head == tail){return true;}else{Node *first = head; Node *last = tail; while(first != last && first->get_prev() != last){if(first->get_data() != last->get_data()){return false;}first = first->get_next();last = last->get_prev();}return (first->get_data() == last->get_data());}}


//========Display function
   void print_list(){if(head == nullptr){cout<<"List is Empty"<<endl;return;}Node *temp = head;while(temp != nullptr){cout<<temp->get_data()<<" -> "; temp = temp->get_next();}cout<<"NULL"<<endl;}
};

int main (){
   DList dl;
   dl.push_back(23);dl.push_back(24);dl.push_back(13);dl.push_back(24);dl.push_back(23);
  
   dl.print_list();
   dl.pop_back();
   dl.pop_front();
   
   palindrome:
   {if(dl.is_palindrome()) cout<<"true";
   else cout<<"false";}
   
   dl.print_list();
}