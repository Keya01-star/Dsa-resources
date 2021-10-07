#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void insertfirst(){
    struct node *ptr;
    int value;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        cout<<"\noverflow";
    }
    else{
        cout<<"\nenter value:";
        cin>>value;
        if(head==NULL){
            ptr->next=NULL;
            ptr->prev=NULL;
            ptr->data=value;
            head=ptr;
        }
        else{
            ptr->data=value;
            ptr->prev=NULL;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
    }
}

void display(){
    struct node *ptr;
    cout<<"\ndoubly linked list: ";
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data;
        ptr=ptr->next;
    }
}

void insertlast(){
        struct node *ptr,*temp;
    int value;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        cout<<"\noverflow";
    }
    else{
        cout<<"\nenter value:";
        cin>>value;
        ptr->data=value;
        if(head==NULL){
            ptr->next=NULL;
            ptr->prev=NULL;

            head=ptr;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;
        }
     }
}

void insertmiddle(){
    struct node *ptr,*temp;
    int value,position;
    ptr=(struct node*)malloc(sizeof(struct node*));

    if(ptr==NULL){
        cout<<"\noverflow";
    }
    else{
        temp=head;
       cout<<"enter position: ";
       cin>>position;
       for(int i=1;i<position;i++)
       {
           temp = temp->next;
           if(temp == NULL)
           {
               cout<<"\n"<<position;
               return;
           }
       }
       cout<<"\nenter value: ";
       cin>>value;
       ptr->data = value;
       ptr->next = temp->next;
       ptr -> prev = temp;
       temp->next = ptr;
       temp->next->prev=ptr;

   }

}
void deleteatfirst(){
    struct node *ptr;
    if(head == NULL)
    {
        cout<<"\nunderflow";
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        cout<<"\nnode deleted";
    }
    else
    {
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
        cout<<"\nnode deleted";
    }
}
void deleteatlast(){
     struct node *ptr;
    if(head == NULL)
    {
          cout<<"\nunderflow";
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
          cout<<"\nnode deleted";
    }
    else
    {
        ptr = head;
        if(ptr->next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
          cout<<"\nnode deleted";
    }
}

void deleteatmiddle(){
    struct node *ptr, *temp;
    int value;
    cout<<"\n Enter the position after which the node is to be deleted : ";
    cin>>value;
    ptr = head;
    while(ptr -> data != val)
    ptr = ptr -> next;
    if(ptr -> next == NULL)
    {
        cout<<"\nnode can not deleted";
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
         cout<<"\nnode deleted";
    }
}

int main(){
    int n;
    cout<<"1.insert at first\n2.display\n3.insert at last\n4.insert at middle\n5.delete at first\n6.delete at last\n7.delete at middle 8.exit\n";
    do{
    cout<<"\nenter choice:";
    cin>>n;
    switch(n){
    case 1:
        insertfirst();
        break;
    case 2:
        display();
        break;
    case 3:
        insertlast();
        break;
    case 4:
        insertmiddle();
        break;
    case 5:
        deleteatfirst();
        break;
    case 6:
        deleteatlast();
        break;
    case 7:
        deleteatmiddle();
        break;
    case 8:
        exit(0);
        break;
    default:
        cout<<"enter proper choice";
    }
    }while(n!=8);

}
