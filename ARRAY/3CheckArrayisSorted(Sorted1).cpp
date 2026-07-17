#include <iostream>
using namespace std;

// Function to check whether the array is sorted or not
bool isSorted(int arr[], int n)
{
    // Compare every element with its next element
    for (int i = 0; i < n - 1; i++)
    {
        // If current element is greater than next element,
        // the array is not sorted
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    // If no such pair is found, the array is sorted
    return true;
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Check whether the array is sorted
    if (isSorted(arr, n))
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}