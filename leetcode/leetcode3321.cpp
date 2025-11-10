#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<long long> ans; // use ll type arr to store ans

        for (int i = 0; i <= n - k; i++)
        {
            vector<int> freq(51, 0);

            // Count frequency of each number in current window
            for (int j = i; j < i + k; j++)
            {
                freq[nums[j]]++;
            }

            // Store (frequency, value) pairs for numbers that appear
            vector<pair<int, int>> pairs;
            for (int v = 1; v <= 50; v++)
            {
                if (freq[v] > 0)
                    pairs.push_back({freq[v], v});
            }

            // Sort by frequency DESC, value DESC
            sort(pairs.begin(), pairs.end(), [](auto &a, auto &b)
                 {
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first; });

            long long sum = 0;
            int taken = 0;

            // Take top x pairs
            for (auto &[f, v] : pairs)
            {
                sum += 1LL * f * v;
                taken++;
                if (taken == x)
                    break;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
