/*
	Doubly Linked List
	
	- Functions : Insertion, Deletion, Display (from head / tail)
	- Be sure to always check if there's no dangling reference.

*/

#include <iostream>

using namespace std;

struct Node{
    struct Node* prev_link;
    int data;
    struct Node* next_link;
};

void insert_node(int, int); // (position, data)
void delete_node(int); // (position)
void front_display(void); // prints from the front
void back_display(void); // prints from the back

struct Node* head;
struct Node* tail;

int main(void){
    head = (struct Node*)malloc(sizeof(struct Node*));
    if(!head) exit(1);
    tail = (struct Node*)malloc(sizeof(struct Node*));
    if(!tail) exit(1);
    
    head -> prev_link = head -> next_link = NULL;
    tail -> prev_link = tail -> next_link = NULL;

    for(int i = 0; i < 10; i++){
        insert_node(i, i);
    }
    front_display();
    back_display();
    
    for(int i = 3; i < 5; i++){
        delete_node(i);
    }
    
    front_display();
    back_display();
    
    return 0;
}

void insert_node(int pos, int data){
    struct Node* new_node;
    new_node = (struct Node*) malloc(sizeof(struct Node*));
    if(!new_node){ // if fails to give memory space to new_node;
        exit(1);
    }
    new_node -> prev_link = NULL;
    new_node -> data = data;
    new_node -> next_link = NULL;
    
    // if new_node is the very first node to be added;
    if(head -> next_link == NULL){
        head -> next_link = new_node;
        new_node -> prev_link = head;
        new_node -> next_link = tail;
        tail -> prev_link = new_node;
    }
    
    else{
        struct Node* ptr = head;
        // ptr = prev_node;
        for(int i = 0; i < pos; i++){
            ptr = ptr -> next_link;
        }
        
        new_node -> prev_link = ptr;
        new_node -> next_link = ptr -> next_link;
        
        // next_node -> prev_link = new_node;
        (ptr -> next_link)->prev_link = new_node;
        ptr -> next_link = new_node;
    }
}

void delete_node(int pos){
    struct Node* ptr = head;
    // ptr = prev_node
    for(int i = 0; i < pos; i++){
        ptr = ptr -> next_link;
    }
    struct Node* del_node = ptr -> next_link;
    
    ptr -> next_link = del_node -> next_link;
    // next_node -> prev_link = del_node -> prev_link;
    (del_node -> next_link) -> prev_link = del_node -> prev_link;
}

void front_display(void){
    struct Node* ptr = head -> next_link;
    while(ptr != tail){
        cout << ptr -> data << " ";
        ptr = ptr -> next_link;
    }
    cout << endl;
}
void back_display(void){
    struct Node* ptr = tail -> prev_link;;
    while(ptr != head){
        cout << ptr -> data << " ";
        ptr = ptr -> prev_link;
    }
    cout << endl;
}
