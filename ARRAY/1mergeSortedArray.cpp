#include <bits/stdc++.h>
using namespace std;

// Solution class
class Solution
{
public:
    // Function to merge two sorted arrays into nums1
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Pointer to the last valid element of nums1
        int i = m - 1;

        // Pointer to the last element of nums2
        int j = n - 1;

        // Pointer to the last position of nums1
        int k = m + n - 1;

        // Compare elements from the end and place the larger one at index k
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy the remaining elements of nums2 (if any)
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // No need to copy remaining elements of nums1
        // because they are already in their correct positions.
    }
};

int main()
{
    // nums1 has enough space to accommodate nums2
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    Solution obj;

    // Merge nums2 into nums1
    obj.merge(nums1, m, nums2, n);

    // Print the merged array
    cout << "Merged Array: ";
    for (int x : nums1)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}