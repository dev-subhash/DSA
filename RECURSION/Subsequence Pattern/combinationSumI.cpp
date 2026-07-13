/*
Combination Sum I (Recursion + Backtracking)
Problem Statement

Given an array of distinct positive integers nums and a target integer target, return all unique combinations of elements whose sum is equal to the target.

Each element can be chosen multiple times.
Two combinations are considered the same if they contain the same elements in a different order.
Return all possible unique combinations.
*/ 
 
 
 
 
 /*
 TARGET IS PASSED IN THE FUNCTION 
 AND WHEN IT BECOMES ADD THAT SUBSEQUENCE SOLUTION 
 */

//Method 1: Remaining Target Method (Target Decreases)


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Recursive function
    void solve(int index,
               vector<int> &nums,
               int target,                     // Remaining target
               vector<int> &current,
               vector<vector<int>> &ans)
    {
        // ---------------- Base Case ----------------
        // If target becomes 0, store the current combination.
        // If target becomes negative OR all elements are processed,
        // simply stop recursion.
        if (target <= 0 || index == nums.size())
        {
            if (target == 0)
                ans.push_back(current);

            return;
        }

        // ---------------- TAKE ----------------

        // Include current element
        current.push_back(nums[index]);

        // Stay at same index because
        // the same element can be used multiple times.
        solve(index,
              nums,
              target - nums[index],
              current,
              ans);

        // Backtrack
        current.pop_back();

        // ---------------- NOT TAKE ----------------

        // Skip current element
        solve(index + 1,
              nums,
              target,
              current,
              ans);
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, target, current, ans);

        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    Solution obj;

    vector<vector<int>> ans = obj.combinationSum(nums, target);

    cout << "Valid Combinations:\n";

    for (auto &combination : ans)
    {
        cout << "{ ";

        for (int x : combination)
            cout << x << " ";

        cout << "}\n";
    }

    return 0;
}


//Method 2: Current Sum Method (Target Never Changes)


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Recursive function
    void solve(int index,
               vector<int> &nums,
               int sum,                        // Current sum
               int target,                     // Original target
               vector<int> &current,
               vector<vector<int>> &ans)
    {
        // ---------------- Base Case ----------------
        // If current sum reaches target,
        // store the answer.
        // If current sum exceeds target OR
        // all elements are processed,
        // stop recursion.
        if (sum >= target || index == nums.size())
        {
            if (sum == target)
                ans.push_back(current);

            return;
        }

        // ---------------- TAKE ----------------

        // Include current element
        current.push_back(nums[index]);

        // Stay at same index because
        // current element can be chosen again.
        solve(index,
              nums,
              sum + nums[index],
              target,
              current,
              ans);

        // Backtrack
        current.pop_back();

        // ---------------- NOT TAKE ----------------

        // Move to next index
        solve(index + 1,
              nums,
              sum,
              target,
              current,
              ans);
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, 0, target, current, ans);

        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    Solution obj;

    vector<vector<int>> ans = obj.combinationSum(nums, target);

    cout << "Valid Combinations:\n";

    for (auto &combination : ans)
    {
        cout << "{ ";

        for (int x : combination)
            cout << x << " ";

        cout << "}\n";
    }

    return 0;
}




/*sum outside the function (as a global/class member variable),
 you must backtrack the sum, just like you backtrack the current vector.
 Otherwise, the value of sum will be incorrect when recursion returns.*/




class Solution
{
public:
    int sum = 0;   // Current sum (kept outside the recursive function)

    // Recursive function to generate all valid combinations
    void solve(int index,
               vector<int> &nums,
               int target,
               vector<int> &current,
               vector<vector<int>> &ans)
    {
        // ---------------- Base Case ----------------

        // If the current sum becomes equal to the target,
        // we have found one valid combination.
        if (sum == target)
        {
            ans.push_back(current);
            return;
        }

        // Stop recursion if:
        // 1. Current sum exceeds the target.
        // 2. All elements have been processed.
        if (sum > target || index == nums.size())
            return;

        // ---------------- TAKE ----------------

        // Choose the current element.
        current.push_back(nums[index]);

        // Update the current sum.
        sum += nums[index];

        // Stay at the same index because the
        // current element can be used multiple times.
        solve(index,
              nums,
              target,
              current,
              ans);

        // ---------------- BACKTRACK ----------------

        // Remove the current element's contribution
        // before exploring another choice.
        sum -= nums[index];

        // Remove the element from the current combination.
        current.pop_back();

        // ---------------- NOT TAKE ----------------

        // Skip the current element and move
        // to the next index.
        solve(index + 1,
              nums,
              target,
              current,
              ans);
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        // Reset sum before starting recursion.
        sum = 0;

        solve(0, nums, target, current, ans);

        return ans;
    }
};