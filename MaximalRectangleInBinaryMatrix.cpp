#include <iostream>
using namespace std;

int maxHistogram(int* heights, int n) {
    int stack[1000], top = -1, maxArea = 0, i = 0;
    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int idx = stack[top--];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = heights[idx] * width;
            if (area > maxArea) maxArea = area;
        }
    }
    while (top != -1) {
        int idx = stack[top--];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = heights[idx] * width;
        if (area > maxArea) maxArea = area;
    }
    return maxArea;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    int matrix[100][100], heights[100] = {0};
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    int maxArea = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            heights[j] = matrix[i][j] ? heights[j] + 1 : 0;
        int currArea = maxHistogram(heights, cols);
        if (currArea > maxArea) maxArea = currArea;
    }
    cout << maxArea << endl;
    return 0;
}
