/*
	Singly Linked List
	
	- Functions : Insertion, Deletion, Length, Display
	- Be sure to always initialize 'link' to NULL
	
*/


#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

// head must be initialized as null
struct Node* head = NULL;

void insert_node(int, int); // (position, data)
void delete_node(int, Node*); // (position, head)
int get_length(void);
void display(Node*);

int main(void){
    struct Node* node1 = (struct Node*) malloc(sizeof(struct Node*));
    node1 -> data = 2;
    node1 -> link = NULL;
    head = node1;

    struct Node* node2 = (struct Node*) malloc(sizeof(struct Node*));
    node2 -> data = 4;
    node2 -> link = NULL;
    node1 -> link = node2;

    struct Node* node3 = (struct Node*) malloc(sizeof(struct Node*));
    node3 -> data = 5;
    node3 -> link = NULL;
    node2 -> link = node3;

    struct Node* node4 = (struct Node*) malloc(sizeof(struct Node*));
    node4 -> data = 3;
    node4 -> link = NULL;
    node3 -> link = node4;

    struct Node* node5 = (struct Node*) malloc(sizeof(struct Node*));
    node5 -> data = 7;
    node5 -> link = NULL;
    node4 -> link = node5;

    struct Node* node6 = (struct Node*) malloc(sizeof(struct Node*));
    node6 -> data = 0;
    node6 -> link = NULL;
    node5 -> link = node6;
    display(head);
    cout << "Length of linked list = " << get_length() << endl;
    delete_node(3, head);
//    insert_node(0, 100);
//    insert_node(1, 500);
    
    display(head);
    cout << "Length of linked list = " << get_length() << endl;
    
    return 0;
}

void insert_node(int position, int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if(!new_node) // fail to malloc new_node a memory space
        exit(1);
    new_node -> data = data;
    new_node -> link = NULL;
    
    if(position == 0){
        new_node -> link = head;
        head = new_node;
    }
    else{
        struct Node* pos = head;
        for(int i = 0; i < position - 1; i++)
            pos = pos -> link;
        struct Node* prev_node = pos;
        new_node -> link = prev_node -> link;
        prev_node -> link = new_node;
    }
}

void delete_node(int pos, Node* head){
    for(int i = 0; i < pos - 1; i++) // points to the previous node of deletion
        head = head -> link;
    struct Node* prev_node = head;
    struct Node* next_node = prev_node -> link -> link;
    
    prev_node -> link = next_node;
}

int get_length(void){
    struct Node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr -> link;
    }
    return count;
}

void display(Node* head){
    while(head){
        cout << head -> data << " ";
        head = head -> link;
    }
    cout << endl;
}
