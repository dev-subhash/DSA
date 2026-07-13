/*
Combination Sum II
Problem Statement 

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations where the chosen numbers sum to the target.

Each number in candidates may be used at most once in a combination.

The solution set must not contain duplicate combinations.
*/

//C++ Code (Standard Decreasing Target Solution)


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Recursive function
    void solve(int index,
               vector<int> &nums,
               int target,
               vector<int> &current,
               vector<vector<int>> &answer)
    {
        // If target becomes 0,
        // we have found a valid combination.
        if (target == 0)
        {
            answer.push_back(current);
            return;
        }

        // Try every element starting from 'index'
        for (int i = index; i < nums.size(); i++)
        {
            // Skip duplicate elements at the same recursion level.
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Since the array is sorted,
            // if current element is larger than target,
            // all remaining elements will also be larger.
            if (nums[i] > target)
                break;

            // Choose the current element.
            current.push_back(nums[i]);

            // Move to the next index because
            // each element can be used only once.
            solve(i + 1,
                  nums,
                  target - nums[i],
                  current,
                  answer);

            // Backtrack.
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> answer;
        vector<int> current;

        // Sorting is necessary for duplicate skipping.
        sort(nums.begin(), nums.end());

        solve(0, nums, target, current, answer);

        return answer;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution obj;

    vector<vector<int>> result =
        obj.combinationSum2(candidates, target);

    cout << "Unique Combinations are:\n";

    for (auto combination : result)
    {
        cout << "{ ";

        for (int num : combination)
            cout << num << " ";

        cout << "}\n";
    }

    return 0;
}




//Combination Sum II (Current Sum Solution)





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Recursive Backtracking Function
    void solve(int index,
               vector<int> &nums,
               int target,
               int sum,
               vector<int> &current,
               vector<vector<int>> &answer)
    {
        // If current sum becomes equal to target,
        // store the current combination.
        if (sum == target)
        {
            answer.push_back(current);
            return;
        }

        // Try every element from the current index.
        for (int i = index; i < nums.size(); i++)
        {
            // Skip duplicate elements at the same recursion level.
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Since the array is sorted,
            // if adding this element exceeds the target,
            // all remaining elements will also exceed it.
            if (sum + nums[i] > target)
                break;

            // Choose the current element.
            current.push_back(nums[i]);

            // Recur for the next index.
            solve(i + 1,
                  nums,
                  target,
                  sum + nums[i],
                  current,
                  answer);

            // Backtrack.
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> answer;
        vector<int> current;

        // Sort the array for duplicate skipping.
        sort(nums.begin(), nums.end());

        solve(0,
              nums,
              target,
              0,          // Initial sum
              current,
              answer);

        return answer;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum2(candidates, target);

    cout << "Unique Combinations are:\n";

    for (auto combination : result)
    {
        cout << "{ ";

        for (int num : combination)
            cout << num << " ";

        cout << "}\n";
    }

    return 0;
}