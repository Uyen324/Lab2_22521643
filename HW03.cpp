#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    int data;
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

void push(Stack& s, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = s.top;
    s.top = newNode;
}

int pop(Stack& s) {
    if (isEmpty(s)) {
        throw out_of_range("Stack is empty");
    }
    Node* temp = s.top;
    int data = temp->data;
    s.top = s.top->next;
    delete temp;
    return data;
}

int peek(Stack& s) {
    if (isEmpty(s)) {
        throw out_of_range("Stack is empty");
    }
    return s.top->data;
}

vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> answer(n, 0);
    Stack stack;
    createStack(stack);

    for (int i = n - 1; i >= 0; --i) {
        int count = 0;
        while (!isEmpty(stack) && peek(stack) < heights[i]) {
            pop(stack);
            count++;
        }
        if (!isEmpty(stack)) {
            count++;
        }
        answer[i] = count;
        push(stack, heights[i]);
    }

    return answer;
}

int main() {
    string input;
    cout << "Enter heights (space-separated): ";
    getline(cin, input);
    stringstream ss(input);
    vector<int> heights;
    int height;

    while (ss >> height) {
        heights.push_back(height);
    }

    vector<int> result = canSeePersonsCount(heights);

    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
