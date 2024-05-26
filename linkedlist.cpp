// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class Node {
    public:
  int val;
  Node* next;
  
  Node(int data) {
      val = data;
      next = NULL;
  }
};
void create(Node* &head,int val) {
      Node* new_node = new Node(val);
      new_node -> next = head;
      head = new_node;
  }
  
  void show(Node* head) {
      Node* temp = head;
      while(temp!=NULL) {
          cout<<temp->val<<"->";
          temp = temp->next;
      }
      cout<<"NULL";
  }
  
 void createtail(Node* head,int val) {
      Node* new_node = new Node(val);
      Node* temp = head;
      while(temp->next != NULL){
          temp = temp->next;
      }
      temp->next = new_node;
  }
  
  void creategiven(Node* &head, int val,int pos) {
      if(pos==1) {
          create(head,val);
      } else {
      Node* new_node = new Node(val);
      Node* temp = head;
      int posii=1;
      while(posii != pos-1) {
          temp = temp->next;
          posii++;
      }
      new_node->next = temp->next;
      temp->next = new_node;
      }
  }
  
  void deletegiven(Node* head, int pos) {
      Node* temp = head;
      int ctr = 1;
      while(ctr != pos-1) {
          temp = temp-> next;
          ctr++;
      }
      Node* dele = temp->next;
      temp->next = temp->next->next;
      free(dele);
  }
int main() {
    Node* head = NULL;
    create(head,10);
    create(head,20);
    create(head,30);
    create(head,40);
    createtail(head,5);
    creategiven(head,25,3);
    creategiven(head,50,1);
    deletegiven(head,4);
    deletegiven(head,6);  
    show(head);

}
