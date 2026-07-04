#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    /*
    ------------------------------------------------------------
    Function : findContentChildren()

    Purpose:
    Find the maximum number of students that can be satisfied
    using the available cookies.

    student[i] = minimum cookie size required by ith student
    cookie[i]  = size of ith cookie

    One cookie can be given to only one student.
    One student can receive only one cookie.

    We first sort both arrays so that smaller cookies are
    considered before larger ones.
    ------------------------------------------------------------
    */

    int findContentChildren(vector<int>& student, vector<int>& cookie)
    {
        /*
        --------------------------------------------------------
        Sorting allows us to process students and cookies
        from smallest to largest.

        Example

        student : 3 1 2
        cookie  : 2 1

        After sorting

        student : 1 2 3
        cookie  : 1 2
        --------------------------------------------------------
        */

        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        /*
        --------------------------------------------------------
        memo[i][j]

        Stores the answer starting from

        ith student
        jth cookie

        -1 means answer has not been computed yet.
        --------------------------------------------------------
        */

        vector<vector<int>> memo(
            student.size(),
            vector<int>(cookie.size(), -1)
        );

        /*
        Start recursion from

        Student = 0
        Cookie  = 0
        */

        return helper(0, 0, student, cookie, memo);
    }

private:

    /*
    ------------------------------------------------------------
    Parameters

    studentIndex
        Current student.

    cookieIndex
        Current cookie.

    student
        Sorted greed array.

    cookie
        Sorted cookie array.

    memo
        DP table storing previously computed answers.
    ------------------------------------------------------------
    */

    int helper(
        int studentIndex,
        int cookieIndex,
        vector<int>& student,
        vector<int>& cookie,
        vector<vector<int>>& memo
    )
    {

        /*
        --------------------------------------------------------
        BASE CASE

        If all students are processed
        OR

        all cookies are used,

        no more students can be satisfied.
        --------------------------------------------------------
        */

        if(studentIndex >= student.size() ||
           cookieIndex >= cookie.size())
        {
            return 0;
        }

        /*
        --------------------------------------------------------
        If this state has already been solved,

        return the stored answer.

        This avoids solving the same problem
        multiple times.
        --------------------------------------------------------
        */

        if(memo[studentIndex][cookieIndex] != -1)
            return memo[studentIndex][cookieIndex];

        /*
        Maximum satisfied students from this state.
        */

        int answer = 0;

        /*
        --------------------------------------------------------
        OPTION 1

        Assign current cookie to current student.

        This is possible only if

        cookie size >= student's greed.

        After assigning,

        move to

        next student
        next cookie
        --------------------------------------------------------
        */

        if(cookie[cookieIndex] >= student[studentIndex])
        {
            answer = max(
                answer,
                1 + helper(
                        studentIndex + 1,
                        cookieIndex + 1,
                        student,
                        cookie,
                        memo
                    )
            );
        }

        /*
        --------------------------------------------------------
        OPTION 2

        Skip the current cookie.

        Maybe this cookie is too small,
        or saving a larger cookie for this student
        leads to a better answer.

        Move only to the next cookie.

        Student remains the same.
        --------------------------------------------------------
        */

        answer = max(
                    answer,
                    helper(
                        studentIndex,
                        cookieIndex + 1,
                        student,
                        cookie,
                        memo
                    )
                 );

        /*
        Store the answer so that future calls
        can reuse it.
        */

        return memo[studentIndex][cookieIndex] = answer;
    }
};

int main()
{
    Solution obj;

    vector<int> student = {1,2,3};
    vector<int> cookie  = {1,1};

    int answer = obj.findContentChildren(student, cookie);

    cout << "Maximum Content Students = "
         << answer << endl;

    return 0;
}