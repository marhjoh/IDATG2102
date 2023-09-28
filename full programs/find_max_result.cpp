#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10; // The length of the array.
int arr[N] = {23, 17, 4, 3, 32, 9, 8, 12, 21, 37}; // Global array initialized with values.
vector<int> arr2 = {23, 17, 4, 3, 32, 9, 8, 12, 21, 37};

float max_result = -1.0F; // Maximum result found so far.

// Function to display the contents of an array.
void display(int a[]) {
    cout << "\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << "\n";
}

// Function to swap two array elements.
void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

// Function to rotate elements of an array to the left.
void rotate_left(int a[], int i) {
    int x, k;
    x = a[i];
    for (k = i + 1; k < N; k++)
        a[k - 1] = a[k];
    a[N - 1] = x;
}

// Function to calculate the result based on the algorithm.
void calculate() {
    float result = arr[0];
    for (int i = 1; i < N; i++)
        result = (result + arr[i]) * 2.0F;
    if (result > max_result)
        max_result = result;
}

// Function to perform permutations and calculate results.
void permute(int i) {
    if (i == N - 1)
        calculate(); // Calculate result for the current permutation.
    else {
        permute(i + 1); // Continue with the next index.
        for (int t = i + 1; t < N; t++) {
            swap(arr[i], arr[t]); // Swap elements.
            permute(i + 1); // Calculate result for the new permutation.
        }
        rotate_left(arr, i); // Rotate elements to restore the original array.
    }
}

// Function to find the maximum result using a priority queue (min-heap).
int findMaxResult(vector<int>& arr) {
    // Create a max-heap (priority queue) to store elements in descending order.
    priority_queue<int> maxHeap;

    // Populate the max-heap with initial elements from the array.
    for (int num : arr) {
        maxHeap.push(num);
    }

    // Perform the operation until there's only one element left in the heap.
    while (maxHeap.size() > 1) {
        // Extract the two largest elements from the heap.
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();

        // Calculate the new result and insert it back into the heap.
        int result = (x + y) * 2;
        maxHeap.push(result);
    }

    // The remaining element in the heap is the maximum result.
    return maxHeap.top();
}

int main() {
    permute(0); // Start permuting the array.
    cout << "\nMaximum result: " << max_result << "\n\n";

    int max_result1 = findMaxResult(arr2);
    cout << "\nMaximum result: " << max_result1 << "\n\n";

    return 0;
}
