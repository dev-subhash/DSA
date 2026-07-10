#include <iostream>
#include <vector>
using namespace std;

/*
-------------------------------------------------------
Function Name : generateSubsequence

Purpose:
Generate every possible subsequence of the given array.

Parameters:

index
------
Current position in the array.

nums
------
Original input array.

current
--------
Stores the subsequence that we are currently building.

answer
--------
Stores all generated subsequences.
-------------------------------------------------------
*/

void generateSubsequence(
        int index,
        vector<int> &nums,
        vector<int> &current,
        vector<vector<int>> &answer)
{

    /*
    ----------------------------------------------------
    BASE CASE

    When index reaches the size of array,
    it means we have already made decisions
    for every element.

    Now whatever is inside current becomes
    one complete subsequence.

    Store it and return.
    ----------------------------------------------------
    */

    if(index == nums.size())
    {
        answer.push_back(current);
        return;
    }

    /*
    ====================================================
    CHOICE 1 : TAKE the current element
    ====================================================

    Add current element into subsequence.
    */

    current.push_back(nums[index]);

    /*
    Move to next index.

    Since current element is already selected,
    continue building the remaining subsequence.
    */

    generateSubsequence(index + 1,
                        nums,
                        current,
                        answer);

    /*
    ----------------------------------------------------
    BACKTRACKING

    Remove the last inserted element.

    Why?

    Because now we want to explore another path
    where current element is NOT selected.

    push_back() always needs pop_back().

    This restores the previous state.
    ----------------------------------------------------
    */

    current.pop_back();

    /*
    ====================================================
    CHOICE 2 : DO NOT TAKE current element
    ====================================================

    Skip current element and move ahead.
    */

    generateSubsequence(index + 1,
                        nums,
                        current,
                        answer);
}

int main()
{
    /*
    Input Array
    */

    vector<int> nums = {1,2,3};

    /*
    Stores current subsequence.
    */

    vector<int> current;

    /*
    Stores all subsequences.
    */

    vector<vector<int>> answer;

    /*
    Start recursion from index 0.
    */

    generateSubsequence(0,
                        nums,
                        current,
                        answer);

    /*
    Print all subsequences.
    */

    cout << "All Subsequences\n\n";

    for(auto &subsequence : answer)
    {
        cout << "{ ";

        for(int x : subsequence)
            cout << x << " ";

        cout << "}\n";
    }

    return 0;
}