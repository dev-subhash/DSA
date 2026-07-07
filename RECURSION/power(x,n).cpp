#include <iostream>
using namespace std;

class Solution {
public:

    // Recursive function to calculate x^n using Binary Exponentiation
    double calpow(double x, long long n) {

        // Base Case:
        // Any number raised to the power 0 is 1.
        if (n == 0)
            return 1.0;

        // Recursively calculate x^(n/2)
        double ans = calpow(x, n / 2);

        // If exponent is even:
        // x^n = (x^(n/2)) * (x^(n/2))
        if (n % 2 == 0) {
            return ans * ans;
        }

        // If exponent is odd:
        // x^n = (x^(n/2)) * (x^(n/2)) * x
        else {
            return ans * ans * x;
        }
    }

    // Function to calculate x raised to power n
    double myPow(double x, int n) {

        // Convert int to long long
        // This is necessary because INT_MIN cannot be negated safely.
        long long N = n;

        // If exponent is positive
        if (N >= 0)
            return calpow(x, N);

        // If exponent is negative
        // x^(-n) = 1 / x^n
        else
            return 1.0 / calpow(x, -N);
    }
};

int main() {

    Solution obj;

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    double result = obj.myPow(x, n);

    cout << "Result = " << result << endl;

    return 0;
}