#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------
// Function to merge two sorted halves of the array
//------------------------------------------------------
void merge(vector<int>& arr, int low, int mid, int high)
{
    // Temporary vector to store merged elements
    vector<int> temp;

    // Starting index of left subarray
    int left = low;

    // Starting index of right subarray
    int right = mid + 1;

    // Compare elements from both halves and
    // store the smaller one in temp
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements of left half
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of right half
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back into original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

//------------------------------------------------------
// Recursive Merge Sort Function
//------------------------------------------------------
void mergeSort(vector<int>& arr, int low, int high)
{
    // Base Case:
    // If there is only one element,
    // it is already sorted.
    if (low >= high)
    {
        return;
    }

    // Find middle index
    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both sorted halves
    merge(arr, low, mid, high);
}

//------------------------------------------------------
// Function to print the array
//------------------------------------------------------
void printArray(const vector<int>& arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

//------------------------------------------------------
// Driver Code
//------------------------------------------------------
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted Array:\n";
    printArray(arr);

    return 0;
}