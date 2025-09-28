#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

string addstrings(string a, string b);

int main()
{
    string a = "1";
    string b = "1";

    int index = 2;

    while (b.size() < 1000)
    {
        string c = addstrings(a, b);
        a = b;
        b = c;
        index++;
    }

    cout << index;

    return 0;
}