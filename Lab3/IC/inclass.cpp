// Pham Quang Đại Phúc - 22521137

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function prototypes for each exercise
int binarySearchFirst(int arr[], int size, int target);
int binarySearchLast(int arr[], int size, int target);
int countOccurrences(int arr[], int size, int target);

int jumpSearch(int arr[], int size, int target);

int interpolationSearch(string arr[], int size, const string &target);

int findMissingNumber(int arr[], int size);

int bidirectionalBinarySearch(int arr[], int size, int target);

void swap(int &a, int &b);
int partition(int arr[], int low, int high);
int quickSelect(int arr[], int low, int high, int k);
int kthSmallest(int arr[], int size, int k);

void linearSearch(int arr[], int size, int target, int &comparisons);
void binarySearch(int arr[], int size, int target, int &comparisons);

int main()
{
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Count Occurrences Using Binary Search\n";
        cout << "2. Dynamic Step Size Jump Search\n";
        cout << "3. Interpolation Search for Strings\n";
        cout << "4. Find Missing Number Using Binary Search\n";
        cout << "5. Multi-Search System (Linear and Binary)\n";
        cout << "6. Bidirectional Binary Search\n";
        cout << "7. Kth Smallest Element Using Binary Search\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int size, target;
            cout << "Enter the size of the array: ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " sorted elements: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            cout << "Enter target to count occurrences: ";
            cin >> target;
            int count = countOccurrences(arr, size, target);
            cout << "Count of " << target << " is: " << count << "\n";
            break;
        }
        case 2:
        {
            int size, target;
            cout << "Enter the size of the array: ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " sorted elements: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            cout << "Enter target to find using Jump Search: ";
            cin >> target;
            int index = jumpSearch(arr, size, target);
            if (index != -1)
                cout << "Found at index: " << index << "\n";
            else
                cout << "Not found\n";
            break;
        }
        case 3:
        {
            int size;
            cout << "Enter the number of strings: ";
            cin >> size;
            string arr[size];
            cout << "Enter " << size << " lexicographically sorted strings: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            string target;
            cout << "Enter target string to search: ";
            cin >> target;
            int index = interpolationSearch(arr, size, target);
            if (index != -1)
                cout << "Found at index: " << index << "\n";
            else
                cout << "Not found\n";
            break;
        }
        case 4:
        {
            int size;
            cout << "Enter the size of the array (excluding missing number): ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " sorted elements with one missing (0 to n): ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            int missing = findMissingNumber(arr, size);
            cout << "Missing number is: " << missing << "\n";
            break;
        }
        case 5:
        {
            int size, target;
            cout << "Enter the size of the array: ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " sorted elements: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            cout << "Enter target to search: ";
            cin >> target;

            int linearComparisons = 0, binaryComparisons = 0;
            linearSearch(arr, size, target, linearComparisons);
            binarySearch(arr, size, target, binaryComparisons);

            cout << "Linear Search Comparisons: " << linearComparisons << "\n";
            cout << "Binary Search Comparisons: " << binaryComparisons << "\n";
            break;
        }
        case 6:
        {
            int size, target;
            cout << "Enter the size of the array: ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " sorted elements: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            cout << "Enter target to find using Bidirectional Binary Search: ";
            cin >> target;
            int index = bidirectionalBinarySearch(arr, size, target);
            if (index != -1)
                cout << "Found at index: " << index << "\n";
            else
                cout << "Not found\n";
            break;
        }
        case 7:
        {
            int size, k;
            cout << "Enter the size of the array: ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " unsorted elements: ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            cout << "Enter k to find kth smallest element: ";
            cin >> k;
            if (k > 0 && k <= size)
            {
                int result = kthSmallest(arr, size, k);
                cout << "The " << k << "th smallest element is: " << result << "\n";
            }
            else
            {
                cout << "Invalid k\n";
            }
            break;
        }
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

void linearSearch(int arr[], int size, int target, int &comparisons)
{
    for (int i = 0; i < size; i++)
    {
        comparisons++;
        if (arr[i] == target)
        {
            cout << "Linear Search: Found at index " << i << "\n";
            return;
        }
    }
    cout << "Linear Search: Not found\n";
}

void binarySearch(int arr[], int size, int target, int &comparisons)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            cout << "Binary Search: Found at index " << mid << "\n";
            return;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Binary Search: Not found\n";
}