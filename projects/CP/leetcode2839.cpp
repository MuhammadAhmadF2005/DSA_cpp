#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 0; j < 4; j++)
            {
                swap(s1[i], s2[j]);

                if (s1 == s2)
                {
                    flag = true;
                }
            }
        }
        return flag;
    }
};