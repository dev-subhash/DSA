#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
        Recursive Backtracking Function

        Parameters:
        start -> The next number to consider (1 to 9).
        k     -> Required number of elements in each combination.
        n     -> Remaining target sum.
        curr  -> Current combination being formed.
        ans   -> Stores all valid combinations.
    */
    void solve(int start,
               int k,
               int n,
               vector<int> &curr,
               vector<vector<int>> &ans)
    {
        // Base Case:
        // If the remaining sum becomes 0 and
        // we have selected exactly k numbers,
        // store the current combination.
        if (n == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        // Invalid Case:
        // 1. Remaining sum becomes negative.
        // 2. We have already selected more than k numbers.
        if (n < 0 || curr.size() > k)
            return;

        // Try every number from 'start' to 9.
        for (int i = start; i <= 9; i++)
        {
            // Choose the current number.
            curr.push_back(i);

            // Move to the next number.
            // Each number can be used only once.
            solve(i + 1,
                  k,
                  n - i,
                  curr,
                  ans);

            // Backtrack by removing the last chosen number.
            curr.pop_back();
        }
    }

    // Function to find all combinations of k numbers
    // from 1 to 9 whose sum is equal to n.
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        // Start searching from number 1.
        solve(1,
              k,
              n,
              curr,
              ans);

        return ans;
    }
};

// -------------------------
// Main Function
// -------------------------
int main()
{
    int k = 3;
    int n = 9;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum3(k, n);

    cout << "Valid Combinations are:\n";

    for (auto combination : result)
    {
        cout << "{ ";

        for (int num : combination)
        {
            cout << num << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}

/*
----------------------------------------
Input:
k = 3
n = 9

Output:
{ 1 2 6 }
{ 1 3 5 }
{ 2 3 4 }

Explanation:
Choose exactly 3 distinct numbers from 1 to 9
such that their sum is 9.

Time Complexity:
O(C(9, k))
(Backtracking explores valid combinations only.)

Space Complexity:
O(k)
(Recursion stack + current combination.)
*/







// CURRENT SUM METHOD OUTSIDE THE FUNCTION








#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Stores the current sum of selected numbers.
    int sum = 0;

    /*
        Recursive Backtracking Function

        Parameters:
        start -> Next number to consider (1 to 9).
        k     -> Required number of elements.
        target-> Target sum.
        curr  -> Current combination.
        ans   -> Stores all valid combinations.
    */
    void solve(int start,
               int k,
               int target,
               vector<int> &curr,
               vector<vector<int>> &ans)
    {
        // Base Case:
        // If the current sum equals the target
        // and exactly k numbers have been selected,
        // store the current combination.
        if (sum == target && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        // Invalid Cases:
        // 1. Current sum exceeds the target.
        // 2. More than k numbers have been selected.
        if (sum > target || curr.size() > k)
            return;

        // Try every number from 'start' to 9.
        for (int i = start; i <= 9; i++)
        {
            // Choose the current number.
            curr.push_back(i);
            sum += i;

            // Recur for the next number.
            solve(i + 1,
                  k,
                  target,
                  curr,
                  ans);

            // Backtrack.
            sum -= i;
            curr.pop_back();
        }
    }

    // Function to find all combinations of k numbers
    // whose sum equals the target.
    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        // Initialize current sum.
        sum = 0;

        // Start searching from number 1.
        solve(1,
              k,
              target,
              curr,
              ans);

        return ans;
    }
};

// -------------------------
// Main Function
// -------------------------
int main()
{
    int k = 3;
    int target = 9;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum3(k, target);

    cout << "Valid Combinations are:\n";

    for (auto combination : result)
    {
        cout << "{ ";

        for (int num : combination)
            cout << num << " ";

        cout << "}" << endl;
    }

    return 0;
}

/*
----------------------------------------
Input:
k = 3
target = 9

Output:
{ 1 2 6 }
{ 1 3 5 }
{ 2 3 4 }

Explanation:
Choose exactly k distinct numbers from 1 to 9
whose sum is equal to the target.

Time Complexity:
O(C(9, k))

Space Complexity:
O(k)
(Recursion stack + current combination.)
*/








// CURRENT SUM METHOD INSIDE THE FUNCTION AS PARAMETER




#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
        Recursive Backtracking Function

        Parameters:
        start -> Next number to consider (1 to 9).
        k     -> Required number of elements.
        target-> Target sum.
        sum   -> Current sum of selected numbers.
        curr  -> Current combination.
        ans   -> Stores all valid combinations.
    */
    void solve(int start,
               int k,
               int target,
               int sum,
               vector<int> &curr,
               vector<vector<int>> &ans)
    {
        // Base Case:
        // If current sum becomes equal to target
        // and exactly k numbers have been selected,
        // store the current combination.
        if (sum == target && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        // Invalid Cases:
        // 1. Current sum exceeds the target.
        // 2. More than k numbers have been selected.
        if (sum > target || curr.size() > k)
            return;

        // Try every number from 'start' to 9.
        for (int i = start; i <= 9; i++)
        {
            // Choose the current number.
            curr.push_back(i);

            // Recur for the next number.
            solve(i + 1,
                  k,
                  target,
                  sum + i,
                  curr,
                  ans);

            // Backtrack.
            curr.pop_back();
        }
    }

    // Function to find all combinations of k numbers
    // whose sum equals the target.
    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        // Start from number 1 with current sum = 0.
        solve(1,
              k,
              target,
              0,
              curr,
              ans);

        return ans;
    }
};

// -------------------------
// Main Function
// -------------------------
int main()
{
    int k = 3;
    int target = 9;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum3(k, target);

    cout << "Valid Combinations are:\n";

    for (auto combination : result)
    {
        cout << "{ ";

        for (int num : combination)
            cout << num << " ";

        cout << "}" << endl;
    }

    return 0;
}

/*
----------------------------------------
Input:
k = 3
target = 9

Output:
{ 1 2 6 }
{ 1 3 5 }
{ 2 3 4 }

Time Complexity:
O(C(9, k))

Space Complexity:
O(k)
(Recursion stack + current combination.)
*/





