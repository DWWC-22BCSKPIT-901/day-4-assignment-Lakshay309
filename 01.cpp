#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

vector<int> gcdPairs(vector<int>& nums, vector<int>& queries) {
    vector<int> gcdPairs;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            gcdPairs.push_back(gcd(nums[i], nums[j]));
        }
    }

    sort(gcdPairs.begin(), gcdPairs.end());

    vector<int> result;
    for (int query : queries) {
        result.push_back(gcdPairs[query]);
    }

    return result;
}

int main() {
    vector<int> nums1 = {2, 3, 4};
    vector<int> queries1 = {0, 2, 2};
    vector<int> result1 = gcdPairs(nums1, queries1);

    cout << "Result for Test Case 1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> nums2 = {4, 4, 2, 1};
    vector<int> queries2 = {5, 3, 1, 0};
    vector<int> result2 = gcdPairs(nums2, queries2);

    cout << "Result for Test Case 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}