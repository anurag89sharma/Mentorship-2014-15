#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

node *create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(node **head, int data){
    node *temp = create_node(data);
    if((*head) == NULL)
        (*head) = temp;
    else{
        node *p = (*head);
        while(p->next)
            p = p->next;
        p->next = temp;
    }
}

void display(node *head){
    node *p = head;
    while(p){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

void delete_list(node **head){
    node *temp,*p = (*head);
    while(p){
        temp = p;
        p = p->next;
        (*head) = p;
        delete temp;
    }
}

void delete_n_nodes(node **head,int m,int n){
    node * p = (*head);
    node *temp;
    int pass_nodes = 1, delete_nodes = 0;
    if(m == 0){
        delete_list(head);
        return;
    }
    while(p){
        while(pass_nodes< m && p->next){
            cout<<"Skip"<<p->data<<endl;
            p = p->next;
            pass_nodes++;
        }
        pass_nodes = 1;
        //cout<<"Last"<<p->data<<endl;
        while(delete_nodes < n && p->next){
            temp = p->next;
            p->next = temp->next;
            //cout<<temp->data<<endl;
            delete temp;
            delete_nodes++;
        }
        delete_nodes = 0;
        p = p->next;
    }
}

int main(){
    int m,n;
    node *head = NULL;
    insert(&head,23);
    insert(&head,3);
    insert(&head,4);
    insert(&head,6);
    insert(&head,9);
    insert(&head,12);
    insert(&head,31);
    insert(&head,14);
    insert(&head,18);
    cout<<"Initial List"<<endl;
    display(head);
    cout<<"Enter m and n: ";
    cin>>m;
    cin>>n;
    delete_n_nodes(&head,m,n);
    cout<<"Final List"<<endl;
    display(head);
    return 0;
}
