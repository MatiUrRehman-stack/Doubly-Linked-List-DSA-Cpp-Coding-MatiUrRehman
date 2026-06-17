class Node{
private:
   int data;
   Node *next;
   Node *prev;
public:
//=====Constructer & Destructer
   Node(int val):data(val), next(nullptr), prev(nullptr){}
   void set_data(int val){data = val;}
   int get_data(){return data;}
   void set_next(Node *temp){next = temp;}
   Node *get_next(){return next;}
   void set_prev(Node *temp){prev = temp;}
   Node *get_prev(){return prev;}
};
