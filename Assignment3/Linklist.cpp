#include <iostream>

using namespace std;

/*struct node{
    int data;
    struct node *next;
};

node *head = NULL;
int node_count = 0;

node* create_node(int data){
    node *temp = new node;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void add_node(int loc,int data){
    node *temp = create_node(data);
    if (head == NULL){
        head = temp;
        node_count ++;
    }
    else if (loc == 0){
        temp->next=head;
        head=temp;
        node_count ++;
    }
    else if (loc > node_count){
        cout<<"Cannot insert "<<data<<" at the desired position\n";
    }
    else{
        int count = 1;
        node *p = head;
        while(count!= loc){
            p = p->next;
            count ++;
        }
        temp->next = p->next;
        p->next = temp;
        node_count++;
    }

}

void delete_node_by_position(int pos){
    if(node_count>0){
        if(pos==1){
            node *temp = head;
            head = head->next;
            delete temp;
            node_count--;
        }
        else if(pos <= node_count){
            int count = 1;
            node *p, *temp;
            p = head;
            while(count!= pos-1){
                p = p->next;
                count ++;
            }
            temp = p->next;
            p->next = temp->next;
            //cout<<temp->data<<"\t"<<p->next->data<<endl;
            delete temp;
            node_count--;
        }
        else{
            cout<<"Cant delete node at the desire position";
        }
    }
    else{
        cout<<"List is empty"<<endl;
    }
}

void delete_node_by_data(int data){
    node *p = head;
    node * temp;
    if (p->data == data){
        temp = p;
        head = p->next;
        delete temp;
        node_count --;
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
        node_count--;
    }
}

void update_node(int loc,int data){
    int count = 1;
    node *p = head;
    if (loc <= node_count){
        while(count != loc){
            p = p->next;
            count++;
        }
        p->data = data;
    }
    else{
        cout<<"Cannot update data, entered position is greater than the length of the list"<<endl;
    }
}

void print_node(){
    node *p = head;
    while(p){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

void reverse_list(){
    node *prev = NULL;
    node *current = head;
    node * next;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    add_node(0,4);
    add_node(1,7);
    add_node(2,9);
    add_node(0,11);
    add_node(4,3);
    print_node();
    cout << "Current count: " <<node_count<<endl;
    update_node(7,21);
    print_node();
    //reverse_list();
    //cout<<"Link list after reversing:"<<endl;
    //print_node();
    cout << "Current count: " <<node_count<<endl;
    //delete_node_by_data(11);
    //delete_node_by_data(42);
    delete_node_by_position(3);
    delete_node_by_position(2);
    delete_node_by_position(3);
    print_node();
    cout << "Current count: " <<node_count<<endl;
    return 0;
}
*/
