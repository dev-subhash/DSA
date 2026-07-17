/*
2. Pascal Triangle II (LeetCode 119)
Brute Force Approach
Idea

Generate the complete Pascal Triangle till rowIndex and return the last row.

Time Complexity
O(n²)
Space Complexity
O(n²)

*/

//C++ Code (Brute Force)


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> triangle;

        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        // Return the required row
        return triangle[rowIndex];
    }
};

int main()
{
    Solution obj;

    int rowIndex;

    cout << "Enter Row Index: ";
    cin >> rowIndex;

    vector<int> ans = obj.getRow(rowIndex);

    cout << "\nRequired Row\n\n";

    for (int x : ans)
        cout << x << " ";

    return 0;
}





//OPTIMAL APPROACH



/*
Pascal Triangle II (Optimal)
Idea

Instead of generating all rows, generate only the required row.

We use the relation

C(n,r)=C(n,r−1)×(n-r+1)/r

	​


Each element can be calculated from the previous one.


*/



#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;

        // First element is always 1
        long long value = 1;
        ans.push_back(1);

        // Compute remaining elements using previous element
        for (int col = 1; col <= rowIndex; col++)
        {
            value = value * (rowIndex - col + 1);
            value = value / col;

            ans.push_back((int)value);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int rowIndex;

    cout << "Enter Row Index: ";
    cin >> rowIndex;

    vector<int> ans = obj.getRow(rowIndex);

    cout << "\nRequired Row\n\n";

    for (int x : ans)
        cout << x << " ";

    return 0;
}