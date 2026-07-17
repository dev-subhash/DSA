#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    pair<int, int> largestAndSecondLargest(vector<int> &arr)
    {
        // If array has less than 2 elements,
        // second largest cannot exist.
        if (arr.size() < 2)
        {
            return {-1, -1};
        }

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        // Traverse the array once
        for (int num : arr)
        {
            // Found a new largest element
            if (num > largest)
            {
                secondLargest = largest;
                largest = num;
            }

            // Update second largest only if
            // current number is different from largest
            else if (num > secondLargest && num != largest)
            {
                secondLargest = num;
            }
        }

        // If second largest was never updated
        if (secondLargest == INT_MIN)
        {
            secondLargest = -1;
        }

        return {largest, secondLargest};
    }
};

int main()
{
    vector<int> arr = {12, 35, 1, 10, 34, 1};

    Solution obj;

    pair<int, int> ans = obj.largestAndSecondLargest(arr);

    cout << "Largest Element = " << ans.first << endl;
    cout << "Second Largest Element = " << ans.second << endl;

    return 0;
}