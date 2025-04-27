#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    map<string, vector<int>> students;

    // Adding student records
    students["Neha"] = {93, 90, 85};
    students["Arya"] = {75, 65, 70};
    students["Dake"] = {90, 85, 90};
	students["Zore"] = {93, 85, 88};
	students["Taslima"] = {89, 85, 90};
    string topper;
    double maxAvg = 0;

    for (auto& [name, marks] : students) {
        int sum = accumulate(marks.begin(), marks.end(), 0);
        double avg = sum / 3.0;
        cout << "Student: " << name << ", Marks:";
        for (int m : marks) cout << " " << m;
        cout << ", Average: " << avg << endl;

        if (avg > maxAvg) {
            maxAvg = avg;
            topper = name;
        }
    }

    cout <<endl<< "Topper: " << topper << " with average " << maxAvg << endl;
    return 0;
}

