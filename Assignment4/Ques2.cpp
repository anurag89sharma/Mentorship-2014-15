#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

node* create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void detect_remove_loop(node *head){
    node *slow = head, *fast = head;
    bool loop = false;

    while(slow!= NULL && fast!= NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            loop = true;
            break;
        }
    }
    cout<<"Loop exists: "<<loop<<endl;
    if(loop){
        node *p1 = head, *p2 = slow, *loop_node = slow;
        while(p1!= p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        cout<<"Loop is at node: "<<p1->data;

        p2 = p1->next;
        while(p2->next!= p1)
            p2 = p2->next;

        p2->next = NULL;
    }
}

void insert(node **root, int data){
    node *temp = create_node(data);
    node *p = (*root);
    if(p==NULL)
        (*root) = temp;
    else{
        while(p->next)
            p = p->next;
        p->next = temp;
    }
}

void display(node *root){
    node *p = root;
    while(p){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    node *head = NULL;
    insert(&head,4);
    insert(&head,7);
    insert(&head,9);
    insert(&head,1);
    insert(&head,3);
    insert(&head,6);

    display(head);
    head->next->next->next->next->next->next = head;
    detect_remove_loop(head);
    display(head);
    return 0;
}
