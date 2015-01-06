#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int node_count = 0;

node* create_node(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

void insert(node **root,int data, int position){
    node *p,*temp = create_node(data);
    if (*root == NULL){
        (*root) = temp;
        node_count++;
    }
    else if(position == 0){
        (*root)->left = temp;
        temp->right = (*root);
        (*root) = temp;
        node_count++;
    }
    else if(position <= node_count){
        int count = 1;
        p = (*root);
        while(count != position){
            p = p->right;
            count++;
        }
        temp->right = p->right;
        p->right = temp;
        temp->left = p;

        if(temp->right)
            temp->right->left = temp;
        node_count++;
    }
    else
        cout<<"Entered position is greater than length of the list"<<endl;
}

void update_node(node** root, int data, int loc){
    int count = 1;
    node *p = (*root);
    if (loc <= node_count){
        while(count != loc){
            p = p->right;
            count++;
        }
        p->data = data;
    }
    else
        cout<<"Cannot update data at the desired position"<<endl;
}
void delete_node(node **root, int position){
    node *temp,*p;
    if(node_count>0){
        if(position==1){
            temp = (*root);
            (*root) = (*root)->right;
            (*root)->left = NULL;
            delete temp;
            node_count--;
        }
        else if(position <= node_count){
            int count = 1;
            p = (*root);
            while(count != position - 1){
                p = p->right;
                count++;
            }
            temp = p->right;
            p->right = temp->right;
            if(temp->right)
                temp->right->left = p;
            delete temp;
            node_count --;
        }
        else
            cout<<"Can't delete, entered position is greater than length of the list"<<endl;
    }
    else
        cout<<"List is empty"<<endl;
}

void reverse_list(node **root){
    node *current = (*root);
    node *next, *prev = NULL;
    while(current){
        next = current->right;
        current->right = prev;
        current->left = next;
        prev = current;
        current = next;
    }
    (*root) = prev;
}

void print(node *root){
    cout<<"Printing List by traversing right"<<endl;
    node *p = root;
    while(p->right){
        cout<<p->data<<"\t";
        p = p->right;
    }
    cout<<p->data;
    cout<<endl;
    cout<<"Printing List by traversing left"<<endl;
    //while(p->left){
    //    cout<<p->data<<"\t";
    //    p = p->left;
    //}
    //cout<<p->data;
    //cout<<endl;
}

int main(){
    node *head = NULL;
    insert(&head,23,0);
    insert(&head,31,0);
    insert(&head,17,2);
    insert(&head,7,2);
    print(head);

    update_node(&head,43,3);
    update_node(&head,3,5);
    print(head);

    reverse_list(&head);
    cout<<"List after reversing"<<endl;
    print(head);

    delete_node(&head,1);
    //cout<<node_count<<endl;
    delete_node(&head,2);
    print(head);

    return 0;
}
