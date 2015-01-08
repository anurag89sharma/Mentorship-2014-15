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

void insert(node **root, int data){
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

void display(node *root){
    while(root){
        cout<<root->data<<"\t";
        root = root->next;
    }
    cout<<endl;
}

int is_present(node *root, int data){
    while(root){
        if(root->data == data)
            return 1;
        root = root->next;
    }
    return 0;
}

node *find_union(node* first, node *second){
    node *result = NULL;
    while(first){
        insert(&result,first->data);
        first = first->next;
    }
    while(second){
        if(!is_present(result,second->data))
            insert(&result,second->data);
        second = second->next;
    }
    return result;
}

node *find_intersection(node *first, node *second){
    node *result = NULL;
    while(first){
        if(is_present(second, first->data))
            insert(&result,first->data);
        first = first->next;
    }
    return result;
}

node *segregate_even_odd(node *root){
    node *result = NULL, *last, *end;
    node *p = root;
    node *prev = root;
    while(p->next)
        p = p->next;
    last = p;
    end = p;
    p = root;
    while(p!=end){
        // check if node is odd
        if(p->data %2 == 1){
            //if the odd node is at the start of the list
            if(p == root){
                //change root to the next element
                root = p->next;
                //update the next pointer of last to this node
                last->next = p;
                //move last to next (so as to point the last to last element of list)
                last = last->next;
                // set next pointer of last to NULL, earlier it was pointing to the second element of the list
                last->next = NULL;
                // point p to next element of the list
                p = root;
                //update previous
                prev= p;
            }
            //if odd node is in between the list
            else{
                //update previous next pointer to current node next pointer, because we are going to remove the current node
                prev->next = p->next;
                //update the next pointer of last to this node
                last->next = p;
                //move last to next (so as to point the last to last element of list)
                last = last->next;
                // set next pointer of last to NULL, earlier it was pointing to its next element of the list
                last->next=NULL;
                //update previous
                p = prev->next;
            }
        }
        else{
            prev = p;
            p = p->next;
        }
    }
    return root;
}

int main(){
    node *first = NULL, *second=NULL;
    node *union_list = NULL;
    node *intersection_list = NULL;
    node *segregate = NULL;

    insert(&first,5);
    insert(&first,58);
    insert(&first,51);
    insert(&first,65);
    insert(&first,6);
    insert(&first,12);
    insert(&first,15);
    insert(&first,9);
    cout<<"First List:"<<endl;
    display(first);

    insert(&second,9);
    insert(&second,6);
    insert(&second,11);
    insert(&second,12);
    insert(&second,15);
    cout<<"Second List:"<<endl;
    display(second);

    cout<<"Union"<<endl;
    union_list = find_union(first, second);
    display(union_list);

    cout<<"Intersection"<<endl;
    intersection_list = find_intersection(first,second);
    display(intersection_list);

    cout<<"Segregate Even and Odd Nodes"<<endl;
    cout<<"Initial List"<<endl;
    display(first);
    cout<<"Final List"<<endl;
    segregate = segregate_even_odd(first);
    display(segregate);

    return 0;

}
