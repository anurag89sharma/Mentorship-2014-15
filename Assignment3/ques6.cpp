#include <iostream>

using namespace std;

/*struct node{
    int data;
    struct node *next;
};

node* create_node(int data){
    node *temp = new node;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void insert_node(node **root,int data){
    node *temp = create_node(data);
    temp->next = (*root);
    (*root) = temp;

}

void display_list(node *root){
    node *p = root;
    while(p){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

node* add_two_lists(node* first, node *second){
    int sum,carry = 0;
    int first_data, second_data;
    node* result = NULL;
    node* temp, *prev = NULL;
    while(first!= NULL || second != NULL){
        if(first)
            first_data = first->data;
        else
            first_data = 0;
        if(second)
            second_data = second->data;
        else
            second_data = 0;

        sum = carry + first_data + second_data;
        carry = sum/10;
        sum = sum % 10;

        temp = create_node(sum);
        if(result == NULL)
            result = temp;
        else
            prev->next = temp;
        prev = temp;

        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }
    if(carry>0)
        temp->next = create_node(carry);
    return result;
}

int main(){
    node *first_number = NULL;
    node *second_number = NULL;
    node *result = NULL;
    insert_node(&first_number,1);
    insert_node(&first_number,3);
    insert_node(&first_number,7);
    insert_node(&first_number,9);
    insert_node(&first_number,5);

    display_list(first_number);

    insert_node(&second_number,4);
    insert_node(&second_number,5);
    insert_node(&second_number,7);

    display_list(second_number);

    result = add_two_lists(first_number,second_number);
    display_list(result);

    return 0;
}
*/
