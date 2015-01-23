#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

node *create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert_node(node **head,int data){
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

void remove_duplicates(node **head){
    node *prev = (*head), *p = (*head);
    node *next,*temp;
    p = p->next;
    while(p){
        if(prev->data == p->data){
            prev->next = p->next;
            temp = p;
            delete temp;
            p = prev->next;
        }
        else{
            p = p->next;
            prev = prev->next;
        }
    }
}

void merge(node **result, node *first, node *second){
    node *p1 = first;
    node *p2 = second;

    while(p1 && p2){
        if(p1->data < p2->data){
            insert_node(result,p1->data);
            p1 = p1->next;
        }
        else{
            insert_node(result,p2->data);
            p2 = p2->next;
        }
    }
    if(p1){
        insert_node(result,p1->data);
        p1 = p1->next;
    }
    if(p2){
        insert_node(result,p2->data);
        p2 = p2->next;
    }
}

void rotate_list(node **head,int n){
    int count = 0;
    node *p = (*head);
    node *next;
    while(p){
        count++;
        p = p->next;
    }
    if(count > n){
        p = (*head);
        count = 1;
        while(count != n){
            p = p->next;
            count++;
        }
        next = p->next;
        p->next = NULL;
        p = next;
        while(p->next)
            p = p->next;
        p->next = (*head);
        (*head) = next;
    }
    else
        cout<<"Enter 'n' to be less than the length of the list";
}

int main()
{
    int n;
    node *head = NULL;
    insert_node(&head,2);
    insert_node(&head,2);
    insert_node(&head,2);
    insert_node(&head,5);
    insert_node(&head,7);
    insert_node(&head,7);
    insert_node(&head,11);
    insert_node(&head,13);
    cout<<"Initial List:"<<endl;
    display(head);
    cout<<"List after removing duplicate elements:"<<endl;
    remove_duplicates(&head);
    display(head);

    cout<<"Enter the number by which you want to rotate the list: ";
    cin>>n;
    rotate_list(&head,n);
    cout<<"Rotated List:"<<endl;
    display(head);

    node *first = NULL, *second = NULL, *result = NULL;
    insert_node(&first,2);
    insert_node(&first,5);
    insert_node(&first,8);
    insert_node(&first,11);
    insert_node(&first,16);
    cout<<"First list: "<<endl;
    display(first);

    insert_node(&second,1);
    insert_node(&second,7);
    insert_node(&second,10);
    insert_node(&second,10);
    insert_node(&second,14);
    cout<<"Second list: "<<endl;
    display(second);

    merge(&result, first, second);
    cout<<"Merged list: "<<endl;
    display(result);

    return 0;
}
