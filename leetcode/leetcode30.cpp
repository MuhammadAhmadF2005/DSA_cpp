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
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (words.empty() || s.empty())
            return res;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordFreq;
        for (auto &w : words)
            wordFreq[w]++;

        for (int i = 0; i < wordLen; i++)
        { // offset
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + wordLen <= s.size())
            {
                string w = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(w))
                {
                    seen[w]++;
                    count++;

                    while (seen[w] > wordFreq[w])
                    {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount)
                        res.push_back(left);
                }
                else
                {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return res;
    }
};