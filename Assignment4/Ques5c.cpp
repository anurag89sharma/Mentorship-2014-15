#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

node *create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = temp;
    return temp;
}

void sorted_insert(node **head, int data){
    node *temp =  create_node(data);
    node *last, *p;
    if((*head) == NULL)
        (*head) = temp;
    else if((*head)->data > data){
        p = (*head);
        do{
            p = p->next;
        }while(p->next!= (*head));
        last = p;
        temp->next = (*head);
        last->next = temp;
        (*head) = temp;
    }
    else{
        p = (*head);
        while(p->next != (*head)&& p->next->data < data){
            p = p->next;
        }
        node *next = p->next;
        p->next = temp;
        temp->next = next;
    }
}

void display(node *head){
    node *p = head;
    do{
        cout<<p->data<<"\t";
        p = p->next;
    }while(p!= head);
    cout<<endl;
}

int main(){
    node *head = NULL;
    sorted_insert(&head,17);
    sorted_insert(&head,7);
    sorted_insert(&head,12);
    sorted_insert(&head,25);
    sorted_insert(&head,5);
    sorted_insert(&head,5);
    sorted_insert(&head,39);

    display(head);
    return 0;
}
