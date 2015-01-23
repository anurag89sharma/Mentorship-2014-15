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

void get_alternate_nodes(node **head){
    node *odd = (*head);
    node *even = NULL,*temp,*prev;
    while(odd){
        // see if next node of this element is not NULL
        if(odd->next){
            // If yes, then this node is a even node
            temp = odd->next;
            // link this odd element with the next odd element in the list
            odd->next = temp->next;
            // check if even node is NULL
            if(even==NULL){
                // if yes, then temp is the first node in the even list
                even = temp;
                // assign next of even to NULL
                even->next = NULL;
            }
            else{
                // add this even element at the beginning of even list
                temp->next = even;
                // assign even to the start of even list
                even = temp;
            }
        }
        // keep track of the last element
        prev = odd;
        odd = odd->next;
    }
    cout<<"Last element of odd list: "<<prev->data<<endl;
    cout<<endl<<"Odd element list:"<<endl;
    display(*head);
    cout<<endl<<"Even element list:"<<endl;
    display(even);
    prev->next = even;
}

int main(){
    node *head = NULL;
    insert(&head,13);
    insert(&head,3);
    insert(&head,4);
    insert(&head,7);
    insert(&head,6);
    insert(&head,9);
    insert(&head,31);
    insert(&head,14);
    insert(&head,18);
    cout<<"Initial List"<<endl;
    display(head);
    get_alternate_nodes(&head);
    cout<<"\nFinal List after reversing alternate nodes"<<endl;
    display(head);
    return 0;
}
