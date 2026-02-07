#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max_len = 1;
        int l = 0;

        for (int r = 0; r < n; r++)
        {
            while ((long long)nums[l] * k < nums[r])
            {
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }

        return n - max_len;
    }
};
