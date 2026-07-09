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