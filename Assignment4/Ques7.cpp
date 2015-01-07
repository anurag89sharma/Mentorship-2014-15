#include<iostream>

/*using namespace std;

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

void reverse_list(node **head){
    node *current = (*head), *next;
    node *prev = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}

void display(node *root){
    while(root){
        cout<<root->data<<"\t";
        root = root->next;
    }
    cout<<endl;
}

int compare_list(node* first, node *second){
    while(first && second){
        if(first->data == second->data){
            first = first->next;
            second = second->next;
        }
        else
            return 0;
    }
    if(first == NULL  && second == NULL)
        return 1;
    return 0;
}

// See this link to understand the below code
// http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
int is_palindrome(node *root){
    struct node *slow = root, *fast = root;
    struct node *second_half, *prev = root;
    struct node *midnode = NULL;  // To handle odd size list
    bool res = true;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (fast != NULL){
        midnode = slow;
        slow = slow->next;
    }

    second_half = slow;
    prev->next = NULL;
    reverse_list(&second_half);

    res = compare_list(root, second_half);

    reverse_list(&second_half);
    if(midnode!= NULL){
        prev->next = midnode;
        midnode->next = second_half;
    }
    else
        prev->next = second_half;

    return res;
}

int main(){
    node *head = NULL;
    insert_node(&head,1);
    insert_node(&head,2);
    insert_node(&head,4);
    insert_node(&head,2);
    insert_node(&head,1);
    //insert_node(&head,4);
    cout<<"List to check for palindrome"<<endl;
    display(head);
    int result = is_palindrome(head);
    if(result)
        cout<<"List is a palindrome"<<endl;
    else
        cout<<"List is a not a palindrome"<<endl;
    display(head);
    return 0;
}*/
