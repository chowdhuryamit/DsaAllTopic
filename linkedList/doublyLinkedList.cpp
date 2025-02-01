#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
   int data;
   Node* prev;
   Node* next;

   Node(int value){
    this->data=value;
   }
};

void insertAtHead(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    
}

void printAccHead(Node* head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void printAccTail(Node* tail){
    Node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<endl;
}

void insertAtTail(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(value);
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}

int getLength(Node* head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition(int position,int value,Node* &head,Node* &tail){
    int len=getLength(head);
    if (position==1)
    {
        insertAtHead(value,head,tail);
    }
    else if (position==len+1)
    {
        insertAtTail(value,head,tail);
    }
    else
    {
        Node* temp=head;
        for (int i = 0; i < position-2; i++)
        {
            temp=temp->next;
        }
        Node* newnode=new Node(value);
        Node* forward=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=forward;
        forward->prev=newnode;
    }   
}


int searchInll(Node* &head,int target){
    Node* temp=head;
    int pos=0;
    bool flag=false;
    while (temp!=NULL)
    {
        pos++;
        if (temp->data==target)
        {
            flag=true;
            break;
        }
        temp=temp->next;
    }
    if (flag)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

void deleteAtPosition(int position,Node* &head,Node* &tail){
    int len=getLength(head);
    if(head==NULL && tail==NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    else if (head==tail)
    {
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else if (position==1)
    {
        Node* temp=head;
        head=temp->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else if (len==position)
    {
        Node* temp=tail;
        Node* backward=temp->prev;
        tail=backward;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    else
    {
        Node* backward=head;
        for (int i = 0; i < position-2; i++)
        {
            backward=backward->next;
        }
        Node* curr=backward->next;
        Node* forward=curr->next;

        backward->next=forward;
        forward->prev=backward;

        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
        
    }
    
}


int main(){
   Node* head=NULL;
   Node* tail=NULL;
//    insertAtHead(10,head,tail);
//    insertAtHead(20,head,tail);
//    insertAtHead(30,head,tail);
//    printAccTail(tail);

    insertAtTail(10,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    insertAtTail(40,head,tail);
    printAccHead(head);
    //printAccTail(tail);

    insertAtPosition(3,420,head,tail);
    printAccHead(head);
    insertAtPosition(1,320,head,tail);
    printAccHead(head);
    insertAtPosition(7,220,head,tail);
    printAccHead(head);

    cout<<searchInll(head,0)<<endl;

    deleteAtPosition(1,head,tail);
    printAccHead(head);
    deleteAtPosition(3,head,tail);
    printAccHead(head);
    deleteAtPosition(5,head,tail);
    printAccHead(head);
    return 0;
}