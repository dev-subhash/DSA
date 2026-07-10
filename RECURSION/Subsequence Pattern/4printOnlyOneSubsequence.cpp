#include <iostream>
#include <vector>
using namespace std;

// Function to print only one subsequence whose sum is equal to K
bool printSubsequence(int index,
                      vector<int> &arr,
                      vector<int> &current,
                      int &sum,
                      int K)
{
    // Base Case
    if (index == arr.size())
    {
        // If the current sum is equal to K,
        // print the subsequence
        if (sum == K)
        {
            cout << "{ ";

            for (int x : current)
                cout << x << " ";

            cout << "}" << endl;

            // A valid subsequence is found
            return true;
        }

        // No valid subsequence
        return false;
    }

    // ------------------------------------
    // Choice 1: Include the current element
    // ------------------------------------

    // Add the current element to the subsequence
    current.push_back(arr[index]);

    // Update the current sum
    sum += arr[index];

    // Recur for the next index
    if (printSubsequence(index + 1, arr, current, sum, K))
        return true;

    // ------------------------------------
    // Backtracking
    // ------------------------------------

    // Restore the sum
    sum -= arr[index];

    // Remove the current element
    current.pop_back();

    // ------------------------------------
    // Choice 2: Exclude the current element
    // ------------------------------------

    if (printSubsequence(index + 1, arr, current, sum, K))
        return true;

    // No valid subsequence found
    return false;
}

int main()
{
    // Input array
    vector<int> arr = {1, 2, 1};

    // Target sum
    int K = 2;

    // Current sum
    int sum = 0;

    // Stores the current subsequence
    vector<int> current;

    // Function call
    printSubsequence(0, arr, current, sum, K);

    return 0;
}