#include <iostream>
using namespace std;

struct node {
    char data;  
    node* next;
};

struct stack {
    node* head;
    node* tail;
    int currentSize;
    int maxSize;
};

void createStack(stack& s, int maxSize) {
    s.head = nullptr;
    s.tail = nullptr;
    s.currentSize = 0;
    s.maxSize = maxSize;
}

node* createNode(char x) {
    node* tmp = new node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

void push(stack& s, char x) {
    if (s.currentSize >= s.maxSize) {
        cout << "Stack is full!" << endl;
        return;
    }
    node* newNode = createNode(x);
    if (s.head == nullptr) {
        s.head = newNode;
        s.tail = newNode;
    } else {
        newNode->next = s.head;
        s.head = newNode;
    }
    s.currentSize++;
}

char pop(stack& s) {
    if (s.head == nullptr) {
        cout << "Stack is empty!" << endl;
        return '\0';
    }
    node* tmp = s.head;
    char poppedValue = tmp->data;
    s.head = s.head->next;
    delete tmp;
    s.currentSize--;
    return poppedValue;
}

bool isEmpty(stack& s) {
    return s.head == nullptr;
}

bool isValidBrackets(string str) {
    stack st;
    createStack(st, str.length()); 
    for (char c : str) {
        if (c == '(' || c == '"' || c == '[') {
            push(st, c); 
        } else if (c == ')' || c == '"' || c == ']') {
            if (isEmpty(st)) return false;  
            char top = pop(st);  
            if ((c == ')' && top != '(') || (c == '"' && top != '"') || (c == ']' && top != '[')) {
                return false;  
            }
        }
    }
    return isEmpty(st);  
}
string reverseWord(string word) {
    stack st;
    createStack(st, word.length());

    for (char c : word) {
        push(st, c); 
    }

    string reversedWord;
    while (!isEmpty(st)) {
        reversedWord += pop(st); 
    }

    return reversedWord;
}

string reverseEachWord(string str) {
    string word, result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            word += str[i];
        } else {
            result += reverseWord(word) + " ";
            word = "";
        }
    }
    if (!word.empty()) {
        result += reverseWord(word);
    }
    return result;
}

void display(stack& s) {
    if (s.head == nullptr) {
        cout << "Stack is empty!" << endl;
        return;
    }
    node* tmp = s.head;
    while (tmp != nullptr) {
        cout << tmp->data << "  ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    stack s;
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;
    createStack(s, maxSize);

    int choice;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Push element into stack\n";
        cout << "2. Check if stack is empty\n";
        cout << "3. Check if stack is full\n";
        cout << "4. Check if string of brackets is valid\n";
        cout << "5. Reverse each word in a string\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                char value;
                cout << "Enter a single character to push: ";
                cin >> value;
                push(s, value);
                display(s);
                break;
            }
            case 2: {
                if (isEmpty(s)) {
                    cout << "True" << endl;
                } else {
                    cout << "False" << endl;
                }
                break;
            }
            case 3: {
                if (s.currentSize >= s.maxSize) {
                    cout << "True" << endl;
                } else {
                    cout << "False" << endl;
                }
                break;
            }
            case 4: {
                string input;
                cout << "Enter a string of brackets: ";
                getline(cin, input);
                if (isValidBrackets(input)) {
                    cout << "The string is valid." << endl;
                } else {
                    cout << "The string is not valid." << endl;
                }
                break;
            }
            case 5: {
                string input;
                cout << "Enter a string: ";
                getline(cin, input); 
                string reversedString = reverseEachWord(input);
                cout << "Reversed words string: " << reversedString << endl;
                break;
            }
            case 6: {
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
