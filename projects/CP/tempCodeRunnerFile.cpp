#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    long long e1, e2;
    cin >> e1 >> e2;

    vector<long long> w1(N);
    for (int i = 0; i < N; ++i)
        cin >> w1[i];

    vector<long long> w2(N);
    for (int i = 0; i < N; ++i)
        cin >> w2[i];

    vector<long long> s1(N - 1);
    for (int i = 0; i < N - 1; ++i)
        cin >> s1[i];

    vector<long long> s2(N - 1);
    for (int i = 0; i < N - 1; ++i)
        cin >> s2[i];

    long long x1, x2;
    cin >> x1 >> x2;

    long long dp1 = e1 + w1[0];
    long long dp2 = e2 + w2[0];

    for (int i = 1; i < N; ++i)
    {
        long long next_dp1 = min(dp1 + w1[i], dp2 + s2[i - 1] + w1[i]);
        long long next_dp2 = min(dp2 + w2[i], dp1 + s1[i - 1] + w2[i]);

        dp1 = next_dp1;
        dp2 = next_dp2;
    }

    cout << min(dp1 + x1, dp2 + x2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}