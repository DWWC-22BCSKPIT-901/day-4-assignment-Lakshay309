#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> stack1; 
    stack<int> stack2; 

    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        int topElement = stack2.top();
        stack2.pop();
        return topElement;
    }

    int peek() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    void printQueue() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }

        stack<int> temp = stack2;
        stack<int> tempStack1 = stack1;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        while (!tempStack1.empty()) {
            cout << tempStack1.top() << " ";
            tempStack1.pop();
        }

        cout << endl;
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); 
    myQueue.push(2); 
    myQueue.push(3); 
    myQueue.printQueue(); 
    int front = myQueue.peek(); 
    int popped = myQueue.pop(); 
    myQueue.printQueue(); 
    bool isEmpty = myQueue.empty(); 
    return 0;
}