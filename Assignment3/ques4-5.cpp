#include <iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    struct node *next;
};

node *head = NULL;

node* create_node(int data){
    node *temp = new node;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void insert_node(int data){
    node *temp = create_node(data);
    if(head == NULL)
        head = temp;
    else{
        node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

void display(){
    node *p = head;
    while(p){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

void print_k_node_from_last(int pos){
    int count = 0;
    node *p = head;
    while(count < pos){
        if(p==NULL){
            cout<<"Length of list is less than: "<<pos<<endl;
            return;
        }
        p = p->next;
        count++;
    }
    node *q = head;
    while(p){
        p = p->next;
        q = q->next;
    }
    cout<<pos<<" node from last is "<<q->data<<endl;
}

void second_min_max(){
    node *p = head;
    int first_min, second_min, first_max, second_max;
    first_min = second_min= INT_MAX;
    first_max = second_max = INT_MIN;
    while(p){
        // finding second minimum
        if(p->data < first_min){
            second_min = first_min;
            first_min = p->data;
        }
        if(p->data < second_min && p->data != first_min)
            second_min = p->data;

        // finding second maximum
        if(p->data> first_max){
            second_max = first_max;
            first_max = p->data;
        }
        if(p->data > second_max && p->data != first_max)
            second_max = p->data;

        p = p->next;
    }

    if (second_min == INT_MAX)
        cout<<"There is no second smallest element"<<endl;
    else
        cout<<"The Smallest element is: "<<first_min<<" and Second Smallest element is: "<<second_min<<endl;

    if (second_max == INT_MIN)
        cout<<"There is no second smallest element"<<endl;
    else
        cout<<"The Largest element is: "<<first_max<<" and Second largest element is: "<<second_max<<endl;
}

int main(){
    int pos = 0;
    insert_node(4);
    insert_node(6);
    insert_node(9);
    insert_node(12);
    insert_node(17);
    insert_node(29);
    insert_node(3);
    insert_node(7);
    display();
    //cout<<"Enter k: ";
    //cin>>pos;
    //print_k_node_from_last(pos);
    second_min_max();

    return 0;
}