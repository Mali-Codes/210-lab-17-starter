#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void addToFront(Node*& head, float value);
void deleteNode(Node*& head, int entry);
void insertNode(Node*& head, int entry, float value);
void addToTail(Node*& head, float value);
void output(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addToFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head , entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // // deleting the linked list
    // current = head;
    // while (current) {
    //     head = current->next;
    //     delete current;
    //     current = head;
    // }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addToFront(Node*& head, float value) {
    Node *newVal = new Node;
    newVal->value = value;
    
    if (!head) { 
        head = newVal;
        newVal->next = nullptr;
    }
    else { 
        newVal->next = head;
        head = newVal;
    }
}

// void addToTail(Node*& head, float value) {
//      Node *newNode = new Node;
//     newNode->value = value;
//     newNode->next = nullptr;

//     if (!head) {
//         head = newNode;
//         return;
//     }

//     Node *current = head;
// }


// delete a node at a specific position
void deleteNode(Node*& head, int entry) {
    if (!head || entry <= 0) return;
    
    // special case: deleting the first node
    if (entry == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // traverse that many times and delete that node
    Node* current = head;
    Node* prev = head;
    
    for (int i = 0; i < (entry - 1); i++) {
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }
    
    if (current) {                          // forgot the delete part
        prev->next = current->next;         // was getting rid of the node but not deleting it
        delete current;
        current = nullptr;
    }
}

void insertNode(Node*& head, int entry, float value) {
    if (!head || entry <= 0) return;

    Node* current = head;           // just following the code pattern
    Node* prev = head;

    for (int i = 0; i < entry; i++) {
        if (i == 0)
            current = current->next;    // using same pattern
        else {
            current = current->next;
            prev = prev->next;
        }
    }

    Node* newnode = new Node;
    newnode->value = value;
    newnode->next = current;
    prev->next = newnode;
}