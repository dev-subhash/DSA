#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print all subsequences
// whose sum is equal to the target.
void solve(int index,
           vector<int>& nums,
           vector<int>& current,
           int target)
{
    // If target becomes 0,
    // we have found a valid subsequence.
    if (target == 0)
    {
        cout << "{ ";

        for (int x : current)
            cout << x << " ";

        cout << "}" << endl;

        return;
    }

    // If target becomes negative,
    // no valid subsequence is possible.
    if (target < 0)
        return;

    // If all elements are processed,
    // stop recursion.
    if (index == nums.size())
        return;

    // -------------------------
    // Choice 1 : Take element
    // -------------------------
    current.push_back(nums[index]);

    solve(index + 1,
          nums,
          current,
          target - nums[index]);

    // Backtrack
    current.pop_back();

    // -------------------------
    // Choice 2 : Don't Take
    // -------------------------
    solve(index + 1,
          nums,
          current,
          target);
}

int main()
{
    // Input array
    vector<int> nums = {1, 2, 1};

    // Target Sum
    int target = 2;

    // Stores the current subsequence
    vector<int> current;

    cout << "Subsequences having sum = " << target << endl << endl;

    // Start recursion from index 0
    solve(0, nums, current, target);

    return 0;
}




// 2nd APPROACH


#include <iostream>
#include <vector>
using namespace std;

// Function to print all subsequences whose sum is equal to K
void printSubsequence(int index,
                      vector<int> &arr,
                      vector<int> &current,
                      int &sum,
                      int K)
{
    // Base Case
    if (index == arr.size())
    {
        // Print the subsequence if the sum is equal to K
        if (sum == K)
        {
            cout << "{ ";

            for (int x : current)
                cout << x << " ";

            cout << "}" << endl;
        }

        return;
    }

    // ------------------------------------
    // Choice 1: Include the current element
    // ------------------------------------

    // Add the element to the subsequence
    current.push_back(arr[index]);

    // Update the current sum
    sum += arr[index];

    // Recur for the next index
    printSubsequence(index + 1, arr, current, sum, K);

    // ------------------------------------
    // Backtracking
    // ------------------------------------

    // Restore the sum
    sum -= arr[index];

    // Remove the last element
    current.pop_back();

    // ------------------------------------
    // Choice 2: Exclude the current element
    // ------------------------------------

    printSubsequence(index + 1, arr, current, sum, K);
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