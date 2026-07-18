/*
LeetCode 80: Remove Duplicates from Sorted Array II
Problem Statement

Given a sorted integer array nums, remove duplicates in-place such that each unique element appears at most twice.

Return the new length (k).

The first k elements should contain the final array.

Use O(1) extra space.

*/



#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates
// so that every element appears at most twice.
int removeDuplicates(vector<int>& nums)
{
    int n = nums.size();

    // If array has two or fewer elements,
    // every element is already valid.
    if (n <= 2)
        return n;

    // i points to the next valid position
    int i = 2;

    // Traverse from the third element
    for (int j = 2; j < n; j++)
    {
        // If current element is different from
        // the element two positions behind,
        // then keep it.
        if (nums[j] != nums[i - 2])
        {
            nums[i] = nums[j];
            i++;
        }
    }

    // i is the new length
    return i;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};

    int k = removeDuplicates(nums);

    cout << "Length = " << k << endl;

    cout << "Modified Array : ";

    for(int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}