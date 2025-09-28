#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
int main()
{
    ll n, x; // num kids, max weight
    cin >> n >> x;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0, left = 0, right = n - 1;
    while (left <= right)
    {
        if (v[left] + v[right] <= x)
        {
            left++;
            right--;
            ans++;
        }
        else
        {
            right--;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}