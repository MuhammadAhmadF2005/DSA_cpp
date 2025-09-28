#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void solveTestCase()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    map<int, int> freq;
    vector<int> repeats;

    for (int num : nums)
    {
        freq[num]++;
        if (freq[num] == 2)
        {
            repeats.push_back(num);
        }
    }

    if (repeats.empty())
    {
        cout << "-1" << endl;
        return;
    }

    if (repeats.size() > 1)
    {
        cout << repeats[0] << " " << repeats[0] << " "
             << repeats[1] << " " << repeats[1] << "\n";
        return;
    }

    int repeatVal = repeats[0];

    vector<int> remainingNums;
    int repeatCount = 2;
    for (int num : nums)
    {
        if (num == repeatVal && repeatCount > 0)
        {
            repeatCount--;
            continue;
        }
        remainingNums.push_back(num);
    }

    bool foundPair = false;
    for (int i = 0; i < remainingNums.size() - 1; i++)
    {
        if (remainingNums[i + 1] < remainingNums[i] + 2 * repeatVal)
        {
            cout << repeatVal << " " << repeatVal << " "
                 << remainingNums[i] << " " << remainingNums[i + 1] << "\n";
            foundPair = true;
            break;
        }
    }

    if (!foundPair)
    {
        cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solveTestCase();
    }

    return 0;
}
