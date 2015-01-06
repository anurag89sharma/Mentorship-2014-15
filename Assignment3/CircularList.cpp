#include<iostream>

/*using namespace std;

struct node{
    int data;
    struct node* next;
};

int node_count = 0;

node *create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = temp;
    return temp;
}

void insert(node **root,int data, int position){
    node *temp = create_node(data);
    node *last = NULL;
    node *p = (*root);
    if((*root) == NULL){
        (*root) = temp;
        node_count++;
    }
    else if(position == 0){
        do{
            p = p->next;
        }while(p->next!= (*root));
        last = p;
        temp->next = (*root);
        last->next = temp;
        (*root) = temp;
        node_count++;
    }
    else if(position <= node_count){
        int count = 1;
        while(count!= position){
            p = p->next;
            count ++;
        }
        temp->next = p->next;
        p->next = temp;
        node_count++;
    }
    else
        cout<<"Entered position is greater than length of the list"<<endl;

}

void update_node(node** root, int loc,int data){
    int count = 1;
    node *p = (*root);
    if (loc <= node_count){
        while(count != loc){
            p = p->next;
            count++;
        }
        p->data = data;
    }
    else{
        cout<<"Cannot update data at the desired position"<<endl;
    }
}

void delete_node(node **root, int position){
    int count = 1;
    node *temp, *p = (*root);
    if(node_count>0){
        if(position == 1){
            temp = (*root);
            p = (*root);
            do{
                p = p->next;
            }while(p->next!= (*root));
            //cout<<p->next->data<<endl;
            (*root) = temp->next;
            p->next = (*root);
            //cout<<p->next->data<<endl;
            delete temp;
            node_count--;
        }
        else if(position <= node_count){
            while(count != position - 1){
                p = p->next;
                count++;
            }
            temp = p->next;
            p->next = temp->next;
            delete temp;
            node_count--;
        }
        else
            cout<<"Can't delete, entered position is greater than length of the list"<<endl;
    }
    else
        cout<<"Can't delete, list is empty"<<endl;
}

void reverse_list(node **root){
    node *current=(*root),*prev=NULL;
    node *next;
    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }while(current != (*root));
    (*root)->next = prev;
    (*root) = prev;
}

void display(node * root){
    cout<<"printing circular-link-list"<<endl;
    node *p = root;
    do{
        cout<<p->data<<"\t";
        p = p->next;
    }while(p!= root);
    cout<<endl;
}

int main(){
    node *head = NULL;
    insert(&head, 23,0);
    insert(&head, 13,0);
    insert(&head, 7,1);

    insert(&head, 71,2);
    insert(&head, 11,4);
    display(head);

    update_node(&head,2,89);
    display(head);

    reverse_list(&head);
    cout<<"Reverse of above list"<<endl;
    display(head);

    delete_node(&head,5);
    delete_node(&head,1);
    delete_node(&head,2);
    display(head);
    return 0;
}
*/
