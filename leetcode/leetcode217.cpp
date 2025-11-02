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
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> seen;

        for (int num : nums)
        {
            if (seen.count(num))
            {
                return true;
            }
            seen[num] = true; // mark as seen//
        }
        return false;
    }
};