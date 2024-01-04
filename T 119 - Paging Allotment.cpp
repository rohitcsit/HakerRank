/*
N number of books are given.

The ith book has Pi number of pages.

You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.

Each student has to be allocated at least one book.

Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: print -1 if a valid assignment is not possible

Input Format

First line contains integers N and M, number of books and number of students.

Second line contains N integers, the number of pages of the books.

Constraints

1 <= N,M <= 105

Output Format

Your program should print an integer corresponding to the minimum maximum number of pages for a student.

Sample Input 0

4 2
12 34 67 90
Sample Output 0

113

*/


// code

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to check if it is possible to allocate pages with given maximum
bool isPossible(vector<int>& arr, int n, int m, int curr_min) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_min) {
            return false;  // It is not possible to allocate pages with the current minimum
        }

        if (sum + arr[i] > curr_min) {
            students++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }

    return students <= m;
}

// Function to find the minimum maximum pages allocation
int findPages(vector<int>& arr, int n, int m) {
    if (n < m) {
        return -1;  // Not enough books to allocate to each student
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;

    // Input number of books and students
    cin >> n >> m;

    vector<int> arr(n);

    // Input the number of pages for each book
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and print the minimum maximum pages allocation
    int result = findPages(arr, n, m);
    cout << result << endl;

    return 0;
}
