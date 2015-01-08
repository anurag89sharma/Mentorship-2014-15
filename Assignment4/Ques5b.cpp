#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

node *create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void sorted_insert(node **head,int data){
    node *temp = create_node(data);
    if ((*head)==NULL)
        (*head) = temp;
    else if (data < (*head)->data){
        temp->next = (*head);
        (*head)->prev = temp;
        (*head) = temp;
    }
    else{
        node *p = (*head), *next;
        while(p->next && p->next->data < data)
            p =p->next;
        next = p->next;
        p->next = temp;
        temp->next = next;
        temp->prev = p;
        if(next)
            temp->next->prev = temp;
    }
}

void display(node *head){
    cout<<"Printing List by traversing right"<<endl;
    node *p = head;
    while(p->next){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<p->data;
    cout<<endl;
    //cout<<"Printing List by traversing left"<<endl;
    //while(p->prev){
    //    cout<<p->data<<"\t";
    //    p = p->prev;
    //}
    //cout<<p->data;
    //cout<<endl;
}

int main(){
    node *head = NULL;
    sorted_insert(&head,17);
    sorted_insert(&head,7);
    sorted_insert(&head,12);
    sorted_insert(&head,25);
    sorted_insert(&head,45);
    sorted_insert(&head,5);
    sorted_insert(&head,5);
    sorted_insert(&head,39);

    display(head);
    return 0;
}
