#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> digits;
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            digits.push_back(digit);
            n /= 10;
        }

        for (int digit : digits)
        {
            sum += digit * digit;
        }

        if (sum == 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    s.isHappy(10);
    return 0;
}
