#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergesort(int arr[], int n)
{
    if (n <= 1)
    {
        return; // base case
    }
    int middle = n / 2;
    int leftArray[] = new int[middle];
    int rightArray[] = new int[n - middle];

    int i = 0; // left array
    int j = 0; // right array

    for (int i = 0; i < n; i++)
    {
        if (i < middle)
        {
            leftArray[i] = arr[i];
        }
        else
        {
            rightArray[j] = arr[i];
            j++;
        }
    }
}

void merge(int[], int leftArray[], int rightArray[])
{
    int leftsize = arr.size() / 2;
    int rightsize = arr.size() - leftsize;

    int i = 0, l = 0, r = 0;
    while (l < leftsize and r < rightsize)
    {
        if (leftArray[i] < rightArray[i])
        {
            array[i] = leftArray[i];
            i++;
            l++;
        }
        else
        {
            array[i] = rightArray[i];
            i++;
            j++;
        }
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 7, 8, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    print_array(arr, n);

    // bubble_sort(arr, n);
    selection_sort(arr, n);

    cout << "Sorted array: ";
    print_array(arr, n);

    return 0;
}
