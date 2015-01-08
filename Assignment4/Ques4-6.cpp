#include<iostream>

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

void insert_node(node **root, int data){
    node *temp = create_node(data);
    node *p = (*root);
    if(*root==NULL)
        (*root) = temp;
    else{
        while(p->next)
            p = p->next;
        p->next = temp;
    }
}

node *reverse_list(node *head){
    node *current = head, *next;
    node *prev = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void delete_node(node **head,int data){
    node *p = (*head);
    node * temp;
    if (p->data == data){
        temp = p;
        (*head) = p->next;
        delete temp;
    }
    else{
        while(p->next != NULL && p->next->data != data)
            p = p->next;

        if(p->next == NULL)
        {
            cout<<"Given node "<<data<<" is not present in Linked List"<<endl;
            return;
        }
        temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

void remove_element_on_right(node **head){
    node *p = (*head);
    int cur_max = p->data;
    p = p->next;
    while(p){
        if(p->data < cur_max){
            node *temp = p->next;
            delete_node(head,p->data);
            p = temp;
        }
        else{
            cur_max = p->data;
            p = p->next;
        }
    }
}

void remove_duplicates(node **root){
    node *p = (*root), *temp, *q, *prev;
    int data;
    while(p){
        data = p->data;
        q = p->next;
        prev = p;
        while(q){
            if(q->data == data){
                temp = q;
                prev->next = temp->next;
                q = temp->next;
                delete(temp);
            }
            else{
                prev = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

void display(node *root){
    while(root){
        cout<<root->data<<"\t";
        root = root->next;
    }
    cout<<endl;
}

int main(){
    node *head = NULL;
    node *rev, *processed_list;
    insert_node(&head,12);
    insert_node(&head,15);
    insert_node(&head,10);
    insert_node(&head,11);
    insert_node(&head,5);
    insert_node(&head,6);
    insert_node(&head,2);
    insert_node(&head,3);

    cout<<"Initial List:"<<endl;
    display(head);

    rev = reverse_list(head);
    remove_element_on_right(&rev);
    rev = reverse_list(rev);
    cout<<"List after deleting nodes which have a greater value on right side"<<endl;
    display(rev);

    head = NULL;
    insert_node(&head,4);
    insert_node(&head,4);
    insert_node(&head,5);
    insert_node(&head,5);
    insert_node(&head,5);
    insert_node(&head,4);
    insert_node(&head,18);
    insert_node(&head,5);
    insert_node(&head,3);

    cout<<"Initial List:"<<endl;
    display(head);
    cout<<"List after removing duplicates:"<<endl;
    remove_duplicates(&head);
    display(head);

    return 0;
}
