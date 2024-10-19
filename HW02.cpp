#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Stack {
    Node* top;
};

void createStack(Stack& s) {
    s.top = nullptr;
}

bool isEmpty(Stack& s) {
    return s.top == nullptr;
}

void push(Stack& s, const string& data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = s.top;
    s.top = newNode;
}

string pop(Stack& s) {
    if (isEmpty(s)) {
        throw out_of_range("Stack is empty");
    }
    Node* temp = s.top;
    string data = s.top->data;
    s.top = s.top->next;
    delete temp;
    return data;
}

struct Browser {
    Stack backStack;
    Stack forwardStack;
    string currentUrl;
};

void createBrowser(Browser& b) {
    createStack(b.backStack);
    createStack(b.forwardStack);
    b.currentUrl = "";
}

void visit(Browser& b, const string& url) {
    if (!b.currentUrl.empty()) {
        push(b.backStack, b.currentUrl);
    }
    b.currentUrl = url;
    while (!isEmpty(b.forwardStack)) {
        pop(b.forwardStack);
    }
    cout << "Visited: " << b.currentUrl << endl;
}

string back(Browser& b) {
    if (isEmpty(b.backStack)) {
        cout << "No previous URL" << endl;
        return b.currentUrl;
    }
    push(b.forwardStack, b.currentUrl);
    b.currentUrl = pop(b.backStack);
    cout << "Back to: " << b.currentUrl << endl;
    return b.currentUrl;
}

string forward(Browser& b) {
    if (isEmpty(b.forwardStack)) {
        cout << "No forward URL" << endl;
        return b.currentUrl;
    }
    push(b.backStack, b.currentUrl);
    b.currentUrl = pop(b.forwardStack);
    cout << "Forward to: " << b.currentUrl << endl;
    return b.currentUrl;
}

int main() {
    Browser browser;
    createBrowser(browser);

    string input, command, url;

    while (true) {
        cout << "Enter command: ";
        getline(cin, input);
        stringstream ss(input);
        ss >> command;

        if (command == "visit") {
            ss >> url;
            visit(browser, url);
        } else if (command == "back") {
            back(browser);
        } else if (command == "forward") {
            forward(browser);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
