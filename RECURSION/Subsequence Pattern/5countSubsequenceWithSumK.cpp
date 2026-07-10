// FIRST APPROACH
#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of subsequences
// whose sum is equal to K
int countSubsequence(int index,
                     vector<int> &arr,
                     int &sum,
                     int K)
{
    // Base Case
    // If all elements have been processed
    if (index == arr.size())
    {
        // If current sum equals K,
        // one valid subsequence is found
        if (sum == K)
            return 1;

        // Otherwise, no valid subsequence
        return 0;
    }

    // ------------------------------------
    // Choice 1: Include the current element
    // ------------------------------------

    // Add the current element to the sum
    sum += arr[index];

    // Count subsequences by taking the current element
    int take = countSubsequence(index + 1, arr, sum, K);

    // ------------------------------------
    // Backtracking
    // ------------------------------------

    // Restore the sum before exploring the next choice
    sum -= arr[index];

    // ------------------------------------
    // Choice 2: Exclude the current element
    // ------------------------------------

    // Count subsequences without taking the current element
    int notTake = countSubsequence(index + 1, arr, sum, K);

    // Return the total count
    return take + notTake;
}

int main()
{
    // Input array
    vector<int> arr = {1, 2, 1};

    // Target sum
    int K = 2;

    // Current sum
    int sum = 0;

    // Count the number of valid subsequences
    int ans = countSubsequence(0, arr, sum, K);

    cout << "Number of subsequences = " << ans << endl;

    return 0;
}







