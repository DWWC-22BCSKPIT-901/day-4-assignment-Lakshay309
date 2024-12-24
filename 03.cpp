#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); 
    stack<int> indexStack; 

    for (int i = 0; i < 2 * n; ++i) {
        while (!indexStack.empty() && nums[indexStack.top()] < nums[i % n]) {
            result[indexStack.top()] = nums[i % n];
            indexStack.pop();
        }
        if (i < n) {
            indexStack.push(i);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}