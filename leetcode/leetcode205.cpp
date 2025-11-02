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
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        if (s.size() != t.size())
        {
            return false;
        }

        for (char i = 0; i <= s.size(); i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            // check one way mapping from s->t
            if (mapST.count(c1))
            {
                if (mapST[c1] != c2)
                {
                    return false;
                }
            }

            else
            {
                mapST[c1] = c2;
            }

            // check other way around asw//

            if (mapTS.count(c2))
            {
                if (mapTS[c2] != c1)
                {
                    return false;
                }
            }

            else
            {
                mapTS[c2] = c1;
            }
        }

        return true;
    }
};