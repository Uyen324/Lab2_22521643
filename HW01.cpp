#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;
};

void push(Stack& s, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = s.head;
    s.head = newNode;
}

int pop(Stack& s) {
    if (s.head == nullptr) {
        cout << "Stack is empty!" << endl;
        return -1; // Dùng -1 để chỉ stack rỗng
    }
    Node* tmp = s.head;
    int poppedValue = tmp->data;
    s.head = s.head->next;
    delete tmp;
    return poppedValue;
}

bool isEmpty(Stack& s) {
    return s.head == nullptr;
}

void printStack(Stack& s) {
    Node* current = s.head;
    cout << "STACK = < ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << ">\n";
}

void printTowers(Stack& A, Stack& B, Stack& C) {
    cout << "A Tower\n";
    printStack(A);
    cout << "========================\n";
    cout << "B Tower\n";
    printStack(B);
    cout << "========================\n";
    cout << "C Tower\n";
    printStack(C);
    cout << "========================\n";
}

void moveDisk(Stack& src, Stack& dest, char s, char d) {
    if (isEmpty(src)) return;
    int disk = pop(src);
    push(dest, disk);
    cout << "Move disk " << disk << " from " << s << " to " << d << endl;
}

void hanoi(int n, Stack& A, Stack& B, Stack& C, char a, char b, char c) {
    if (n == 1) {
        moveDisk(A, C, a, c);
        printTowers(A, B, C);
        return;
    }
    hanoi(n - 1, A, C, B, a, c, b);
    moveDisk(A, C, a, c);
    printTowers(A, B, C);
    hanoi(n - 1, B, A, C, b, a, c);
}

int main() {
    Stack A{nullptr}, B{nullptr}, C{nullptr};
    int n = 3;  // Number of disks

    for (int i = n; i >= 1; --i) {
        push(A, i);
    }

    cout << "======== Demo Stack ========\n0. Creating Tower.\n";
    printTowers(A, B, C);

    hanoi(n, A, B, C, 'A', 'B', 'C');

    cout << "\nFinished status\n";
    printTowers(A, B, C);

    return 0;
}
