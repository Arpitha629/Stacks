#include <iostream>
using namespace std;

int main() {
    int nums[100000];
    int result[100000];
    int stack[100000];
    int topIndex = -1;

    int n = 0, x;
    while (cin >> x) {
        nums[n++] = x;
        if (cin.peek() == '\n' || cin.eof()) break;
    }

    for (int i = 0; i < n; i++) result[i] = -1;

    for (int i = 0; i < n; i++) {
        while (topIndex != -1 && nums[i] > nums[stack[topIndex]]) {
            result[stack[topIndex]] = nums[i];
            topIndex--;
        }
        stack[++topIndex] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i != n - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}

