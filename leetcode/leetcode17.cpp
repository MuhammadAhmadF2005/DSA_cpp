#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> res;
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

    void backtrack(string &digits, int i, string cur)
    {
        if (cur.size() == digits.size())
        {
            res.push_back(cur);
            return;
        }

        for (char c : digitToLetters[digits[i]])
        {
            backtrack(digits, i + 1, cur + c);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return res;
        backtrack(digits, 0, "");
        return res;
    }
};
