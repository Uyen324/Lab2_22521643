#include <iostream>
using namespace std;

struct Node {
    int data;   
    Node* next; 
};

struct Queue {
    Node* front; 
    Node* rear;   
    int maxSize;  
    int currentSize; 
};
void createQueue(Queue& q, int maxSize) {
    q.front = nullptr;  
    q.rear = nullptr;   
    q.maxSize = maxSize; 
    q.currentSize = 0; 
}

Node* createNode(int data) {
    Node* tmp = new Node();  
    tmp->data = data;        
    tmp->next = nullptr;     
    return tmp;
}

void enqueue(Queue& q, int data) {
    if (q.currentSize >= q.maxSize) {  
        cout << "Queue is full!" << endl;
        return;
    }
    Node* newNode = createNode(data);  
    if (q.rear == nullptr) {          
        q.front = newNode;            
        q.rear = newNode;            
    } else {
        q.rear->next = newNode;       
        q.rear = newNode;         
    }
    q.currentSize++;  
    cout << "Enqueued: " << data << endl;
}

bool isEmpty(Queue& q) {
    return q.front == nullptr;  
}

bool isFull(Queue& q) {
    return q.currentSize >= q.maxSize;  
}
int main() {
    Queue q;
    int maxSize;
    cout << "Enter the maximum size of the queue: ";
    cin >> maxSize;
    createQueue(q, maxSize); 
    

    int choice;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Check if queue is empty\n";
        cout << "3. Check if queue is full\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(q, data);
                break;
            }
            case 2: {
                if (isEmpty(q)) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            }
            case 3: {
                if (isFull(q)) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
            }
            case 4: {
                running = false;
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}

