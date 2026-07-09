#include <iostream>
#include <vector>

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    // Outer loop for each pass
    for (int i = 0; i < n - 1; i++)
    {
        // Flag to check if any swap happened
        bool swapped = false;

        // Compare adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if elements are in wrong order
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swap occurred, array is already sorted
        if (!swapped)
            break;
    }
}

// Function to print the array
void printArray(const vector<int>& arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Array:\n";
    printArray(arr);

    bubbleSort(arr);

    cout << "\nSorted Array:\n";
    printArray(arr);

    return 0;
}