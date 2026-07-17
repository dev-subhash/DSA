/*
1. Pascal Triangle I (LeetCode 118)
Problem

Generate the first numRows of Pascal's Triangle.

Brute Force = Optimal

Since every element of the triangle must be generated, there is no faster algorithm.

Time Complexity
O(n²)
Space Complexity
O(n²)
*/



#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        // Stores the complete Pascal Triangle
        vector<vector<int>> ans;

        // Generate each row
        for (int i = 0; i < numRows; i++)
        {
            // Every row has i+1 elements.
            // Initialize all elements with 1.
            vector<int> row(i + 1, 1);

            // Fill the middle elements
            for (int j = 1; j < i; j++)
            {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            // Store the current row
            ans.push_back(row);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = obj.generate(numRows);

    cout << "\nPascal Triangle\n\n";

    for (auto row : result)
    {
        for (int x : row)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}