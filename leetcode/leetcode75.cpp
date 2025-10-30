#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int l, int h)
    {
        int pivot = nums[h];
        int i = l - 1;
        for (int j = l; j < h; j++)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[h]);
        return i + 1;
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }

    void sortColors(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
};
