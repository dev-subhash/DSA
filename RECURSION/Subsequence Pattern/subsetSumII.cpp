#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    /*
    ------------------------------------------------------------
    Function : subsetsWithDup()

    Purpose:
    Generate all UNIQUE subsets of the given array.

    Why "Unique"?
    Because the input array may contain duplicate elements.

    Example:

    Input:
    [1,2,2]

    Output:
    []
    [1]
    [2]
    [1,2]
    [2,2]
    [1,2,2]

    Duplicate subsets are NOT allowed.
    ------------------------------------------------------------
    */

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Stores all unique subsets
        vector<vector<int>> answer;

        // Stores the subset currently being built
        vector<int> current;

        /*
        ------------------------------------------------------------
        IMPORTANT STEP

        Sort the array.

        Why?

        Duplicate elements become adjacent.

        Before sorting:
        2 1 2

        After sorting:
        1 2 2

        This makes it easy to detect duplicates.
        ------------------------------------------------------------
        */

        sort(nums.begin(), nums.end());

        /*
        Start recursion from index 0.
        */

        backtrack(0, nums, current, answer);

        return answer;
    }

private:

    /*
    ------------------------------------------------------------
    Parameters

    start
        Current starting index from where we can choose elements.

    nums
        Original sorted array.

    current
        Current subset.

    answer
        Stores all subsets.
    ------------------------------------------------------------
    */

    void backtrack(int start,
                   vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& answer)
    {

        /*
        ------------------------------------------------------------
        Every recursive call represents ONE valid subset.

        Store it immediately.

        Example:

        current = {}

        store {}

        current = {1}

        store {1}

        current = {1,2}

        store {1,2}

        Every node in recursion tree is a valid answer.
        ------------------------------------------------------------
        */

        answer.push_back(current);

        /*
        Explore every possible element starting from "start".
        */

        for(int i = start; i < nums.size(); i++)
        {

            /*
            --------------------------------------------------------
            DUPLICATE CHECK

            Skip duplicate elements ONLY if they appear
            at the SAME recursion level.

            Condition:

            i > start

            means this is NOT the first choice
            of this recursion level.

            nums[i] == nums[i-1]

            means duplicate element.

            Example:

            nums = [1,2,2]

                    Level

                     start=1

                     2
                    /
                   2   ← duplicate

            We skip the second 2 because
            choosing it first creates the same subsets.

            --------------------------------------------------------
            */

            if(i > start && nums[i] == nums[i-1])
                continue;

            /*
            --------------------------------------------------------
            CHOOSE

            Include nums[i] into current subset.
            --------------------------------------------------------
            */

            current.push_back(nums[i]);

            /*
            --------------------------------------------------------
            Move forward.

            Since subsets cannot reuse the same element,

            next recursion starts from i+1.
            --------------------------------------------------------
            */

            backtrack(i + 1, nums, current, answer);

            /*
            --------------------------------------------------------
            BACKTRACK

            Remove the recently added element.

            This restores the previous subset so that
            another choice can be explored.

            Before pop:

            current = {1,2}

            After pop:

            current = {1}
            --------------------------------------------------------
            */

            current.pop_back();
        }
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1,2,2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    cout << "All Unique Subsets\n\n";

    for(auto subset : ans)
    {
        cout << "{ ";

        for(int x : subset)
            cout << x << " ";

        cout << "}\n";
    }

    return 0;
}