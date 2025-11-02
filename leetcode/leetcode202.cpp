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
        set<int> seen;
        while (n != 1 and !seen.count(n))
        {
            seen.insert(n);

            int sum = 0;

            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return n == 1;
    }
};

// int main()
// {
//     Solution s;
//     s.isHappy(10);
//     return 0;
// }
