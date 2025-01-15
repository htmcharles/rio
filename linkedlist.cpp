#include <iostream>
using namespace std;

class Node {
public:
    int data; 
    Node* next; 

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;  

public:
    LinkedList() : head(nullptr) {}

    void addNode(int value) {
        Node* newNode = new Node(value);  
        if (head == nullptr) {         
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {  
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void traverseList() const {
        Node* temp = head;
        while (temp != nullptr) { 
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    LinkedList list;  
    list.addNode(10);
    list.addNode(30);    
    list.addNode(20);

    cout << "Linked List: ";
    list.traverseList();

    return 0;
}

