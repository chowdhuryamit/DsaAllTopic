#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};

Node* insertAtHead(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(value);
        newnode->next=head;
        head=newnode;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void insertAtTail(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(value);
        tail->next=newnode;
        tail=newnode;
    }
}

int getLength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtPosition(int position,int value,Node* &head,Node* &tail){
    int length=getLength(head);
    if(position==1){
        head=insertAtHead(value,head,tail);
    }
    else if (position==length+1)
    {
        insertAtTail(value,head,tail);
    }
    else{
        Node* temp=head;
        for (int i = 1; i < position-1; i++)
        {
            temp=temp->next;
        }
        Node* newnode=new Node(value);
        newnode->next=temp->next;
        temp->next=newnode;
        
    }
}

int searchll(int target,Node* head){
  Node* temp=head;
  int pos=0;
  while(temp!=NULL){
    pos++;
    if(temp->data==target){
        return pos;
    }
    temp=temp->next;
  }
  int len=getLength(head);
  if (len==pos)
  {
    return -1;
  }
}

void deletell(int position,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        cout<<"ll is empty"<<endl;
        return;
    }
    else if (head==tail)
    {
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        cout<<"single node deleted"<<endl;
        return;
    }
    else{
      if (position==1)
      {
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
      }
      else
      {
        Node* temp=head;
        for(int i=1;i<position-1;i++){
            temp=temp->next;
        }
        Node* curr=temp->next;
        temp->next=curr->next;
        curr->next=NULL;
        delete curr;
      }
    }
}
int main(){
    //Node* first=new Node(10);
      Node* head=NULL;
      Node* tail=NULL;
    //   head=insertAtHead(10,head,tail);
    //   head=insertAtHead(20,head,tail);
    //   head=insertAtHead(30,head,tail);
    
    insertAtTail(15,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    //print(head);
    insertAtPosition(2,19,head,tail);

    //print(head);
    insertAtPosition(4,25,head,tail);
    print(head);

    //cout<<searchll(30,head)<<endl;
    deletell(5,head,tail);
    print(head);

    return 0;
}