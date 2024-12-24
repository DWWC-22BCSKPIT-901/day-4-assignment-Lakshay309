#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class DinnerPlates {
private:
    vector<deque<int>> stacks;
    int capacity;
    deque<int> leftmostEmptyStack;
    int rightmostNonEmptyStack; 
    
public:
    DinnerPlates(int capacity) : capacity(capacity), rightmostNonEmptyStack(-1) {}

    void push(int val) {
        if (!leftmostEmptyStack.empty()) {
            int index = leftmostEmptyStack.front();
            leftmostEmptyStack.pop_front();
            stacks[index].push_back(val);
            if (stacks[index].size() == capacity) {
                rightmostNonEmptyStack = max(rightmostNonEmptyStack, index);
            }
        } else {
            stacks.push_back({val});
            leftmostEmptyStack.push_back(stacks.size() - 1);
            rightmostNonEmptyStack = max(rightmostNonEmptyStack, static_cast<int>(stacks.size() - 1));
        }
    }

    int pop() {
        if (rightmostNonEmptyStack == -1) return -1; 

        int val = stacks[rightmostNonEmptyStack].back();
        stacks[rightmostNonEmptyStack].pop_back();

        if (stacks[rightmostNonEmptyStack].empty()) {
            rightmostNonEmptyStack--;
        }

        if (stacks[rightmostNonEmptyStack].size() < capacity) {
            leftmostEmptyStack.push_back(rightmostNonEmptyStack);
        }

        return val;
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty()) {
            return -1; 
        }

        int val = stacks[index].back();
        stacks[index].pop_back();

        if (stacks[index].empty()) {
            leftmostEmptyStack.push_back(index);
        }

        return val;
    }
};

int main() {
    DinnerPlates dp(2); 

    dp.push(1);  
    dp.push(2);  
    dp.push(3); 
    dp.push(4);  
    dp.push(5);  
    cout << dp.popAtStack(0) << endl; 
    dp.push(20); 
    dp.push(21); 
    cout << dp.popAtStack(0) << endl; 
    cout << dp.popAtStack(2) << endl; 
    cout << dp.pop() << endl; 
    cout << dp.pop() << endl; 
    cout << dp.pop() << endl; 
    cout << dp.pop() << endl; 

    return 0;
}