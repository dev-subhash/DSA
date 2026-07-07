#include <iostream>
#include <vector>

using namespace std;


//Power Set (Take/Not Take) Method

class Solution {
public:

    // Recursive function to generate all subsets
    void solve(int index,
               vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans)
    {
        // Base Case:
        // If we have processed every element,
        // the current subset is complete.
        if (index == nums.size())
        {
            ans.push_back(current);
            return;
        }

        // ==========================
        // Choice 1 : Include element
        // ==========================

        // Add the current element into the subset
        current.push_back(nums[index]);

        // Move to the next index
        solve(index + 1, nums, current, ans);

        // Backtrack
        // Remove the last inserted element so that
        // we can explore the "exclude" choice.
        current.pop_back();

        // ==========================
        // Choice 2 : Exclude element
        // ==========================

        // Ignore the current element
        // and move to the next index.
        solve(index + 1, nums, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        // Stores all subsets
        vector<vector<int>> ans;

        // Stores the current subset being formed
        vector<int> current;

        // Start recursion from index 0
        solve(0, nums, current, ans);

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    vector<vector<int>> ans = obj.subsets(nums);

    cout << "\nPower Set (All Subsets)\n\n";

    for (auto subset : ans)
    {
        cout << "{ ";

        for (int element : subset)
        {
            cout << element << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}