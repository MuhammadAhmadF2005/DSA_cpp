#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> window(k);
    long long cur_sum = 0;
    long long ans = 0;

    // Generate first k elements
    for (int i = 0; i < k; i++)
    {
        window[i] = x;
        cur_sum += x;
        x = (a * x + b) % c;
    }

    ans ^= cur_sum;

    // Slide window
    for (int i = k; i < n; i++)
    {
        long long new_val = x;
        x = (a * x + b) % c;

        cur_sum += new_val;
        cur_sum -= window[i % k];

        window[i % k] = new_val;

        ans ^= cur_sum;
    }

    cout << ans << "\n";
    return 0;
}
