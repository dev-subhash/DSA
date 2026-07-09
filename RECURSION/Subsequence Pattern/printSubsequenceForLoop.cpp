#include <iostream>
#include <vector>
using namespace std;

// ---------------------------------------------------------
// Recursive function to generate and print all subsequences
//
// Parameters:
// index   -> Starting position from where we can choose elements.
// nums    -> Original input array.
// current -> Stores the current subsequence being formed.
// ---------------------------------------------------------
void solve(int index, vector<int>& nums, vector<int>& current)
{
    // ---------------------------------------------------------
    // Print the current subsequence.
    //
    // Every recursive call represents one valid subsequence.
    // Even the empty subsequence {} is printed.
    // ---------------------------------------------------------
    cout << "{ ";

    for (int x : current)
    {
        cout << x << " ";
    }

    cout << "}" << endl;

    // ---------------------------------------------------------
    // Loop through every remaining element.
    //
    // We start from 'index' because elements before 'index'
    // have already been considered.
    //
    // Example:
    // nums = [1,2,3]
    //
    // If index = 1
    // We can only choose:
    // 2
    // 3
    //
    // We cannot choose 1 again because subsequences
    // must preserve the original order.
    // ---------------------------------------------------------
    for (int i = index; i < nums.size(); i++)
    {
        // -----------------------------------------------------
        // Choose the current element.
        //
        // Example:
        // current = {1}
        //
        // Choosing nums[i] = 2
        //
        // current becomes
        // {1,2}
        // -----------------------------------------------------
        current.push_back(nums[i]);

        // -----------------------------------------------------
        // Explore all subsequences that begin with
        // the current choice.
        //
        // Notice that we pass (i + 1).
        //
        // Why?
        //
        // Because after choosing nums[i],
        // the next element must come AFTER i.
        //
        // Example:
        //
        // nums = [1,2,3]
        //
        // If we choose 2
        //
        // Next choices can only be
        // 3
        //
        // Therefore recursion starts from i+1.
        // -----------------------------------------------------
        solve(i + 1, nums, current);

        // -----------------------------------------------------
        // BACKTRACK
        //
        // Remove the last inserted element.
        //
        // This restores the previous state so that
        // we can try another choice.
        //
        // Example:
        //
        // current = {1,2}
        //
        // pop_back()
        //
        // current = {1}
        //
        // Now the loop can try
        // {1,3}
        // -----------------------------------------------------
        current.pop_back();
    }
}

int main()
{
    // ---------------------------------------------------------
    // Input array
    // ---------------------------------------------------------
    vector<int> nums = {1, 2, 3};

    // ---------------------------------------------------------
    // Initially no element has been chosen.
    //
    // current = {}
    // ---------------------------------------------------------
    vector<int> current;

    cout << "All Subsequences\n\n";

    // ---------------------------------------------------------
    // Start recursion from index 0.
    //
    // Initially we can choose
    //
    // 1
    // 2
    // 3
    // ---------------------------------------------------------
    solve(0, nums, current);

    return 0;
}