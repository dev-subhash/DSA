#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
        Recursive Function

        index -> Current position in the array.
        nums  -> Input array.
        curr  -> Current subset being formed.
        ans   -> Stores all subsets.
    */
    void solve(int index,
               vector<int> &nums,
               vector<int> &curr,
               vector<vector<int>> &ans)
    {
        // Base Case
        // If all elements have been processed,
        // store the current subset.
        if (index == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        // -------------------------
        // Choice 1 : Take the element
        // -------------------------
        curr.push_back(nums[index]);

        solve(index + 1, nums, curr, ans);

        // Backtrack
        curr.pop_back();

        // -----------------------------
        // Choice 2 : Do Not Take element
        // -----------------------------
        solve(index + 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, curr, ans);

        return ans;
    }
};

// Utility function to print all subsets
void printSubsets(vector<vector<int>> &ans)
{
    cout << "All Possible Subsets:\n";

    for (auto subset : ans)
    {
        cout << "{ ";

        for (int x : subset)
            cout << x << " ";

        cout << "}\n";
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution obj;

    vector<vector<int>> ans = obj.subsets(nums);

    printSubsets(ans);

    return 0;
}