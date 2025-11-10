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
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) // we have a total of n-k iters in sliding window
        {
            vector<int> freq(51, 0); // create an array to store freq and initialize all vals with 0//
            for (int j = i; j < i + k; j++)
            {
                freq[nums[j]]++;
            }

            // Store (frequency, value) pairs for numbers that appear
            vector<pair<int, int>> pairs;
            for (int v = 1; v <= 50; v++)
            {
                if (freq[v] > 0)
                {
                    pairs.push_back({freq[v], v});
                }
            }

            // sort pairs//
            sort(pairs.begin(), pairs.end(), [](auto &a, auto &b)
                 {
                if(a.first==b.first)
                    return a.second>b.second;
                return a.first>b.first; });

            int sum = 0;
            int taken = 0;
            for (auto &[f, v] : pairs)
            {
                sum += f * v; // add all occurrences (freq * value)
                taken++;
                if (taken == x)
                    break;
            }

            ans.push_back(sum);
        }
        return ans;
    }
};