#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string c : tokens)
        {
            if (c == "+")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first + second);
            }
            else if (c == "-")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first - second);
            }
            else if (c == "*")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first * second);
            }
            else if (c == "/")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first / second);
            }
            else
            {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};