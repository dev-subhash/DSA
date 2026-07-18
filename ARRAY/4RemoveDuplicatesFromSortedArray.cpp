/*
LeetCode 26: Remove Duplicates from Sorted Array
Problem Statement

Given a sorted integer array nums, remove the duplicates in-place such that every unique element appears only once.

Return the number of unique elements (k).

The first k elements of the array should contain the unique elements.

You must solve it using O(1) extra space.
*/


#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates from sorted array
// such that every element appears only once.
int removeDuplicates(vector<int>& nums)
{
    // If array is empty
    if (nums.size() == 0)
        return 0;

    // i points to the last unique element
    int i = 0;

    // Traverse the array
    for (int j = 1; j < nums.size(); j++)
    {
        // If current element is different,
        // place it after the last unique element.
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }

    // Number of unique elements
    return i + 1;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = removeDuplicates(nums);

    cout << "Length = " << k << endl;

    cout << "Modified Array : ";

    for(int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}