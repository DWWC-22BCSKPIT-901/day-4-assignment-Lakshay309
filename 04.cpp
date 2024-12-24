#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    for (int student : students) {
        studentQueue.push(student);
    }

    int sandwichIndex = 0;
    int attempts = 0;

    while (!studentQueue.empty() && attempts < studentQueue.size()) {
        if (studentQueue.front() == sandwiches[sandwichIndex]) {
            studentQueue.pop();
            sandwichIndex++;
            attempts = 0; 
        } else {
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            attempts++;
        }
    }

    return studentQueue.size();
}

int main() {
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    cout << countStudents(students, sandwiches) << endl;
    return 0;
}