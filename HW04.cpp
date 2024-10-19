#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int index; 
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

void push(Stack& s, int index) {
    Node* newNode = new Node();
    newNode->index = index;
    newNode->next = s.top;
    s.top = newNode;
}

void pop(Stack& s) {
    if (!isEmpty(s)) {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

int top(Stack& s) {
    if (!isEmpty(s)) {
        return s.top->index;
    }
    return -1;  
}

void clearStack(Stack& s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int minimumCoins(int prices[], int n) {
    Stack stack;
    createStack(stack);

    for (int i = 0; i < n; ++i) {
        push(stack, i);
    }

    for (int i = (n - 1) / 2; i > 0; --i) {
        int minPriceIndex = -1;
        int minPrice = INT_MAX;

        for (int j = i; j < 2 * i + 1 && j < n; ++j) {
            if (prices[j] < minPrice) {
                minPrice = prices[j];
                minPriceIndex = j;
            }
        }

        prices[i - 1] += prices[minPriceIndex];
    }

    clearStack(stack); 
    return prices[0];
}

int main() {
    int prices[] = {3, 1, 2};
    int prices2[] = {1, 10, 1, 1};
    int prices3[] = {26, 18, 6, 12, 49, 7, 45, 45};

    int n = sizeof(prices) / sizeof(prices[0]);
    int k = sizeof(prices2) / sizeof(prices2[0]);
    int l = sizeof(prices3) / sizeof(prices3[0]);

    int result = minimumCoins(prices, n);
    int result2 = minimumCoins(prices2, k);
    int result3 = minimumCoins(prices3, l);

    cout << "Minimum coins needed: " << result << endl;
    cout << "Minimum coins needed: " << result2 << endl;
    cout << "Minimum coins needed: " << result3 << endl;

    return 0;
}
