#include <iostream>
using namespace std ;
// #include " Node.cpp "
class node{
int data;

public:
node* next;                              // public banaya kyuki isko access karneke liye koi function na lage humko

node(){
  this -> data = 0;                     // data set karne ke liye
    this -> next = NULL; 
}
node (int data){                               // constructor node banane ke liye 
    this -> data = data;                     // data set karne ke liye
    this -> next = NULL;               // initially NULL pointer banana ,atki baad mein dusre node ko point kar sake
}
void print(node * temp){                       // print function
  if(temp != NULL){ 
     cout<<temp -> data<<endl;
    print( temp ->next);
  }
}

node* reverseLL( node * head ) {
  if ( head == NULL || head-> next == NULL ) {
    return head ;
}
 
  node* smallAns = reverseLL ( head -> next ) ;
  node* temp = smallAns ;

 while( temp -> next != NULL ) {
    temp = temp -> next ;
  }
  temp -> next = head ;
  head -> next = NULL ;
  return smallAns ;
  }
 
 node* input(){
    int data;
    cin>>data;
    node * head = NULL;
    node * temp;
    while(data != -1){
        node * newNode = new node (data);
        if(head == NULL){
            head = newNode;
            temp = head;
        }
        else{
            temp -> next = newNode;
            temp = temp ->next;
        }
        cin>>data;
    }
    
        return head;
    
}


} ;
int main(){
  node n1;
  cout<<"enter data for linked list "<<endl<<"note : input ends when you enter -1"<<endl;
node * head = n1.input() ;
head = n1.reverseLL(head);
n1.print(head);
return 0;
}