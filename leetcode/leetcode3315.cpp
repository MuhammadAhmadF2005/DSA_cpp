#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;
int main()
{

    return 0;
}

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (int &x : nums)
        {
            int res = -1;
            int d = 1;
            while ((x & d) != 0)
            {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};