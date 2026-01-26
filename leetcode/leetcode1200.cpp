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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> output;

        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] == min_diff)
            {
                output.push_back({arr[i], arr[i + 1]});
            }
        }
        return output;
    }
};